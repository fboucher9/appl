/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <socket/appl_download_handle.h>

#include <object/appl_object.h>

#include <list/appl_node.h>

#include <socket/appl_download_node.h>

#include <thread/appl_thread_property.h>

#include <thread/appl_thread_descriptor.h>

#include <thread/appl_thread_handle.h>

#include <mutex/appl_mutex_handle.h>

#include <event/appl_event_handle.h>

#include <clock/appl_clock_handle.h>

#include <socket/appl_address_property.h>

#include <socket/appl_address_handle.h>

#include <socket/appl_socket_descriptor.h>

#include <socket/appl_socket_handle.h>

#include <buf/appl_buf.h>

#include <socket/appl_http_decoder.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

#include <misc/appl_unused.h>

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
    m_socket(),
    m_status(),
    m_thread_created(),
    m_mutex_created(),
    m_event_created(),
    m_socket_created(),
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
    enum appl_status
        e_status;

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
    e_status =
        f_create_socket();

    if (
        appl_status_ok
        == e_status)
    {
        // Send GET request
        // GET URL HTTP/1.1
        unsigned char
            a_packet[1600u];

        static unsigned char const s_get_request[] =
        {
            'G',
            'E',
            'T',
            ' ',
            '/',
            ' ',
            'H',
            'T',
            'T',
            'P',
            '/',
            '1',
            '.',
            '1',
            '\r',
            '\n',
            '\r',
            '\n'
        };

        unsigned char *
            p_packet_iterator;

        p_packet_iterator =
            appl_buf_copy(
                a_packet,
                a_packet + sizeof(a_packet),
                s_get_request,
                s_get_request + sizeof(s_get_request));

        unsigned long int
            i_count;

        e_status =
            appl_socket_send(
                m_socket,
                a_packet,
                p_packet_iterator,
                &(
                    i_count));

        if (
            appl_status_ok
            == e_status)
        {
            // Wait for GET reponse
            e_status =
                appl_socket_recv(
                    m_socket,
                    a_packet,
                    a_packet + sizeof(a_packet),
                    &(
                        i_count));

            if (
                appl_status_ok
                == e_status)
            {
                // Use http decoder on buffer...
                {
                    struct appl_http_decoder *
                        p_http_decoder;

                    struct appl_http_decoder_descriptor
                        o_http_decoder_descriptor;

                    e_status =
                        appl_http_decoder_create(
                            m_context,
                            &(
                                o_http_decoder_descriptor),
                            &(
                                p_http_decoder));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        appl_http_decoder_write(
                            p_http_decoder,
                            a_packet,
                            a_packet + i_count);

                        appl_http_decoder_destroy(
                            p_http_decoder);
                    }
                }

#if defined APPL_DEBUG
                if ((0))
                {
                    appl_debug_impl::s_print(
                        a_packet,
                        a_packet + i_count);
                }
#endif /* #if defined APPL_DEBUG */
            }
        }

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

        f_destroy_socket();
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
    struct appl_thread_descriptor *
        p_thread_descriptor;

    e_status =
        appl_thread_descriptor_create(
            m_context,
            &(
                p_thread_descriptor));

    if (
        appl_status_ok
        == e_status)
    {
        appl_thread_descriptor_set_callback(
            p_thread_descriptor,
            &(
                appl_download::s_thread_entry),
            this);

        appl_mutex_lock(
            m_mutex);

        e_status =
            appl_thread_create(
                m_context,
                p_thread_descriptor,
                &(
                    m_thread));

        appl_thread_descriptor_destroy(
            p_thread_descriptor);

        if (
            appl_status_ok
            == e_status)
        {
            m_thread_created =
                true;
        }

        appl_mutex_unlock(
            m_mutex);
    }

    return
        e_status;

} // f_start_thread()

//
//
//
enum appl_status
    appl_download::f_create_socket(void)
{
    enum appl_status
        e_status;

    if (
        m_socket_created)
    {
        e_status =
            appl_raise_fail();
    }
    else
    {
        struct appl_socket_property *
            p_socket_property;

        e_status =
            appl_socket_property_create(
                m_context,
                &(
                    p_socket_property));

        if (
            appl_status_ok
            == e_status)
        {
            struct appl_address_property *
                p_address_property;

            e_status =
                appl_address_property_create(
                    m_context,
                    &(
                        p_address_property));

            if (
                appl_status_ok
                == e_status)
            {
                appl_address_property_set_port(
                    p_address_property,
                    m_descriptor.i_connect_port);

                appl_address_property_set_name(
                    p_address_property,
                    m_descriptor.p_connect_min,
                    m_descriptor.p_connect_max);

                struct appl_address *
                    p_address;

                e_status =
                    appl_address_create(
                        m_context,
                        p_address_property,
                        &(
                            p_address));

                if (
                    appl_status_ok
                    == e_status)
                {
                    int
                        e_family;

                    if (
                        appl_status_ok
                        == appl_address_get_family(
                            p_address,
                            &(
                                e_family)))
                    {
                        appl_socket_property_set_family(
                            p_socket_property,
                            e_family);
                    }

                    appl_socket_property_set_protocol(
                        p_socket_property,
                        appl_socket_protocol_tcp_stream);

                    appl_socket_property_set_connect_address(
                        p_socket_property,
                        p_address);

                    e_status =
                        appl_socket_create(
                            m_context,
                            p_socket_property,
                            &(
                                m_socket));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        m_socket_created =
                            true;
                    }

                    appl_address_destroy(
                        p_address);
                }

                appl_address_property_destroy(
                    p_address_property);
            }

            appl_socket_property_destroy(
                p_socket_property);
        }
    }

    return
        e_status;

} // f_create_socket()

//
//
//
void
    appl_download::f_destroy_socket(void)
{
    if (
        m_socket_created)
    {
        appl_socket_destroy(
            m_socket);

        m_socket =
            0;

        m_socket_created =
            false;
    }

} // f_destroy_socket()

/* end-of-file: appl_download_node.cpp */
