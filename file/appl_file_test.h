/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_FILE_TEST_H

/* Reverse include guard */
enum guard_appl_file_test_h
{
    inc_appl_file_test_h = 1
        /* Header file dependencies */
};

#include <misc/appl_extern_c_begin.h>

enum appl_status
    appl_file_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift);

void
    appl_file_test_1(
        struct appl_context * const
            p_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_file_test.h */
