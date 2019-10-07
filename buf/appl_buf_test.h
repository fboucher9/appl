/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_buf_test_h
{
    inc_appl_buf_test_h = 1
        + inc_appl_predefines_h
};

/* Included. */
#define INC_APPL_BUF_TEST_H

#include <misc/appl_extern_c_begin.h>

void
    appl_buf_test_1(
        struct appl_context * const
            p_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_buf_test.h */
