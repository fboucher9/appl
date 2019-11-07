/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_trace_message_h
{
    inc_appl_trace_message_h = 1
        /* Header file dependencies */
        | inc_appl_status_h
        | inc_appl_types_h
        /* ... */
}; /* enum guard_appl_trace_message_h */

/* Predefine */
struct appl_trace;

/*

*/
enum appl_trace_message_type
{
    appl_trace_message_type_enter = 1,

    appl_trace_message_type_leave = 2,

    appl_trace_message_type_signal = 3

}; /* enum appl_trace_message_type */

/*

*/
struct appl_trace_message
{
    /* time of message */
    appl_ull_t
        i_clock;

    /* -- */

    /* expansion of variable arguments */
    appl_ull_t
        a_arguments[4u];

    /* -- */

    /* pointer to trace structure, with name and stats */
    struct appl_trace *
        p_trace;

    /* type of message */
    unsigned char
        e_type;

    unsigned char
        i_argument_count;

#define PADDING (APPL_SIZEOF_PTR + 2)
#include <misc/appl_padding.h>

}; /* struct appl_trace_message */

#include <misc/appl_extern_c_begin.h>

enum appl_status
appl_trace_message_init(
    struct appl_context * const
        p_context,
    struct appl_trace_message * const
        p_trace_message,
    struct appl_trace * const
        p_trace,
    enum appl_trace_message_type const
        e_type);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_trace_message.h */
