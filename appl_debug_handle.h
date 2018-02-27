/* See LICENSE for license details */

/*

*/

#if ! defined APPL_DEBUG
#error include only from debug build
#endif /* #if ! defined APPL_DEBUG */

#if defined(INC_APPL_DEBUG_HANDLE_H)
#error include appl_debug_handle.h once
#endif /* #if defined(INC_APPL_DEBUG_HANDLE_H) */

#define INC_APPL_DEBUG_HANDLE_H

struct appl_context_handle;

struct appl_buf;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_debug_break(
    struct appl_context_handle * const
        p_context_handle);

enum appl_status
appl_debug_print(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_buf const * const
        p_buf);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_debug_handle.h */
