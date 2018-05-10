/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_SOCKET_DESCRIPTOR_H
#error include appl_socket_descriptor.h once
#endif /* #if defined INC_APPL_SOCKET_DESCRIPTOR_H */

#define INC_APPL_SOCKET_DESCRIPTOR_H

/* Predefine */
struct appl_address;

/* Predefine */
struct appl_socket;

/* Predefine */
struct appl_socket_property;

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
    struct appl_context * const
        p_context,
    struct appl_socket_property * * const
        r_socket_property);

enum appl_status
appl_socket_property_destroy(
    struct appl_socket_property * const
        p_socket_property);

struct appl_property *
appl_socket_property_parent(
    struct appl_socket_property * const
        p_socket_property);

struct appl_property const *
appl_socket_property_const_parent(
    struct appl_socket_property const * const
        p_socket_property);

enum appl_status
appl_socket_property_set_protocol(
    struct appl_socket_property * const
        p_socket_property,
    enum appl_socket_protocol const
        e_socket_protocol);

enum appl_status
appl_socket_property_set_bind_address(
    struct appl_socket_property * const
        p_socket_property,
    struct appl_address const * const
        p_bind_address);

enum appl_status
appl_socket_property_set_connect_address(
    struct appl_socket_property * const
        p_socket_property,
    struct appl_address const * const
        p_connect_address);

enum appl_status
appl_socket_property_set_listen_count(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_listen_count);

enum appl_status
appl_socket_property_set_recv_timeout(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_recv_timeout);

enum appl_status
appl_socket_property_set_send_timeout(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_send_timeout);

enum appl_status
appl_socket_property_set_recv_buffer(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_recv_buffer);

enum appl_status
appl_socket_property_set_send_buffer(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_send_buffer);

enum appl_status
appl_socket_property_set_connect_timeout(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_connect_timeout);

enum appl_status
appl_socket_property_set_accept_timeout(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_accept_timeout);

enum appl_status
appl_socket_property_set_join_address(
    struct appl_socket_property * const
        p_socket_property,
    struct appl_address const * const
        p_join_address);

enum appl_status
appl_socket_property_set_join_interface(
    struct appl_socket_property * const
        p_socket_property,
    struct appl_address const * const
        p_interface_address);

enum appl_status
appl_socket_property_get_protocol(
    struct appl_socket_property const * const
        p_socket_property,
    enum appl_socket_protocol * const
        r_socket_protocol);

enum appl_status
appl_socket_property_get_bind_address(
    struct appl_socket_property const * const
        p_socket_property,
    struct appl_address const * * const
        r_bind_address);

enum appl_status
appl_socket_property_get_connect_address(
    struct appl_socket_property const * const
        p_socket_property,
    struct appl_address const * * const
        r_connect_address);

enum appl_status
appl_socket_property_get_listen_count(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_listen_count);

enum appl_status
appl_socket_property_get_recv_timeout(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_recv_timeout);

enum appl_status
appl_socket_property_get_send_timeout(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_send_timeout);

enum appl_status
appl_socket_property_get_recv_buffer(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_recv_buffer);

enum appl_status
appl_socket_property_get_send_buffer(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_send_buffer);

enum appl_status
appl_socket_property_get_connect_timeout(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_connect_timeout);

enum appl_status
appl_socket_property_get_accept_timeout(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_accept_timeout);

enum appl_status
appl_socket_property_get_join_address(
    struct appl_socket_property const * const
        p_socket_property,
    struct appl_address const * * const
        r_join_address);

enum appl_status
appl_socket_property_get_join_interface(
    struct appl_socket_property const * const
        p_socket_property,
    struct appl_address const * * const
        r_interface_address);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_socket_descriptor.h */
