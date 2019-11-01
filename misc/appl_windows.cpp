/* See LICENSE for license details */

/*

*/

#include <appl_types.h>

#include <misc/appl_windows.h>

#include <misc/appl_unused.h>

#if defined APPL_OS_WINDOWS

#include <windows.h>

#endif /* #if defined APPL_OS_WINDOWS */

//
//
//
char
appl_windows_time_begin_period(
    unsigned long int const
        i_period_msec)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    MMRESULT
        e_time_result;

    e_time_result =
        timeBeginPeriod(
            i_period_msec);

    b_result =
        (
            TIMERR_NOERROR
            == e_time_result);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        i_period_msec);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_time_begin_period()

//
//
//
char
appl_windows_time_end_period(
    unsigned long int const
        i_period_msec)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    MMRESULT
        e_time_result;

    e_time_result =
        timeEndPeriod(
            i_period_msec);

    b_result =
        (
            TIMERR_NOERROR
            == e_time_result);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        i_period_msec);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_time_end_period()

//
//
//
char
appl_windows_query_performance_frequency(
    appl_ull_t * const
        r_value)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    BOOL
        b_query_result;

    LARGE_INTEGER
        o_query_value;

    b_query_result =
        QueryPerformanceFrequency(
            &(
                o_query_value));

    if (
        b_query_result)
    {
        *(
            r_value) =
            o_query_value.QuadPart;

        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        r_value);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_query_performance_frequency()

//
//
//
char
appl_windows_query_performance_counter(
    appl_ull_t * const
        r_value)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    LARGE_INTEGER
        o_query_value;

    BOOL const
        b_query_result =
        QueryPerformanceCounter(
            &(
                o_query_value));

    if (
        b_query_result)
    {
        *(
            r_value) =
            o_query_value.QuadPart;

        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        r_value);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_query_performance_counter()

//
//
//
char
appl_windows_sleep_ex(
    unsigned long int const
        i_count_msec,
    char const
        b_alertable)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    if (
        0
        == SleepEx(
            i_count_msec,
            b_alertable))
    {
        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        i_count_msec,
        b_alertable);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_sleep_ex()

/* end-of-file: appl_windows.h */
