/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_callstack_test_h
{
    inc_appl_callstack_test_h = 1
        /* Header file dependencies */
        + inc_appl_predefines_h
        /* ... */
}; /* enum guard_appl_callstack_test_h */

#include <misc/appl_extern_c_begin.h>

void
appl_callstack_test_1(
    struct appl_context * const
        p_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_callstack_test.h */
