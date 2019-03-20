/* See LICENSE for license details */

/*

*/

/* Predefine */
struct appl_file;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

extern
struct appl_file *
g_test_stdin;

extern
struct appl_file *
g_test_stdout;

extern
struct appl_file *
g_test_stderr;

void
appl_print(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max);

void
appl_print0(
    char const * const
        p_buf0);

void
appl_print_number(
    signed long int const
        i_value,
    int const
        i_flags,
    unsigned int const
        i_width);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_test.h */
