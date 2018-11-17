/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_main_std.h>

#include <appl_context_handle.h>

#include <appl_convert.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_list.h>

#include <appl_options.h>

#include <appl_options_std.h>

#include <appl_buf0.h>

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
        appl_options_std::s_create(
            p_context->m_allocator,
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
                p_options->v_append_argument(
                    p_arg,
                    p_arg + i_arg_len);

            if (
                appl_status_ok
                == e_status)
            {
                p_arg_it ++;
            }
        }

        *(
            r_options) =
            p_options;
    }

    return
        e_status;

} // init_options()

/*

*/
enum appl_status
    appl_main_std(
        unsigned char const * const * const
            p_arg_min,
        unsigned char const * const * const
            p_arg_max,
        enum appl_status (*
            p_main_callback)(
            struct appl_context * const
                p_context,
            struct appl_options const * const
                p_options))
{
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
                p_arg_min,
                p_arg_max,
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

            p_options->v_destroy();
        }

        p_context->v_destroy();
    }

    return
        e_status;

} /* appl_main_std() */

/* end-of-file: appl_main_std.cpp */
