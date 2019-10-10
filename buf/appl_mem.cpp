/* See LICENSE for license details */

/*

*/

#include <buf/appl_mem.h>

#include <string.h>

/*

*/
unsigned long int
    appl_mem_zero(
        void * const
            p_buf,
        unsigned long int const
            i_buf_len)
{
    unsigned long int
        i_zero_len;

    i_zero_len =
        i_buf_len;

    memset(
        p_buf,
        0u,
        i_zero_len);

    return
        i_zero_len;

} /* appl_mem_zero() */

/*

*/
unsigned long int
    appl_mem_fill(
        void * const
            p_buf,
        unsigned char const
            i_value,
        unsigned long int const
            i_buf_len)
{
    unsigned long int
        i_fill_len;

    i_fill_len =
        i_buf_len;

    memset(
        p_buf,
        i_value,
        i_fill_len);

    return
        i_fill_len;

} /* appl_mem_fill() */

/*

*/
unsigned long int
    appl_mem_copy(
        void * const
            p_dst,
        unsigned long int const
            i_dst_len,
        void const * const
            p_src,
        unsigned long int const
            i_src_len)
{
    unsigned long int
        i_copy_len;

    i_copy_len =
        i_src_len;

    if (
        i_dst_len
        < i_copy_len)
    {
        i_copy_len =
            i_dst_len;
    }

    memcpy(
        p_dst,
        p_src,
        i_copy_len);

    return
        i_copy_len;

} /* appl_mem_copy */

/* end-of-file: appl_mem.cpp */
