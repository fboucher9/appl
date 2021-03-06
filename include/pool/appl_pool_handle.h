/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_pool_handle_h
{
    inc_appl_pool_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
        + inc_appl_types_h
};

/* Descriptor */
struct appl_pool_descriptor
{
    appl_size_t
        i_count_min;

    appl_size_t
        i_count_max;

    /* -- */

    appl_size_t
        i_length;

#define PADDING (APPL_SIZEOF_PTR)
#include <misc/appl_padding.h>

}; /* struct appl_pool_descriptor */

#include <misc/appl_extern_c_begin.h>

enum appl_status
    appl_pool_create(
        struct appl_context * const
            p_context,
        struct appl_pool_descriptor const * const
            p_pool_descriptor,
        struct appl_pool * * const
            r_pool);

enum appl_status
    appl_pool_destroy(
        struct appl_pool * const
            p_pool);

struct appl_allocator *
    appl_pool_parent(
        struct appl_pool * const
            p_pool);

struct appl_allocator const *
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

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_pool_handle.h */
