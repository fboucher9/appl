/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_socket_descriptor.h"

#include "appl_socket_node.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_socket_node *
    appl_socket_node::convert_handle(
        struct appl_socket_handle * const
            p_socket_handle)
{
    return
        reinterpret_cast<class appl_socket_node *>(
            p_socket_handle);

} // convert_handle()

//
//
//
enum appl_status
appl_socket_node::v_send(
    struct appl_buf * const
        p_buf)
{
    static_cast<void>(
        p_buf);
    return
        appl_status_not_implemented;
} // v_send()

//
//
//
enum appl_status
appl_socket_node::v_recv(
    struct appl_buf * const
        p_buf)
{
    static_cast<void>(
        p_buf);
    return
        appl_status_not_implemented;
}

//
//
//
enum appl_status
appl_socket_node::v_sendto(
    struct appl_buf * const
        p_buf,
    class appl_address_node * const
        p_remote_address)
{
    static_cast<void>(
        p_buf);
    static_cast<void>(
        p_remote_address);
    return
        appl_status_not_implemented;
}

//
//
//
enum appl_status
appl_socket_node::v_recvfrom(
    struct appl_buf * const
        p_buf,
    class appl_address_node * const
        p_remote_address)
{
    static_cast<void>(
        p_buf);
    static_cast<void>(
        p_remote_address);
    return
        appl_status_not_implemented;
}

//
//
//
enum appl_status
appl_socket_node::v_wait(
    enum appl_socket_wait_type const
        e_wait_type,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count)
{
    static_cast<void>(
        e_wait_type);
    static_cast<void>(
        i_wait_freq);
    static_cast<void>(
        i_wait_count);
    return
        appl_status_not_implemented;
}

//
//
//
enum appl_status
appl_socket_node::v_cancel(void)
{
    return
        appl_status_not_implemented;
}

//
//
//
appl_socket_node::appl_socket_node() :
    appl_object()
{
}

//
//
//
appl_socket_node::~appl_socket_node()
{
}

/* end-of-file: appl_socket_node.cpp */
