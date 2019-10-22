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
        | inc_appl_status_h
        | inc_appl_types_h
};

/* Predefine */
struct appl_clock_details;

/*

*/
struct appl_clock_details
{
    /* Fractions of a second according to freq */
    unsigned long int
        i_fraction;

    /* Year (calculated once at calibration) */
    unsigned long int
        i_year;

    /* -- */

    /* Month (calculated once at calibration) */
    unsigned char
        i_month;

    /* Number of days since reference */
    unsigned char
        i_day;

    /* Number of hours in last day */
    unsigned char
        i_hour;

    /* Number of minutes in last hour */
    unsigned char
        i_minute;

    /* Number of seconds in last minute */
    unsigned char
        i_second;

#define PADDING (5)
#include <misc/appl_padding.h>

}; /* struct appl_clock_details */

#include <misc/appl_extern_c_begin.h>

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

enum appl_status
appl_clock_convert(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_time_freq,
    appl_ull_t const
        i_time_count,
    struct appl_clock_details * const
        r_clock_details);

unsigned char *
appl_clock_print(
    struct appl_context const * const
        p_context,
    struct appl_clock_details const * const
        p_clock_details,
    unsigned char * const
        p_buffer_min,
    unsigned char * const
        p_buffer_max);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_clock_handle.h */
