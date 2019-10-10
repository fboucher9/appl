/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <timer/appl_timer_test.h>

#include <list/appl_node.h>

#include <timer/appl_timer_node.h>

#include <timer/appl_timer_mgr.h>

#include <misc/appl_unused.h>

#include <stdio.h>

/*

*/
static
void
appl_timer_test_event_cb(
    void * const
        p_timer_context,
    struct appl_timer_node * const
        p_timer_node)
{
    appl_unused(p_timer_node);

    printf("event [%s]\n", static_cast<char *>(p_timer_context));
}

/*

*/
void
appl_timer_test_1(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_timer_group *
        p_timer_group;

    /* Create a timer and schedule some events */
    e_status =
        appl_timer_group_create(
            p_context,
            &(
                p_timer_group));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_timer_node *
            p_timer_node;

        /* Parent */
        appl_timer_group_parent(
            p_timer_group);

        appl_timer_group_const_parent(
            p_timer_group);

        e_status =
            appl_timer_node_create(
                p_timer_group,
                &(
                    p_timer_node));

        if (
            appl_status_ok
            == e_status)
        {
            appl_ull_t
                i_now_usec;

            /* Parent */
            appl_timer_node_parent(
                p_timer_node);

            appl_timer_node_const_parent(
                p_timer_node);

            /* Detect current time */
            e_status =
                appl_clock_read(
                    p_context,
                    1000000ul,
                    &(
                        i_now_usec));

            if (
                appl_status_ok
                == e_status)
            {
                /* Schedule some events */
                {
                    static char g_event_A[] = "A";

                    struct appl_timer_descriptor
                        o_timer_descriptor;

                    o_timer_descriptor.i_abstime_usec =
                        i_now_usec + 1000000ul;

                    o_timer_descriptor.p_timer_callback =
                        &(
                            appl_timer_test_event_cb);

                    o_timer_descriptor.p_timer_context =
                        static_cast<void *>(
                            g_event_A);

                    printf("schedule [A]\n");

                    e_status =
                        appl_timer_node_schedule(
                            p_timer_node,
                            &(
                                o_timer_descriptor));
                }

                /* Wait for events to occur */
                printf("waiting ...\n");

                appl_clock_delay(
                    p_context,
                    1000ul,
                    2000ul);

                printf("... done\n");
            }

            appl_timer_node_destroy(
                p_timer_group,
                p_timer_node);
        }

        appl_timer_group_destroy(
            p_context,
            p_timer_group);
    }

    // base timer mgr
    {
        class appl_timer_mgr *
            p_timer_mgr;

        e_status =
            appl_new(
                p_context,
                &(
                    p_timer_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            p_timer_mgr->v_create_group(
                0);

            p_timer_mgr->v_destroy_group(
                0);

            appl_delete(
                p_context,
                p_timer_mgr);
        }
    }

    // base timer group
    {
    }

    // base timer node
    {
        struct appl_timer_node *
            p_timer_node;

        e_status =
            appl_new(
                p_context,
                &(
                    p_timer_node));

        if (
            appl_status_ok
            == e_status)
        {
            p_timer_node->v_schedule(
                0);

            appl_delete(
                p_context,
                p_timer_node);
        }
    }

} /* appl_timer_test_1() */

/* end-of-file: appl_timer_test.c */
