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

    o_context_descriptor.p_arg_min =
        argv;

    o_context_descriptor.p_arg_max =
        argv + argc;

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
        class appl_client * const
            p_client =
            reinterpret_cast<class appl_client *>(
                p_context);

        struct appl_options_descriptor
            o_options_descriptor;

        e_status =
            p_client->m_options->query(
                &(
                    o_options_descriptor));

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
                    &(
                        o_options_descriptor),
                    &(
                        i_exit_code));
        }
        else
        {
            i_exit_code =
                1;
        }

        appl_object_destroy(
            &(
                p_context->o_object_handle));
    }
    else
    {
        i_exit_code =
            1;
    }

    return
        i_exit_code;

} /* main() */

/* end-of-file: appl.cpp */
