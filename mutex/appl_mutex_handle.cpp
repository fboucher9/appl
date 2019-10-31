/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <mutex/appl_mutex_handle.h>

#include <mutex/appl_mutex_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <mutex/appl_mutex_node.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

/*

*/
enum appl_status
appl_mutex_create(
    struct appl_context * const
        p_context,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex)
{
    enum appl_status
        e_status;

    if (
        p_context
        && p_mutex_descriptor
        && r_mutex)
    {
        e_status =
            appl_mutex_service::s_create(
                p_context,
                p_mutex_descriptor,
                r_mutex);
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} /* appl_mutex_create() */

/*

*/
enum appl_status
appl_mutex_destroy(
    struct appl_mutex * const
        p_mutex)
{
    enum appl_status
        e_status;

    if (
        p_mutex)
    {
        e_status =
            appl_mutex_service::s_destroy(
                p_mutex);
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} /* appl_mutex_destroy() */

struct appl_object *
appl_mutex_parent(
    struct appl_mutex * const
        p_mutex)
{
#if defined APPL_DEBUG
    if (
        !p_mutex)
    {
        appl_debug_impl::s_print0(
            "appl_mutex_parent: invalid param\n");
    }
#endif /* #if defined APPL_DEBUG */

    return
        p_mutex;

}

struct appl_object const *
appl_mutex_const_parent(
    struct appl_mutex const * const
        p_mutex)
{
#if defined APPL_DEBUG
    if (
        !p_mutex)
    {
        appl_debug_impl::s_print0(
            "appl_mutex_const_parent: invalid param\n");
    }
#endif /* #if defined APPL_DEBUG */

    return
        p_mutex;

}

/*

*/
enum appl_status
appl_mutex_lock(
    struct appl_mutex * const
        p_mutex)
{
    enum appl_status
        e_status;

    if (
        p_mutex)
    {
        e_status =
            appl_mutex_service::s_lock(
                p_mutex);
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} /* appl_mutex_lock() */

/*

*/
enum appl_status
appl_mutex_unlock(
    struct appl_mutex * const
        p_mutex)
{
    enum appl_status
        e_status;

    if (
        p_mutex)
    {
        e_status =
            appl_mutex_service::s_unlock(
                p_mutex);
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} /* appl_mutex_unlock() */

/*

*/
enum appl_status
appl_mutex_sync(
    struct appl_mutex * const
        p_mutex,
    enum appl_status (*
        p_sync_callback)(
        void * const
            p_sync_context),
    void * const
        p_sync_context)
{
    enum appl_status
        e_status;

    if (
        p_mutex
        && p_sync_callback)
    {
        e_status =
            appl_mutex_service::s_sync(
                p_mutex,
                p_sync_callback,
                p_sync_context);
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} /* appl_mutex_sync() */

/* end-of-file: appl_mutex_handle.cpp */
