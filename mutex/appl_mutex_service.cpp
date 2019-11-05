/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <mutex/appl_mutex_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <context/appl_context.h>

#include <mutex/appl_mutex_mgr.h>

#include <mutex/appl_mutex_node.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
enum appl_status
    appl_mutex_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex * * const
            r_mutex)
{
    enum appl_status
        e_status;

    class appl_mutex_mgr *
        p_mutex_mgr;

    e_status =
        p_context->v_mutex_mgr(
            &(
                p_mutex_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_mutex_mgr->v_create_node(
                p_context->v_allocator(),
                p_mutex_descriptor,
                r_mutex);
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_mutex_service::s_destroy(
        struct appl_mutex * const
            p_mutex)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_mutex->get_context();

    class appl_mutex_mgr *
        p_mutex_mgr;

    e_status =
        p_context->v_mutex_mgr(
            &(
                p_mutex_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_mutex_mgr->v_destroy_node(
                p_context->v_allocator(),
                p_mutex);
    }

    return
        e_status;

} // s_destroy()

//
//
//
enum appl_status
    appl_mutex_service::s_lock(
        struct appl_mutex * const
            p_mutex)
{
    enum appl_status
        e_status;

    e_status =
        p_mutex->v_lock();

    return
        e_status;

} // s_lock()

//
//
//
enum appl_status
    appl_mutex_service::s_unlock(
        struct appl_mutex * const
            p_mutex)
{
    enum appl_status
        e_status;

    e_status =
        p_mutex->v_unlock();

    return
        e_status;

} // s_unlock()

//
//
//
enum appl_status
    appl_mutex_service::s_sync(
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

    e_status =
        p_mutex->v_sync(
            p_sync_callback,
            p_sync_context);

    return
        e_status;

} // s_sync()

/* end-of-file: appl_mutex_service.cpp */
