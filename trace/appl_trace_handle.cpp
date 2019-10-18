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
        unsigned char const * const
            p_args_min,
        unsigned char const * const
            p_args_max)
{
    struct appl_trace_message
        o_trace_message;

    o_trace_message.i_clock =
        0u;

    o_trace_message.p_trace =
        p_trace;

    o_trace_message.o_args.o_min.pc_uchar =
        p_args_min;

    o_trace_message.o_args.o_max.pc_uchar =
        p_args_max;

    o_trace_message.b_enter =
        1;

    return
        appl_trace_service::s_message(
            p_context,
            &(
                o_trace_message));

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
        unsigned char const * const
            p_args_min,
        unsigned char const * const
            p_args_max)
{
    struct appl_trace_message
        o_trace_message;

    o_trace_message.i_clock =
        0u;

    o_trace_message.p_trace =
        p_trace;

    o_trace_message.o_args.o_min.pc_uchar =
        p_args_min;

    o_trace_message.o_args.o_max.pc_uchar =
        p_args_max;

    o_trace_message.b_enter =
        0;

    return
        appl_trace_service::s_message(
            p_context,
            &(
                o_trace_message));

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
    appl_trace_stack_report_length(
        struct appl_context * const
            p_context,
        unsigned long int * const
            r_length)
{
    return
        appl_trace_service::s_stack_report_length(
            p_context,
            r_length);

} // appl_trace_stack_report_length()

//
//
//
enum appl_status
    appl_trace_stack_report(
        struct appl_context * const
            p_context,
        struct appl_buf * const
            p_report_iterator)
{
    return
        appl_trace_service::s_stack_report(
            p_context,
            p_report_iterator);

} // appl_trace_stack_report()

//
//
//
enum appl_status
    appl_trace_profile_report_length(
        struct appl_context * const
            p_context,
        unsigned long int * const
            r_report_length)
{
    return
        appl_trace_service::s_profile_report_length(
            p_context,
            r_report_length);

} // appl_trace_profile_report_length()

//
//
//
enum appl_status
    appl_trace_profile_report(
        struct appl_context * const
            p_context,
        struct appl_buf * const
            p_report_iterator)
{
    return
        appl_trace_service::s_profile_report(
            p_context,
            p_report_iterator);

} // appl_trace_profile_report()

/* end-of-file: appl_trace_handle.cpp */
