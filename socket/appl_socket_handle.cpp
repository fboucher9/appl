/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <socket/appl_socket_descriptor.h>

#include <socket/appl_socket_handle.h>

#include <socket/appl_socket_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_socket_node.h>

/*

*/
enum appl_status
appl_socket_create(
    struct appl_context * const
        p_context,
    struct appl_socket_property const * const
        p_socket_descriptor,
    struct appl_socket * * const
        r_socket)
{
    enum appl_status
        e_status;

    e_status =
        appl_socket_service::s_create(
            p_context,
            p_socket_descriptor,
            r_socket);

    return
        e_status;

} /* appl_socket_create() */

/*

*/
enum appl_status
appl_socket_destroy(
    struct appl_socket * const
        p_socket)
{
    return
        appl_socket_service::s_destroy(
            p_socket);

} /* _destroy() */

/*

*/
struct appl_object *
appl_socket_parent(
    struct appl_socket * const
        p_socket)
{
    return
        p_socket;

} /* parent() */

/*

*/
struct appl_object const *
appl_socket_const_parent(
    struct appl_socket const * const
        p_socket)
{
    return
        p_socket;

} /* const_parent() */

/*

*/
enum appl_status
appl_socket_accept(
    struct appl_socket * const
        p_socket,
    struct appl_socket * * const
        r_socket,
    struct appl_address * * const
        r_address)
{
    return
        appl_socket_service::s_accept(
            p_socket,
            r_socket,
            r_address);

} /* accept() */

/*

*/
enum appl_status
appl_socket_send(
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

    e_status =
        appl_socket_service::s_send(
            p_socket,
            p_buf_min,
            p_buf_max,
            r_count);

    return
        e_status;

} /* appl_socket_send() */

/*

*/
enum appl_status
appl_socket_recv(
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

    e_status =
        appl_socket_service::s_recv(
            p_socket,
            p_buf_min,
            p_buf_max,
            r_count);

    return
        e_status;

} /* appl_socket_recv() */

/*

*/
enum appl_status
appl_socket_sendto(
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

    e_status =
        appl_socket_service::s_sendto(
            p_socket,
            p_buf_min,
            p_buf_max,
            r_count,
            p_remote_address);

    return
        e_status;

} /* appl_socket_sendto() */

/*

*/
enum appl_status
appl_socket_recvfrom(
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

    e_status =
        appl_socket_service::s_recvfrom(
            p_socket,
            p_buf_min,
            p_buf_max,
            r_count,
            p_remote_address);

    return
        e_status;

} /* appl_socket_recvfrom() */

/*

*/
enum appl_status
appl_socket_wait(
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

    e_status =
        appl_socket_service::s_wait(
            p_socket,
            e_wait_type,
            i_wait_freq,
            i_wait_count);

    return
        e_status;

} /* appl_socket_wait() */

enum appl_status
appl_socket_poll(
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

    e_status =
        appl_socket_service::s_poll(
            p_context,
            p_poll_descriptor_min,
            p_poll_descriptor_max,
            i_wait_freq,
            i_wait_count);

    return
        e_status;

} /* appl_socket_poll() */

/* end-of-file: appl_socket_handle.cpp */
