/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_LOG_TEST_H

/* Reverse include guard */
enum guard_appl_log_test_h
{
    inc_appl_log_test_h = 1
        /* Header file dependency */
};

/* Predefine */
struct appl_context;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

void
    appl_log_test_1(
        struct appl_context * const
            p_context);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_log_test.h */
