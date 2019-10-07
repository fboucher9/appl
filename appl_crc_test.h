/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_crc_test_h
{
    inc_appl_crc_test_h = 1
        + inc_appl_status_h
        + inc_appl_predefines_h
};

/* Included. */
#define INC_APPL_CRC_TEST_H

#include <misc/appl_extern_c_begin.h>

enum appl_status
    appl_crc16_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift);

enum appl_status
    appl_crc32_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift);

void
    appl_crc_test_1(
        struct appl_context * const
            p_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_crc_test.h */
