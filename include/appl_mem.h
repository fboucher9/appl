/* See LICENSE for license details */

/*

*/

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

unsigned long int
    appl_mem_zero(
        void * const
            p_buf,
        unsigned long int const
            i_buf_len);

unsigned long int
    appl_mem_fill(
        void * const
            p_buf,
        unsigned char const
            i_value,
        unsigned long int const
            i_buf_len);

unsigned long int
    appl_mem_copy(
        void * const
            p_dst,
        unsigned long int const
            i_dst_len,
        void const * const
            p_src,
        unsigned long int const
            i_src_len);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_mem.h */
