/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <options/appl_options_test.h>

#include <appl_options_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <options/appl_options.h>

#include <appl_heap_handle.h>

#include <stdio.h>

/*

*/
void
appl_options_test_1(
    struct appl_options const * const
        p_options)
{
    enum appl_status
        e_status;

    unsigned long int
        argc;

    unsigned long int
        argi;

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

} /* appl_options_test_1() */

/*

*/
void
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
                    appl_options_test_1(
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

} /* appl_options_test_2() */

//
//
//
void
    appl_options_test_3(
        struct appl_context * const
            p_context)
{
    // test of options base class
    {
        struct appl_options *
            p_options;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_options));

        if (
            appl_status_ok
            == e_status)
        {
            p_options->v_count(
                0);

            p_options->v_get(
                0,
                0,
                0);

            p_options->v_write(
                0,
                0,
                0,
                0);

            p_options->v_append_argument(
                0,
                0);

            p_options->v_reset();

            appl_delete(
                p_context,
                p_options);
        }

    }

    // test of append
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
            appl_options_parent(
                p_options);

            appl_options_const_parent(
                p_options);

            {
                static unsigned char const g_arg[] =
                {
                    't',
                    'e',
                    's',
                    't',
                    '1'
                };

                appl_options_append_argument(
                    p_options,
                    g_arg,
                    g_arg + sizeof(g_arg));
            }

            appl_options_test_1(
                p_options);

            appl_options_reset(
                p_options);

            {
                static unsigned char const g_arg[] =
                {
                    'a',
                    ' ',
                    'b',
                    ' ',
                    'c',
                    '\n'
                };

                unsigned long int
                    i_length;

                char
                    b_ready;

                appl_options_write(
                    p_options,
                    g_arg,
                    g_arg + sizeof(g_arg),
                    &(
                        i_length),
                    &(
                        b_ready));
            }

            appl_options_test_1(
                p_options);

            appl_options_reset(
                p_options);

            appl_options_destroy(
                p_options);
        }
    }

    // test of write
    {
    }

} // appl_options_test_3()

/* end-of-file: appl_options_test.c */
