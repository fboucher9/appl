/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POOL_HANDLE_H
#error include appl_pool_handle.h once
#endif /* #if defined INC_APPL_POOL_HANDLE_H */

#define INC_APPL_POOL_HANDLE_H

struct appl_context;

struct appl_object;

struct appl_pool;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_pool_create(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_length,
        struct appl_pool * * const
            r_pool);

struct appl_object *
    appl_pool_parent(
        struct appl_pool * const
            p_pool);

struct appl_object const *
    appl_pool_const_parent(
        struct appl_pool const * const
            p_pool);

enum appl_status
    appl_pool_alloc(
        struct appl_pool * const
            p_pool,
        void * * const
            r_buffer);

enum appl_status
    appl_pool_free(
        struct appl_pool * const
            p_pool,
        void * const
            p_buffer);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_pool_handle.h */
