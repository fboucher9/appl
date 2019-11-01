/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_linux_h
{
    inc_appl_linux_h = 1
        /* Header file dependencies */
        | inc_appl_types_h
        /* ... */
}; /* enum guard_appl_linux_h */

/*

*/
enum appl_linux_clock_id
{
    appl_linux_clock_id_mono = 1,

    appl_linux_clock_id_real = 2

}; /* enum appl_linux_clock_id */

/*

*/
struct appl_linux_time_usec
{
    signed long int
        i_sec;

    signed long int
        i_usec;

}; /* struct appl_linux_timeval */

/*

*/
struct appl_linux_time_nsec
{
    signed long int
        i_sec;

    signed long int
        i_nsec;

};

/*

*/
struct appl_linux_time_info
{
    int
        i_year;

    int
        i_mon;

    int
        i_mday;

    int
        i_hour;

    int
        i_min;

    int
        i_sec;

};

#include <misc/appl_extern_c_begin.h>

int
appl_linux_clock_gettime(
    enum appl_linux_clock_id const
        i_clock_id,
    struct appl_linux_time_nsec * const
        r_time_nsec);

int
appl_linux_usleep(
    unsigned long int const
        i_count_usec);

int
appl_linux_localtime(
    appl_ull_t const
        i_time_sec,
    struct appl_linux_time_info * const
        r_time_info);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_linux.h */
