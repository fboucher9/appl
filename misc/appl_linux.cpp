/* See LICENSE for license details */

/*

*/

#include <appl_types.h>

#include <misc/appl_linux.h>

#if defined APPL_OS_LINUX

#include <string.h>

#include <stdlib.h>

#include <time.h>

#include <unistd.h>

#endif /* #if defined APPL_OS_LINUX */

#include <misc/appl_unused.h>

//
//
//
int
appl_linux_clock_gettime(
    enum appl_linux_clock_id const
        i_clock_id,
    struct appl_linux_time_nsec * const
        r_time_nsec)
{
    int
        i_result;

#if defined APPL_OS_LINUX

    int const
        i_converted_clock_id =
        (
            appl_linux_clock_id_mono
            == i_clock_id)
        ? CLOCK_MONOTONIC
        : CLOCK_REALTIME;

    struct timespec
        o_timespec;

    o_timespec.tv_sec =
        r_time_nsec->i_sec;

    o_timespec.tv_nsec =
        r_time_nsec->i_nsec;

    i_result =
        clock_gettime(
            i_converted_clock_id,
            &(
                o_timespec));

    r_time_nsec->i_sec =
        o_timespec.tv_sec;

    r_time_nsec->i_nsec =
        o_timespec.tv_nsec;

#else /* #if defined APPL_OS_LINUX */

    appl_unused(
        i_clock_id,
        r_time_nsec);

    i_result =
        -1;

#endif /* #if defined APPL_OS_LINUX */

    return
        i_result;

} // appl_linux_clock_gettime()

//
//
//
int
appl_linux_usleep(
    unsigned long int const
        i_count_usec)
{
    int
        i_result;

#if defined APPL_OS_LINUX

    i_result =
        usleep(
            i_count_usec);

#else /* #if defined APPL_OS_LINUX */

    appl_unused(
        i_count_usec);

    i_result =
        -1;

#endif /* #if defined APPL_OS_LINUX */

    return
        i_result;

} // appl_linux_usleep()

//
//
//
int
appl_linux_localtime(
    appl_ull_t const
        i_time_sec,
    struct appl_linux_time_info * const
        r_time_info)
{
    int
        i_result;

#if defined APPL_OS_LINUX

    struct tm *
        p_localtime_result;

    time_t const
        i_time =
        static_cast<time_t>(
            i_time_sec);

    struct tm
        o_time_details;

    p_localtime_result =
        localtime_r(
            &(
                i_time),
            &(
                o_time_details));

    if (
        p_localtime_result)
    {
        r_time_info->i_year =
            o_time_details.tm_year;

        r_time_info->i_mon =
            o_time_details.tm_mon;

        r_time_info->i_mday =
            o_time_details.tm_mday;

        r_time_info->i_hour =
            o_time_details.tm_hour;

        r_time_info->i_min =
            o_time_details.tm_min;

        r_time_info->i_sec =
            o_time_details.tm_sec;

        i_result =
            0;
    }
    else
    {
        i_result =
            -1;
    }

#else /* #if defined APPL_OS_LINUX */

    appl_unused(
        i_time_sec,
        r_time_info);

    i_result =
        -1;

#endif /* #if defined APPL_OS_LINUX */

    return
        i_result;

} // appl_linux_localtime()

//
//
//
char const *
appl_linux_getenv(
    char const * const
        p_name)
{
    char const *
        p_result;

#if defined APPL_OS_LINUX

    p_result =
        getenv(
            p_name);

#else /* #if defined APPL_OS_LINUX */

    appl_unused(
        p_name);

    p_result =
        0;

#endif /* #if defined APPL_OS_LINUX */

    return
        p_result;

} // appl_linux_getenv()

//
//
//
int
appl_linux_setenv(
    char const * const
        p_name,
    char const * const
        p_value,
    int const
        b_overwrite)
{
    int
        i_result;

#if defined APPL_OS_LINUX

    i_result =
        setenv(
            p_name,
            p_value,
            b_overwrite);

#else /* #if defined APPL_OS_LINUX */

    appl_unused(
        p_name,
        p_value,
        b_overwrite);

    i_result =
        -1;

#endif /* #if defined APPL_OS_LINUX */

    return
        i_result;

} // appl_linux_setenv()

/* end-of-file: appl_linux.cpp */
