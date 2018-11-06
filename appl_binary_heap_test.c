/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <appl_binary_heap.h>

#include <appl_binary_heap_test.h>

#include <stdio.h>

#include <string.h>

static
int
compare_string(
    void * const
        p_compare_context,
    void const * const
        p_data_1,
    void const * const
        p_data_2)
{
    (void)(
        p_compare_context);

#if 0
    return
        strcmp(
            (char const *)(
                p_data_1),
            (char const *)(
                p_data_2));
#endif
    return
        (int)(
            (char const *)(
                p_data_1)
            - (char const *)(
                p_data_2));

}

/*

*/
enum appl_status
appl_binary_heap_test_1(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_binary_heap *
        p_binary_heap;

    struct appl_binary_heap_descriptor
        o_descriptor;

    o_descriptor.p_compare =
        &(
            compare_string);

    o_descriptor.p_compare_context =
        (void *)(
            0);

    o_descriptor.i_initial_max =
        2u;

    e_status =
        appl_binary_heap_create(
            p_context,
            &(
                o_descriptor),
            &(
                p_binary_heap));

    if (
        appl_status_ok
        == e_status)
    {
        static char a_msg1[] = "xterior";
        static char a_msg2[] = "mindboggling";
        static char a_msg3[] = "testing";
        static char a_msg4[] = "george";
        static char a_msg5[] = "amazing";
        static char a_msg6[] = "zesty";

        static char * a_msgs[] =
        {
            a_msg1,
            a_msg2,
            a_msg3,
            a_msg4,
            a_msg5,
            a_msg6
        };

        appl_ull_t
            a_time[4u];

        appl_clock_read(
            p_context,
            1000000ul,
            &(
                a_time[0u]));

        /* Insert some items */
        {
            unsigned long int
                j;

            unsigned int
                i;

            j =
                0u;

            i =
                0u;

            while (
                j < 60000u)
            {
                e_status =
                    appl_binary_heap_insert(
                        p_binary_heap,
                        (void *)(
                            a_msgs[i]));

                i ++;
                if (i >= 6u)
                {
                    i = 0u;
                }

                j ++;
            }
        }

        appl_clock_read(
            p_context,
            1000000ul,
            &(
                a_time[1u]));

        /* Shuffle it */
        {
            unsigned long int
                j;

            unsigned int
                i;

            j =
                0ul;

            i =
                0u;

            while (
                j < 60000u)
            {
                void *
                    p_data;

                e_status =
                    appl_binary_heap_remove(
                        p_binary_heap,
                        &(
                            p_data));

                if (
                    appl_status_ok
                    == e_status)
                {
                    e_status =
                        appl_binary_heap_insert(
                            p_binary_heap,
                            (void *)(
                                a_msgs[i]));

                    i ++;
                    if (i >= 6u)
                    {
                        i = 0u;
                    }
                }

                j ++;
            }
        }

        appl_clock_read(
            p_context,
            1000000ul,
            &(
                a_time[2u]));

        /* Remove some items */
        {
            unsigned long int
                j;

            j =
                0ul;

            while (
                j < 60000u)
            {
                void *
                    p_data;

                e_status =
                    appl_binary_heap_remove(
                        p_binary_heap,
                        &(
                            p_data));

                if (
                    appl_status_ok
                    == e_status)
                {
                }

                j ++;
            }
        }

        appl_clock_read(
            p_context,
            1000000ul,
            &(
                a_time[3u]));

        printf("time[1-0] = %ld\n",
            (signed long int)(
                a_time[1u] - a_time[0u]));
        printf("time[2-1] = %ld\n",
            (signed long int)(
                a_time[2u] - a_time[1u]));
        printf("time[3-2] = %ld\n",
            (signed long int)(
                a_time[3u] - a_time[2u]));

        appl_object_destroy(
            appl_binary_heap_parent(
                p_binary_heap));
    }

    return
        e_status;

} /* _test_1() */

/* end-of-file: appl_binary_heap_test.c */
