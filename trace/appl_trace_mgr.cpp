/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <trace/appl_trace_mgr.h>

#include <misc/appl_unused.h>

//
//
//
appl_trace_mgr::appl_trace_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_trace_mgr::~appl_trace_mgr()
{
}

//
//
//
enum appl_status
    appl_trace_mgr::v_init(
        struct appl_trace * const
            p_trace,
        char const * const
            p_name0,
        int const
            e_level)
{
    appl_unused(
        p_trace,
        p_name0,
        e_level);

    return
        appl_raise_not_implemented();

} // v_init()

//
//
//
enum appl_status
    appl_trace_mgr::v_register(
        struct appl_trace_descriptor const * const
            p_descriptor,
        struct appl_trace_client * * const
            r_instance)
{
    appl_unused(
        p_descriptor,
        r_instance);

    return
        appl_raise_not_implemented();

} // v_register()

//
//
//
enum appl_status
    appl_trace_mgr::v_unregister(
        struct appl_trace_client * const
            p_instance)
{
    appl_unused(
        p_instance);

    return
        appl_raise_not_implemented();

} // v_unregister()

//
//
//
enum appl_status
    appl_trace_mgr::v_get_levels(
        int * const
            r_levels) const
{
    appl_unused(
        r_levels);

    return
        appl_raise_not_implemented();

} // v_get_levels()

//
//
//
enum appl_status
    appl_trace_mgr::v_set_levels(
        int const
            i_levels)
{
    appl_unused(
        i_levels);

    return
        appl_raise_not_implemented();

} // v_set_levels()

//
//
//
char
    appl_trace_mgr::v_test(
        struct appl_trace * const
            p_trace) const
{
    appl_unused(
        p_trace);

    return
        0;

} // v_test()

//
//
//
enum appl_status
    appl_trace_mgr::v_message(
        struct appl_trace_message const * const
            p_trace_message)
{
    appl_unused(
        p_trace_message);

    return
        appl_raise_not_implemented();

} // v_message()

//
//
//
enum appl_status
    appl_trace_mgr::v_capture(
        char * * const
            p_capture_array,
        unsigned long int const
            i_capture_max,
        unsigned long int * const
            r_capture_count)
{
    appl_unused(
        p_capture_array,
        i_capture_max,
        r_capture_count);

    return
        appl_raise_not_implemented();

} // v_capture()

//
//
//
enum appl_status
    appl_trace_mgr::v_stack_report_length(
        unsigned long int * const
            r_length)
{
    appl_unused(
        r_length);

    return
        appl_raise_not_implemented();

} // v_stack_report_length()

//
//
//
enum appl_status
    appl_trace_mgr::v_stack_report(
        struct appl_buf * const
            p_iterator)
{
    appl_unused(
        p_iterator);

    return
        appl_raise_not_implemented();

} // v_stack_report()

//
//
//
enum appl_status
    appl_trace_mgr::v_profile_report_length(
        unsigned long int * const
            r_length)
{
    appl_unused(
        r_length);

    return
        appl_raise_not_implemented();

} // v_profile_report_length()

//
//
//
enum appl_status
    appl_trace_mgr::v_profile_report(
        struct appl_buf * const
            p_iterator)
{
    appl_unused(
        p_iterator);

    return
        appl_raise_not_implemented();

} // v_profile_report()

/* end-of-file: appl_trace_mgr.cpp */
