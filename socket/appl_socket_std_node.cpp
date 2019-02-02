/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <unistd.h>

#include <fcntl.h>

#include <errno.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <poll.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_socket_descriptor.h>

#include <socket/appl_socket_node.h>

#include <socket/appl_socket_std_node.h>

#include <socket/appl_address_node.h>

#include <socket/appl_address_std_node.h>

#include <appl_address_handle.h>

#include <appl_unused.h>

#include <appl_buf.h>

#include <appl_convert.h>

#include <appl_allocator_handle.h>

#include <context/appl_context.h>

#include <appl_address_family.h>

#include <appl_address_property.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_socket_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_socket_property const * const
            p_socket_descriptor,
        struct appl_socket * * const
            r_socket)
{
    enum appl_status
        e_status;

    class appl_socket_std_node *
        p_socket_std_node;

    e_status =
        appl_new(
            p_allocator,
            p_socket_descriptor,
            &(
                p_socket_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_socket) =
            p_socket_std_node;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_socket_std_node::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_socket * const
            p_socket)
{
    enum appl_status
        e_status;

    e_status =
        appl_delete(
            p_allocator,
            p_socket);

    return
        e_status;

} // s_destroy()


//
//
//
appl_socket_std_node::appl_socket_std_node(
    struct appl_context * const
        p_context) :
    appl_socket(
        p_context),
    m_fd(-1)
{
}

//
//
//
appl_socket_std_node::~appl_socket_std_node()
{
}

//
//
//
enum appl_status
appl_socket_std_node::f_init(
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

    // sockopt
    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            init_recv_timeout(
                p_socket_descriptor);
    }

    // sockopt
    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            init_send_timeout(
                p_socket_descriptor);
    }

    if (
        appl_status_ok
        != e_status)
    {
        if (
            -1 != m_fd)
        {
            close(
                m_fd);

            m_fd =
                -1;
        }
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
appl_socket_std_node::f_init(
    int const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    m_fd =
        *(
            p_socket_descriptor);

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
appl_socket_std_node::init_socket(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    int
        i_protocol;

    {
        enum appl_socket_protocol
            e_protocol;

        if (
            appl_status_ok
            == appl_socket_property_get_protocol(
                p_socket_descriptor,
                &(
                    e_protocol)))
        {
            if (
                appl_socket_protocol_udp_dgram == e_protocol)
            {
                i_protocol =
                    SOCK_DGRAM;
            }
            else
            {
                i_protocol =
                    SOCK_STREAM;
            }
        }
        else
        {
            i_protocol =
                SOCK_STREAM;
        }
    }

    int
        i_domain;

    {
        int
            e_family;

        if (
            appl_status_ok
            == appl_socket_property_get_family(
                p_socket_descriptor,
                &(
                    e_family)))
        {
            if (
                appl_address_family_inet6 == e_family)
            {
                i_domain =
                    AF_INET6;
            }
            else
            {
                i_domain =
                    AF_INET;
            }
        }
        else
        {
            i_domain =
                AF_INET;
        }
    }

    int const
        i_socket_result =
        socket(
            i_domain,
            i_protocol,
            0);

    if (
        -1 != i_socket_result)
    {
        m_fd =
            i_socket_result;

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

} // init_socket()

//
//
//
enum appl_status
appl_socket_std_node::init_bind(
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
                p_address_std_node->m_sockaddr_len);

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
appl_socket_std_node::init_connect(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    struct appl_address const *
        p_connect_address;

    bool
        b_connect_timeout;

    unsigned long int
        i_connect_timeout;

    if (
        appl_status_ok
        == appl_socket_property_get_connect_timeout(
            p_socket_descriptor,
            &(
                i_connect_timeout)))
    {
        b_connect_timeout =
            true;
    }
    else
    {
        b_connect_timeout =
            false;

        i_connect_timeout =
            0ul;
    }

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

        if (
            b_connect_timeout)
        {
            // set socket to non-blocking mode
            fcntl(m_fd, F_SETFL, O_NONBLOCK);

            // clear the error number before calling
            errno = 0;
        }

        int const
            i_connect_result =
            connect(
                m_fd,
                &(
                    p_address_std_node->m_sockaddr.o_sockaddr_base),
                p_address_std_node->m_sockaddr_len);

        if (
            0
            == i_connect_result)
        {
            e_status =
                appl_status_ok;
        }
        else if (
            b_connect_timeout
            && (
                EINPROGRESS == errno))
        {
            /* Use poll to wait for completion */
            struct pollfd
                a_poll_table[1u];

            a_poll_table[0u].fd =
                m_fd;

            a_poll_table[0u].events =
                POLLIN | POLLOUT;

            a_poll_table[0u].revents =
                0;

            int const
                i_poll_result =
                poll(
                    a_poll_table,
                    1,
                    appl_convert::to_int(
                        appl_convert::to_signed(
                            i_connect_timeout)));

            if (
                0 == i_poll_result)
            {
                e_status =
                    appl_status_fail;
            }
            else if (
                0 < i_poll_result)
            {
                /* Get SO_ERROR option */
                int
                    i_sockopt_value;

                socklen_t
                    i_sockopt_length;

                i_sockopt_length =
                    appl_convert::to_uint(
                        sizeof(i_sockopt_value));

                int const
                    i_sockopt_result =
                    getsockopt(
                        m_fd,
                        SOL_SOCKET,
                        SO_ERROR,
                        &(
                            i_sockopt_value),
                        &(
                            i_sockopt_length));

                if (
                    (
                        0 == i_sockopt_result)
                    && (
                        0 == i_sockopt_value))
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
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        if (b_connect_timeout)
        {
            // restore original mode
            fcntl(m_fd, F_SETFL, 0);
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
enum appl_status
appl_socket_std_node::init_listen(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    unsigned long int
        ul_listen_count;

    if (
        appl_status_ok
        == appl_socket_property_get_listen_count(
            p_socket_descriptor,
            &(
                ul_listen_count)))
    {
        int const
            i_listen_count =
            appl_convert::to_int(
                ul_listen_count);

        int const
            i_listen_result =
            listen(
                m_fd,
                i_listen_count);

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
appl_socket_std_node::init_recv_timeout(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    unsigned long int
        i_recv_timeout;

    if (
        appl_status_ok
        == appl_socket_property_get_recv_timeout(
            p_socket_descriptor,
            &(
                i_recv_timeout)))
    {
        struct timeval
            o_sockopt_value;

        o_sockopt_value.tv_sec =
            appl_convert::to_signed(
                i_recv_timeout / 1000ul);

        o_sockopt_value.tv_usec =
            appl_convert::to_signed(
                (i_recv_timeout % 1000ul) * 1000ul);

        socklen_t const
            i_sockopt_length =
            appl_convert::to_uint(
                sizeof(o_sockopt_value));

        int const
            i_sockopt_result =
            setsockopt(
                m_fd,
                SOL_SOCKET,
                SO_RCVTIMEO,
                &(
                    o_sockopt_value),
                i_sockopt_length);

        if (
            0
            == i_sockopt_result)
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

} // init_recv_timeout()

//
//
//
enum appl_status
appl_socket_std_node::init_send_timeout(
    struct appl_socket_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    unsigned long int
        i_send_timeout;

    if (
        appl_status_ok
        == appl_socket_property_get_send_timeout(
            p_socket_descriptor,
            &(
                i_send_timeout)))
    {
        struct timeval
            o_sockopt_value;

        o_sockopt_value.tv_sec =
            appl_convert::to_signed(
                i_send_timeout / 1000ul);

        o_sockopt_value.tv_usec =
            appl_convert::to_signed(
                (i_send_timeout % 1000ul) * 1000ul);

        socklen_t const
            i_sockopt_length =
            appl_convert::to_uint(
                sizeof(o_sockopt_value));

        int const
            i_sockopt_result =
            setsockopt(
                m_fd,
                SOL_SOCKET,
                SO_SNDTIMEO,
                &(
                    o_sockopt_value),
                i_sockopt_length);

        if (
            0
            == i_sockopt_result)
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

} // init_send_timeout()

//
//
//
appl_size_t
appl_socket_std_node::v_cleanup(void)
{
    if (
        -1 != m_fd)
    {
        close(
            m_fd);

        m_fd =
            -1;
    }

    return
        sizeof(class appl_socket_std_node);

} // v_cleanup()

//
//
//
enum appl_status
appl_socket_std_node::v_accept(
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

            socklen_t
                i_address_length;

            i_address_length =
                appl_convert::to_uint(
                    sizeof(
                        p_address_std_node->m_sockaddr.o_sockaddr_storage));

            // setup non-blocking mode?

            int const
                i_accept_result =
                accept(
                    m_fd,
                    &(
                        p_address_std_node->m_sockaddr.o_sockaddr_base),
                    &(
                        i_address_length));

            if (
                -1 != i_accept_result)
            {
                p_address_std_node->m_sockaddr_len =
                    i_address_length;

                // create a socket node to hold this new file descriptor
                class appl_socket_std_node *
                    p_socket_std_node;

                e_status =
                    appl_new(
                        m_context->v_allocator(),
                        &(
                            i_accept_result),
                        &(
                            p_socket_std_node));

                if (
                    appl_status_ok
                    == e_status)
                {
                    *(
                        r_socket) =
                        p_socket_std_node;

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
                appl_address_destroy(
                    p_address);
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
appl_socket_std_node::v_send(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    enum appl_status
        e_status;

    appl_ptrdiff_t
        i_send_result;

    i_send_result =
        send(
            m_fd,
            p_buf_min,
            appl_buf_len(
                p_buf_min,
                p_buf_max),
            0);

    if (
        -1 != i_send_result)
    {
        *(
            r_count) =
            appl_convert::to_ulong(
                appl_convert::to_unsigned(
                    i_send_result));

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
appl_socket_std_node::v_recv(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    enum appl_status
        e_status;

    appl_ptrdiff_t
        i_recv_result;

    i_recv_result =
        recv(
            m_fd,
            p_buf_min,
            appl_buf_len(
                p_buf_min,
                p_buf_max),
            0);

    if (
        -1 != i_recv_result)
    {
        *(
            r_count) =
            appl_convert::to_ulong(
                appl_convert::to_unsigned(
                    i_recv_result));

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
appl_socket_std_node::v_sendto(
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

    appl_ptrdiff_t
        i_send_result;

    class appl_address_std_node const * const
        p_address_std_node =
        appl_address_std_node::convert_handle(
            p_remote_address);

    i_send_result =
        sendto(
            m_fd,
            p_buf_min,
            appl_buf_len(
                p_buf_min,
                p_buf_max),
            0,
            &(
                p_address_std_node->m_sockaddr.o_sockaddr_base),
            p_address_std_node->m_sockaddr_len);

    if (
        -1 != i_send_result)
    {
        *(
            r_count) =
            appl_convert::to_ulong(
                appl_convert::to_unsigned(
                    i_send_result));

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

} // v_sendto()

//
//
//
enum appl_status
appl_socket_std_node::v_recvfrom(
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

    class appl_address_std_node * const
        p_address_std_node =
        appl_address_std_node::convert_handle(
            p_remote_address);

    appl_ptrdiff_t
        i_recv_result;

    socklen_t
        i_sockaddr_len;

    i_sockaddr_len =
        sizeof(
            p_address_std_node->m_sockaddr);

    i_recv_result =
        recvfrom(
            m_fd,
            p_buf_min,
            appl_buf_len(
                p_buf_min,
                p_buf_max),
            0,
            &(
                p_address_std_node->m_sockaddr.o_sockaddr_base),
            &(
                i_sockaddr_len));

    if (
        -1 != i_recv_result)
    {
        p_address_std_node->m_sockaddr_len =
            i_sockaddr_len;

        *(
            r_count) =
            appl_convert::to_ulong(
                appl_convert::to_unsigned(
                    i_recv_result));

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

} // v_recvfrom()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_socket_std_node.cpp */
