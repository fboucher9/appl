/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <trace/appl_trace_message.h>

#include <clock/appl_clock_handle.h>

//
//
//
enum appl_status
appl_trace_message_init(
    struct appl_context * const
        p_context,
    struct appl_trace_message * const
        p_trace_message,
    struct appl_trace * const
        p_trace,
    enum appl_trace_message_type const
        e_type)
{
    enum appl_status
        e_status;

    p_trace_message->p_trace =
        p_trace;

    p_trace_message->e_type =
        e_type;

    p_trace_message->i_argument_count =
        0u;

    e_status =
        appl_clock_read(
            p_context,
            1000000ul,
            &(
                p_trace_message->i_clock));

    return
        e_status;

} // appl_trace_message_init()

/* end-of-file: appl_trace_message.cpp */
