/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_BACKTRACE_HANDLE_H

/* Reverse include guard */
enum guard_appl_backtrace_handle_h
{
    inc_appl_backtrace_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_types_h
};

#include <appl_extern_c_begin.h>

enum appl_status
    appl_backtrace_capture(
        struct appl_context * const
            p_context,
        void const * * const
            p_buffer,
        appl_size_t const
            i_count_max,
        appl_size_t * const
            r_count);

enum appl_status
    appl_backtrace_report(
        struct appl_context * const
            p_context,
        void const * const * const
            p_buffer,
        appl_size_t const
            i_count);

enum appl_status
    appl_backtrace_ouch(
        struct appl_context * const
            p_context,
        char const * const
            p_header0);

#include <appl_extern_c_end.h>

/* end-of-file: appl_backtrace_handle.h */
