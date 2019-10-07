/* See LICENSE for license details */

/*

Module: appl_trace_handle.h

Description:

    Tracing and profiling services.  Keeps logs of functions called with
    information about parameters and results.  Generate a profiling report on
    application exit.

*/

/* Reverse include guard */
enum guard_appl_trace_handle_h
{
    inc_appl_trace_handle_h = 1
        /* Header file dependencies */
        /* ... */

}; /* enum guard_appl_trace_handle_h */

/*

Structure: appl_trace_node

Description:

    Storage of trace information for a single function.

*/
struct appl_trace_node
{
    struct appl_trace_node *
        p_next;

    char const *
        p_name0;

    /* -- */

    unsigned long int
        i_level;

    unsigned long int
        i_count;

    /* -- */

    appl_ull_t
        i_time;

}; /* struct appl_trace_node */

#include <misc/appl_extern_c_begin.h>

void
    appl_trace_enter(
        struct appl_context * const
            p_context,
        struct appl_trace_node * const
            p_node,
        unsigned char const * const
            p_args_min,
        unsigned char const * const
            p_args_max);

void
    appl_trace_leave(
        struct appl_context * const
            p_context,
        struct appl_trace_node * const
            p_node,
        unsigned char const * const
            p_args_min,
        unsigned char const * const
            p_args_max);

void
    appl_trace_message(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_level,
        unsigned char const * const
            p_message_min,
        unsigned char const * const
            p_message_max);

void
    appl_trace_report(
        struct appl_context * const
            p_context);

#include <misc/appl_extern_c_end.h>

#if 0

#if APPL_TRACE_LEVELS > 1
static struct appl_trace_node g_demo_trace_node =
{
    (struct appl_trace_node *)(0),
    "demo",
    1,
    0,
    0
};
#endif

void
demo(
    struct appl_context * const
        p_context)
{
#if APPL_TRACE_LEVELS > 1
    appl_trace_enter(
        p_context,
        &g_demo_trace_node);
#endif

#if APPL_TRACE_LEVELS > 1
    appl_trace_leave(
        p_context,
        &g_demo_trace_node);
#endif
}

#endif

/* end-of-file: appl_trace_handle.h */
