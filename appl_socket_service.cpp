/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_socket_descriptor.h"

#include "appl_socket_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_socket_mgr.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
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
    static_cast<void>(
        p_context_handle);
    static_cast<void>(
        p_socket_descriptor);
    static_cast<void>(
        r_socket_handle);
    return
        appl_status_not_implemented;
} // s_create()

//
//
//
enum appl_status
appl_socket_service::s_send(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf)
{
    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        p_buf);
    return
        appl_status_not_implemented;
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
    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        p_buf);
    return
        appl_status_not_implemented;
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
    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        p_buf);
    static_cast<void>(
        p_remote_address);
    return
        appl_status_not_implemented;
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
    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        p_buf);
    static_cast<void>(
        p_remote_address);
    return
        appl_status_not_implemented;
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
    static_cast<void>(
        p_socket_handle);
    static_cast<void>(
        e_wait_type);
    static_cast<void>(
        i_wait_freq);
    static_cast<void>(
        i_wait_count);
    return
        appl_status_not_implemented;
} // s_wait()

//
//
//
enum appl_status
appl_socket_service::s_cancel(
    struct appl_socket_handle * const
        p_socket_handle)
{
    static_cast<void>(
        p_socket_handle);
    return
        appl_status_not_implemented;
} // s_cancel()

/* end-of-file: appl_socket_service.cpp */
