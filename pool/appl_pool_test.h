/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_pool_test_h
{
    inc_appl_pool_test_h =
        /* Header file dependency */
        inc_appl_h
};

#include <misc/appl_extern_c_begin.h>

char
appl_pool_test_1(
    struct appl_context * const
        p_context);

char
appl_pool_test_2(
    struct appl_context * const
        p_context);

char
appl_pool_test_3(
    struct appl_context * const
        p_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_pool_test.h */
