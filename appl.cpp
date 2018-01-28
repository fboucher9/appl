/* See LICENSE for license details */

/*

Module: appl.c

Description:

    Dispatch of Application Library entry-points.

*/

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "appl.h"

#include "appl_object.h"

#include "appl_client.h"

#include "appl_options.h"

#include "appl_options_std.h"

/*

*/
enum appl_status
appl_object_destroy(
    struct appl_object_handle * const
        p_object_handle)
{
    class appl_object * const
        p_object =
        reinterpret_cast<class appl_object *>(
            p_object_handle);

    return
        p_object->destroy();

} /* appl_object_destroy() */

/*

*/
enum appl_status
appl_context_create(
    struct appl_context_descriptor const * const
        p_client_descriptor,
    struct appl_context_handle * * const
        r_context_handle)
{
    class appl_client *
        p_client;

    enum appl_status const
    e_status =
        appl_client::create_instance(
            p_client_descriptor,
            &(
                p_client));

    if (
        appl_status_ok == e_status)
    {
        *(
            r_context_handle) =
            reinterpret_cast<struct appl_context_handle *>(
                p_client);
    }

    return
        e_status;

} /* appl_context_create() */

/*

*/
enum appl_status
appl_options_create(
    struct appl_context_handle * const
        p_context,
    struct appl_options_descriptor const * const
        p_options_descriptor,
    struct appl_options_handle * * const
        r_options_handle)
{
    class appl_options_std *
        p_options_std;

    class appl_client * const
        p_client =
        reinterpret_cast<class appl_client *>(
            p_context);

    enum appl_status const
    e_status =
        appl_options_std::create_instance(
            p_client,
            p_options_descriptor,
            &(
                p_options_std));

    if (
        appl_status_ok == e_status)
    {
        *(
            r_options_handle) =
            reinterpret_cast<struct appl_options_handle *>(
                p_options_std);
    }

    return
        e_status;

} /* appl_options_create() */

/*

*/
enum appl_status
appl_options_query(
    struct appl_options_handle * const
        p_options_handle,
    struct appl_options_descriptor * const
        p_options_descriptor)
{
    class appl_options * const
        p_options =
        reinterpret_cast<class appl_options *>(
            p_options_handle);

    enum appl_status const
        e_status =
        p_options->query(
            p_options_descriptor);

    return
        e_status;

} /* appl_options_query() */

int
main(
    int argc,
    char * * argv)
{
    int
        i_exit_code;

    struct appl_context_handle *
        p_context;

    enum appl_status
        e_status;

    struct appl_context_descriptor
        o_context_descriptor;

    /* Create context */
    e_status =
        appl_context_create(
            &(
                o_context_descriptor),
            &(
                p_context));

    if (
        appl_status_ok
        == e_status)
    {
        /* Create options */
        struct appl_options_handle *
            p_options;

        struct appl_options_descriptor
            o_options_descriptor;

        if (argc)
        {
            /* Create array of buffer */
            o_options_descriptor.p_buf_min =
                static_cast<struct appl_buf *>(
                    malloc(
                        argc * sizeof(
                            struct appl_buf)));

            if (
                o_options_descriptor.p_buf_min)
            {
                int argi;

                o_options_descriptor.p_buf_max =
                    o_options_descriptor.p_buf_min + argc;

                for (argi = 0; argi < argc; argi ++)
                {
                    o_options_descriptor.p_buf_min[argi].o_min.p_void =
                        static_cast<void *>(
                            argv[argi]);

                    o_options_descriptor.p_buf_min[argi].o_max.p_void =
                        static_cast<void *>(
                            argv[argi] + strlen(argv[argi]));
                }
            }
        }
        else
        {
            o_options_descriptor.p_buf_min =
                0;

            o_options_descriptor.p_buf_max =
                0;

        }

        e_status =
            appl_options_create(
                p_context,
                &(
                    o_options_descriptor),
                &(
                    p_options));

        if (
            o_options_descriptor.p_buf_min)
        {
            free(
                static_cast<void *>(
                    o_options_descriptor.p_buf_min));

            o_options_descriptor.p_buf_min =
                0;

            o_options_descriptor.p_buf_max =
                0;
        }

        if (
            appl_status_ok
            == e_status)
        {
            /* Dispatch */
            i_exit_code =
                1;

            e_status =
                appl_main(
                    p_context,
                    p_options,
                    &(
                        i_exit_code));
        }
        else
        {
            i_exit_code =
                1;
        }
    }
    else
    {
        i_exit_code =
            1;
    }


    return
        i_exit_code;

}
