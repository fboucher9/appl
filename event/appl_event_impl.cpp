/* See LICENSE for license details */

/*

*/

#include <event/appl_event_defs.h>

#include <mutex/appl_mutex_defs.h>

#include <appl_status.h>

#include <appl_types.h>

#include <event/appl_event_impl.h>

#include <mutex/appl_mutex_impl.h>

#include <misc/appl_convert.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

#if defined APPL_HAVE_COVERAGE
#include <coverage/appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

//
//
//
appl_event_impl::appl_event_impl() :
    m_storage()
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
    appl_event_impl::f_init(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_init_result =
#if defined APPL_HAVE_COVERAGE
        appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
        pthread_cond_init(
            &(
                m_storage.m_linux.m_private),
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
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "pthread_cond_init fail\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

#else /* #if defined APPL_OS_Xx */

    InitializeConditionVariable(
        &(
            m_storage.m_windows.m_private));

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
    appl_event_impl::f_cleanup(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_destroy_result =
#if defined APPL_HAVE_COVERAGE
        appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
        pthread_cond_destroy(
            &(
                m_storage.m_linux.m_private));

    if (
        0
        == i_destroy_result)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "pthread_cond_destroy fail\n");
#endif /* #if defined APPL_DEBUG */

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
    appl_event_impl::f_signal(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_signal_result =
#if defined APPL_HAVE_COVERAGE
        appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
        pthread_cond_signal(
            &(
                m_storage.m_linux.m_private));

    if (
        0
        == i_signal_result)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "pthread_cond_signal fail\n");
#endif /* #if defined APPL_DEBUG */
        e_status =
            appl_status_fail;
    }

#else /* #if defined APPL_OS_Xx */

    WakeConditionVariable(
        &(
            m_storage.m_windows.m_private));

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
    appl_event_impl::f_wait(
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
#if defined APPL_HAVE_COVERAGE
        appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
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
#if defined APPL_HAVE_COVERAGE
            appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
            pthread_cond_timedwait(
                &(
                    m_storage.m_linux.m_private),
                &(
                    p_mutex_impl->m_storage.m_private_linux),
                &(
                    o_abstime));

        if (
            (
                0
                == i_wait_result)
            || (
                ETIMEDOUT == i_wait_result))
        {
            e_status =
                appl_status_ok;
        }
        else
        {
#if defined APPL_DEBUG
            appl_debug_impl::s_print0(
                "pthread_cond_timedwait fail\n");
#endif /* #if defined APPL_DEBUG */

            e_status =
                appl_status_fail;
        }
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "clock_gettime fail\n");
#endif /* #if defined APPL_DEBUG */

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
                m_storage.m_windows.m_private),
            &(
                p_mutex_impl->m_storage.m_private_windows),
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
