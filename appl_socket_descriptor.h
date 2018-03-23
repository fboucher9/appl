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
    /* Select 0 for TCP with SOCK_STREAM,
              1 for UDP with SOCK_DGRAM */
    /* Default is to select TCP type with SOCK_STREAM option */
    appl_socket_option_id_protocol = 1,

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
    appl_socket_option_id_send_buffer = 11,

    /* Set timeout for call to connect() */
    appl_socket_option_id_connect_timeout = 12,

    /* Set timeout for call to accept() */
    appl_socket_option_id_accept_timeout = 13

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

    /* Option is an unsigned fraction */
    appl_socket_option_type_unsigned_fraction = 5,

    /* Option is a signed fraction */
    appl_socket_option_type_signed_fraction = 6

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

#if 0 /* sizeof int == 2 */
    unsigned int
        ui_padding[2u];
#endif /* sizeof int == 2 */

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

        struct appl_socket_option_unsigned_fraction
        {
            unsigned long int
                u_num;

            unsigned long int
                u_den;

        } o_unsigned_fraction;

        struct appl_socket_option_signed_fraction
        {
            signed long int
                i_num;

            signed long int
                i_den;

        } o_signed_fraction;

    } o_data;

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
    /* wait for send or sendto */
    appl_socket_wait_send = 1,

    /* wait for recv or recvfrom */
    appl_socket_wait_recv = 2

}; /* enum appl_socket_wait_type */

/* end-of-file: appl_socket_descriptor.h */
