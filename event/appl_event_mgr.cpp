/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <event/appl_event_mgr.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_event_mgr::v_create_node(
        struct appl_event_descriptor const * const
            p_event_descriptor,
        struct appl_event * * const
            r_event)
{
    enum appl_status
        e_status;

    appl_unused(
        p_event_descriptor,
        r_event);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "event mgr create node not implemented\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_node()

//
//
//
enum appl_status
    appl_event_mgr::v_destroy_node(
        struct appl_event * const
            p_event)
{
    enum appl_status
        e_status;

    appl_unused(
        p_event);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "event mgr destroy node not implemented\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_destroy_node()

//
//
//
appl_event_mgr::appl_event_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_event_mgr::~appl_event_mgr()
{
}

/* end-of-file: appl_event_mgr.cpp */
