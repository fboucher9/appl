/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_buf_test_h
{
    inc_appl_buf_test_h = 1
};

/* Included. */
#define INC_APPL_BUF_TEST_H

/* Predefine */
struct appl_context;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

void
    appl_buf_test_1(
        struct appl_context * const
            p_context);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_buf_test.h */
