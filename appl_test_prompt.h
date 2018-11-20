/* See LICENSE for license details */

/*

*/

#define INC_APPL_TEST_PROMPT_H

/* Reverse include guard */
enum guard_appl_test_prompt_h
{
    inc_appl_test_prompt_h =
        /* Header file dependencies */
        inc_appl_h
};

#if ! defined APPL_BUILD_EXE
#error include only when APPL_BUILD_EXE is defined
#endif /* #if ! defined APPL_BUILD_EXE */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_test_prompt(
    struct appl_context * const
        p_context,
    struct appl_file * const
        p_file);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_test_prompt.h */
