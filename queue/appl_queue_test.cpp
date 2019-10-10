/* See LICENSE for license details */

#include <queue/appl_queue_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_queue_handle.h>

#include <appl_object.h>

#include <queue/appl_queue.h>

#include <list/appl_list.h>

#include <misc/appl_unused.h>

#include <appl_heap_handle.h>

//
//
//
void
    appl_queue_test_1(
        struct appl_context * const
            p_context)
{
    // sanity check
    {
        enum appl_status
            e_status;

        struct appl_queue *
            p_queue;

        struct appl_queue_descriptor
            o_queue_descriptor;

        o_queue_descriptor.i_max_count =
            1u;

        e_status =
            appl_queue_create(
                p_context,
                &(
                    o_queue_descriptor),
                &(
                    p_queue));

        if (
            appl_status_ok
            == e_status)
        {
            {
                struct appl_object *
                    p_object;

                p_object =
                    appl_queue_parent(
                        p_queue);

                appl_unused(
                    p_object);
            }

            {
                appl_queue_interrupt(
                    p_queue);
            }

            {
                static struct appl_list
                    o_dummy_node;

                static struct appl_list
                    o_dummy_node2;

                struct appl_list *
                    p_pop_result;

                appl_list_init(
                    &(
                        o_dummy_node));

                appl_list_init(
                    &(
                        o_dummy_node2));

                appl_queue_push(
                    p_queue,
                    &(
                        o_dummy_node),
                    1000ul,
                    1ul);

                appl_queue_push(
                    p_queue,
                    &(
                        o_dummy_node2),
                    1000ul,
                    1ul);

                appl_queue_pop(
                    p_queue,
                    &(
                        p_pop_result),
                    1000ul,
                    1ul);

                appl_queue_pop(
                    p_queue,
                    &(
                        p_pop_result),
                    1000ul,
                    1ul);
            }

            appl_queue_destroy(
                p_queue);
        }
    }

    // coverage of queue base class
    {
        struct appl_queue *
            p_queue;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_queue));

        if (
            appl_status_ok
            == e_status)
        {
            p_queue->v_push(
                0,
                0,
                0);

            p_queue->v_pop(
                0,
                0,
                0);

            p_queue->v_interrupt();

            appl_delete(
                p_context,
                p_queue);
        }
    }

} // appl_queue_test_1()

/* end-of-file: appl_queue_test.cpp */
