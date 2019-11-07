/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <trace/appl_trace_handle.h>

#include <trace/appl_trace_service.h>

#include <trace/appl_trace_message.h>

//
//
//
enum appl_status
    appl_trace_init(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        char const * const
            p_name0,
        int const
            e_level)
{
    return
        appl_trace_service::s_init(
            p_context,
            p_trace,
            p_name0,
            e_level);

} // appl_trace_init()

//
//
//
enum appl_status
    appl_trace_enter(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace)
{
    enum appl_status
        e_status;

    struct appl_trace_message
        o_message;

    e_status =
        appl_trace_message_init(
            p_context,
            &(
                o_message),
            p_trace,
            appl_trace_message_type_enter);

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_trace_service::s_message(
                p_context,
                &(
                    o_message));
    }

    return
        e_status;

} // appl_trace_enter()

//
//
//
enum appl_status
    appl_trace_leave(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace)
{
    enum appl_status
        e_status;

    struct appl_trace_message
        o_message;

    e_status =
        appl_trace_message_init(
            p_context,
            &(
                o_message),
            p_trace,
            appl_trace_message_type_leave);

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_trace_service::s_message(
                p_context,
                &(
                    o_message));
    }

    return
        e_status;

} // appl_trace_leave()

//
//
//
enum appl_status
    appl_trace_signal(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace)
{
    enum appl_status
        e_status;

    struct appl_trace_message
        o_message;

    e_status =
        appl_trace_message_init(
            p_context,
            &(
                o_message),
            p_trace,
            appl_trace_message_type_signal);

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_trace_service::s_message(
                p_context,
                &(
                    o_message));
    }

    return
        e_status;

} // appl_trace_signal()

//
//
//
enum appl_status
    appl_trace_capture(
        struct appl_context * const
            p_context,
        char * * const
            p_capture_array,
        unsigned long int const
            i_capture_max,
        unsigned long int * const
            r_capture_count)
{
    return
        appl_trace_service::s_capture(
            p_context,
            p_capture_array,
            i_capture_max,
            r_capture_count);

} // appl_trace_capture()

//
//
//
enum appl_status
    appl_trace_stack_report(
        struct appl_context * const
            p_context)
{
    return
        appl_trace_service::s_stack_report(
            p_context);

} // appl_trace_stack_report()

//
//
//
enum appl_status
    appl_trace_profile_report(
        struct appl_context * const
            p_context)
{
    return
        appl_trace_service::s_profile_report(
            p_context);

} // appl_trace_profile_report()

/* end-of-file: appl_trace_handle.cpp */
