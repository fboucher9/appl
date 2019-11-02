/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_trace_message_h
{
    inc_appl_trace_message_h = 1
        /* Header file dependencies */
        | inc_appl_buf_h
        /* ... */
}; /* enum guard_appl_trace_message_h */

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
    /* expansion of variable arguments */
    struct appl_buf
        o_args;

    /* -- */

    /* pointer to trace structure, with name and stats */
    struct appl_trace *
        p_trace;

    /* type of message */
    enum appl_trace_message_type
        e_type;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_INT)
#include <misc/appl_padding.h>

}; /* struct appl_trace_message */

/* end-of-file: appl_trace_message.h */
