/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_socket_descriptor.h"

#include "appl_socket_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_socket_mgr.h"

#include "appl_context.h"

#include "appl_socket_node.h"

#include "appl_address_node.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//  Function: s_create
//
//  Description:
//      Create an instance of a socket node.
//
//  Parameters:
//      p_context_handle
//          (input) Library context handle
//
//      p_socket_descriptor
//          (input) Pointer to socket descriptor structure
//
//      r_socket_handle
//          (output) Pointer to returned socket handle
//
// Returns:
//      appl_status_ok on success.
//
enum appl_status
appl_socket_service::s_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_socket_descriptor const * const
        p_socket_descriptor,
    struct appl_socket_handle * * const
        r_socket_handle)
{
    enum appl_status
        e_status;

    // Convert opaque context handle to context object
    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    // Get socket manager from context
    class appl_socket_mgr * const
        p_socket_mgr =
        p_context->m_socket_mgr;

    // Dispatch to socket manager
    e_status =
        p_socket_mgr->v_create_socket(
            p_socket_descriptor,
            reinterpret_cast<class appl_socket_node * *>(
                r_socket_handle));

    return
        e_status;

} // s_create()

//
//  Function: s_send()
//
//  Description:
//      Send a packet to connected address.
//
//  Parameters:
//      p_socket_handle
//          (input) Socket handle
//
//      p_buf
//          (modified) Buffer to send.  Pointers will be updated to reflect
//          actual number of bytes sent.
//
enum appl_status
appl_socket_service::s_send(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf)
{
    enum appl_status
        e_status;

    // Convert socket handle to pointer to socket node
    class appl_socket_node * const
        p_socket_node =
        appl_socket_node::convert_handle(
            p_socket_handle);

    // Dispatch to socket node
    e_status =
        p_socket_node->v_send(
            p_buf);

    return
        e_status;

} // s_send()

//
//
//
enum appl_status
appl_socket_service::s_recv(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf)
{
    enum appl_status
        e_status;

    // Convert socket handle to pointer to socket node
    class appl_socket_node * const
        p_socket_node =
        appl_socket_node::convert_handle(
            p_socket_handle);

    // Dispatch to socket node
    e_status =
        p_socket_node->v_recv(
            p_buf);

    return
        e_status;

} // s_recv()

//
//
//
enum appl_status
appl_socket_service::s_sendto(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf,
    struct appl_address_handle * const
        p_remote_address)
{
    enum appl_status
        e_status;

    // Convert socket handle to pointer to socket node
    class appl_socket_node * const
        p_socket_node =
        appl_socket_node::convert_handle(
            p_socket_handle);

    // Convert address handle to pointer to address node
    class appl_address_node * const
        p_address_node =
        appl_address_node::convert_handle(
            p_remote_address);

    // Dispatch to socket node
    e_status =
        p_socket_node->v_sendto(
            p_buf,
            p_address_node);

    return
        e_status;

} // s_sendto()

//
//
//
enum appl_status
appl_socket_service::s_recvfrom(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf,
    struct appl_address_handle * const
        p_remote_address)
{
    enum appl_status
        e_status;

    // Convert socket handle to pointer to socket node
    class appl_socket_node * const
        p_socket_node =
        appl_socket_node::convert_handle(
            p_socket_handle);

    // Convert address handle to pointer to address node
    class appl_address_node * const
        p_address_node =
        appl_address_node::convert_handle(
            p_remote_address);

    // Dispatch to socket node
    e_status =
        p_socket_node->v_recvfrom(
            p_buf,
            p_address_node);

    return
        e_status;

} // s_recvfrom()

//
//
//
enum appl_status
appl_socket_service::s_wait(
    struct appl_socket_handle * const
        p_socket_handle,
    enum appl_socket_wait_type const
        e_wait_type,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count)
{
    enum appl_status
        e_status;

    // Convert socket handle to pointer to socket node
    class appl_socket_node * const
        p_socket_node =
        appl_socket_node::convert_handle(
            p_socket_handle);

    // Dispatch to socket node
    e_status =
        p_socket_node->v_wait(
            e_wait_type,
            i_wait_freq,
            i_wait_count);

    return
        e_status;

} // s_wait()

/* end-of-file: appl_socket_service.cpp */
