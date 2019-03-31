/* See LICENSE for license details */

/*

*/

/* Compile-time include guard */
enum guard_appl_buf_iterator_h
{
    deps_appl_buf_iterator_h = 1
        /* Header file dependencies */
};

/* Included. */
#define INC_APPL_BUF_ITERATOR_H

/* Predefine */
struct appl_buf;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

/* buf iterator write a single character */
char
appl_buf_iterator_write(
    struct appl_buf * const
        p_buf_iterator,
    unsigned char const
        c_value);

/* buf iterator read a single character */
char
appl_buf_iterator_read(
    struct appl_buf * const
        p_buf_iterator,
    unsigned char * const
        r_value);

/* buf iterator copy from source buffer */
char
appl_buf_iterator_copy(
    struct appl_buf * const
        p_buf_iterator,
    struct appl_buf * const
        p_buf_source);

/* buf iterator copy from source buffer up to n */
char
appl_buf_iterator_copy_n(
    struct appl_buf * const
        p_buf_iterator,
    struct appl_buf * const
        p_buf_source,
    unsigned long int const
        i_count);

/* buf iterator fill with zeroes */
char
appl_buf_iterator_zero(
    struct appl_buf * const
        p_buf_iterator);

/* buf iterator fill with zeroes up to n */
char
appl_buf_iterator_zero_n(
    struct appl_buf * const
        p_buf_iterator,
    unsigned long int const
        i_count);

/* buf iterator fill with same character */
char
appl_buf_iterator_fill(
    struct appl_buf * const
        p_buf_iterator,
    unsigned char const
        c_value);

/* buf iterator fill up to n characters */
char
appl_buf_iterator_fill_n(
    struct appl_buf * const
        p_buf_iterator,
    unsigned char const
        c_value,
    unsigned long int const
        i_count);

/* buf iterator print a number */
char
appl_buf_iterator_print_number(
    struct appl_buf * const
        p_buf_iterator,
    signed long int const
        i_number,
    int const
        i_flags,
    unsigned int const
        i_width);

/* buf iterator scan a number */
char
appl_buf_iterator_scan_number(
    struct appl_buf * const
        p_buf_iterator,
    signed long int * const
        r_value,
    int const
        i_flags);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_buf_iterator.h */
