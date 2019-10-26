/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_clock_details_h
{
    inc_appl_clock_details_h = 1
        /* Header file dependencies */
        | inc_appl_types_h
        /* ... */
}; /* enum guard_appl_clock_details_h */

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

