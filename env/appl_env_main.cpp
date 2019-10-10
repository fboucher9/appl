/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <env/appl_env_main.h>

#include <env/appl_env_handle.h>

#include <appl_options_handle.h>

#include <buf/appl_buf.h>

#include <appl_test.h>

#include <misc/appl_unused.h>

//
//
//
static
void
    appl_env_main_get_cb(
        void * const
            p_query_context,
        unsigned char const * const
            p_value_min,
        unsigned char const * const
            p_value_max)
{
    appl_unused(
        p_query_context);

    appl_print(
        p_value_min,
        p_value_max);
}

//
//
//
static
enum appl_status
    appl_env_main_get(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_name_min;

    unsigned char const *
        p_name_max;

    e_status =
        appl_options_get(
            p_options,
            i_shift + 1u,
            &(
                p_name_min),
            &(
                p_name_max));

    if (
        appl_status_ok
        == e_status)
    {
        appl_print(
            p_name_min,
            p_name_max);

        appl_print0(
            "=");

        e_status =
            appl_env_query(
                p_context,
                p_name_min,
                p_name_max,
                appl_env_main_get_cb,
                0);

        appl_print0(
            "\n");
    }

    return
        e_status;

} // appl_env_main_get()

//
//
//
static
enum appl_status
    appl_env_main_set(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_name_min;

    unsigned char const *
        p_name_max;

    e_status =
        appl_options_get(
            p_options,
            i_shift + 1u,
            &(
                p_name_min),
            &(
                p_name_max));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char const *
            p_value_min;

        unsigned char const *
            p_value_max;

        e_status =
            appl_options_get(
                p_options,
                i_shift + 2u,
                &(
                    p_value_min),
                &(
                    p_value_max));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                appl_env_set(
                    p_context,
                    p_name_min,
                    p_name_max,
                    p_value_min,
                    p_value_max);
        }
    }

    return
        e_status;

} // appl_env_main_set()

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
                    e_status =
                        appl_env_main_get(
                            p_context,
                            p_options,
                            i_options_index);

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        i_options_index +=
                            2u;
                    }
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
                    e_status =
                        appl_env_main_set(
                            p_context,
                            p_options,
                            i_options_index);

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        i_options_index +=
                            3u;
                    }
                }
                else
                {
                    e_status =
                        appl_raise_invalid_param();
                }
            }
        }
    }

    return
        e_status;

} // appl_env_main()

/* end-of-file: appl_env_main.cpp */
