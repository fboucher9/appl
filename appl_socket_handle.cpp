/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_socket_descriptor.h"

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

    e_status =
        appl_socket_service::s_create(
            p_context_handle,
            p_socket_descriptor,
            r_socket_handle);

    return
        e_status;

} /* appl_socket_create() */

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

    e_status =
        appl_socket_service::s_send(
            p_socket_handle,
            p_buf);

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

    e_status =
        appl_socket_service::s_recv(
            p_socket_handle,
            p_buf);

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

    e_status =
        appl_socket_service::s_sendto(
            p_socket_handle,
            p_buf,
            p_remote_address);

    return
        e_status;

} /* appl_socket_sendto() */

/*

*/
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

    e_status =
        appl_socket_service::s_recvfrom(
            p_socket_handle,
            p_buf,
            p_remote_address);

    return
        e_status;

} /* appl_socket_recvfrom() */

/*

*/
enum appl_status
appl_socket_wait(
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

    e_status =
        appl_socket_service::s_wait(
            p_socket_handle,
            e_wait_type,
            i_wait_freq,
            i_wait_count);

    return
        e_status;

} /* appl_socket_wait() */

/* end-of-file: appl_socket_handle.cpp */
