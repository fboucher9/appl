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

/* Socket option unique identifiers */
enum appl_socket_option_id
{
    /* Select UDP type with SOCK_DGRAM option */
    /* Default is to select TCP type with SOCK_STREAM option */
    appl_socket_option_id_is_udp = 1,

    /* Provide an address for call to bind() */
    /* Default is an unbound socket, kernel will select interface and port */
    appl_socket_option_id_bind_address = 2,

    /* Provide an address for call to connect() */
    appl_socket_option_id_connect_address = 3,

    /* Provide number for call to listen() */
    appl_socket_option_id_listen_count = 4,

    /* Provide an empty address for call to accept() */
    appl_socket_option_id_accept_address = 5,

    /* Set recv timeout socket option */
    appl_socket_option_id_recv_timeout = 6,

    /* Set send timeout socket option */
    appl_socket_option_id_send_timeout = 7,

    /* Provide an address for add membership */
    appl_socket_option_id_join_address = 8,

    /* Provide an interface for add membership */
    appl_socket_option_id_join_interface = 9,

    /* Provide recv buffer size option */
    appl_socket_option_id_recv_buffer = 10,

    /* Provide send buffer size option */
    appl_socket_option_id_send_buffer = 11

}; /* enum appl_socket_option_id */

/* Socket option storage types */
enum appl_socket_option_type
{
    /* Option is a pointer to an address handle */
    appl_socket_option_type_address_handle = 1,

    /* Option is a pointer to a socket handle */
    appl_socket_option_type_socket_handle = 2,

    /* Option is an unsigned integer */
    appl_socket_option_type_unsigned_integer = 3,

    /* Option is a signed integer */
    appl_socket_option_type_signed_integer = 4,

    /* Option is a boolean */
    appl_socket_option_type_boolean = 5

}; /* appl_socket_option_type */

/*

Structure: appl_socket_option

Description:
    Description of a single socket option.

*/
struct appl_socket_option
{
    enum appl_socket_option_id
        e_id;

    enum appl_socket_option_type
        e_type;

    unsigned int
        ui_padding[2u];

    /* -- */

    union appl_socket_option_data
    {
        struct appl_address_handle *
            p_address_handle;

        struct appl_socket_handle *
            p_socket_handle;

        unsigned long int
            u_value;

        signed long int
            i_value;

        unsigned char
            b_value;

    } u;

}; /* struct appl_socket_option */

/* socket descriptor */
struct appl_socket_descriptor
{
    struct appl_socket_option const *
        p_option_min;

    struct appl_socket_option const *
        p_option_max;

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
