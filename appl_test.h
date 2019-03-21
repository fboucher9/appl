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

void
appl_print_ld(
    signed long int const
        i_value);

void
appl_print_lu(
    unsigned long int const
        i_value);

void
appl_print_08lx(
    unsigned long int const
        i_value);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_test.h */
