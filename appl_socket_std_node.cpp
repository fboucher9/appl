/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <unistd.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_socket_descriptor.h>

#include <appl_socket_node.h>

#include <appl_socket_std_node.h>

#include <appl_address_node.h>

#include <appl_address_std_node.h>

#include <appl_address_handle.h>

#include <appl_address_property.h>

#include <appl_unused.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_socket_std_node::s_create(
        struct appl_context * const
            p_context,
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
        appl_object::s_create (
            p_context,
            (&
                appl_socket_std_node::s_new),
            (&
                appl_socket_std_node::init),
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
appl_socket_std_node::appl_socket_std_node() :
    appl_socket(),
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
void
    appl_socket_std_node::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_socket_std_node;

} // s_new()

//
//
//
enum appl_status
appl_socket_std_node::init(
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

} // init()

//
//
//
enum appl_status
appl_socket_std_node::init_fd(
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

} // init_fd()

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
        appl_socket_protocol_tcp_stream
        == e_protocol)
    {
        int const
            i_socket_result =
            static_cast<int>(
                socket(
                    AF_INET,
                    SOCK_STREAM,
                    0));

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
            static_cast<class appl_address_std_node const *>(
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
appl_socket_std_node::init_connect(
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
            static_cast<class appl_address_std_node const *>(
                p_connect_address);

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
enum appl_status
appl_socket_std_node::init_listen(
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
                static_cast<int>(
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
appl_socket_std_node::v_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        -1 != m_fd)
    {
        close(
            m_fd);

        m_fd =
            -1;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

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
                static_cast<class appl_address_std_node *>(
                    p_address);

            socklen_t
                i_address_length;

            i_address_length =
                static_cast<socklen_t>(
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
                // create a socket node to hold this new file descriptor
                class appl_socket_std_node *
                    p_socket_std_node;

                e_status =
                    appl_object::s_create(
                        m_context,
                        (&
                            appl_socket_std_node::s_new),
                        (&
                            appl_socket_std_node::init_fd),
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
            }
        }

        appl_address_property_destroy(
            p_address_property);
    }

    return
        appl_status_not_implemented;

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

    appl_unused(
        p_buf_min,
        p_buf_max,
        r_count);

    e_status =
        appl_status_not_implemented;

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

    appl_unused(
        p_buf_min,
        p_buf_max,
        r_count);

    e_status =
        appl_status_not_implemented;

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

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_socket_std_node.cpp */
