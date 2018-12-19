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

/* Predefine */
struct appl_context;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

void
    appl_file_test_1(
        struct appl_context * const
            p_context);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_file_test.h */
