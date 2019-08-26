/* See LICENSE for license details */

/*

*/

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

unsigned long int
    appl_str_len(
        struct appl_buf * const
            p_buf);

void
    appl_str_zero(
        struct appl_buf * const
            p_buf);

unsigned char *
    appl_str_fill(
        struct appl_buf * const
            p_buf,
        unsigned char const
            i_value);

unsigned char *
    appl_str_copy(
        struct appl_buf * const
            p_dst,
        struct appl_buf const * const
            p_src);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_str.h */
