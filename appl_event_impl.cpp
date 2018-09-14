
#include <appl_status.h>

#include <appl_types.h>

#if defined APPL_OS_LINUX

#include <pthread.h>

#else /* #if defined APPL_OS_Xx */

#define WINVER 0x601

#define _WIN32_WINNT 0x601

#include <windows.h>

#endif /* #if defined APPL_OS_Xx */

#include <appl_event_impl.h>

#include <appl_mutex_impl.h>

#include <appl_convert.h>

//
//
//
appl_event_impl::appl_event_impl() :
    m_private()
{
}

//
//
//
appl_event_impl::~appl_event_impl()
{
}

//
//
//
enum appl_status
    appl_event_impl::init(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_init_result =
        pthread_cond_init(
            &(
                m_private),
            NULL);

    if (
        0
        == i_init_result)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

#else /* #if defined APPL_OS_Xx */

    InitializeConditionVariable(
        &(
            m_private));

    e_status =
        appl_status_ok;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // init()

//
//
//
enum appl_status
    appl_event_impl::cleanup(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_destroy_result =
        pthread_cond_destroy(
            &(
                m_private));

    if (
        0
        == i_destroy_result)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

#else /* #if defined APPL_OS_Xx */

    e_status =
        appl_status_ok;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
    appl_event_impl::signal(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_signal_result =
        pthread_cond_signal(
            &(
                m_private));

    if (
        0
        == i_signal_result)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

#else /* #if defined APPL_OS_Xx */

    WakeConditionVariable(
        &(
            m_private));

    e_status =
        appl_status_ok;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // signal()

//
//
//
enum appl_status
    appl_event_impl::wait(
        class appl_mutex_impl * const
            p_mutex_impl,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    struct timespec
        o_now;

    int
        i_clock_result;

    i_clock_result =
        clock_gettime(
            CLOCK_REALTIME,
            &(
                o_now));

    if (
        0
        == i_clock_result)
    {
        appl_ull_t
            ll_abstime;

        appl_ull_t
            ll_now_sec;

        appl_ull_t
            ll_now_nsec;

        appl_ull_t
            ll_wait_count;

        ll_now_sec =
            appl_convert::to_unsigned(
                o_now.tv_sec);

        ll_now_nsec =
            appl_convert::to_unsigned(
                o_now.tv_nsec);

        ll_wait_count =
            i_wait_count;

        ll_abstime =
                (
                    ll_now_sec
                    * 1000000000ul)
                + ll_now_nsec
                + (
                    (
                        ll_wait_count
                        * 1000000000ul)
                    / i_wait_freq);

        /* Default timeout ... */
        struct timespec
            o_abstime;

        o_abstime.tv_sec =
            appl_convert::to_long(
                ll_abstime / 1000000000ul);

        o_abstime.tv_nsec =
            appl_convert::to_long(
                ll_abstime % 1000000000ul);

        int const
            i_wait_result =
            pthread_cond_timedwait(
                &(
                    m_private),
                &(
                    p_mutex_impl->m_private),
                &(
                    o_abstime));

        if (
            0
            == i_wait_result)
        {
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

#else /* #if defined APPL_OS_Xx */

    appl_ull_t const
        ll_wait_count =
        i_wait_count;

    DWORD
        i_timeout_msec =
        appl_convert::to_ulong(
            ((ll_wait_count * 1000u) / i_wait_freq));

    BOOL const
        b_sleep_result =
        SleepConditionVariableCS(
            &(
                m_private),
            &(
                p_mutex_impl->m_private),
            i_timeout_msec);

    if (
        b_sleep_result)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // wait()

/* end-of-file: appl_event_impl.cpp */