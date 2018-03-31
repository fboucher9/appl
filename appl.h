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

#define APPL_CONFIG_WITH_SOCKET

#define APPL_CONFIG_WITH_CLOCK

#define APPL_CONFIG_WITH_MAIN

#define APPL_CONFIG_WITH_PROPERTY

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_list.h"

#include "appl_object_handle.h"

#include "appl_context_handle.h"

#if defined(APPL_CONFIG_WITH_DEBUG)

#if defined APPL_DEBUG

#include "appl_debug_handle.h"

#endif /* #if defined APPL_DEBUG */

#endif /* #if defined(APPL_CONFIG_WITH_DEBUG) */

#if defined(APPL_CONFIG_WITH_HEAP)

#include "appl_heap_handle.h"

#endif /* #if defined(APPL_CONFIG_WITH_HEAP) */

#if defined(APPL_CONFIG_WITH_FILE)

#include "appl_file_descriptor.h"

#include "appl_file_handle.h"

#endif /* #if defined(APPL_CONFIG_WITH_FILE) */

#if defined(APPL_CONFIG_WITH_THREAD)

#include "appl_thread_descriptor.h"

#include "appl_thread_handle.h"

#include "appl_event_handle.h"

#include "appl_mutex_handle.h"

#endif /* #if defined(APPL_CONFIG_WITH_THREAD) */

#if defined(APPL_CONFIG_WITH_SOCKET)

#include "appl_address_descriptor.h"

#include "appl_address_handle.h"

#include "appl_socket_descriptor.h"

#include "appl_socket_handle.h"

#endif /* #if defined(APPL_CONFIG_WITH_SOCKET) */

#if defined(APPL_CONFIG_WITH_CLOCK)

#include "appl_clock_handle.h"

#endif /* #if defined(APPL_CONFIG_WITH_CLOCK) */

#if defined APPL_CONFIG_WITH_PROPERTY

#include "appl_property_handle.h"

#endif /* #if defined APPL_CONFIG_WITH_PROPERTY */

#if defined(APPL_CONFIG_WITH_MAIN)

#include "appl_options_descriptor.h"

#include "appl_main.h"

#endif /* #if defined(APPL_CONFIG_WITH_MAIN) */

/* end-of-file: appl.h */
