/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <trace/appl_trace_mgr.h>

#include <trace/appl_trace_std_mgr.h>

#include <misc/appl_unused.h>

#include <list/appl_list.h>

#include <trace/appl_trace_handle.h>

//
//
//
appl_trace_std_mgr::appl_trace_std_mgr(
    struct appl_context * const
        p_context) :
    appl_trace_mgr(
        p_context)
{
}

//
//
//
appl_trace_std_mgr::~appl_trace_std_mgr()
{
}

//
//
//
enum appl_status
    appl_trace_std_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_trace_std_mgr::v_cleanup(void)
{
    return
        sizeof(
            class appl_trace_std_mgr);

} // v_cleanup()

//
//
//
enum appl_status
    appl_trace_std_mgr::v_init(
        struct appl_trace * const
            p_trace,
        char const * const
            p_name0,
        int const
            e_level)
{
    enum appl_status
        e_status;

    appl_list_init(
        &(
            p_trace->o_list));

    p_trace->i_first_time =
        0u;

    p_trace->i_last_time =
        0u;

    p_trace->i_elapsed =
        0u;

    p_trace->i_count =
        0u;

    p_trace->p_name0 =
        p_name0;

    p_trace->e_level =
        e_level;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_init()

//
//
//
enum appl_status
    appl_trace_std_mgr::v_message(
        struct appl_trace_message const * const
            p_trace_message)
{
    appl_unused(
        p_trace_message);

    return
        appl_raise_not_implemented();

} // v_message()

/* end-of-file: appl_trace_std_mgr.cpp */
