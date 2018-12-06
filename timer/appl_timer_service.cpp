/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_timer_handle.h>

#include <timer/appl_timer_service.h>

#include <appl_object.h>

#include <timer/appl_timer_mgr.h>

#include <timer/appl_timer.h>

#include <context/appl_context.h>

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
    enum appl_status
        e_status;

    class appl_timer_mgr *
        p_timer_mgr;

    e_status =
        p_context->v_timer_mgr(
            &(
                p_timer_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_timer_mgr->v_create_node(
                r_timer);
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_timer_service::s_destroy(
    struct appl_timer * const
        p_timer)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_timer->get_context();

    class appl_timer_mgr *
        p_timer_mgr;

    e_status =
        p_context->v_timer_mgr(
            &(
                p_timer_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_timer_mgr->v_destroy_node(
                p_timer);
    }

    return
        e_status;

} // s_destroy()

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
