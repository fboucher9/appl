/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_socket_handle.h"

#include "appl_socket_service.h"

/*

*/
enum appl_status
appl_socket_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_socket_descriptor const * const
        p_socket_descriptor,
    struct appl_socket_handle * * const
        r_socket_handle)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_context_handle);
    static_cast<void>(
        p_socket_descriptor);
    static_cast<void>(
        r_socket_handle);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_socket_create() */

/*

*/
enum appl_status
appl_socket_wait(
    struct appl_socket_handle * const
        p_socket_handle,
    unsigned int const
        i_wait_flags,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        i_wait_flags);
    static_cast<void>(
        i_wait_freq);
    static_cast<void>(
        i_wait_count);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_socket_wait() */

/*

*/
enum appl_status
appl_socket_send(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        p_buf);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_socket_send() */

/*

*/
enum appl_status
appl_socket_recv(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        p_buf);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_socket_recv() */

/*

*/
enum appl_status
appl_socket_sendto(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf,
    struct appl_address_handle * const
        p_remote_address)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        p_buf);
    static_cast<void>(
        p_remote_address);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_socket_sendto() */

enum appl_status
appl_socket_recvfrom(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf,
    struct appl_address_handle * const
        p_remote_address)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        p_buf);
    static_cast<void>(
        p_remote_address);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_socket_recvfrom() */

/* end-of-file: appl_socket_handle.cpp */
