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
        i_first_time;

    /* -- */

    appl_ull_t
        i_last_time;

    /* -- */

    appl_ull_t
        i_elapsed;

    /* -- */

    appl_ull_t
        i_count;

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

enum appl_status
    appl_trace_enter(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace);

enum appl_status
    appl_trace_enter_1(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        appl_ull_t const
            i_argument_1);

enum appl_status
    appl_trace_enter_n(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        appl_ull_t const * const
            p_arguments,
        unsigned char const
            i_argument_count);

enum appl_status
    appl_trace_leave(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace);

enum appl_status
    appl_trace_leave_1(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        appl_ull_t const
            i_argument_1);

enum appl_status
    appl_trace_leave_n(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        appl_ull_t const * const
            p_arguments,
        unsigned char const
            i_argument_count);

enum appl_status
    appl_trace_signal(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace);

enum appl_status
    appl_trace_signal_1(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        appl_ull_t const
            i_argument_1);

enum appl_status
    appl_trace_signal_n(
        struct appl_context * const
            p_context,
        struct appl_trace * const
            p_trace,
        appl_ull_t const * const
            p_arguments,
        unsigned char const
            i_argument_count);

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
    appl_trace_stack_report(
        struct appl_context * const
            p_context);

enum appl_status
    appl_trace_profile_report(
        struct appl_context * const
            p_context);

#include <misc/appl_extern_c_end.h>

#if 0

static struct appl_trace g_trace_demo;

void
demo(
    struct appl_context * const
        p_context)
{
    appl_trace_init(
        p_context,
        &g_trace_demo,
        "demo",
        1);

    appl_trace_enter(
        p_context,
        &g_trace_demo);

    appl_trace_leave(
        p_context,
        &g_trace_demo);
}

#endif

/* end-of-file: appl_trace_handle.h */
