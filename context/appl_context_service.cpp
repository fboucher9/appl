/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <context/appl_context_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <allocator/appl_allocator.h>

#include <heap/appl_heap.h>

#include <heap/appl_heap_std.h>

#include <context/appl_context_std.h>

//
//
//
enum appl_status
appl_context_service::s_create(
    struct appl_context * * const
        r_context)
{
    enum appl_status
        e_status;

    struct appl_context *
        p_context;

    e_status =
        appl_context_std::s_create(
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

} // s_create()

//
//
//
enum appl_status
appl_context_service::s_destroy(
    struct appl_context * const
        p_context)
{
    return
        appl_context_std::s_destroy(
            p_context);

} // s_destroy()

//
//
//
struct appl_object *
appl_context_service::s_parent(
    struct appl_context * const
        p_context)
{
    return
        p_context;

} // s_parent()

//
//
//
struct appl_object const *
appl_context_service::s_const_parent(
    struct appl_context const * const
        p_context)
{
    return
        p_context;

} // s_const_parent()

//
//
//
struct appl_allocator *
appl_context_service::s_get_allocator(
    struct appl_context const * const
        p_context)
{
    return
        p_context->v_allocator();

} // s_get_allocator()

/* end-of-file: appl_context_service.cpp */
