/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_download_handle.h>

#include <appl_object.h>

#include <appl_node.h>

#include <socket/appl_download_node.h>

#include <appl_thread_property.h>

#include <appl_thread_descriptor.h>

#include <appl_thread_handle.h>

#include <appl_mutex_handle.h>

#include <appl_event_handle.h>

#include <appl_clock_handle.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

#include <appl_unused.h>

//
//
//
union appl_download_ptr
{
    struct appl_download *
        p_this;

    void *
        p_void;

}; // union appl_download_ptr

//
//
//
appl_download::appl_download(
    struct appl_context * const
        p_context) :
    appl_node(
        p_context),
    m_descriptor(),
    m_thread(),
    m_mutex(),
    m_event(),
    m_status(),
    m_thread_created(),
    m_mutex_created(),
    m_event_created(),
    m_kill()
{
}

//
//
//
appl_download::~appl_download()
{
}

//
//
//
enum appl_status
    appl_download::f_init(
        struct appl_download_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor =
        *(
            p_descriptor);

    struct appl_mutex_descriptor
        o_mutex_descriptor;

    e_status =
        appl_mutex_create(
            m_context,
            &(
                o_mutex_descriptor),
            &(
                m_mutex));

    if (
        appl_status_ok
        == e_status)
    {
        m_mutex_created =
            true;

        struct appl_event_descriptor
            o_event_descriptor;

        e_status =
            appl_event_create(
                m_context,
                &(
                    o_event_descriptor),
                &(
                    m_event));

        if (
            appl_status_ok
            == e_status)
        {
            m_event_created =
                true;

            e_status =
                f_start_thread();

            if (
                appl_status_ok
                != e_status)
            {
                if (
                    m_event_created)
                {
                    appl_event_destroy(
                        m_event);

                    m_event_created =
                        false;
                }
            }

        }

        if (
            appl_status_ok
            != e_status)
        {
            if (
                m_mutex_created)
            {
                appl_mutex_destroy(
                    m_mutex);

                m_mutex_created =
                    false;
            }
        }
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_download::v_cleanup(void)
{
    // force a cancel of thread...
    f_cancel();

    if (
        m_event_created)
    {
        appl_event_destroy(
            m_event);

        m_event_created =
            false;
    }

    if (
        m_mutex_created)
    {
        appl_mutex_destroy(
            m_mutex);

        m_mutex_created =
            false;
    }

    return
        sizeof(
            struct appl_download);

} // v_cleanup()

//
//
//
enum appl_status
    appl_download::v_cancel(void)
{
    enum appl_status
        e_status;

    e_status =
        f_cancel();

    return
        e_status;

} // v_cancel()

//
//
//
enum appl_status
    appl_download::v_wait(
        unsigned long int const
            i_timeout_msec,
        enum appl_download_status * const
            r_status)
{
    enum appl_status
        e_status;

    appl_mutex_lock(
        m_mutex);

    if (
        m_thread_created)
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "download wait for completion\n");
#endif /* #if defined APPL_DEBUG */

        appl_event_wait(
            m_event,
            m_mutex,
            1000ul,
            i_timeout_msec);
    }

    if (
        m_thread_created)
    {
        e_status =
            appl_status_timeout;
    }
    else
    {
        *(
            r_status) =
            m_status;

        e_status =
            appl_status_ok;
    }

    appl_mutex_unlock(
        m_mutex);

    return
        e_status;

} // v_wait()

//
//
//
void
    appl_download::s_thread_entry(
        void * const
            p_thread_context)
{
    union appl_download_ptr
        o_download_ptr;

    o_download_ptr.p_void =
        p_thread_context;

    o_download_ptr.p_this->f_thread_handler();

} // s_thread_entry()

//
//
//
void
    appl_download::f_thread_handler(void)
{
    bool
        b_continue;

    unsigned int
        i_timeout;

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "download thread created.\n");
#endif /* #if defined APPL_DEBUG */

    // Do connection

    // Wait for connection

    // Send GET request

    // Wait for GET reponse

    b_continue =
        true;

    i_timeout =
        10u;

    while (
        b_continue)
    {
        appl_mutex_lock(
            m_mutex);

        if (
            m_kill)
        {
            m_status =
                appl_download_status_canceled;

            b_continue =
                false;
        }

        appl_mutex_unlock(
            m_mutex);

        if (
            b_continue)
        {
#if defined APPL_DEBUG
            appl_debug_impl::s_print0(
                "downloading... for 1 sec\n");
#endif /* #if defined APPL_DEBUG */

            appl_clock_delay(
                m_context,
                1000ul,
                1000ul);

            if (
                i_timeout)
            {
                i_timeout --;
            }

            if (
                0
                == i_timeout)
            {
                b_continue =
                    false;
            }
        }
    }

    appl_mutex_lock(
        m_mutex);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "download done.\n");
#endif /* #if defined APPL_DEBUG */

    if (
        !m_status)
    {
        m_status =
            appl_download_status_ok;
    }

    appl_thread_destroy(
        m_thread);

    m_thread_created =
        false;

    appl_event_signal(
        m_event);

    appl_mutex_unlock(
        m_mutex);

} // f_thread_handler()

//
//
//
enum appl_status
    appl_download::f_cancel(void)
{
    bool
        b_continue;

    // Wait for thread to complete
    b_continue =
        true;

    appl_mutex_lock(
        m_mutex);

    while (
        b_continue)
    {
        // Set the kill flag
        if (
            m_thread_created)
        {
            m_kill =
                true;

            // Interrupt blocking operations
            appl_thread_interrupt(
                m_thread);

            appl_event_wait(
                m_event,
                m_mutex,
                1000ul,
                10ul * 1000ul);
        }
        else
        {
            b_continue =
                false;
        }
    }

    appl_mutex_unlock(
        m_mutex);

    return
        appl_status_ok;

} // f_cancel()

//
//
//
enum appl_status
    appl_download::f_start_thread(void)
{
    enum appl_status
        e_status;

    /* Create a thread for connect and download operation */
    struct appl_thread_descriptor
        o_thread_descriptor;

    appl_thread_descriptor_init(
        &(
            o_thread_descriptor));

    o_thread_descriptor.b_callback =
        1;

    o_thread_descriptor.o_callback.p_entry =
        &(
            appl_download::s_thread_entry);

    union appl_download_ptr
        o_download_ptr;

    o_download_ptr.p_this =
        this;

    o_thread_descriptor.o_callback.p_context =
        o_download_ptr.p_void;

    appl_mutex_lock(
        m_mutex);

    e_status =
        appl_thread_create(
            m_context,
            &(
                o_thread_descriptor),
            &(
                m_thread));

    if (
        appl_status_ok
        == e_status)
    {
        m_thread_created =
            true;
    }

    appl_mutex_unlock(
        m_mutex);

    return
        e_status;

} // f_start_thread()

/* end-of-file: appl_download_node.cpp */
