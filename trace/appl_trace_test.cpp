/* See LICENSE for license details */

/*

*/

#include <appl_predefines.h>

#include <trace/appl_trace_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <list/appl_list.h>

#include <trace/appl_trace_handle.h>

//
//
//
void
    appl_trace_test_1(
        struct appl_context * const
            p_context)
{
    static struct appl_trace
        g_trace_function;

    enum appl_status
        e_status;

    e_status =
        appl_trace_init(
            p_context,
            &(
                g_trace_function),
            "function",
            0);

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_trace_enter(
                p_context,
                &(
                    g_trace_function));

        e_status =
            appl_trace_leave(
                p_context,
                &(
                    g_trace_function));
    }

} // appl_trace_test_1()

/* end-of-file: appl_trace_test.cpp */
