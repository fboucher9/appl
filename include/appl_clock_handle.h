/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_CLOCK_HANDLE_H

/* Reverse include guard */
enum guard_appl_clock_handle_h
{
    inc_appl_clock_handle_h = 1
        /* Header file dependency */
        + inc_appl_status_h
};

/* Predefine */
struct appl_context;

#include <appl_extern_c_begin.h>

enum appl_status
appl_clock_read(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_time_freq,
    appl_ull_t * const
        p_time_count);

enum appl_status
appl_clock_delay(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_time_freq,
    appl_ull_t const
        i_time_count);

#include <appl_extern_c_end.h>

/* end-of-file: appl_clock_handle.h */
