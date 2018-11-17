/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_HEAP_HANDLE_H)
#error include appl_heap_handle.h once
#endif /* #if defined(INC_APPL_HEAP_HANDLE_H) */

/* Header file dependency */
#if ! defined INC_APPL_TYPES_H
#error include appl_types.h before
#endif /* #if ! defined INC_APPL_TYPES_H */

/* Predefine */
struct appl_context;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_heap_alloc(
    struct appl_context const * const
        p_context,
    appl_size_t const
        i_length,
    void * * const
        r_buf);

enum appl_status
appl_heap_free(
    struct appl_context const * const
        p_context,
    appl_size_t const
        i_length,
    void * const
        p_buf);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_heap_handle.h */
