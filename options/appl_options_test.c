/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <options/appl_options_test.h>

#include <stdio.h>

/*

*/
enum appl_status
appl_options_test_1(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_options)
{
    enum appl_status
        e_status;

    unsigned long int
        argc;

    unsigned long int
        argi;

    (void)(
        p_context);

    {
        struct appl_object const *
            pc_object;

        pc_object =
            appl_options_const_parent(
                p_options);

        (void)(
            pc_object);
    }

    e_status =
        appl_options_count(
            p_options,
            &(
                argc));

    if (
        appl_status_ok
        == e_status)
    {
        argi = 0;

        while (
            argi < argc)
        {
            unsigned char const *
                p_buf_min;

            unsigned char const *
                p_buf_max;

            e_status =
                appl_options_get(
                    p_options,
                    argi,
                    &(
                        p_buf_min),
                    &(
                        p_buf_max));

            if (
                appl_status_ok
                == e_status)
            {
                printf("[%ld] [%.*s]\n",
                    (signed long int)(argi),
                    (int)(p_buf_max - p_buf_min),
                    p_buf_min);
            }

            argi ++;
        }
    }

    return
        e_status;

} /* appl_options_test_1() */

/*

*/
enum appl_status
appl_options_test_2(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_options *
        p_options;

    e_status =
        appl_options_create(
            p_context,
            &(
                p_options));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned long int
            i_count;

        char
            b_ready;

        static unsigned char a_msg[] = " \n\t test '1 2 3' a\\ b\\ c\n";

        unsigned char * p_msg_iterator;

        {
            struct appl_object *
                p_object;

            p_object =
                appl_options_parent(
                    p_options);

            (void)(
                p_object);
        }

        p_msg_iterator =
            a_msg;

        while (
            (
                appl_status_ok
                == e_status)
            && (
                p_msg_iterator
                != a_msg + sizeof(a_msg)))
        {
            e_status =
                appl_options_write(
                    p_options,
                    p_msg_iterator,
                    a_msg + sizeof(a_msg),
                    &(
                        i_count),
                    &(
                        b_ready));

            if (
                appl_status_ok
                == e_status)
            {
                if (
                    b_ready)
                {
                    e_status =
                        appl_options_test_1(
                            p_context,
                            p_options);
                }

                p_msg_iterator +=
                    i_count;
            }
        }

        appl_options_reset(
            p_options);

        appl_options_destroy(
            p_options);
    }

    return
        e_status;

} /* appl_options_test_2() */

/* end-of-file: appl_options_test.c */
