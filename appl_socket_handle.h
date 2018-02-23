/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_SOCKET_HANDLE_H
#error include appl_socket_handle.h once
#endif /* #if defined INC_APPL_SOCKET_HANDLE_H */

#define INC_APPL_SOCKET_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_HANDLE_H
#error include appl_object_handle.h before
#endif /* #if ! defined INC_APPL_OBJECT_HANDLE_H */

struct appl_socket_handle;

struct appl_address_handle;

struct appl_socket_descriptor;

/* socket descriptor */
struct appl_socket_descriptor
{
    struct appl_address_handle *
        p_bind_address;

    struct appl_address_handle *
        p_connect_address;

    /* -- */

    struct appl_address_handle *
        p_join_address;

    struct appl_address_handle *
        p_join_interface;

    /* -- */

    struct appl_socket_handle *
        p_server_socket;

    struct appl_address_handle *
        p_accept_address;

    /* -- */

    unsigned long int
        i_recv_timeout;

    unsigned long int
        i_send_timeout;

    /* -- */

    unsigned long int
        i_listen_value;

    unsigned long int
        ul_padding[1u];

    /* -- */

    unsigned char
        b_udp;

    unsigned char
        b_bind;

    unsigned char
        b_connect;

    unsigned char
        b_listen;

    unsigned char
        b_accept;

    unsigned char
        b_accept_address;

    unsigned char
        b_recv_timeout;

    unsigned char
        b_send_timeout;

    /* -- */

    unsigned char
        b_join_address;

    unsigned char
        b_join_interface;

    unsigned char
        uc_padding[6u];

}; /* struct appl_socket_descriptor */

struct appl_socket_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_socket_handle */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_socket_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_socket_descriptor const * const
        p_socket_descriptor,
    struct appl_socket_handle * * const
        r_socket_handle);

enum appl_status
appl_socket_send(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf);

enum appl_status
appl_socket_recv(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf);

enum appl_status
appl_socket_sendto(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf,
    struct appl_address_handle * const
        p_remote_address);

enum appl_status
appl_socket_recvfrom(
    struct appl_socket_handle * const
        p_socket_handle,
    struct appl_buf * const
        p_buf,
    struct appl_address_handle * const
        p_remote_address);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_socket_handle.h */