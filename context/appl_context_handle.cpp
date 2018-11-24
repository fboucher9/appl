/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_context_handle.h>

#include <context/appl_context_service.h>

/*

*/
enum appl_status
appl_context_create(
    struct appl_context * * const
        r_context)
{
    return
        appl_context_service::s_create(
            r_context);

} /* appl_context_create() */

/*

*/
struct appl_object *
appl_context_parent(
    struct appl_context * const
        p_context)
{
    return
        appl_context_service::s_parent(
            p_context);

} /* parent() */

/*

*/
struct appl_object const *
appl_context_const_parent(
    struct appl_context const * const
        p_context)
{
    return
        appl_context_service::s_const_parent(
            p_context);

} /* const_parent() */

/*

*/
struct appl_allocator *
appl_context_get_allocator(
    struct appl_context const * const
        p_context)
{
    return
        appl_context_service::s_get_allocator(
            p_context);

} /* get_allocator() */

/* end-of-file: appl_context_handle.cpp */
