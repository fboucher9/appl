/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_windows_h
{
    inc_appl_windows_h = 1
        /* Header file dependencies */
        | inc_appl_types_h
        /* ... */
}; /* enum guard_appl_windows_h */

#include <misc/appl_extern_c_begin.h>

char
appl_windows_time_begin_period(
    unsigned long int const
        i_period_msec);

char
appl_windows_time_end_period(
    unsigned long int const
        i_period_msec);

char
appl_windows_query_performance_frequency(
    appl_ull_t * const
        r_value);

char
appl_windows_query_performance_counter(
    appl_ull_t * const
        r_value);

char
appl_windows_sleep_ex(
    unsigned long int const
        i_count_msec,
    char const
        b_alertable);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_windows.h */

