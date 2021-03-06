/* See LICENSE for license details */

/*

Module: appl_bits_handle.h

Description:

    Bitstream read and write operations.  Use of accumulator trick to simplify
    bit field operations that cross byte boundaries.

*/

/* Reverse include guard */
enum guard_appl_bits_handle_h
{
    inc_appl_bits_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
        /* ... */
}; /* enum guard_appl_bits_handle_h */

#include <misc/appl_extern_c_begin.h>

enum appl_status
    appl_bits_create(
        struct appl_context * const
            p_context,
        struct appl_bits_descriptor const * const
            p_descriptor,
        struct appl_bits * * const
            r_bits);

enum appl_status
    appl_bits_destroy(
        struct appl_bits * const
            p_bits);

enum appl_status
    appl_bits_read(
        struct appl_bits * const
            p_bits,
        unsigned char const
            i_count,
        unsigned long int * const
            r_value);

enum appl_status
    appl_bits_write(
        struct appl_bits * const
            p_bits,
        unsigned char const
            i_count,
        unsigned long int const
            i_value);

enum appl_status
    appl_bits_query(
        struct appl_bits * const
            p_bits,
        unsigned long int * const
            r_count);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_bits_handle.h */
