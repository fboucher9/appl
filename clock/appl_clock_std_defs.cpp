/* See LICENSE for license details */

#include <clock/appl_clock_std_defs.h>

#include <misc/appl_unused.h>

#if defined APPL_OS_WINDOWS

//
//
//
int
clock_gettime(
    int id,
    struct timespec * p)
{
    appl_unused(id, p);
    return -1;
} // clock_gettime()

//
//
//
int
usleep(
    unsigned int n)
{
    appl_unused(n);
    return -1;
} // usleep()

//
//
//
struct tm *
localtime_r(
    time_t const * p1,
    struct tm * p2)
{
    appl_unused(p1, p2);
    return 0;
} // localtime_r()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_clock_std_defs.cpp */
