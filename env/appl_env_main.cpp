/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <env/appl_env_main.h>

#include <appl_env_handle.h>

#include <appl_options_handle.h>

#include <appl_buf.h>

#include <appl_test.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_env_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    unsigned long int
        i_options_count;

    appl_unused(
        p_context);

    appl_print0("env main\n");

    e_status =
        appl_options_count(
            p_options,
            &(
                i_options_count));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned long int
            i_options_index;

        i_options_index =
            i_shift + 1ul;

        while (
            (
                appl_status_ok
                == e_status)
            && (
                i_options_index
                < i_options_count))
        {
            unsigned char const *
                p_arg_min;

            unsigned char const *
                p_arg_max;

            e_status =
                appl_options_get(
                    p_options,
                    i_options_index,
                    &(
                        p_arg_min),
                    &(
                        p_arg_max));

            if (
                appl_status_ok
                == e_status)
            {
                static unsigned char const s_ref_get[] =
                {
                    'g',
                    'e',
                    't'
                };

                static unsigned char const s_ref_set[] =
                {
                    's',
                    'e',
                    't'
                };

                if (
                    (
                        0
                        == appl_buf_compare(
                            p_arg_min,
                            p_arg_max,
                            s_ref_get,
                            s_ref_get + sizeof(s_ref_get)))

                    && (
                        i_options_index + 1ul
                        < i_options_count))
                {
                }
                else if (
                    (
                        0
                        == appl_buf_compare(
                            p_arg_min,
                            p_arg_max,
                            s_ref_set,
                            s_ref_set + sizeof(s_ref_set)))
                    && (
                        i_options_index + 2ul
                        < i_options_count))
                {
                }
                else
                {
                }
            }
        }
    }

    return
        e_status;

} // appl_env_main()

/* end-of-file: appl_env_main.cpp */
