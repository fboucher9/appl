/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <main/appl_main.h>

#include <main/appl_main_service.h>

#include <context/appl_context_handle.h>

#include <options/appl_options_handle.h>

#include <object/appl_object_handle.h>

#include <buf/appl_buf0.h>

#include <misc/appl_convert.h>

#include <misc/appl_unused.h>

//
//
//
void
    appl_main_service::s_init(
        struct appl_main_descriptor * const
            p_main_descriptor)
{
    p_main_descriptor->p_arg_vector_min =
        0;

    p_main_descriptor->p_arg_vector_max =
        0;

    p_main_descriptor->p_main_callback =
        0;

} // s_init()

//
//
//
void
    appl_main_service::s_cleanup(
        struct appl_main_descriptor * const
            p_main_descriptor)
{
    appl_unused(
        p_main_descriptor);

} // s_cleanup()

//
//
//
void
    appl_main_service::s_set_arg_vector(
        struct appl_main_descriptor * const
            p_main_descriptor,
        char const * const * const
            p_arg_vector_min,
        char const * const * const
            p_arg_vector_max)
{
    p_main_descriptor->p_arg_vector_min =
        p_arg_vector_min;

    p_main_descriptor->p_arg_vector_max =
        p_arg_vector_max;

} // s_set_arg_vector()

//
//
//
void
    appl_main_service::s_set_callback(
        struct appl_main_descriptor * const
            p_main_descriptor,
        appl_main_callback * const
            p_main_callback)
{
    p_main_descriptor->p_main_callback =
        p_main_callback;

} // s_set_callback()

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
    struct appl_main_descriptor const * const
        p_main_descriptor)
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
                    p_main_descriptor->p_arg_vector_min),
                appl_convert::to_uchar_ptr_table(
                    p_main_descriptor->p_arg_vector_max),
                &(
                    p_options));

        if (
            appl_status_ok
            == e_status)
        {
            /* Dispatch */
            e_status =
                (*p_main_descriptor->p_main_callback)(
                    p_context,
                    p_options,
                    0ul);

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
