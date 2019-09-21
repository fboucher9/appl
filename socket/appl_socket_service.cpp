/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_socket_descriptor.h>

#include <socket/appl_socket_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_socket_mgr.h>

#include <context/appl_context.h>

#include <socket/appl_socket_node.h>

#include <socket/appl_address_node.h>

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//  Function: s_create
//
//  Description:
//      Create an instance of a socket node.
//
//  Parameters:
//      p_context
//          (input) Library context handle
//
//      p_socket_descriptor
//          (input) Pointer to socket descriptor structure
//
//      r_socket
//          (output) Pointer to returned socket handle
//
// Returns:
//      appl_status_ok on success.
//
enum appl_status
appl_socket_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_socket_property const * const
        p_socket_descriptor,
    struct appl_socket * * const
        r_socket)
{
    enum appl_status
        e_status;

    class appl_socket_mgr *
        p_socket_mgr;

    e_status =
        p_context->v_socket_mgr(
            &(
                p_socket_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        // Dispatch to socket manager
        e_status =
            p_socket_mgr->v_create_socket(
                p_socket_descriptor,
                r_socket);
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_socket_service::s_destroy(
    struct appl_socket * const
        p_socket)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_socket->get_context();

    class appl_socket_mgr *
        p_socket_mgr;

    e_status =
        p_context->v_socket_mgr(
            &(
                p_socket_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_socket_mgr->v_destroy_socket(
                p_socket);
    }

    return
        e_status;

} // s_destroy()

//
//  Function: s_accept()
//
//  Description:
//      Accept a connection from remote machine.
//
//  Parameters:
//      p_socket
//          (input) Socket handle of listen socket.
//
//      r_socket
//          (output) Socket handle of connected remote machine.
//
//      r_address
//          (output) Address of remote machine.
//
enum appl_status
appl_socket_service::s_accept(
    struct appl_socket * const
        p_socket,
    struct appl_socket * * const
        r_socket,
    struct appl_address * * const
        r_address)
{
    enum appl_status
        e_status;

    e_status =
        p_socket->v_accept(
            r_socket,
            r_address);

    return
        e_status;

} // s_accept()

//
//  Function: s_send()
//
//  Description:
//      Send a packet to connected address.
//
//  Parameters:
//      p_socket
//          (input) Socket handle
//
//      p_buf
//          (modified) Buffer to send.  Pointers will be updated to reflect
//          actual number of bytes sent.
//
enum appl_status
appl_socket_service::s_send(
    struct appl_socket * const
        p_socket,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    enum appl_status
        e_status;

    // Dispatch to socket node
    e_status =
        p_socket->v_send(
            p_buf_min,
            p_buf_max,
            r_count);

    return
        e_status;

} // s_send()

//
//
//
enum appl_status
appl_socket_service::s_recv(
    struct appl_socket * const
        p_socket,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    enum appl_status
        e_status;

    // Dispatch to socket node
    e_status =
        p_socket->v_recv(
            p_buf_min,
            p_buf_max,
            r_count);

    return
        e_status;

} // s_recv()

//
//
//
enum appl_status
appl_socket_service::s_sendto(
    struct appl_socket * const
        p_socket,
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

    // Dispatch to socket node
    e_status =
        p_socket->v_sendto(
            p_buf_min,
            p_buf_max,
            r_count,
            p_remote_address);

    return
        e_status;

} // s_sendto()

//
//
//
enum appl_status
appl_socket_service::s_recvfrom(
    struct appl_socket * const
        p_socket,
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

    // Dispatch to socket node
    e_status =
        p_socket->v_recvfrom(
            p_buf_min,
            p_buf_max,
            r_count,
            p_remote_address);

    return
        e_status;

} // s_recvfrom()

//
//
//
enum appl_status
appl_socket_service::s_wait(
    struct appl_socket * const
        p_socket,
    enum appl_socket_wait_type const
        e_wait_type,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count)
{
    enum appl_status
        e_status;

    // Dispatch to socket node
    e_status =
        p_socket->v_wait(
            e_wait_type,
            i_wait_freq,
            i_wait_count);

    return
        e_status;

} // s_wait()

//
//
//
enum appl_status
appl_socket_service::s_poll(
    struct appl_context * const
        p_context,
    struct appl_poll_descriptor const * const
        p_poll_descriptor_min,
    struct appl_poll_descriptor const * const
        p_poll_descriptor_max,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count)
{
    enum appl_status
        e_status;

    class appl_socket_mgr *
        p_socket_mgr;

    e_status =
        p_context->v_socket_mgr(
            &(
                p_socket_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_socket_mgr->v_poll(
                p_poll_descriptor_min,
                p_poll_descriptor_max,
                i_wait_freq,
                i_wait_count);
    }

    return
        e_status;

} // s_poll()

/* end-of-file: appl_socket_service.cpp */
