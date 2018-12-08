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
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

#include <appl_unused.h>

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
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "pthread_mutex_init fail\n");
#endif /* #if defined APPL_DEBUG */

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

} // f_init()

//
//
//
enum appl_status
    appl_mutex_impl::f_cleanup(void)
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
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "pthread_mutex_destroy fail\n");
#endif /* #if defined APPL_DEBUG */

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

} // f_cleanup()

//
//
//
enum appl_status
    appl_mutex_impl::f_lock(void)
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
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "pthread_mutex_lock fail\n");
#endif /* #if defined APPL_DEBUG */

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

} // f_lock()

//
//
//
enum appl_status
    appl_mutex_impl::f_unlock(void)
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
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "pthread_mutex_unlock fail\n");
#endif /* #if defined APPL_DEBUG */

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
