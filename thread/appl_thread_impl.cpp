/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <pthread.h>

#include <signal.h>

#else /* #if defined APPL_OS_Xx */

#include <windows.h>

#endif /* #if defined APPL_OS_Xx */

#include <appl_status.h>

#include <appl_types.h>

#include <appl_thread_descriptor.h>

#include <thread/appl_thread_impl.h>

#include <appl_unused.h>

//
//
//
appl_thread_impl::appl_thread_impl() :
    m_descriptor(),
    m_storage()
{
}

//
//
//
appl_thread_impl::~appl_thread_impl()
{
}

//
//
//
enum appl_status
    appl_thread_impl::f_init(
        struct appl_thread_descriptor const * const
            p_thread_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor =
        *(
            p_thread_descriptor);

#if defined APPL_OS_LINUX
    int
        i_create_result;

    i_create_result =
        pthread_create(
            &(
                m_storage.m_thread),
            NULL,
            &(
                appl_thread_impl::thread_linux_entry),
            this);

    if (
        0
        == i_create_result)
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

    DWORD
        dwThreadId;

    m_storage.m_thread =
        CreateThread(
            NULL,
            0,
            &(
                appl_thread_impl::thread_windows_entry),
            this,
            0,
            &(
                dwThreadId));

    if (
        INVALID_HANDLE_VALUE != m_storage.m_thread)
    {
        e_status =
            appl_status_ok;

        if (0)
        {
            DWORD const
                dwWaitResult =
                WaitForSingleObject(
                    m_storage.m_thread,
                    INFINITE);

            if (
                WAIT_OBJECT_0 == dwWaitResult)
            {
                e_status =
                    appl_status_ok;
            }
            else
            {
                e_status =
                    appl_status_fail;
            }

            if (INVALID_HANDLE_VALUE != m_storage.m_thread)
            {
                CloseHandle(
                    m_storage.m_thread);

                m_storage.m_thread =
                    INVALID_HANDLE_VALUE;
            }
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

#endif /* #if defined APPL_OS_Xx */

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_thread_impl::f_cleanup(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_cleanup()

union appl_thread_impl_callback_ptr
{
    void *
        p_thread_context;

    class appl_thread_impl *
        p_thread_impl;

};

#if defined APPL_OS_LINUX

/*

*/
static
void
dummy_urgent_signal_handler(
    int
        i_unused)
{
    appl_unused(
        i_unused);
} /* dummy_urgent_signal_handler() */

#else /* #if defined APPL_OS_Xx */

//
//
//
static
VOID
CALLBACK
DummyAPCEntry(
    ULONG_PTR dwParam)
{
    appl_unused(
        dwParam);

} // DummyAPCEntry

#endif /* #if defined APPL_OS_Xx */

//
//
//
enum appl_status
    appl_thread_impl::f_interrupt(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    // setup SIGURG handler
    struct sigaction
        o_new_action;

    struct sigaction
        o_old_action;

#if defined __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#endif

    o_new_action.sa_handler =
        &(
            dummy_urgent_signal_handler);

#if defined __clang__
#pragma clang diagnostic pop
#endif

    sigemptyset(
        &(
            o_new_action.sa_mask));

    o_new_action.sa_flags = 0;

    int
        i_sigaction_result;

    i_sigaction_result =
        sigaction(
            SIGURG,
            &(
                o_new_action),
            &(
                o_old_action));

    if (
        0
        == i_sigaction_result)
    {
        int
            i_external_result;

        i_external_result =
            pthread_kill(
                m_storage.m_thread,
                SIGURG);

        if (
            0
            == i_external_result)
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

    DWORD const
        dwQueueResult =
        QueueUserAPC(
            &(
                DummyAPCEntry),
            m_storage.m_thread,
            0);

    if (
        0 != dwQueueResult)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        // GetLastError...

        e_status =
            appl_status_fail;
    }

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // f_interrupt()

//
//
//
#if defined APPL_OS_LINUX

void *
    appl_thread_impl::thread_linux_handler(void)
{
    int const
        i_detach_result =
        pthread_detach(
            m_storage.m_thread);

    if (
        0
        == i_detach_result)
    {
        (*(m_descriptor.o_callback.p_entry))(
            m_descriptor.o_callback.p_context);
    }
    else
    {
    }

    return
        0;

} // thread_linux_handler()

#endif /* #if defined APPL_OS_Xx */

//
//
//
#if defined APPL_OS_LINUX

void *
    appl_thread_impl::thread_linux_entry(
        void *
            p_thread_context)
{
    union appl_thread_impl_callback_ptr
        o_callback_ptr;

    o_callback_ptr.p_thread_context =
        p_thread_context;

    class appl_thread_impl * const
        p_thread_impl =
        o_callback_ptr.p_thread_impl;

    return
        p_thread_impl->thread_linux_handler();

} // thread_linux_entry()

#endif /* #if defined APPL_OS_Xx */

#if defined APPL_OS_WINDOWS

//
//
//
DWORD
CALLBACK
    appl_thread_impl::thread_windows_entry(
        void * const
            p_thread_context)
{
    union appl_thread_impl_callback_ptr
        o_callback_ptr;

    o_callback_ptr.p_thread_context =
        p_thread_context;

    class appl_thread_impl * const
        p_thread_impl =
        o_callback_ptr.p_thread_impl;

    return
        p_thread_impl->thread_windows_handler();

} // thread_entry()

#endif /* #if defined APPL_OS_Xx */

#if defined APPL_OS_WINDOWS

//
//
//
DWORD
    appl_thread_impl::thread_windows_handler(void)
{
    (*(m_descriptor.o_callback.p_entry))(
        m_descriptor.o_callback.p_context);

    DWORD const
        u_exit_code =
        0u;

    return
        u_exit_code;

} // thread_windows_handler()

#endif /* #if defined APPL_OS_Xx */

/* end-of-file: appl_thread_impl.cpp */
