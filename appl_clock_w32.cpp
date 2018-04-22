/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_clock.h>

#include <appl_clock_w32.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_clock_w32::create_instance(
        struct appl_context * const
            p_context,
        class appl_clock * * const
            r_clock)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::s_create
        < appl_clock_w32, appl_clock >
        (
            p_context,
            (&
                appl_clock_w32::placement_new),
            (&
                appl_clock_w32::init),
            r_clock);

    return
        e_status;

} // create_instance()

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
void
    appl_clock_w32::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_clock_w32;

} // placement_new()

//
//
//
enum appl_status
    appl_clock_w32::init(void)
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

} // init()

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

            i_time_count =
                static_cast<unsigned long int>(
                    (liCounter.QuadPart * i_time_freq) / liFreq.QuadPart);

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
            static_cast<unsigned long int>(
                (
                    (
                        static_cast<appl_ull_t>(
                            i_time_count)
                        * 1000ul)
                    / i_time_freq)
                & 0xFFFFFFFFul);

        SleepEx(
            static_cast<unsigned int>(
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
