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

/* Header file dependency */
#if ! defined INC_APPL_SOCKET_DESCRIPTOR_H
#error include appl_socket_descriptor.h before
#endif /* #if ! defined INC_APPL_SOCKET_DESCRIPTOR_H */

struct appl_socket_handle;

struct appl_address_handle;

struct appl_socket_descriptor;

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

enum appl_status
appl_socket_wait(
    struct appl_socket_handle * const
        p_socket_handle,
    enum appl_socket_wait_type const
        e_wait_type,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count);

enum appl_status
appl_socket_cancel(
    struct appl_socket_handle * const
        p_socket_handle);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_socket_handle.h */
