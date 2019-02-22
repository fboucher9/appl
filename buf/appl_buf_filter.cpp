/* See LICENSE for license details */

/*

*/

#include <appl_buf_filter.h>

#include <appl_buf.h>

#include <appl_convert.h>

//
//
//
char
appl_buf_filter_test(
    struct appl_buf const * const
        p_buf_filter,
    unsigned char const
        c_data)
{
    char
        b_result;

    unsigned char const
        i_offset =
        p_buf_filter->o_min.pc_uchar[0u];

    unsigned char const
        c_index =
        appl_convert::to_uchar(
            appl_convert::to_unsigned(
                c_data
                - i_offset));

    unsigned char const
        c_byte_index =
        appl_convert::to_uchar(
            appl_convert::to_unsigned(
                c_index
                >> 3u));

    unsigned char const * const
        p_filter_byte =
        p_buf_filter->o_min.pc_uchar
        + c_byte_index
        + 1u;

    if (
        p_filter_byte
        < p_buf_filter->o_max.pc_uchar)
    {
        unsigned char const
            c_filter_byte =
            *(
                p_filter_byte);

        unsigned char const
            c_bit_index =
            (
                c_index
                & 0x07u);

        unsigned char const
            c_bit_mask =
            appl_convert::to_uchar(
                1u
                << c_bit_index);

        b_result =
               (
                   0 != (
                       c_filter_byte
                       & c_bit_mask));
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

} // appl_buf_filter_test()

//
//
//
unsigned long int
appl_buf_filter_get_build_length(
    struct appl_buf const * const
        p_input)
{
    unsigned long int
        i_length;

    unsigned char const
        c_input_min =
        appl_buf_min_value(
            p_input->o_min.pc_uchar,
            p_input->o_max.pc_uchar);

    unsigned char const
        c_input_max =
        appl_buf_max_value(
            p_input->o_min.pc_uchar,
            p_input->o_max.pc_uchar);

    i_length =
        1ul
        + (
            (
                c_input_max
                - c_input_min
                + 8ul)
            / 8ul);

    return
        i_length;

} // appl_buf_filter_get_build_length()

//
//
//
void
appl_buf_filter_build(
    struct appl_buf * const
        p_buf_filter,
    struct appl_buf const * const
        p_input)
{
    unsigned char const
        c_input_min =
        appl_buf_min_value(
            p_input->o_min.pc_uchar,
            p_input->o_max.pc_uchar);

    p_buf_filter->o_min.p_uchar[0u] =
        c_input_min;

    unsigned char const *
        p_input_iterator;

    p_input_iterator =
        p_input->o_min.pc_uchar;

    while (
        p_input_iterator
        < p_input->o_max.pc_uchar)
    {
        unsigned char const
            c_data =
            *(
                p_input_iterator);

        p_input_iterator ++;

        unsigned char const
            c_index =
            appl_convert::to_uchar(
                appl_convert::to_unsigned(
                    c_data
                    - c_input_min));

        unsigned char const
            c_byte_index =
            appl_convert::to_uchar(
                appl_convert::to_unsigned(
                    c_index
                    >> 3u));

        unsigned char * const
            p_filter_byte =
            p_buf_filter->o_min.p_uchar
            + c_byte_index
            + 1u;

        if (
            p_filter_byte
            < p_buf_filter->o_max.p_uchar)
        {
            unsigned char const
                c_bit_index =
                (
                    c_index
                    & 0x07u);

            unsigned char const
                c_bit_mask =
                appl_convert::to_uchar(
                    1u
                    << c_bit_index);

            *(
                p_filter_byte) |=
                c_bit_mask;
        }

    }

} // appl_buf_filter_build()

/* end-of-file: appl_buf_filter.cpp */
