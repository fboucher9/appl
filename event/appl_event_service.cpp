/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <event/appl_event_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <event/appl_event_node.h>

#include <event/appl_event_mgr.h>

#include <mutex/appl_mutex_node.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

//
//
//
enum appl_status
appl_event_service::s_validate(
    bool const
        b_condition)
{
    enum appl_status
        e_status;

    if (
        b_condition
#if defined APPL_HAVE_COVERAGE
        && !appl_coverage_check()
#endif /* #if defined APPL_HAVE_COVERAGE */
        )
    {
        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "event invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_invalid_param;
    }

    return
        e_status;

} // s_validate()

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

    e_status =
        appl_event_service::s_validate(
            (0 != p_context)
            && (0 != p_event_descriptor)
            && (0 != r_event));

    if (
        appl_status_ok
        == e_status)
    {
        class appl_event_mgr *
            p_event_mgr;

        e_status =
            p_context->v_event_mgr(
                &(
                    p_event_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_event_mgr->v_create_node(
                    p_event_descriptor,
                    r_event);
        }
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_event_service::s_destroy(
    struct appl_event * const
        p_event)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_service::s_validate(
            (0 != p_event));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_context * const
            p_context =
            p_event->get_context();

        class appl_event_mgr *
            p_event_mgr;

        e_status =
            p_context->v_event_mgr(
                &(
                    p_event_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_event_mgr->v_destroy_node(
                    p_event);
        }
    }

    return
        e_status;

} // s_destroy()

//
//
//
struct appl_object *
appl_event_service::s_parent(
    struct appl_event * const
        p_event)
{
    appl_event_service::s_validate(
        (0 != p_event));

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
    appl_event_service::s_validate(
        (0 != p_event));

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
        appl_event_service::s_validate(
            (0 != p_event));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_event->v_signal();
    }

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
        appl_event_service::s_validate(
            (0 != p_event));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_event->v_wait(
                p_mutex,
                i_wait_freq,
                i_wait_count);
    }

    return
        e_status;

} // s_wait()

/* end-of-file: appl_event_service.cpp */
