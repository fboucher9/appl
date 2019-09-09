/* See LICENSE for license details */

/*

*/

#include <appl_str.h>

#include <appl_mem.h>

#include <appl_types.h>

#include <appl_convert.h>

//
//
//
unsigned long int
    appl_str_len(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max)
{
    unsigned long int
        i_str_len;

    if (
        p_buf_max
        >= p_buf_min)
    {
        i_str_len =
            appl_convert::to_ulong(
                appl_convert::to_unsigned(
                    p_buf_max - p_buf_min));
    }
    else
    {
        i_str_len =
            0ul;
    }

    return
        i_str_len;

} // appl_str_len()

//
//
//
unsigned char *
    appl_str_zero(
        unsigned char * const
            p_buf_min,
        unsigned char * const
            p_buf_max)
{
    unsigned char *
        p_buf_iterator;

    unsigned long int const
        i_str_len =
        appl_str_len(
            p_buf_min,
            p_buf_max);

    unsigned long int const
        i_result =
        appl_mem_zero(
            p_buf_min,
            i_str_len);

    p_buf_iterator =
        p_buf_min
        + i_result;

    return
        p_buf_iterator;

} // appl_str_zero()

//
//
//
unsigned char *
    appl_str_fill(
        unsigned char * const
            p_buf_min,
        unsigned char * const
            p_buf_max,
        unsigned char const
            i_value)
{
    unsigned char *
        p_buf_iterator;

    unsigned long int const
        i_str_len =
        appl_str_len(
            p_buf_min,
            p_buf_max);

    unsigned long int const
        i_result =
        appl_mem_fill(
            p_buf_min,
            i_value,
            i_str_len);

    p_buf_iterator =
        p_buf_min
        + i_result;

    return
        p_buf_iterator;

} // appl_str_fill()

//
//
//
unsigned char *
    appl_str_copy(
        unsigned char * const
            p_dst_min,
        unsigned char * const
            p_dst_max,
        unsigned char const * const
            p_src_min,
        unsigned char const * const
            p_src_max)
{
    unsigned char *
        p_dst_iterator;

    unsigned long int const
        i_dst_len =
        appl_str_len(
            p_dst_min,
            p_dst_max);

    unsigned long int const
        i_src_len =
        appl_str_len(
            p_src_min,
            p_src_max);

    unsigned long int const
        i_result =
        appl_mem_copy(
            p_dst_min,
            i_dst_len,
            p_src_min,
            i_src_len);

    p_dst_iterator =
        p_dst_min
        + i_result;

    return
        p_dst_iterator;

} // appl_str_copy()

/* end-of-file: appl_str.cpp */
