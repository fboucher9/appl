/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_thread_node.h>

#include <appl_thread_descriptor.h>

#include <appl_mutex_impl.h>

#include <appl_event_impl.h>

#include <appl_thread_w32_node.h>

#include <appl_object_handle.h>

#include <appl_property_handle.h>

#include <appl_thread_property.h>

#include <appl_unused.h>

#include <appl_convert.h>

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

    class appl_thread_w32_node *
        p_thread_w32_node;

    e_status =
        appl_object::s_create (
            p_context,
            (&
                appl_thread_w32_node::placement_new),
            (&
                appl_thread_w32_node::init),
            p_thread_property,
            &(
                p_thread_w32_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_thread) =
            p_thread_w32_node;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_thread_w32_node::appl_thread_w32_node() :
    appl_thread(),
    m_descriptor(),
    m_lock(),
    m_event(),
    m_w32_thread_handle(
        INVALID_HANDLE_VALUE),
    m_running(false),
    m_start(false),
    m_kill(false)
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
            i_wait_count)
{
    enum appl_status
        e_status;

    appl_unused(
        i_wait_freq,
        i_wait_count);

    m_lock.lock();

    if (
        m_running)
    {
        if (
            m_start)
        {
            m_event.wait(
                &(
                    m_lock),
                i_wait_freq,
                i_wait_count);

            if (
                m_start)
            {
                e_status =
                    appl_status_fail;
            }
            else
            {
                e_status =
                    appl_status_ok;
            }
        }
        else
        {
            e_status =
                appl_status_ok;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    m_lock.unlock();

    return
        e_status;

} // v_stop()

//
//
//
enum appl_status
    appl_thread_w32_node::v_start(
        void (* const p_callback)(
            void * const
                p_context),
        void * const
            p_context)
{
    enum appl_status
        e_status;

    m_lock.lock();

    if (
        m_running)
    {
        if (
            !m_start)
        {
            m_descriptor.p_entry =
                p_callback;

            m_descriptor.p_context =
                p_context;

            m_start =
                true;

            m_event.signal();

            m_event.wait(
                &(
                    m_lock),
                1,
                1);

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

    m_lock.unlock();

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

    DWORD const
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

    DWORD
        dwThreadId;

    appl_unused(
        p_thread_property);

    m_lock.init();

    m_event.init();

    m_w32_thread_handle =
        CreateThread(
            NULL,
            0,
            &(
                appl_thread_w32_node::thread_entry),
            this,
            0,
            &(
                dwThreadId));

    if (
        INVALID_HANDLE_VALUE != m_w32_thread_handle)
    {
        m_running =
            true;

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

    m_lock.lock();

    if (
        m_running)
    {
        m_kill =
            true;

        m_event.signal();

        m_event.wait(
            &(
                m_lock),
            1,
            1);
    }

    m_lock.unlock();

    DWORD const
        dwWaitResult =
        WaitForSingleObject(
            m_w32_thread_handle,
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

    if (INVALID_HANDLE_VALUE != m_w32_thread_handle)
    {
        CloseHandle(
            m_w32_thread_handle);

        m_w32_thread_handle =
            INVALID_HANDLE_VALUE;
    }

    m_event.cleanup();

    m_lock.cleanup();

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

union appl_thread_w32_node_thread_context_ptr
{
    void *
        p_thread_context;

    class appl_thread_w32_node *
        p_thread_w32_node;

}; // appl_thread_w32_node_thread_context_ptr

//
//
//
DWORD
CALLBACK
    appl_thread_w32_node::thread_entry(
        void * const
            p_thread_context)
{
    union appl_thread_w32_node_thread_context_ptr
        o_thread_ctxt_ptr;

    o_thread_ctxt_ptr.p_thread_context =
        p_thread_context;

    class appl_thread_w32_node * const
        p_thread_w32_node =
        o_thread_ctxt_ptr.p_thread_w32_node;

    p_thread_w32_node->thread_handler();

    DWORD
        u_exit_code;

    u_exit_code =
        0u;

    return
        u_exit_code;

} // thread_entry()

//
//
//
void
    appl_thread_w32_node::thread_handler(void)
{
    m_lock.lock();

    // wait for start event
    while (
        !(
            m_kill))
    {
        if (
            m_start)
        {
            struct appl_thread_descriptor const
                o_descriptor =
                m_descriptor;

            m_event.signal();

            m_lock.unlock();

            (*(o_descriptor.p_entry))(
                o_descriptor.p_context);

            m_lock.lock();

            m_start =
                false;

            m_event.signal();
        }
        else
        {
            // wait for start event
            m_event.wait(
                &(
                    m_lock),
                1,
                1);
        }
    }

    m_running =
        false;

    m_event.signal();

    m_lock.unlock();

    m_running =
        false;

    // automatic delete if detached...

} // thread_handler()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_thread_w32_node.cpp */
