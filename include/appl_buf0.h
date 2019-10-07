/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_buf0_h
{
    inc_appl_buf0_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
};

#include <misc/appl_extern_c_begin.h>

enum appl_status
appl_buf0_create(
    struct appl_context * const
        p_context,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    struct appl_buf0 * * const
        r_instance);

enum appl_status
appl_buf0_destroy(
    struct appl_buf0 * const
        p_instance);

unsigned char const *
appl_buf0_get(
    struct appl_buf0 const * const
        p_instance);

/* buf length */
unsigned long int
appl_buf0_len(
    unsigned char const * const
        p_buf_0);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_buf0.h */
