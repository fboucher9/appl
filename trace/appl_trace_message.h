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
struct appl_trace_message
{
    appl_ull_t
        i_clock;

    /* -- */

    struct appl_buf
        o_args;

    /* -- */

    struct appl_trace *
        p_trace;

    char
        b_enter;

#define PADDING (APPL_SIZEOF_PTR + 1)
#include <misc/appl_padding.h>

    /* -- */

}; /* struct appl_trace_message */

/* end-of-file: appl_trace_message.h */
