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

/* Wait for send, sendto to be ready */
/* Wait for connect to be completed on connect socket */
/* Wait for accept to be ready on listen socket */
/* Wait for accept to be completed on accept socket */
#define APPL_SOCKET_WAIT_SEND \
    1ul

/* Wait for recv or recvfrom to be ready */
#define APPL_SOCKET_WAIT_RECV \
    2ul

enum appl_status
appl_socket_wait(
    struct appl_socket_handle * const
        p_socket_handle,
    unsigned int const
        i_wait_flags,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count);

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
