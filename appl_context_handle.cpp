/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_object_handle.h>

#include <appl_context_handle.h>

#include <appl_types.h>

#include <appl_buf.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_context_std.h>

/*

*/
enum appl_status
appl_context_create(
    struct appl_context_descriptor const * const
        p_context_descriptor,
    struct appl_context * * const
        r_context)
{
    enum appl_status
        e_status;

    struct appl_context *
        p_context;

    e_status =
        appl_context_std::create_instance(
            p_context_descriptor,
            &(
                p_context));

    if (
        appl_status_ok == e_status)
    {
        *(
            r_context) =
            p_context;
    }

    return
        e_status;

} /* appl_context_create() */

struct appl_object *
appl_context_parent(
    struct appl_context * const
        p_context)
{
    return
        p_context;

} /* parent() */

struct appl_object const *
appl_context_const_parent(
    struct appl_context const * const
        p_context)
{
    return
        p_context;

} /* const_parent() */

/* end-of-file: appl_context_handle.cpp */
