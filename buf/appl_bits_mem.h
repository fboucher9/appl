/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bits_mem_h
{
    inc_appl_bits_mem_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_buf_h
        + inc_appl_predefines_h
        /* ... */

}; /* enum guard_appl_bits_mem_h */

#include <appl_extern_c_begin.h>

enum appl_status
    appl_bits_mem_create(
        struct appl_context * const
            p_context,
        struct appl_bits_mem_descriptor const * const
            p_descriptor,
        struct appl_bits_mem * * const
            r_instance);

struct appl_bits *
    appl_bits_mem_parent(
        struct appl_bits_mem * const
            p_instance);

struct appl_bits const *
    appl_bits_mem_const_parent(
        struct appl_bits_mem const * const
            p_instance);

enum appl_status
    appl_bits_mem_query(
        struct appl_bits_mem const * const
            p_instance,
        struct appl_buf * const
            r_buf_used,
        struct appl_buf * const
            r_buf_unused);

#include <appl_extern_c_end.h>

/* end-of-file: appl_bits_mem.h */
