/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POOL_TEST_H
#error include appl_pool_test.h once
#endif /* #if defined INC_APPL_POOL_TEST_H */

#define INC_APPL_POOL_TEST_H

/* Header file dependency */
#if ! defined INC_APPL_H
#error include appl.h before
#endif /* #if ! defined INC_APPL_H */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

char
appl_pool_test_1(
    struct appl_context * const
        p_context);

char
appl_pool_test_2(
    struct appl_context * const
        p_context);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_pool_test.h */
