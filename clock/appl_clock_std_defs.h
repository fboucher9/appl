/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_clock_std_defs_h
{
    inc_appl_clock_std_defs_h = 1
        /* Header file dependencies */
        /* ... */
}; /* enum guard_appl_clock_std_defs_h */

#if defined APPL_OS_LINUX

#include <time.h>

#include <unistd.h>

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS

#include <misc/appl_extern_c_begin.h>

#define CLOCK_MONOTONIC 1
#define CLOCK_REALTIME 2

typedef signed long int time_t;

struct timespec
{
    time_t tv_sec;
    signed long int tv_nsec;
};

struct tm
{
    int tm_year;
    int tm_mday;
    int tm_mon;
    int tm_hour;
    int tm_min;
    int tm_sec;
};

int clock_gettime(int id, struct timespec * p);

int usleep(unsigned int n);

struct tm * localtime_r(time_t const * p1, struct tm * p2);

#include <misc/appl_extern_c_end.h>

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_clock_std_defs.h */
