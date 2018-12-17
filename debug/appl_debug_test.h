/* See LICENSE for license details */

/*

*/

/* Assert configuration */
#if ! defined APPL_DEBUG
#error include only from debug build
#endif /* #if ! defined APPL_DEBUG */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

void
    appl_debug_test_1(
        struct appl_context * const
            p_context);

void
    appl_debug_test_2(
        struct appl_context * const
            p_context);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_debug_test.h */
