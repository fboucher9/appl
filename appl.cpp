/* See LICENSE for license details */

/*

Module: appl.c

Description:

    Dispatch of Application Library entry-points.

*/

#include <appl.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_options.h>

#include <appl_heap.h>

/*

*/
int
main(
    int argc,
    char * * argv)
{
    int
        i_exit_code;

    struct appl_context *
        p_context;

    enum appl_status
        e_status;

    struct appl_context_descriptor
        o_context_descriptor;

    o_context_descriptor.p_arg_min =
        reinterpret_cast<unsigned char * *>(
            argv);

    o_context_descriptor.p_arg_max =
        reinterpret_cast<unsigned char * *>(
            argv + argc);

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
        /* Dispatch */
        e_status =
            appl_main(
                p_context);

        if (
            appl_status_ok
            == e_status)
        {
            i_exit_code =
                0;
        }
        else
        {
            i_exit_code =
                1;
        }

        appl_object_destroy(
            appl_context_parent(
                p_context));
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
