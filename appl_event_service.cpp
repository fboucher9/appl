/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_event_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_event_node.h"

#include "appl_event_mgr.h"

#include "appl_mutex_node.h"

//
//
//
enum appl_status
appl_event_service::s_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_event_descriptor const * const
        p_event_descriptor,
    struct appl_event_handle * * const
        r_event_handle)
{
    enum appl_status
        e_status;

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_event_mgr * const
        p_event_mgr =
        p_context->m_event_mgr;

    e_status =
        p_event_mgr->v_create(
            p_context,
            p_event_descriptor,
            reinterpret_cast<class appl_event_node * *>(
                r_event_handle));

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_event_service::s_signal(
    struct appl_event_handle * const
        p_event_handle)
{
    enum appl_status
        e_status;

    class appl_event_node * const
        p_event_node =
        appl_event_node::convert_handle(
            p_event_handle);

    e_status =
        p_event_node->v_signal();

    return
        e_status;

} // s_signal()

//
//
//
enum appl_status
appl_event_service::s_wait(
    struct appl_event_handle * const
        p_event_handle,
    struct appl_mutex_handle * const
        p_mutex_handle,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count)
{
    enum appl_status
        e_status;

    class appl_event_node * const
        p_event_node =
        appl_event_node::convert_handle(
            p_event_handle);

    class appl_mutex_node * const
        p_mutex_node =
        appl_mutex_node::convert_handle(
            p_mutex_handle);

    e_status =
        p_event_node->v_wait(
            p_mutex_node,
            i_wait_freq,
            i_wait_count);

    return
        e_status;

} // s_wait()

/* end-of-file: appl_event_service.cpp */
