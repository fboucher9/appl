/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <event/appl_event_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <context/appl_context.h>

#include <event/appl_event_node.h>

#include <event/appl_event_mgr.h>

#include <mutex/appl_mutex_node.h>

//
//
//
enum appl_status
appl_event_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_event_descriptor const * const
        p_event_descriptor,
    struct appl_event * * const
        r_event)
{
    enum appl_status
        e_status;

    class appl_event_mgr * const
        p_event_mgr =
        p_context->m_event_mgr;

    e_status =
        p_event_mgr->v_create(
            p_event_descriptor,
            r_event);

    return
        e_status;

} // s_create()

//
//
//
struct appl_object *
appl_event_service::s_parent(
    struct appl_event * const
        p_event)
{
    return
        p_event;

} // s_parent()

//
//
//
struct appl_object const *
appl_event_service::s_const_parent(
    struct appl_event const * const
        p_event)
{
    return
        p_event;

} // s_const_parent()

//
//
//
enum appl_status
appl_event_service::s_signal(
    struct appl_event * const
        p_event)
{
    enum appl_status
        e_status;

    e_status =
        p_event->v_signal();

    return
        e_status;

} // s_signal()

//
//
//
enum appl_status
appl_event_service::s_wait(
    struct appl_event * const
        p_event,
    struct appl_mutex * const
        p_mutex,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count)
{
    enum appl_status
        e_status;

    e_status =
        p_event->v_wait(
            p_mutex,
            i_wait_freq,
            i_wait_count);

    return
        e_status;

} // s_wait()

/* end-of-file: appl_event_service.cpp */
