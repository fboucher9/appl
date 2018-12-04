/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <winsock2.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_socket_descriptor.h>

#include <socket/appl_socket_node.h>

#include <socket/appl_socket_w32_node.h>

#include <socket/appl_address_node.h>

#include <socket/appl_address_std_node.h>

#include <appl_address_property.h>

#include <appl_address_handle.h>

#include <appl_unused.h>

#include <appl_buf.h>

#include <appl_convert.h>

#include <appl_allocator_handle.h>

#include <appl_context_handle.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_socket_w32_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_socket_property const * const
            p_socket_descriptor,
        struct appl_socket * * const
            r_socket)
{
    enum appl_status
        e_status;

    class appl_socket_w32_node *
        p_socket_w32_node;

    e_status =
        appl_allocator_alloc_object(
            p_allocator,
            p_socket_descriptor,
            &(
                p_socket_w32_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_socket) =
            p_socket_w32_node;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_socket_w32_node::appl_socket_w32_node() :
    appl_socket(),
    m_fd(-1)
{
}

//
//
//
appl_socket_w32_node::~appl_socket_w32_node()
{
}

//
//
//
enum appl_status
appl_socket_w32_node::f_init(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    // call socket()
    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            init_socket(
                p_socket_descriptor);
    }

#if 0
    // reuse addr option
    if (
        appl_status_ok
        == e_status)
    {
        union reuseaddr_value
        {
            BOOL
                b;

            char
                a[1u];

        } o_reuseaddr_value;

        int
            i_setsockopt_result;

        o_reuseaddr_value.b =
            TRUE;

        i_setsockopt_result =
            setsockopt(
                m_fd,
                SOL_SOCKET,
                SO_REUSEADDR,
                o_reuseaddr_value.a,
                sizeof(
                    i_reuseaddr_value));
    }
#endif

    // call bind()
    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            init_bind(
                p_socket_descriptor);
    }

    // call connect()
    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            init_connect(
                p_socket_descriptor);
    }

    // call listen()
    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            init_listen(
                p_socket_descriptor);
    }

    // recv timeout option
    // send timeout option


    if (
        appl_status_ok
        != e_status)
    {
        if (
            INVALID_SOCKET != m_fd)
        {
            closesocket(
                m_fd);
        }
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
appl_socket_w32_node::f_init(
    SOCKET const * const
        p_init_descriptor)
{
    m_fd =
        *p_init_descriptor;

    return
        appl_status_ok;

} // f_init()

//
//
//
enum appl_status
appl_socket_w32_node::init_socket(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    enum appl_socket_protocol
        e_protocol;

    if (
        appl_status_ok
        == appl_socket_property_get_protocol(
            p_socket_descriptor,
            &(
                e_protocol)))
    {
    }
    else
    {
        e_protocol =
            appl_socket_protocol_tcp_stream;
    }

    if (
        appl_socket_protocol_tcp_stream == e_protocol)
    {
        m_fd =
            socket(
                AF_INET,
                SOCK_STREAM,
                0);

        if (
            INVALID_SOCKET != m_fd)
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

} // init_socket()

//
//
//
enum appl_status
appl_socket_w32_node::init_bind(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    struct appl_address const *
        p_bind_address;

    if (
        appl_status_ok
        == appl_socket_property_get_bind_address(
            p_socket_descriptor,
            &(
                p_bind_address)))
    {
        class appl_address_std_node const * const
            p_address_std_node =
            appl_address_std_node::convert_handle(
                p_bind_address);

        int const
            i_bind_result =
            bind(
                m_fd,
                &(
                    p_address_std_node->m_sockaddr.o_sockaddr_base),
                sizeof(
                    p_address_std_node->m_sockaddr.o_sockaddr_in));

        if (
            0
            == i_bind_result)
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
            appl_status_ok;
    }

    return
        e_status;

} // init_bind()

//
//
//
enum appl_status
appl_socket_w32_node::init_listen(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    unsigned long int
        i_listen_count;

    if (
        appl_status_ok
        == appl_socket_property_get_listen_count(
            p_socket_descriptor,
            &(
                i_listen_count)))
    {
        int const
            i_listen_result =
            listen(
                m_fd,
                appl_convert::to_signed(
                    i_listen_count));

        if (
            0
            == i_listen_result)
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
            appl_status_ok;
    }

    return
        e_status;

} // init_listen()

//
//
//
enum appl_status
appl_socket_w32_node::init_connect(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    struct appl_address const *
        p_connect_address;

    if (
        appl_status_ok
        == appl_socket_property_get_connect_address(
            p_socket_descriptor,
            &(
                p_connect_address)))
    {
        class appl_address_std_node const * const
            p_address_std_node =
            appl_address_std_node::convert_handle(
                p_connect_address);

        // setup an event object
        WSAEVENT
            h_event;

        h_event =
            WSACreateEvent();

        if (
            WSA_INVALID_EVENT != h_event)
        {
            int const
                i_event_select_result =
                WSAEventSelect(
                    m_fd,
                    h_event,
                    FD_CONNECT);

            if (
                0 == i_event_select_result)
            {
                int const
                    i_connect_result =
                    connect(
                        m_fd,
                        &(
                            p_address_std_node->m_sockaddr.o_sockaddr_base),
                        sizeof(
                            p_address_std_node->m_sockaddr.o_sockaddr_in));

                if (
                    0
                    == i_connect_result)
                {
                    e_status =
                        appl_status_ok;
                }
                else
                {
                    // Wait for completion
                    DWORD
                        i_wait_event_result;

                    DWORD
                        i_wait_event_timeout;

                    i_wait_event_timeout =
                        2000;

                    appl_socket_property_get_connect_timeout(
                        p_socket_descriptor,
                        &(
                            i_wait_event_timeout));

                    i_wait_event_result =
                        WSAWaitForMultipleEvents(
                            1,
                            &h_event,
                            FALSE,
                            i_wait_event_timeout,
                            TRUE);

                    if (
                        WSA_WAIT_EVENT_0 == i_wait_event_result)
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

                // set socket to blocking mode
                WSAEventSelect(
                    m_fd,
                    h_event,
                    0);
            }
            else
            {
                e_status =
                    appl_status_fail;
            }

            WSACloseEvent(
                h_event);
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
            appl_status_ok;
    }

    return
        e_status;

} // init_connect()

//
//
//
appl_size_t
appl_socket_w32_node::v_cleanup(void)
{
    if (
        INVALID_SOCKET
        != m_fd)
    {
        closesocket(
            m_fd);

        m_fd =
            INVALID_SOCKET;
    }

    return
        sizeof(class appl_socket_w32_node);

} // v_cleanup()

//
//
//
enum appl_status
appl_socket_w32_node::v_accept(
    struct appl_socket * * const
        r_socket,
    struct appl_address * * const
        r_address)
{
    enum appl_status
        e_status;

    // create empty address property
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
        // create empty address
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
            class appl_address_std_node * const
                p_address_std_node =
                appl_address_std_node::convert_handle(
                    p_address);

            int
                i_address_length;

            i_address_length =
                appl_convert::to_int(
                    sizeof(
                        p_address_std_node->m_sockaddr.o_sockaddr_storage));

            // setup non-blocking mode?

            SOCKET const
                i_accept_result =
                accept(
                    m_fd,
                    &(
                        p_address_std_node->m_sockaddr.o_sockaddr_base),
                    &(
                        i_address_length));

            if (
                INVALID_SOCKET != i_accept_result)
            {
                // create a socket node to hold this new file descriptor
                class appl_socket_w32_node *
                    p_socket_w32_node;

                struct appl_allocator * const
                    p_allocator =
                    appl_context_get_allocator(
                        m_context);

                e_status =
                    appl_allocator_alloc_object(
                        p_allocator,
                        &(
                            i_accept_result),
                        &(
                            p_socket_w32_node));

                if (
                    appl_status_ok
                    == e_status)
                {
                    *(
                        r_socket) =
                        p_socket_w32_node;

                    *(
                        r_address) =
                        p_address;
                }
            }
            else
            {
                e_status =
                    appl_status_fail;
            }

            if (
                appl_status_ok
                != e_status)
            {
            }
        }

        appl_address_property_destroy(
            p_address_property);
    }

    return
        e_status;

} // v_accept()

//
//
//
enum appl_status
appl_socket_w32_node::v_send(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    enum appl_status
        e_status;

    signed long int
        i_send_result;

    i_send_result =
        send(
            m_fd,
            appl_convert::to_char_ptr(
                p_buf_min),
            appl_buf_len(
                p_buf_min,
                p_buf_max),
            0);

    if (
        0 <= i_send_result)
    {
        *(
            r_count) =
            appl_convert::to_unsigned(
                i_send_result);

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

} // v_send()

//
//
//
enum appl_status
appl_socket_w32_node::v_recv(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    enum appl_status
        e_status;

    signed long int
        i_recv_result;

    i_recv_result =
        recv(
            m_fd,
            appl_convert::to_char_ptr(
                p_buf_min),
            appl_buf_len(
                p_buf_min,
                p_buf_max),
            0);

    if (
        0 <= i_recv_result)
    {
        *(
            r_count) =
            appl_convert::to_unsigned(
                i_recv_result);

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

} // v_recv()

//
//
//
enum appl_status
appl_socket_w32_node::v_sendto(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count,
    struct appl_address * const
        p_remote_address)
{
    enum appl_status
        e_status;

    appl_unused(
        p_buf_min,
        p_buf_max,
        r_count,
        p_remote_address);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_sendto()

//
//
//
enum appl_status
appl_socket_w32_node::v_recvfrom(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count,
    struct appl_address * const
        p_remote_address)
{
    enum appl_status
        e_status;

    appl_unused(
        p_buf_min,
        p_buf_max,
        r_count,
        p_remote_address);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_recvfrom()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_socket_w32_node.cpp */
