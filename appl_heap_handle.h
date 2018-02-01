/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_HEAP_HANDLE_H)
#error include appl_heap_handle.h once
#endif /* #if defined(INC_APPL_HEAP_HANDLE_H) */

struct appl_context_handle;

struct appl_buf;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_heap_alloc(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_buf * const
        p_buf,
    unsigned long int const
        i_length);

enum appl_status
appl_heap_free(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_buf * const
        p_buf);

enum appl_status
appl_heap_realloc(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_buf * const
        p_buf,
    unsigned long int const
        i_length);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_heap_handle.h */
