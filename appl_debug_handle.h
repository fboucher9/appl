/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_DEBUG_HANDLE_H)
#error include appl_debug_handle.h once
#endif /* #if defined(INC_APPL_DEBUG_HANDLE_H) */

#define INC_APPL_DEBUG_HANDLE_H

struct appl_context_handle;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_debug_break(
    struct appl_context_handle * const
        p_context_handle);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_debug_handle.h */
