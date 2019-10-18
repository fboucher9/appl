/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <trace/appl_trace_service.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
    appl_trace_service::s_init(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        char const * const
            p_name0,
        int const
            e_level)
{
    appl_unused(
        p_context,
        p_trace,
        p_name0,
        e_level);

    return
        appl_raise_not_implemented();

} // s_init()

//
//
//
enum appl_status
    appl_trace_service::s_register(
        struct appl_context * const
            p_context,
        struct appl_trace_descriptor const * const
            p_descriptor,
        struct appl_trace_client * * const
            r_instance)
{
    appl_unused(
        p_context,
        p_descriptor,
        r_instance);

    return
        appl_raise_not_implemented();

} // s_register()

//
//
//
enum appl_status
    appl_trace_service::s_unregister(
        struct appl_trace_client * const
            p_instance)
{
    appl_unused(
        p_instance);

    return
        appl_raise_not_implemented();

} // s_unregister()

//
//
//
enum appl_status
    appl_trace_service::s_message(
        struct appl_context * const
            p_context,
        struct appl_trace_message const * const
            p_trace_message)
{
    appl_unused(
        p_context,
        p_trace_message);

    return
        appl_raise_not_implemented();

} // s_message()

//
//
//
enum appl_status
    appl_trace_service::s_capture(
        struct appl_context * const
            p_context,
        char * * const
            p_capture_array,
        unsigned long int const
            i_capture_max,
        unsigned long int * const
            r_capture_count)
{
    appl_unused(
        p_context,
        p_capture_array,
        i_capture_max,
        r_capture_count);

    return
        appl_raise_not_implemented();

} // s_capture()

//
//
//
enum appl_status
appl_trace_service::s_stack_report_length(
        struct appl_context * const
            p_context,
        unsigned long int * const
            r_length)
{
    appl_unused(
        p_context,
        r_length);

    return
        appl_raise_not_implemented();

} // s_stack_report_length()

//
//
//
enum appl_status
    appl_trace_service::s_stack_report(
        struct appl_context * const
            p_context,
        struct appl_buf * const
            p_report_iterator)
{
    appl_unused(
        p_context,
        p_report_iterator);

    return
        appl_raise_not_implemented();

} // s_stack_report()

//
//
//
enum appl_status
    appl_trace_service::s_profile_report_length(
        struct appl_context * const
            p_context,
        unsigned long int * const
            r_length)
{
    appl_unused(
        p_context,
        r_length);

    return
        appl_raise_not_implemented();

} // s_profile_report_length()

//
//
//
enum appl_status
    appl_trace_service::s_profile_report(
        struct appl_context * const
            p_context,
        struct appl_buf * const
            p_report_iterator)
{
    appl_unused(
        p_context,
        p_report_iterator);

    return
        appl_raise_not_implemented();

} // s_profile_report()

/* end-of-file: appl_trace_service.cpp */
