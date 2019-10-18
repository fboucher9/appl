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
        | inc_appl_predefines_h
        | inc_appl_types_h
        | inc_appl_status_h
        /* ... */

}; /* enum guard_appl_trace_handle_h */

/* Setup default trace level */
#if ! defined APPL_TRACE_LEVELS
#define APPL_TRACE_LEVELS 8
#endif /* #if ! defined APPL_TRACE_LEVELS */

/* Predefine */
struct appl_trace;

/* Predefine */
struct appl_trace_message;

/*

Structure: appl_trace

Description:

    Storage of trace information for a single function.

*/
struct appl_trace
{
    appl_ull_t
        i_count;

    /* -- */

    appl_ull_t
        i_time;

    /* -- */

    char const *
        p_name0;

    struct appl_trace *
        p_next;

    /* -- */

    int
        e_level;

#define PADDING (APPL_SIZEOF_INT)
#include <misc/appl_padding.h>

}; /* struct appl_trace */

typedef
enum appl_status
(appl_trace_callback)(
    void * const
        p_void,
    struct appl_trace_message const * const
        p_trace_message);

/*

*/
struct appl_trace_descriptor
{
    appl_trace_callback *
        p_callback;

    void *
        p_void;

}; /* struct appl_trace_descriptor */

#include <misc/appl_extern_c_begin.h>

enum appl_status
    appl_trace_init(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        char const * const
            p_name0,
        int const
            e_level);

enum appl_status
    appl_trace_register(
        struct appl_context * const
            p_context,
        struct appl_trace_descriptor const * const
            p_descriptor,
        struct appl_trace_client * * const
            r_instance);

enum appl_status
    appl_trace_unregister(
        struct appl_context * const
            p_context,
        struct appl_trace_client * const
            p_instance);

enum appl_status
    appl_trace_get_levels(
        struct appl_context * const
            p_context,
        int * const
            r_levels);

enum appl_status
    appl_trace_set_levels(
        struct appl_context * const
            p_context,
        int const
            i_levels);

char
    appl_trace_test(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace);

enum appl_status
    appl_trace_enter(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        unsigned char const * const
            p_args_min,
        unsigned char const * const
            p_args_max);

enum appl_status
    appl_trace_leave(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        unsigned char const * const
            p_args_min,
        unsigned char const * const
            p_args_max);

enum appl_status
    appl_trace_capture(
        struct appl_context * const
            p_context,
        char * * const
            p_capture_array,
        unsigned long int const
            i_capture_max,
        unsigned long int * const
            r_capture_count);

enum appl_status
    appl_trace_stack_report_length(
        struct appl_context * const
            p_context,
        unsigned long int * const
            r_report_length);

enum appl_status
    appl_trace_stack_report(
        struct appl_context * const
            p_context,
        struct appl_buf * const
            p_report_iterator);

enum appl_status
    appl_trace_profile_report_length(
        struct appl_context * const
            p_context,
        unsigned long int * const
            r_report_length);

enum appl_status
    appl_trace_profile_report(
        struct appl_context * const
            p_context,
        struct appl_buf * const
            p_report_iterator);

#include <misc/appl_extern_c_end.h>

#if 0

#if APPL_TRACE_LEVELS > 1
static struct appl_trace_node g_demo_trace_node =
{
    (struct appl_trace_node *)(0),
    "demo",
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
    if (appl_trace_test(p_context, &g_demo_trace_node))
    {
        appl_trace_enter(
            p_context,
            &g_demo_trace_node,
            a_message,
            appl_buf_print_number(
                appl_buf_print0(
                    a_message,
                    a_message + sizeof(a_message),
                    "argc="),
                i_argc));
    }
#endif

#if APPL_TRACE_LEVELS > 1
    if (appl_trace_test(p_context, &g_demo_trace_node))
    {
        appl_buf_print0(
            &o_iterator,
            "");

        appl_trace_leave(
            p_context,
            &g_demo_trace_node,
            &o_iterator);
    }
#endif
}

#endif

/* end-of-file: appl_trace_handle.h */
