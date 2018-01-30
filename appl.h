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

/* #define APPL_CONFIG_WITH_HEAP */

/* #define APPL_CONFIG_WITH_FILE */

/* #define APPL_CONFIG_WITH_THREAD */

/* #define APPL_CONFIG_WITH_SOCKET */

/* #define APPL_CONFIG_WITH_CLOCK */

#define APPL_CONFIG_WITH_MAIN

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_list.h"

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

/*

*/

struct appl_object_handle;

struct appl_object_handle
{
    void *
        reserved;

};

enum appl_status
appl_object_destroy(
    struct appl_object_handle * const
        p_object);

/*

*/
struct appl_context_handle;

struct appl_context_descriptor
{
    char const * const *
        p_arg_min;

    char const * const *
        p_arg_max;

};

struct appl_context_handle
{
    struct appl_object_handle
        o_object_handle;

};

enum appl_status
appl_context_create(
    struct appl_context_descriptor const * const
        p_client_descriptor,
    struct appl_context_handle * * const
        r_context_handle);

#if defined(APPL_CONFIG_WITH_HEAP)

/*

*/

enum appl_status
appl_heap_alloc(
    struct appl_context_handle * const
        p_context,
    struct appl_buf * const
        p_buf,
    unsigned long int const
        i_length);

enum appl_status
appl_heap_free(
    struct appl_context_handle * const
        p_context,
    struct appl_buf * const
        p_buf);

enum appl_status
appl_heap_realloc(
    struct appl_context_handle * const
        p_context,
    struct appl_buf * const
        p_buf,
    unsigned long int const
        i_length);

#endif /* #if defined(APPL_CONFIG_WITH_HEAP) */

#if defined(APPL_CONFIG_WITH_FILE)

enum appl_file_type
{
    appl_file_type_stdin = 1,

    appl_file_type_stdout = 2,

    appl_file_type_stderr = 3,

    appl_file_type_disk = 4

};

enum appl_file_mode
{
    appl_file_mode_read = 1,

    appl_file_mode_write = 2,

    appl_file_mode_append = 3

};

struct appl_file;

struct appl_file_descriptor
{
    struct appl_buf
        o_name;

    enum appl_file_type
        e_type;

    enum appl_file_mode
        e_mode;

}; /* struct appl_file_descriptor */

struct appl_file_handle
{
    struct appl_object_handle
        o_object_handle;

};

enum appl_status
appl_file_create(
    struct appl_context_handle * const
        p_context,
    struct appl_file_descriptor const * const
        p_file_descriptor,
    struct appl_file * * const
        p_file);

enum appl_status
appl_file_read(
    struct appl_file * const
        p_file,
    unsigned char * const
        p_buffer,
    unsigned long int const
        i_buffer_max_length,
    unsigned long int * const
        p_actual_length);

enum appl_status
appl_file_write(
    struct appl_file * const
        p_file,
    unsigned char const * const
        p_buffer,
    unsigned long int const
        i_buffer_max_length,
    unsigned long int * const
        p_actual_length);

#endif /* #if defined(APPL_CONFIG_WITH_FILE) */

#if defined(APPL_CONFIG_WITH_THREAD)

struct appl_thread_handle;

typedef
void *
(appl_thread_callback)(
    struct appl_context_handle * const
        p_context,
    struct appl_thread_handle * const
        p_thread,
    void * const
        p_thread_context);

struct appl_thread_descriptor
{
    appl_thread_callback *
        p_callback;

    void *
        p_thread_context;

    unsigned long int
        i_stack_size;

    unsigned long int
        ul_padding[1u];

    char
        b_detach;

    unsigned char
        uc_padding[7u];

};

struct appl_thread_handle
{
    struct appl_object_handle
        o_object_handle;

};

enum appl_status
appl_thread_create(
    struct appl_context_handle * const
        p_context,
    struct appl_thread_descriptor const * const
        p_thread_descriptor,
    struct appl_thread_handle * * const
        r_thread_handle);

struct appl_event_handle;

struct appl_event_descriptor
{
    void *
        p_dummy;

};

struct appl_event_handle
{
    struct appl_object_handle
        o_object_handle;

};

enum appl_status
appl_event_create(
    struct appl_context_handle * const
        p_context,
    struct appl_event_descriptor const * const
        p_event_descriptor,
    struct appl_event_handle * * const
        p_event);

enum appl_status
appl_event_signal(
    struct appl_event_handle * const
        p_event);

enum appl_status
appl_event_wait(
    struct appl_event_handle * const
        p_event,
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count);

/* mutex */
struct appl_mutex_handle;

struct appl_mutex_descriptor
{
    void *
        p_dummy;

};

struct appl_mutex_handle
{
    struct appl_object_handle
        o_object_handle;

};

enum appl_status
appl_mutex_create(
    struct appl_context_handle * const
        p_context,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex_handle * * const
        r_mutex_handle);

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

enum appl_status
appl_socket_address_create(
    struct appl_context_handle * const
        p_context,
    struct appl_socket_address_descriptor const * const
        p_socket_address_descriptor,
    struct appl_socket_address_handle * * const
        r_socket_address_handle);

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

enum appl_status
appl_tcp_socket_create(
    struct appl_context_handle * const
        p_context,
    struct appl_tcp_socket_descriptor const * const
        p_tcp_socket_descriptor,
    struct appl_tcp_socket_handle * * const
        r_tcp_socket_handle);

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

enum appl_status
appl_udp_socket_create(
    struct appl_context_handle * const
        p_context,
    struct appl_udp_socket_descriptor const * const
        p_udp_socket_descriptor,
    struct appl_udp_socket * * const
        p_udp_socket);

#endif /* #if defined(APPL_CONFIG_WITH_SOCKET) */

#if defined(APPL_CONFIG_WITH_CLOCK)

enum appl_status
appl_clock_read(
    struct appl_context_handle * const
        p_context,
    unsigned long int const
        i_time_freq,
    unsigned long int * const
        p_time_count);

enum appl_status
appl_clock_delay(
    struct appl_context_handle * const
        p_context,
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count);

#endif /* #if defined(APPL_CONFIG_WITH_CLOCK) */

#if defined(APPL_CONFIG_WITH_MAIN)

/* Predefine options handle */
struct appl_options;

/*

Structure: appl_options_descriptor

Description:

    Descriptor for initialization of appl_options object.

*/
struct appl_options_descriptor
{
    struct appl_buf *
        p_buf_min;

    struct appl_buf *
        p_buf_max;

}; /* struct appl_options_descriptor */

/* extern */
enum appl_status
appl_main(
    struct appl_context_handle * const
        p_context,
    struct appl_options_descriptor const * const
        p_options_descriptor,
    int * const
        r_exit_code);

#endif /* #if defined(APPL_CONFIG_WITH_MAIN) */

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl.h */
