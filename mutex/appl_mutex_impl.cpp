/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include <appl_status.h>

#include <appl_types.h>

#include <misc/appl_windows.h>

#include <mutex/appl_mutex_impl.h>

#include <misc/appl_os.h>

#if defined APPL_HAVE_COVERAGE
#include <coverage/appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

//
//
//
appl_mutex_impl::appl_mutex_impl() :
    m_storage()
{
}

//
//
//
appl_mutex_impl::~appl_mutex_impl()
{
}

//
//
//
enum appl_status
    appl_mutex_impl::f_init(void)
{
    enum appl_status
        e_status;

    if (
        appl_os_linux
        == appl_os_get())
    {
        int const
            i_init_result =
#if defined APPL_HAVE_COVERAGE
            appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
            pthread_mutex_init(
                &(
                    m_storage.m_private_linux),
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
                appl_raise_fail();
        }
    }
    else if (
        appl_os_windows
        == appl_os_get())
    {
        m_storage.m_private_windows =
            appl_windows_create_critical_section();

        if (
            m_storage.m_private_windows)
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

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_mutex_impl::f_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        appl_os_linux
        == appl_os_get())
    {
        int
            i_destroy_result;

        i_destroy_result =
            pthread_mutex_destroy(
                &(
                    m_storage.m_private_linux));

#if defined APPL_HAVE_COVERAGE
        if (appl_coverage_check())
        {
            i_destroy_result =
                -1;
        }
#endif /* #if defined APPL_HAVE_COVERAGE */

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
                appl_raise_fail();
        }
    }
    else if (
        appl_os_windows
        == appl_os_get())
    {
        if (
            m_storage.m_private_windows)
        {
            appl_windows_destroy_critical_section(
                m_storage.m_private_windows);

            m_storage.m_private_windows =
                0;
        }

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

} // f_cleanup()

//
//
//
enum appl_status
    appl_mutex_impl::f_lock(void)
{
    enum appl_status
        e_status;

    if (
        appl_os_linux
        == appl_os_get())
    {
        int const
            i_lock_result =
#if defined APPL_HAVE_COVERAGE
            appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
            pthread_mutex_lock(
                &(
                    m_storage.m_private_linux));

        if (
            0
            == i_lock_result)
        {
            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_raise_fail();
        }
    }
    else if (
        appl_os_windows
        == appl_os_get())
    {
        appl_windows_enter_critical_section(
            m_storage.m_private_windows);

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

} // f_lock()

//
//
//
enum appl_status
    appl_mutex_impl::f_unlock(void)
{
    enum appl_status
        e_status;

    if (
        appl_os_linux
        == appl_os_get())
    {
        int
            i_unlock_result;

        i_unlock_result =
            pthread_mutex_unlock(
                &(
                    m_storage.m_private_linux));

#if defined APPL_HAVE_COVERAGE
        if (appl_coverage_check())
        {
            i_unlock_result =
                -1;
        }
#endif /* #if defined APPL_HAVE_COVERAGE */

        if (
            0
            == i_unlock_result)
        {
            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_raise_fail();
        }
    }
    else if (
        appl_os_windows
        == appl_os_get())
    {
        appl_windows_leave_critical_section(
            m_storage.m_private_windows);

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

} // f_unlock()

//
//
//
enum appl_status
    appl_mutex_impl::f_sync(
        enum appl_status (*
            p_sync_callback)(
            void * const
                p_sync_context),
        void * const
            p_sync_context)
{
    enum appl_status
        e_status;

    e_status =
        f_lock();

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            (*p_sync_callback)(
                p_sync_context);

        f_unlock();
    }

    return
        e_status;

} // f_sync()

/* end-of-file: appl_mutex_impl.cpp */
