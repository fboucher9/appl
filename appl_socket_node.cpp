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
enum appl_status
appl_socket::v_send(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    static_cast<void>(
        p_buf_min);
    static_cast<void>(
        p_buf_max);
    static_cast<void>(
        r_count);
    return
        appl_status_not_implemented;
} // v_send()

//
//
//
enum appl_status
appl_socket::v_recv(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    static_cast<void>(
        p_buf_min);
    static_cast<void>(
        p_buf_max);
    static_cast<void>(
        r_count);
    return
        appl_status_not_implemented;
} // v_recv()

//
//
//
enum appl_status
appl_socket::v_sendto(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count,
    struct appl_address * const
        p_remote_address)
{
    static_cast<void>(
        p_buf_min);
    static_cast<void>(
        p_buf_max);
    static_cast<void>(
        r_count);
    static_cast<void>(
        p_remote_address);
    return
        appl_status_not_implemented;
} // v_sendto()

//
//
//
enum appl_status
appl_socket::v_recvfrom(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count,
    struct appl_address * const
        p_remote_address)
{
    static_cast<void>(
        p_buf_min);
    static_cast<void>(
        p_buf_max);
    static_cast<void>(
        r_count);
    static_cast<void>(
        p_remote_address);
    return
        appl_status_not_implemented;
} // v_recvfrom()

//
//
//
enum appl_status
appl_socket::v_wait(
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
appl_socket::appl_socket() :
    appl_object()
{
}

//
//
//
appl_socket::~appl_socket()
{
}

/* end-of-file: appl_socket_node.cpp */
