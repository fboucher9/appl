/* See LICENSE for license details */

/*

Module: appl.h

Description:

    Header file for Application Library (appl).

*/

/* Include guard */
#if defined(INC_APPL_H)
#error include appl.h once
#endif /* #if defined(INC_APPL_H) */

#define INC_APPL_H

/* Detect compiler */

/* Detect cpu */

/* Detect types */
#include "appl_types.h"

/* Configuration */

#define APPL_CONFIG_WITH_DEBUG

#define APPL_CONFIG_WITH_HEAP

#define APPL_CONFIG_WITH_FILE

#define APPL_CONFIG_WITH_THREAD

/* #define APPL_CONFIG_WITH_SOCKET */

/* #define APPL_CONFIG_WITH_CLOCK */

#define APPL_CONFIG_WITH_MAIN

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_list.h"

#include "appl_object_handle.h"

#include "appl_context_handle.h"

#if defined(APPL_CONFIG_WITH_DEBUG)

#include "appl_debug_handle.h"

#endif /* #if defined(APPL_CONFIG_WITH_DEBUG) */

#if defined(APPL_CONFIG_WITH_HEAP)

#include "appl_heap_handle.h"

#endif /* #if defined(APPL_CONFIG_WITH_HEAP) */

#if defined(APPL_CONFIG_WITH_FILE)

#include "appl_file_handle.h"

#endif /* #if defined(APPL_CONFIG_WITH_FILE) */

#if defined(APPL_CONFIG_WITH_THREAD)

#include "appl_thread_descriptor.h"

#include "appl_thread_handle.h"

#include "appl_event_handle.h"

#include "appl_mutex_handle.h"

#endif /* #if defined(APPL_CONFIG_WITH_THREAD) */

#if defined(APPL_CONFIG_WITH_SOCKET)

/* socket address */
struct appl_socket_address_handle;

struct appl_socket_address_descriptor
{
    void *
        p_dummy;

};

struct appl_socket_address_handle
{
    struct appl_object_handle
        o_object_handle;

};

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_socket_address_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_socket_address_descriptor const * const
        p_socket_address_descriptor,
    struct appl_socket_address_handle * * const
        r_socket_address_handle);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* tcp socket */
struct appl_tcp_socket_handle;

struct appl_tcp_socket_descriptor
{
    void *
        p_dummy;

};

struct appl_tcp_socket_handle
{
    struct appl_object_handle
        o_object_handle;

};

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_tcp_socket_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_tcp_socket_descriptor const * const
        p_tcp_socket_descriptor,
    struct appl_tcp_socket_handle * * const
        r_tcp_socket_handle);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* udp socket */
struct appl_udp_socket_handle;

struct appl_udp_socket_descriptor
{
    void *
        p_dummy;

};

struct appl_udp_socket_handle
{
    struct appl_object_handle
        o_object_handle;

};

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_udp_socket_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_udp_socket_descriptor const * const
        p_udp_socket_descriptor,
    struct appl_udp_socket * * const
        p_udp_socket);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

#endif /* #if defined(APPL_CONFIG_WITH_SOCKET) */

#if defined(APPL_CONFIG_WITH_CLOCK)

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_clock_read(
    struct appl_context_handle * const
        p_context_handle,
    unsigned long int const
        i_time_freq,
    unsigned long int * const
        p_time_count);

enum appl_status
appl_clock_delay(
    struct appl_context_handle * const
        p_context_handle,
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

#endif /* #if defined(APPL_CONFIG_WITH_CLOCK) */

#if defined(APPL_CONFIG_WITH_MAIN)

#include "appl_options_descriptor.h"

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

/* extern */
enum appl_status
appl_main(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_options_descriptor const * const
        p_options_descriptor,
    int * const
        r_exit_code);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

#endif /* #if defined(APPL_CONFIG_WITH_MAIN) */

/* end-of-file: appl.h */
