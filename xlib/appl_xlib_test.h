/* See LICENSE for license details */

/*

Module: appl_xlib_test.h

Description:

    Unit tests for appl_xlib module.

*/

#define INC_APPL_XLIB_TEST_H

enum guard_appl_xlib_test_h
{
    inc_appl_xlib_test_h = 1
};

#include <misc/appl_extern_c_begin.h>

/* Basic sanity check */
void
appl_xlib_test_1(
    struct appl_context * const
        p_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_xlib_test.h */
