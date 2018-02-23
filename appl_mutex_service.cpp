/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_mutex_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_mutex_mgr.h"

#include "appl_mutex_node.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_mutex_service::s_create(
        struct appl_context_handle * const
            p_context_handle,
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex_handle * * const
            r_mutex_handle)
{
    enum appl_status
        e_status;

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_mutex_mgr * const
        p_mutex_mgr =
        p_context->m_mutex_mgr;

    e_status =
        p_mutex_mgr->v_create(
            p_mutex_descriptor,
            reinterpret_cast<class appl_mutex_node * *>(
                r_mutex_handle));

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_mutex_service::s_lock(
        struct appl_mutex_handle * const
            p_mutex_handle)
{
    enum appl_status
        e_status;

    class appl_mutex_node * const
        p_mutex_node =
        appl_mutex_node::convert_handle(
            p_mutex_handle);

    e_status =
        p_mutex_node->v_lock();

    return
        e_status;

} // s_lock()

//
//
//
enum appl_status
    appl_mutex_service::s_unlock(
        struct appl_mutex_handle * const
            p_mutex_handle)
{
    enum appl_status
        e_status;

    class appl_mutex_node * const
        p_mutex_node =
        appl_mutex_node::convert_handle(
            p_mutex_handle);

    e_status =
        p_mutex_node->v_unlock();

    return
        e_status;

} // s_unlock()

/* end-of-file: appl_mutex_service.cpp */
