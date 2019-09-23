/* See LICENSE for license details */

/* Reverse include guard */
enum guard_appl_bytes_test_h
{
    inc_appl_bytes_test_h = 1
        /* Header file dependencies */
        + inc_appl_predefines_h
        /* ... */
};

#include <appl_extern_c_begin.h>

void
    appl_bytes_test_1(
        struct appl_context * const
            p_context);

#include <appl_extern_c_end.h>

/* end-of-file: appl_bytes_test.h */
