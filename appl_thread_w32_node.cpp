/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_thread_node.h"

#include "appl_thread_w32_node.h"

#include "appl_thread_descriptor.h"

//
//
//
enum appl_status
    appl_thread_w32_node::create_instance(
        class appl_context * const
            p_context,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        class appl_thread_node * * const
            r_thread_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::create_instance(
            p_context,
            sizeof(
                class appl_thread_w32_node),
            &(
                appl_thread_w32_node::placement_new),
            static_cast<void const *>(
                p_thread_descriptor),
            reinterpret_cast<class appl_object * *>(
                r_thread_node));

    return
        e_status;

} // create_instance()

//
//
//
appl_thread_w32_node::appl_thread_w32_node() :
    appl_thread_node(),
    m_w32_thread_handle(
        INVALID_HANDLE_VALUE)
{
}

//
//
//
appl_thread_w32_node::~appl_thread_w32_node()
{
}

//
//
//
enum appl_status
    appl_thread_w32_node::wait_result(
        void * * const
            r_result)
{
    enum appl_status
        e_status;

    DWORD
        dwWaitResult;

    dwWaitResult =
        WaitForSingleObject(
            m_w32_thread_handle,
            INFINITE);

    if (
        WAIT_OBJECT_0 == dwWaitResult)
    {
        DWORD
            dwExitCode;

        if (
            GetExitCodeThread(
                m_w32_thread_handle,
                &(
                    dwExitCode)))
        {
            *(
                r_result) =
                reinterpret_cast<void *>(
                    static_cast<DWORD_PTR>(
                        dwExitCode));

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

} // wait_result()

//
//
//
enum appl_status
    appl_thread_w32_node::detach(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // detach()

//
//
//
static
VOID
CALLBACK
DummyAPCEntry(
    ULONG_PTR dwParam)
{
    static_cast<void>(
        dwParam);

} // DummyAPCEntry

//
//
//
enum appl_status
    appl_thread_w32_node::interrupt(void)
{
    enum appl_status
        e_status;

    DWORD
        dwQueueResult;

    dwQueueResult =
        QueueUserAPC(
            &(
                DummyAPCEntry),
            m_w32_thread_handle,
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

    return
        e_status;

} // interrupt()

//
//
//
void
    appl_thread_w32_node::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_thread_w32_node;

} // placement_new()

//
//
//
enum appl_status
    appl_thread_w32_node::init(
        void const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_thread_descriptor const * const
        p_thread_descriptor =
        static_cast<struct appl_thread_descriptor const *>(
            p_descriptor);

    DWORD
        dwThreadId;

    m_w32_thread_handle =
        CreateThread(
            NULL,
            0,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(
                p_thread_descriptor->p_entry),
            p_thread_descriptor->p_context,
            0,
            &(
                dwThreadId));

    if (
        INVALID_HANDLE_VALUE != m_w32_thread_handle)
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
    appl_thread_w32_node::cleanup(void)
{
    enum appl_status
        e_status;

    if (INVALID_HANDLE_VALUE != m_w32_thread_handle)
    {
        CloseHandle(
            m_w32_thread_handle);

        m_w32_thread_handle =
            INVALID_HANDLE_VALUE;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_thread_w32_node.cpp */
