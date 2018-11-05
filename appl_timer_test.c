/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <appl_timer_test.h>

#include <stdio.h>

/*

*/
static
void
appl_timer_test_event_cb(
    void * const
        p_timer_context)
{
    printf("event [%s]\n", (char *)(p_timer_context));
}

/*

*/
enum appl_status
appl_timer_test_1(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_timer *
        p_timer;

    /* Create a timer and schedule some events */
    e_status =
        appl_timer_create(
            p_context,
            &(
                p_timer));

    if (
        appl_status_ok
        == e_status)
    {
        /* Detect current time */
        appl_ull_t
            i_now_usec;

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
                    (void *)(
                        g_event_A);

                printf("schedule [A]\n");

                e_status =
                    appl_timer_schedule(
                        p_timer,
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

        appl_object_destroy(
            appl_timer_parent(
                p_timer));
    }

    return
        e_status;

} /* appl_timer_test_1() */

/* end-of-file: appl_timer_test.c */
