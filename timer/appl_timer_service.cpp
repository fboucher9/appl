/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_timer_handle.h>

#include <timer/appl_timer_service.h>

#include <object/appl_object.h>

#include <timer/appl_timer_mgr.h>

#include <timer/appl_timer.h>

#include <appl_context.h>

//
//
//
enum appl_status
appl_timer_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_timer * * const
        r_timer)
{
    return
        p_context->m_timer_mgr->v_create(
            r_timer);

} // s_create()

//
//
//
struct appl_object *
appl_timer_service::s_parent(
    struct appl_timer * const
        p_timer)
{
    return
        p_timer;

} // s_parent()

//
//
//
enum appl_status
appl_timer_service::s_schedule(
    struct appl_timer * const
        p_timer,
    struct appl_timer_descriptor const * const
        p_timer_descriptor)
{
    return
        p_timer->v_schedule(
            p_timer_descriptor);

} // s_schedule()

/* end-of-file: appl_timer_service.cpp */
