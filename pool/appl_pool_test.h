/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_pool_test_h
{
    inc_appl_pool_test_h =
        /* Header file dependency */
        inc_appl_h
};

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
