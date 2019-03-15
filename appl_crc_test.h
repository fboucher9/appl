/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_crc_test_h
{
    inc_appl_crc_test_h = 1
        + inc_appl_status_h
};

/* Included. */
#define INC_APPL_CRC_TEST_H

/* Predefine */
struct appl_context;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_crc_main(
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

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_crc_test.h */
