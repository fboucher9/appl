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
struct appl_socket_descriptor;

/* Flags to select descriptor fields */

/* Select UDP type with SOCK_DGRAM option */
/* Default is to select TCP type with SOCK_STREAM option */
#define APPL_SOCKET_FLAG_UDP_DGRAM \
    0x00000001ul

/* Provide an address for call to bind() */
/* Default is an unbound socket, kernel will select interface and port */
#define APPL_SOCKET_FLAG_BIND_ADDRESS \
    0x00000002ul

/* Provide an address for call to connect() */
#define APPL_SOCKET_FLAG_CONNECT_ADDRESS \
    0x00000004ul

/* Provide number for call to listen() */
#define APPL_SOCKET_FLAG_LISTEN \
    0x00000008ul

/* Provide an empty address for call to accept() */
#define APPL_SOCKET_FLAG_ACCEPT_ADDRESS \
    0x00000010ul

/* Set recv timeout socket option */
#define APPL_SOCKET_FLAG_RECV_TIMEOUT \
    0x00000020ul

/* Set send timeout socket option */
#define APPL_SOCKET_FLAG_SEND_TIMEOUT \
    0x00000040ul

/* Provide an address for add membership */
#define APPL_SOCKET_FLAG_JOIN_ADDRESS \
    0x00000080ul

/* Provide an interface for add membership */
#define APPL_SOCKET_FLAG_JOIN_INTERFACE \
    0x00000100ul

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
        i_flags;

}; /* struct appl_socket_descriptor */

/* Options for appl_socket_wait */
enum appl_socket_wait_type
{
    /* wait for connect to be completed */
    appl_socket_wait_connect = 1,

    /* wait for accept to be available */
    appl_socket_wait_accept = 2,

    /* wait for send or sendto */
    appl_socket_wait_send = 3,

    /* wait for recv or recvfrom */
    appl_socket_wait_recv = 4

}; /* enum appl_socket_wait_type */

/* end-of-file: appl_socket_descriptor.h */
