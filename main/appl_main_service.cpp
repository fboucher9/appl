/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <main/appl_main_service.h>

#include <appl_context_handle.h>

#include <appl_options_handle.h>

#include <appl_object_handle.h>

#include <appl_buf0.h>

#include <appl_convert.h>

//
//
//
static
enum appl_status
init_options(
    struct appl_context * const
        p_context,
    unsigned char const * const * const
        p_arg_min,
    unsigned char const * const * const
        p_arg_max,
    struct appl_options * * const
        r_options)
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
        // append some arguments
        unsigned char const * const *
            p_arg_it;

        p_arg_it =
            p_arg_min;

        while (
            (
                appl_status_ok
                == e_status)
            && (
                p_arg_it
                != p_arg_max))
        {
            unsigned char const * const
                p_arg =
                *(
                    p_arg_it);

            // find length of arg
            unsigned long int const
                i_arg_len =
                appl_buf0_len(
                    p_arg);

            e_status =
                appl_options_append_argument(
                    p_options,
                    p_arg,
                    p_arg + i_arg_len);

            if (
                appl_status_ok
                == e_status)
            {
                p_arg_it ++;
            }
        }

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_options) =
                p_options;
        }

        if (
            appl_status_ok
            != e_status)
        {
            appl_options_destroy(
                p_options);
        }
    }

    return
        e_status;

} // init_options()

//
//
//
int
appl_main_service::s_main(
    int const
        i_arg_count,
    char * * const
        p_arg_vector,
    enum appl_status (*
        p_main_callback)(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options))
{
    int
        i_main_result;

    enum appl_status
        e_status;

    struct appl_context *
        p_context;

    /* Create context */
    e_status =
        appl_context_create(
            &(
                p_context));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_options *
            p_options;

        /* Create options */
        e_status =
            init_options(
                p_context,
                appl_convert::to_uchar_ptr_table(
                    p_arg_vector),
                appl_convert::to_uchar_ptr_table(
                    p_arg_vector + i_arg_count),
                &(
                    p_options));

        if (
            appl_status_ok
            == e_status)
        {
            /* Dispatch */
            e_status =
                (*p_main_callback)(
                    p_context,
                    p_options);

            appl_options_destroy(
                p_options);
        }

        appl_context_destroy(
            p_context);
    }

    if (
        appl_status_ok
        == e_status)
    {
        i_main_result =
            0;
    }
    else
    {
        i_main_result =
            1;
    }

    return
        i_main_result;

} // s_main()

/* end-of-file: appl_main_service.cpp */
