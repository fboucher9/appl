/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <winsock2.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_socket_descriptor.h>

#include <appl_socket_node.h>

#include <appl_socket_w32_node.h>

#include <appl_address_node.h>

#include <appl_address_std_node.h>

#include <appl_unused.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_socket_w32_node::s_create(
        struct appl_context * const
            p_context,
        struct appl_property const * const
            p_socket_descriptor,
        struct appl_socket * * const
            r_socket)
{
    enum appl_status
        e_status;

    class appl_socket_w32_node *
        p_socket_w32_node;

    e_status =
        appl_object::s_create (
            p_context,
            (&
                appl_socket_w32_node::s_new),
            (&
                appl_socket_w32_node::init),
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
void
    appl_socket_w32_node::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_socket_w32_node;

} // s_new()

//
//
//
enum appl_status
appl_socket_w32_node::init(
    struct appl_property const * const
        p_socket_descriptor)
{
    enum appl_status
        e_status;

    appl_unused(
        p_socket_descriptor);

    // call socket()
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

    SOCKET
        fd;

    if (
        appl_socket_protocol_tcp_stream == e_protocol)
    {
        fd =
            static_cast<SOCKET>(
                socket(
                    AF_INET,
                    SOCK_STREAM,
                    0));

        if (
            INVALID_SOCKET != fd)
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

        fd =
            INVALID_SOCKET;
    }

    // call bind()
    if (
        appl_status_ok
        == e_status)
    {
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
                    fd,
                    reinterpret_cast<struct sockaddr const *>(
                        &(
                            p_address_std_node->m_sockaddr.o_sockaddr_in)),
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
    }

    // call connect()
    if (
        appl_status_ok
        == e_status)
    {
    }

    // call listen()
    if (
        appl_status_ok
        == e_status)
    {
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
                    fd,
                    static_cast<int>(
                        i_listen_count));

            if (
                0
                == i_listen_result)
            {
            }
            else
            {
                e_status =
                    appl_status_fail;
            }
        }
    }

    // store fd
    if (
        appl_status_ok
        == e_status)
    {
        m_fd =
            fd;
    }

    if (
        appl_status_ok
        != e_status)
    {
        if (
            INVALID_SOCKET != fd)
        {
            closesocket(
                fd);
        }
    }

    return
        e_status;

} // init()

//
//
//
enum appl_status
appl_socket_w32_node::v_cleanup(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

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
