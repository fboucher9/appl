/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_BACKTRACE_TEST_H

/* Reverse include guard */
enum guard_appl_backtrace_test_h
{
    inc_appl_backtrace_test_h = 1
        + inc_appl_predefines_h
};

#include <appl_extern_c_begin.h>

void
appl_backtrace_test_1(
    struct appl_context * const
        p_context);

#include <appl_extern_c_end.h>

/* end-of-file: appl_backtrace_test.h */
