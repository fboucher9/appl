/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <trace/appl_trace_handle.h>

#include <trace/appl_trace_service.h>

#include <buf/appl_buf.h>

#include <trace/appl_trace_message.h>

#include <stdarg.h>

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
            p_trace,
        char const * const
            p_format0,
        ...)
{
    enum appl_status
        e_status;

    va_list
        o_arguments;

    va_start(
        o_arguments,
        p_format0);

    e_status =
        appl_trace_service::s_message(
            p_context,
            p_trace,
            appl_trace_message_type_enter,
            p_format0,
            &(
                o_arguments));

    va_end(
        o_arguments);

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
            p_trace,
        char const * const
            p_format0,
        ...)
{
    enum appl_status
        e_status;

    va_list
        o_arguments;

    va_start(
        o_arguments,
        p_format0);

    e_status =
        appl_trace_service::s_message(
            p_context,
            p_trace,
            appl_trace_message_type_leave,
            p_format0,
            &(
                o_arguments));

    va_end(
        o_arguments);

    return
        e_status;

} // appl_trace_leave()

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
