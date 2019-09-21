/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_str_bits_h
{
    inc_appl_str_bits_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_buf_h
        + inc_appl_predefines_h
        /* ... */

}; /* enum guard_appl_str_bits_h */

/*

*/
struct appl_str_bits_descriptor
{
    struct appl_buf
        o_buf;

}; /* struct appl_str_bits_descriptor */

#include <appl_extern_c_begin.h>

enum appl_status
    appl_str_bits_create(
        struct appl_context * const
            p_context,
        struct appl_str_bits_descriptor const * const
            p_descriptor,
        struct appl_str_bits * * const
            r_instance);

struct appl_bits *
    appl_str_bits_parent(
        struct appl_str_bits * const
            p_instance);

struct appl_bits const *
    appl_str_bits_const_parent(
        struct appl_str_bits const * const
            p_instance);

enum appl_status
    appl_str_bits_query(
        struct appl_str_bits const * const
            p_instance,
        struct appl_buf * const
            r_buf_used,
        struct appl_buf * const
            r_buf_unused);

#include <appl_extern_c_end.h>

/* end-of-file: appl_str_bits.h */
