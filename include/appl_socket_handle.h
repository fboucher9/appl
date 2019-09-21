/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_socket_handle_h
{
    inc_appl_socket_handle_h =
        /* Header file dependency */
        inc_appl_socket_descriptor_h
        + inc_appl_status_h
};

#include <appl_extern_c_begin.h>

enum appl_status
appl_socket_create(
    struct appl_context * const
        p_context,
    struct appl_socket_property const * const
        p_socket_descriptor,
    struct appl_socket * * const
        r_socket);

enum appl_status
appl_socket_destroy(
    struct appl_socket * const
        p_socket);

struct appl_object *
appl_socket_parent(
    struct appl_socket * const
        p_socket);

struct appl_object const *
appl_socket_const_parent(
    struct appl_socket const * const
        p_socket);

enum appl_status
appl_socket_accept(
    struct appl_socket * const
        p_socket,
    struct appl_socket * * const
        r_socket,
    struct appl_address * * const
        r_address);

enum appl_status
appl_socket_send(
    struct appl_socket * const
        p_socket,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count);

enum appl_status
appl_socket_recv(
    struct appl_socket * const
        p_socket,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count);

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
        p_remote_address);

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
        p_remote_address);

enum appl_status
appl_socket_wait(
    struct appl_socket * const
        p_socket,
    enum appl_socket_wait_type const
        e_wait_type,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count);

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
        i_wait_count);

#include <appl_extern_c_end.h>

/* end-of-file: appl_socket_handle.h */
