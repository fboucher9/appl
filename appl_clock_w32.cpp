/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_clock.h>

#include <appl_clock_w32.h>

#include <appl_unused.h>

#include <appl_convert.h>

#include <appl_heap.h>

//
//
//
enum appl_status
    appl_clock_w32::s_create(
        struct appl_heap * const
            p_heap,
        class appl_clock * * const
            r_clock)
{
    enum appl_status
        e_status;

    class appl_clock_w32 *
        p_clock_w32;

    e_status =
        p_heap->alloc_object(
            &(
                p_clock_w32));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_clock) =
            p_clock_w32;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_clock_w32::appl_clock_w32() :
    appl_clock()
{
}

//
//
//
appl_clock_w32::~appl_clock_w32()
{
}

//
//
//
enum appl_status
    appl_clock_w32::f_init(void)
{
    enum appl_status
        e_status;

    MMRESULT
        iWindowsResult;

    UINT
        uPeriod;

    uPeriod =
        1u;

    iWindowsResult =
        timeBeginPeriod(
            uPeriod);

    if (
        TIMERR_NOERROR
        == iWindowsResult)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_clock_w32::v_cleanup(void)
{
    enum appl_status
        e_status;

    MMRESULT
        iWindowsResult;

    UINT
        uPeriod;

    uPeriod =
        1u;

    iWindowsResult =
        timeEndPeriod(
            uPeriod);

    if (
        TIMERR_NOERROR
        == iWindowsResult)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_cleanup()

//
//
//
static
unsigned long int
appl_math_muldiv(
    unsigned long int const
        i_value,
    unsigned long int const
        i_mul,
    unsigned long int const
        i_div)
{
    appl_ull_t const
        ll_value =
            i_value;

    return
        appl_convert::to_ulong(
            (
                ll_value
                * i_mul)
            / i_div);

} // appl_math_muldiv()

//
//
//
enum appl_status
appl_clock_w32::v_read(
    unsigned long int const
        i_time_freq,
    unsigned long int * const
        p_time_count)
{
    enum appl_status
        e_status;

    LARGE_INTEGER
        liFreq;

    BOOL
        bWindowsResult;

    bWindowsResult =
        QueryPerformanceFrequency(
            &(
                liFreq));

    if (
        bWindowsResult)
    {
        LARGE_INTEGER
            liCounter;

        bWindowsResult =
            QueryPerformanceCounter(
                &(
                    liCounter));

        if (
            bWindowsResult)
        {
            unsigned long int
                i_time_count;

            appl_ull_t
                ll_time_count;

            ll_time_count =
                ((liCounter.QuadPart * i_time_freq) / liFreq.QuadPart);

            i_time_count =
                appl_convert::to_ulong(
                    ll_time_count);

            *(
                p_time_count) =
                i_time_count;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_read()

//
//
//
enum appl_status
appl_clock_w32::v_delay(
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count)
{
    enum appl_status
        e_status;

    unsigned long int
        i_time_msec;

    if (
        i_time_freq)
    {
        i_time_msec =
            appl_math_muldiv(
                i_time_count,
                1000ul,
                i_time_freq);

        SleepEx(
            appl_convert::to_uint(
                i_time_msec),
            TRUE);

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_delay()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_clock_w32.cpp */
