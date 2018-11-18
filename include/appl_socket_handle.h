/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_SOCKET_HANDLE_H
#error include appl_socket_handle.h once
#endif /* #if defined INC_APPL_SOCKET_HANDLE_H */

#define INC_APPL_SOCKET_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_SOCKET_DESCRIPTOR_H
#error include appl_socket_descriptor.h before
#endif /* #if ! defined INC_APPL_SOCKET_DESCRIPTOR_H */

struct appl_object;

struct appl_socket;

struct appl_address;

struct appl_socket_property;

struct appl_poll_descriptor;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_socket_create(
    struct appl_context * const
        p_context,
    struct appl_socket_property const * const
        p_socket_descriptor,
    struct appl_socket * * const
        r_socket);

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

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_socket_handle.h */
