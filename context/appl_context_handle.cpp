/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_context_handle.h>

#include <context/appl_context_service.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

/*

*/
enum appl_status
appl_context_create(
    struct appl_context * * const
        r_context)
{
    enum appl_status
        e_status;

    if (
        r_context)
    {
        e_status =
            appl_context_service::s_create(
                r_context);
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "appl_context_create invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* appl_context_create() */

/*

*/
enum appl_status
appl_context_destroy(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    if (
        p_context)
    {
        e_status =
            appl_context_service::s_destroy(
                p_context);
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "appl_context_destroy invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* appl_context_destroy() */

/*

*/
struct appl_object *
appl_context_parent(
    struct appl_context * const
        p_context)
{
#if defined APPL_DEBUG
    if (
        !p_context)
    {
        appl_debug_impl::s_print0(
            "appl_context_parent invalid param\n");
    }
#endif /* #if defined APPL_DEBUG */

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
#if defined APPL_DEBUG
    if (
        !p_context)
    {
        appl_debug_impl::s_print0(
            "appl_context_const_parent invalid param\n");
    }
#endif /* #if defined APPL_DEBUG */

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
#if defined APPL_DEBUG
    if (
        !p_context)
    {
        appl_debug_impl::s_print0(
            "appl_context_get_allocator invalid param\n");
    }
#endif /* #if defined APPL_DEBUG */

    return
        appl_context_service::s_get_allocator(
            p_context);

} /* get_allocator() */

/* end-of-file: appl_context_handle.cpp */
