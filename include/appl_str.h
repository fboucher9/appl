/* See LICENSE for license details */

/*

*/

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

unsigned long int
    appl_str_len(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max);

unsigned char *
    appl_str_zero(
        unsigned char * const
            p_buf_min,
        unsigned char * const
            p_buf_max);

unsigned char *
    appl_str_fill(
        unsigned char * const
            p_buf_min,
        unsigned char * const
            p_buf_max,
        unsigned char const
            i_value);

unsigned char *
    appl_str_copy(
        unsigned char * const
            p_dst_min,
        unsigned char * const
            p_dst_max,
        unsigned char const * const
            p_src_min,
        unsigned char const * const
            p_src_max);

int
    appl_str_compare(
        unsigned char const * const
            p_left_min,
        unsigned char const * const
            p_left_max,
        unsigned char const * const
            p_right_min,
        unsigned char const * const
            p_right_max);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_str.h */
