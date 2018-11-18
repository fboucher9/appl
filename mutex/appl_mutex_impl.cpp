/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#if defined APPL_OS_LINUX
#include <pthread.h>
#else /* #if defined APPL_OS_Xx */
#include <windows.h>
#endif /* #if defined APPL_OS_Xx */

#include <appl_types.h>

#include <mutex/appl_mutex_impl.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

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
    appl_mutex_impl::init(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_init_result =
        pthread_mutex_init(
            &(
                m_storage.m_private),
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

    InitializeCriticalSection(
        &(
            m_storage.m_private));

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
    appl_mutex_impl::cleanup(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_destroy_result =
        pthread_mutex_destroy(
            &(
                m_storage.m_private));

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

    DeleteCriticalSection(
        &(
            m_storage.m_private));

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
    appl_mutex_impl::lock(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_lock_result =
        pthread_mutex_lock(
            &(
                m_storage.m_private));

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
            appl_status_fail;
    }

#else /* #if defined APPL_OS_Xx */

    EnterCriticalSection(
        &(
            m_storage.m_private));

    e_status =
        appl_status_ok;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // lock()

//
//
//
enum appl_status
    appl_mutex_impl::unlock(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    int const
        i_unlock_result =
        pthread_mutex_unlock(
            &(
                m_storage.m_private));

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
            appl_status_fail;
    }

#else /* #if defined APPL_OS_Xx */

    LeaveCriticalSection(
        &(
            m_storage.m_private));

    e_status =
        appl_status_ok;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // unlock()

/* end-of-file: appl_mutex_impl.cpp */
