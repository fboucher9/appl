/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_handle_h
{
    inc_appl_heap_handle_h =
        /* Header file dependency */
        inc_appl_status_h
        + inc_appl_types_h
};

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
