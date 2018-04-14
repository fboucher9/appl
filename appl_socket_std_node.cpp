/* See LICENSE for license details */

/*

*/

#include <sys/socket.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_socket_descriptor.h>

#include <appl_socket_node.h>

#include <appl_socket_std_node.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_socket_std_node::s_create(
        class appl_context * const
            p_context,
        struct appl_property_handle const * const
            p_socket_descriptor,
        class appl_socket_node * * const
            r_socket_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_socket_std_node),
            &(
                appl_socket_std_node::s_new),
            p_socket_descriptor,
            r_socket_node);

    return
        e_status;

} // s_create()

//
//
//
appl_socket_std_node::appl_socket_std_node() :
    appl_socket_node(),
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
    void const * const
        p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_property_handle const * const
        p_socket_descriptor =
        static_cast<struct appl_property_handle const *>(
            p_descriptor);

    static_cast<void>(
        p_socket_descriptor);

    // call socket()
    enum appl_socket_protocol
        e_protocol = appl_socket_protocol_tcp_stream;

    appl_socket_property_get_protocol(
        p_socket_descriptor,
        &(
            e_protocol));

    int
        fd;

    if (
        appl_socket_protocol_tcp_stream == e_protocol)
    {
        fd =
            socket(
                AF_INET,
                SOCK_STREAM,
                0);
    }
    else
    {
    }

    static_cast<void>(
        fd);

    // call bind()

    // call connect()

    // call listen()

    // call accept()

    e_status =
        appl_status_fail;

    return
        e_status;

} // init()

//
//
//
enum appl_status
appl_socket_std_node::cleanup(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
appl_socket_std_node::v_send(
    struct appl_buf * const
        p_buf)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_buf);

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
    struct appl_buf * const
        p_buf)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_buf);

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
    struct appl_buf * const
        p_buf,
    class appl_address_node * const
        p_remote_address)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_buf);
    static_cast<void>(
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
    struct appl_buf * const
        p_buf,
    class appl_address_node * const
        p_remote_address)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_buf);
    static_cast<void>(
        p_remote_address);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_recvfrom()

/* end-of-file: appl_socket_std_node.cpp */
