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

/* C-style include guard */
enum guard_appl_h
{
    inc_appl_h =
        1
};

/* Detect compiler */

/* Detect cpu */

/* Detect types */
#include <appl_types.h>

/* Configuration */
#if ( ! defined APPL_DEBUG ) && ( ! defined APPL_RELEASE )
#error "define APPL_DEBUG or APPL_RELEASE from makefile"
#endif

#if ( ! defined APPL_OS_LINUX ) && ( ! defined APPL_OS_WINDOWS )
#error "define APPL_OS_LINUX or APPL_OS_WINDOWS from makefile"
#endif

#define APPL_CONFIG_WITH_DEBUG

#define APPL_CONFIG_WITH_ALLOCATOR

#define APPL_CONFIG_WITH_HEAP

#define APPL_CONFIG_WITH_POOL

#define APPL_CONFIG_WITH_FILE

#define APPL_CONFIG_WITH_THREAD

#define APPL_CONFIG_WITH_SOCKET

#define APPL_CONFIG_WITH_CLOCK

#define APPL_CONFIG_WITH_MAIN

#define APPL_CONFIG_WITH_PROPERTY

#define APPL_CONFIG_WITH_STRING

#define APPL_CONFIG_WITH_ENV

#define APPL_CONFIG_WITH_LIBRARY

#define APPL_CONFIG_WITH_RANDOM

#define APPL_CONFIG_WITH_LOG

#define APPL_CONFIG_WITH_HASH

#define APPL_CONFIG_WITH_MODULE

#define APPL_CONFIG_WITH_TIMER

#include <appl_status.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#include <appl_list.h>

#include <appl_tree.h>

#include <appl_object_handle.h>

#if defined __cplusplus
#include <appl_object.h>
#endif /* #if defined __cplusplus */

#include <appl_context_handle.h>

#if defined(APPL_CONFIG_WITH_DEBUG)

#if defined APPL_DEBUG

#include <appl_debug_handle.h>

#endif /* #if defined APPL_DEBUG */

#endif /* #if defined(APPL_CONFIG_WITH_DEBUG) */

#if defined APPL_CONFIG_WITH_ALLOCATOR

#include <appl_allocator_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_ALLOCATOR */

#if defined(APPL_CONFIG_WITH_HEAP)

#include <appl_heap_handle.h>

#endif /* #if defined(APPL_CONFIG_WITH_HEAP) */

#if defined APPL_CONFIG_WITH_POOL

#include <appl_pool_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_POOL */

#if defined APPL_CONFIG_WITH_STRING

#include <appl_string_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_STRING */

#if defined APPL_CONFIG_WITH_PROPERTY

#include <appl_property_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_PROPERTY */

#if defined(APPL_CONFIG_WITH_FILE)

#include <appl_file_descriptor.h>

#include <appl_file_handle.h>

#endif /* #if defined(APPL_CONFIG_WITH_FILE) */

#if defined(APPL_CONFIG_WITH_THREAD)

#include <appl_thread_descriptor.h>

#include <appl_thread_property.h>

#include <appl_thread_handle.h>

#include <appl_thread_cache.h>

#include <appl_event_handle.h>

#include <appl_mutex_handle.h>

#include <appl_queue_handle.h>

#endif /* #if defined(APPL_CONFIG_WITH_THREAD) */

#if defined(APPL_CONFIG_WITH_SOCKET)

#include <appl_address_property.h>

#include <appl_address_handle.h>

#include <appl_socket_descriptor.h>

#include <appl_poll_descriptor.h>

#include <appl_socket_handle.h>

#endif /* #if defined(APPL_CONFIG_WITH_SOCKET) */

#if defined(APPL_CONFIG_WITH_CLOCK)

#include <appl_clock_handle.h>

#endif /* #if defined(APPL_CONFIG_WITH_CLOCK) */

#if defined(APPL_CONFIG_WITH_ENV)

#include <appl_env_handle.h>

#endif /* #if defined(APPL_CONFIG_WITH_ENV) */

#if defined APPL_CONFIG_WITH_LIBRARY

#include <appl_library_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_LIBRARY */

#if defined APPL_CONFIG_WITH_RANDOM

#include <appl_random_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_RANDOM */

#if defined APPL_CONFIG_WITH_LOG

#include <appl_log_handle.h>

#endif /*#if defined APPL_CONFIG_WITH_LOG */

#if defined APPL_CONFIG_WITH_HASH

#include <appl_hash_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_HASH */

#if defined APPL_CONFIG_WITH_MODULE

#include <appl_module_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_MODULE */

#if defined APPL_CONFIG_WITH_TIMER

#include <appl_timer_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_TIMER */

#if defined APPL_CONFIG_WITH_XLIB

#include <appl_xlib_handle.h>

#endif /* #if defined APPL_CONFIG_WITH_XLIB */

#if defined(APPL_CONFIG_WITH_MAIN)

#include <appl_options_handle.h>

#include <appl_main.h>

#endif /* #if defined(APPL_CONFIG_WITH_MAIN) */

/* end-of-file: appl.h */
