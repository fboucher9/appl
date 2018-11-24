/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <mutex/appl_mutex_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <mutex/appl_mutex_mgr.h>

#include <mutex/appl_mutex_node.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

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

    e_status =
        p_context->m_mutex_mgr->v_create(
            p_mutex_descriptor,
            r_mutex);

    return
        e_status;

} // s_create()

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

/* end-of-file: appl_mutex_service.cpp */
