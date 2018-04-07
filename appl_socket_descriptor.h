/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_SOCKET_DESCRIPTOR_H
#error include appl_socket_descriptor.h once
#endif /* #if defined INC_APPL_SOCKET_DESCRIPTOR_H */

#define INC_APPL_SOCKET_DESCRIPTOR_H

/* Predefine */
struct appl_address_handle;

/* Predefine */
struct appl_socket_handle;

/* Predefine */
struct appl_property_handle;

/* Protocol values */
enum appl_socket_protocol
{
    /* Default is TCP with SOCK_STREAM */
    appl_socket_protocol_tcp_stream = 0,

    /* Select UDP with SOCK_DGRAM */
    appl_socket_protocol_udp_dgram = 1

}; /* enum appl_socket_protocol */

/* Options for appl_socket_wait */
enum appl_socket_wait_type
{
    /* wait for send or sendto */
    appl_socket_wait_send = 1,

    /* wait for recv or recvfrom */
    appl_socket_wait_recv = 2

}; /* enum appl_socket_wait_type */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_socket_property_create(
    struct appl_context_handle * const
       p_context_handle,
    struct appl_property_handle * * const
        r_property_handle);

enum appl_status
appl_socket_property_set_protocol(
    struct appl_property_handle * const
        p_property_handle,
    enum appl_socket_protocol const
        e_socket_protocol);

enum appl_status
appl_socket_property_set_bind_address(
    struct appl_property_handle * const
        p_property_handle,
    struct appl_address_handle * const
        p_bind_address_handle);

enum appl_status
appl_socket_property_set_connect_address(
    struct appl_property_handle * const
        p_property_handle,
    struct appl_address_handle * const
        p_connect_address_handle);

enum appl_status
appl_socket_property_set_listen_count(
    struct appl_property_handle * const
        p_property_handle,
    unsigned long int const
        i_listen_count);

enum appl_status
appl_socket_property_set_accept_address(
    struct appl_property_handle * const
        p_property_handle,
    struct appl_address_handle * const
        p_accept_address_handle);

enum appl_status
appl_socket_property_set_accept_socket(
    struct appl_property_handle * const
        p_property_handle,
    struct appl_socket_handle * const
        p_accept_socket_handle);

enum appl_status
appl_socket_property_set_recv_timeout(
    struct appl_property_handle * const
        p_property_handle,
    unsigned long int const
        i_recv_timeout);

enum appl_status
appl_socket_property_set_send_timeout(
    struct appl_property_handle * const
        p_property_handle,
    unsigned long int const
        i_send_timeout);

enum appl_status
appl_socket_property_set_recv_buffer(
    struct appl_property_handle * const
        p_property_handle,
    unsigned long int const
        i_recv_buffer);

enum appl_status
appl_socket_property_set_send_buffer(
    struct appl_property_handle * const
        p_property_handle,
    unsigned long int const
        i_send_buffer);

enum appl_status
appl_socket_property_set_connect_timeout(
    struct appl_property_handle * const
        p_property_handle,
    unsigned long int const
        i_connect_timeout);

enum appl_status
appl_socket_property_set_accept_timeout(
    struct appl_property_handle * const
        p_property_handle,
    unsigned long int const
        i_accept_timeout);

enum appl_status
appl_socket_property_set_join_address(
    struct appl_property_handle * const
        p_property_handle,
    struct appl_address_handle * const
        p_join_address_handle);

enum appl_status
appl_socket_property_set_join_interface(
    struct appl_property_handle * const
        p_property_handle,
    struct appl_address_handle * const
        p_interface_address_handle);

enum appl_status
appl_socket_property_get_protocol(
    struct appl_property_handle const * const
        p_property_handle,
    enum appl_socket_protocol * const
        r_socket_protocol);

enum appl_status
appl_socket_property_get_bind_address(
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_address_handle * * const
        r_bind_address_handle);

enum appl_status
appl_socket_property_get_connect_address(
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_address_handle * * const
        r_connect_address_handle);

enum appl_status
appl_socket_property_get_listen_count(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned long int * const
        r_listen_count);

enum appl_status
appl_socket_property_get_accept_address(
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_address_handle * * const
        r_accept_address_handle);

enum appl_status
appl_socket_property_get_accept_socket(
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_socket_handle * * const
        r_accept_socket_handle);

enum appl_status
appl_socket_property_get_recv_timeout(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned long int * const
        r_recv_timeout);

enum appl_status
appl_socket_property_get_send_timeout(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned long int * const
        r_send_timeout);

enum appl_status
appl_socket_property_get_recv_buffer(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned long int * const
        r_recv_buffer);

enum appl_status
appl_socket_property_get_send_buffer(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned long int * const
        r_send_buffer);

enum appl_status
appl_socket_property_get_connect_timeout(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned long int * const
        r_connect_timeout);

enum appl_status
appl_socket_property_get_accept_timeout(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned long int * const
        r_accept_timeout);

enum appl_status
appl_socket_property_get_join_address(
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_address_handle * * const
        r_join_address_handle);

enum appl_status
appl_socket_property_get_join_interface(
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_address_handle * * const
        r_interface_address_handle);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_socket_descriptor.h */
