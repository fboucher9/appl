/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_thread_node.h>

#include <appl_thread_w32_node.h>

#include <appl_thread_descriptor.h>

#include <appl_object_handle.h>

#include <appl_property_handle.h>

#include <appl_thread_property.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_thread_w32_node::create_instance(
        struct appl_context * const
            p_context,
        struct appl_thread_property const * const
            p_thread_property,
        struct appl_thread * * const
            r_thread)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::s_create
        < appl_thread_w32_node, appl_thread_property, appl_thread >
        (
            p_context,
            (&
                appl_thread_w32_node::placement_new),
            (&
                appl_thread_w32_node::init),
            p_thread_property,
            r_thread);

    return
        e_status;

} // create_instance()

//
//
//
appl_thread_w32_node::appl_thread_w32_node() :
    appl_thread(),
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
    appl_thread_w32_node::v_stop(
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count,
        void * * const
            r_result)
{
    enum appl_status
        e_status;

    DWORD
        dwWaitResult;

    appl_unused(
        i_wait_freq,
        i_wait_count);

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

} // v_stop()

//
//
//
enum appl_status
    appl_thread_w32_node::v_start(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_start()

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

//
//
//
enum appl_status
    appl_thread_w32_node::v_interrupt(void)
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

} // v_interrupt()

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
        struct appl_thread_property const * const
            p_thread_property)
{
    enum appl_status
        e_status;

    struct appl_thread_descriptor
        o_thread_descriptor;

    appl_thread_property_get_callback(
        p_thread_property,
        &(
            o_thread_descriptor.p_entry));

    appl_thread_property_get_context(
        p_thread_property,
        &(
            o_thread_descriptor.p_context));

    DWORD
        dwThreadId;

    m_w32_thread_handle =
        CreateThread(
            NULL,
            0,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(
                o_thread_descriptor.p_entry),
            o_thread_descriptor.p_context,
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
    appl_thread_w32_node::v_cleanup(void)
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

} // v_cleanup()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_thread_w32_node.cpp */
