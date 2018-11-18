/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_allocator_handle_h
{
    inc_appl_allocator_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_allocator;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

struct appl_object *
    appl_allocator_parent(
        struct appl_allocator * const
            p_allocator);

enum appl_status
    appl_allocator_alloc(
        struct appl_allocator * const
            p_allocator,
        unsigned long int const
            i_buf_len,
        void * * const
            r_buf);

enum appl_status
    appl_allocator_free(
        struct appl_allocator * const
            p_allocator,
        unsigned long int const
            i_buf_len,
        void * const
            p_buf);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_allocator_handle.h */
