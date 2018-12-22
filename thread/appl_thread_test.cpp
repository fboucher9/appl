/* See LICENSE for license details */

/*

*/

#include <thread/appl_thread_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <thread/appl_thread_mgr.h>

#include <thread/appl_thread_node.h>

#include <appl_thread_descriptor.h>

#include <appl_thread_handle.h>

#include <appl_thread_property.h>

#include <appl_heap_handle.h>

#include <appl_clock_handle.h>

//
//
//
static
void
    appl_thread_test_1_callback(
        void * const
            p_thread_context)
{
    struct appl_context * const
        p_context =
        (struct appl_context *)(
            p_thread_context);

    appl_clock_delay(
        p_context,
        1ul,
        1000ul);

} // appl_thread_test_1_callback()

//
//
//
void
    appl_thread_test_1(
        struct appl_context * const
            p_context)
{
    // Thread Manager Base
    {
        class appl_thread_mgr *
            p_thread_mgr;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_thread_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            p_thread_mgr->v_create_node(
                0,
                0,
                0);

            p_thread_mgr->v_destroy_node(
                0);

            appl_delete(
                p_context,
                p_thread_mgr);
        }

    }

    // Thread Node Base
    {
        struct appl_thread *
            p_thread;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_thread));

        if (
            appl_status_ok
            == e_status)
        {
            p_thread->v_interrupt();

            appl_delete(
                p_context,
                p_thread);
        }
    }

    // Sanity check
    {
        struct appl_thread *
            p_thread;

        enum appl_status
            e_status;

        struct appl_thread_property *
            p_thread_property;

        e_status =
            appl_thread_property_create(
                p_context,
                &(
                    p_thread_property));

        if (
            appl_status_ok
            == e_status)
        {
            appl_thread_property_parent(
                p_thread_property);

            appl_thread_property_const_parent(
                p_thread_property);

            {
                unsigned char
                    b_detach_state;

                b_detach_state =
                    0u;

                appl_thread_property_set_detach_state(
                    p_thread_property,
                    b_detach_state);

                appl_thread_property_get_detach_state(
                    p_thread_property,
                    &(
                        b_detach_state));
            }

            struct appl_thread_descriptor
                o_thread_descriptor;

            o_thread_descriptor.b_callback =
                1;

            o_thread_descriptor.b_name =
                0;

            o_thread_descriptor.b_stack =
                0;

            o_thread_descriptor.b_scheduling =
                0;

            o_thread_descriptor.o_callback.p_entry =
                & appl_thread_test_1_callback;

            o_thread_descriptor.o_callback.p_context =
                p_context;

            e_status =
                appl_thread_create(
                    p_context,
                    p_thread_property,
                    &(
                        o_thread_descriptor),
                    &(
                        p_thread));

            if (
                appl_status_ok
                == e_status)
            {
                appl_thread_parent(
                    p_thread);

                appl_thread_const_parent(
                    p_thread);

                appl_clock_delay(
                    p_context,
                    1000ul,
                    50ul);

                appl_thread_interrupt(
                    p_thread);

                appl_thread_destroy(
                    p_thread);
            }

            appl_thread_property_destroy(
                p_thread_property);
        }
    }

} // appl_thread_test_1()

/* end-of-file: appl_thread_test.cpp */
