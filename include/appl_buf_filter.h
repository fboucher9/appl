/* See LICENSE for license details */

/*

Module: appl_buf_filter.h

Description:
    Filtering of character buffers.  Detect if a character is part of a
    list of characters.  Functions to generate a filter using a list
    of characters.

*/

/* Reverse include guard */
enum guard_appl_buf_filter_h
{
    inc_appl_buf_filter_h = 1
}; /* enum guard_appl_buf_filter_h */

/* Included. */
#define INC_APPL_BUF_FILTER_H

/* Predefine */
struct appl_buf;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

/* Detect if given character is part of filter */
char
appl_buf_filter_test(
    struct appl_buf const * const
        p_buf_filter,
    unsigned char const
        c_data);

/* Calculate length in bytes of filter given a list of characters */
unsigned long int
appl_buf_filter_get_build_length(
    struct appl_buf const * const
        p_input);

/* Generate a filter given a list of characters */
void
appl_buf_filter_build(
    struct appl_buf * const
        p_buf_filter,
    struct appl_buf const * const
        p_input);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_buf_filter.h */
