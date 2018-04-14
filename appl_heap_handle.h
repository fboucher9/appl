/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_HEAP_HANDLE_H)
#error include appl_heap_handle.h once
#endif /* #if defined(INC_APPL_HEAP_HANDLE_H) */

struct appl_object_handle;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_heap_alloc(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned long int const
        i_length,
    void * * const
        r_buf);

enum appl_status
appl_heap_free(
    struct appl_object_handle const * const
        p_object_handle,
    void * const
        p_buf);

enum appl_status
appl_heap_realloc(
    struct appl_object_handle const * const
        p_object_handle,
    void * const
        p_old_buf,
    unsigned long int const
        i_length,
    void * * const
        r_new_buf);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_heap_handle.h */
