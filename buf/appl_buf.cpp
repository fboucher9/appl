/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <appl_convert.h>

#include <appl_mem.h>

/*

*/
unsigned long int
appl_buf_len(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        appl_convert::to_ulong(
            appl_convert::to_unsigned(
                p_buf_max
                - p_buf_min));

} /* appl_buf_len() */

#if 0
/*

*/
enum appl_status
appl_buf_read(
    struct appl_buf * const
        p_buf,
    unsigned char * const
        p_value)
{
    enum appl_status
        e_status;

    if (
        p_buf->o_min.pc_uchar < p_buf->o_max.pc_uchar)
    {
        *(
            p_value) =
            *(
                p_buf->o_min.pc_uchar);

        p_buf->o_min.pc_uchar ++;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* appl_buf_read() */
#endif

#if 0
/*

*/
enum appl_status
appl_buf_read_tail(
    struct appl_buf * const
        p_buf,
    unsigned char * const
        p_value)
{
    enum appl_status
        e_status;

    if (
        p_buf->o_min.pc_uchar < p_buf->o_max.pc_uchar)
    {
        p_buf->o_max.pc_uchar --;

        *(
            p_value) =
            *(
                p_buf->o_max.pc_uchar);

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* appl_buf_read_tail() */
#endif

/*

*/
unsigned char *
appl_buf_write(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned char const
        c_value)
{
    unsigned char *
        p_cur;

    p_cur =
        p_buf_min;

    if (
        p_cur < p_buf_max)
    {
        *(
            p_cur) =
            c_value;

        p_cur ++;
    }

    return
        p_cur;

} /* appl_buf_write() */

#if 0
/*

*/
enum appl_status
appl_buf_write_tail(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    if (
        p_buf->o_min.p_uchar < p_buf->o_max.p_uchar)
    {
        p_buf->o_max.p_uchar --;

        *(
            p_buf->o_max.p_uchar) =
            c_value;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* appl_buf_write_tail() */
#endif

#if 0
/*

*/
enum appl_status
appl_buf_write_repeat(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value,
    unsigned long int const
        i_count)
{
    enum appl_status
        e_status;

    unsigned long int
        i_remain;

    e_status =
        appl_status_ok;

    i_remain =
        i_count;

    while (
        i_remain
        && (appl_status_ok == e_status))
    {
        if (
            p_buf->o_min.p_uchar < p_buf->o_max.p_uchar)
        {
            *(
                p_buf->o_min.p_uchar) =
                c_value;

            p_buf->o_min.p_uchar ++;

            i_remain --;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;

} /* appl_buf_write_repeat() */
#endif

#if 0
/*

*/
enum appl_status
appl_buf_write_tail_repeat(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value,
    unsigned long int const
        i_count)
{
    enum appl_status
        e_status;

    unsigned long int
        i_remain;

    e_status =
        appl_status_ok;

    i_remain =
        i_count;

    while (
        i_remain
        && (appl_status_ok == e_status))
    {
        if (
            p_buf->o_min.p_uchar < p_buf->o_max.p_uchar)
        {
            p_buf->o_max.p_uchar --;

            *(
                p_buf->o_max.p_uchar) =
                c_value;

            i_remain --;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;

} /* appl_buf_write_tail_repeat() */
#endif

/*

*/
unsigned char *
appl_buf_zero(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max)
{
    unsigned long int const
        i_buf_len =
        appl_buf_len(
            p_buf_min,
            p_buf_max);

    unsigned long int
        i_zero_len =
        appl_mem_zero(
            p_buf_min,
            i_buf_len);

    return
        p_buf_min + i_zero_len;

} /* appl_buf_zero() */

/*

*/
unsigned char *
appl_buf_fill(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned char const
        c_value)
{
    unsigned long int const
        i_buf_len =
        appl_buf_len(
            p_buf_min,
            p_buf_max);

    unsigned long int const
        i_fill_len =
        appl_mem_fill(
            p_buf_min,
            c_value,
            i_buf_len);

    return
        p_buf_min + i_fill_len;

} /* appl_buf_fill() */

/*

*/
unsigned char *
appl_buf_copy(
    unsigned char * const
        p_dst_min,
    unsigned char * const
        p_dst_max,
    unsigned char const * const
        p_src_min,
    unsigned char const * const
        p_src_max)
{
    unsigned long int const
        i_src_len =
        appl_buf_len(
            p_src_min,
            p_src_max);

    unsigned long int const
        i_dst_len =
        appl_buf_len(
            p_dst_min,
            p_dst_max);

    unsigned long int const
        i_copy_len =
        appl_mem_copy(
            p_dst_min,
            i_dst_len,
            p_src_min,
            i_src_len);

    return
        p_dst_min + i_copy_len;

} /* appl_buf_copy() */

/*

*/
signed int
appl_buf_compare(
    unsigned char const * const
        p_left_min,
    unsigned char const * const
        p_left_max,
    unsigned char const * const
        p_right_min,
    unsigned char const * const
        p_right_max)
{
    signed int
        i_result;

    unsigned char const *
        p_left_it;

    unsigned char const *
        p_right_it;

    i_result =
        0;

    p_left_it =
        p_left_min;

    p_right_it =
        p_right_min;

    while (
        (
            0
            == i_result)
        && (
            (
                p_left_it
                < p_left_max)
            || (
                p_right_it
                < p_right_max)))
    {
        unsigned char
            c_left;

        unsigned char
            c_right;

        if (
                p_left_it
                < p_left_max)
        {
            c_left =
                *(
                    p_left_it);

            p_left_it ++;
        }
        else
        {
            c_left =
                0u;
        }

        if (
            p_right_it
            < p_right_max)
        {
            c_right =
                *(
                    p_right_it);

            p_right_it ++;
        }
        else
        {
            c_right =
                0u;
        }

        i_result =
            appl_convert::to_int(
                appl_convert::to_int(
                    appl_convert::to_uint(
                        c_left))
                - appl_convert::to_int(
                    appl_convert::to_uint(
                        c_right)));
    }

    return
        i_result;

} /* appl_buf_compare() */

/*

*/
#if 0
enum appl_status
appl_buf_case_compare(
    struct appl_buf const * const
        p_buf_left,
    struct appl_buf const * const
        p_buf_right,
    signed int * const
        p_result)
{
} /* appl_buf_case_compare() */
#endif

/*

*/
unsigned char
appl_buf_min_value(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    unsigned char
        c_min;

    unsigned char const *
        p_buf_it;

    c_min =
        255;

    p_buf_it =
        p_buf_min;

    while (
        p_buf_it
        != p_buf_max)
    {
        unsigned char const
            c_data =
            *(
                p_buf_it);

        if (
            c_min > c_data)
        {
            c_min = c_data;
        }

        p_buf_it ++;
    }

    return
        c_min;

} /* appl_buf_min_value() */

/*

*/
unsigned char
appl_buf_max_value(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    unsigned char
        c_max;

    unsigned char const *
        p_buf_it;

    c_max =
        0u;

    p_buf_it =
        p_buf_min;

    while (
        p_buf_it
        != p_buf_max)
    {
        unsigned char const
            c_data =
            *(
                p_buf_it);

        if (
            c_max < c_data)
        {
            c_max = c_data;
        }

        p_buf_it ++;
    }

    return
        c_max;

} /* appl_buf_max_value() */

/*

*/
static
unsigned int
build_digits(
    unsigned char * const
        a_digits,
    unsigned long int
        u_value,
    unsigned int const
        i_base)
{
    unsigned int
        i_count;

    i_count =
        0u;

    do
    {
        static unsigned char const a_symbols[16u] =
        {
            '0',
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8',
            '9',
            'a',
            'b',
            'c',
            'd',
            'e',
            'f'
        };

        unsigned int
            n;

        n =
            appl_convert::to_uint(
                u_value
                % i_base);

        u_value =
            u_value
            / i_base;

        if (
            i_count < 64u)
        {
            a_digits[i_count] =
                a_symbols[n];

            i_count ++;
        }
    }
    while (
        u_value);

    return
        i_count;

} /* build_digits() */

/*

*/
unsigned char *
appl_buf_print_number(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    signed long int const
        i_value,
    int const
        i_flags,
    unsigned int const
        i_width_const)
{
    unsigned char *
        p_cur;

    unsigned char
        a_digits[64u];

    unsigned int
        i_count;

    unsigned int
        i_width;

    unsigned int
        i_base;

    unsigned long int
        u_value;

    char
        b_negative;

    unsigned char
        b_sign;

    unsigned char
        i_sign;

    p_cur =
        p_buf_min;

    if (appl_buf_print_flag_binary & i_flags)
    {
        i_base = 2u;
    }
    else if (appl_buf_print_flag_octal & i_flags)
    {
        i_base = 8u;
    }
    else if (appl_buf_print_flag_hex & i_flags)
    {
        i_base = 16u;
    }
    else
    {
        i_base = 10u;
    }

    if (appl_buf_print_flag_unsigned & i_flags)
    {
        u_value =
            appl_convert::to_unsigned(
                i_value);

        b_negative =
            0;
    }
    else
    {
        if (
            i_value >= 0l)
        {
            u_value =
                appl_convert::to_unsigned(
                    i_value);

            b_negative =
                0;
        }
        else
        {
            u_value =
                appl_convert::to_unsigned(
                    -i_value);

            b_negative =
                1;
        }
    }

    if (appl_buf_print_flag_space & i_flags)
    {
        if (
            b_negative)
        {
            i_sign =
                '-';
        }
        else
        {
            i_sign =
                ' ';
        }

        b_sign =
            1;
    }
    else if (appl_buf_print_flag_plus & i_flags)
    {
        if (
            b_negative)
        {
            i_sign =
                '-';
        }
        else
        {
            i_sign =
                '+';
        }

        b_sign =
            1;
    }
    else
    {
        if (
            b_negative)
        {
            i_sign =
                '-';

            b_sign =
                1;
        }
        else
        {
            i_sign =
                0;

            b_sign =
                0;
        }
    }

    i_count =
        build_digits(
            a_digits,
            u_value,
            i_base);

    i_width =
        i_width_const;

    if (i_width > (i_count + b_sign))
    {
        i_width = (i_width - i_count - b_sign);
    }
    else
    {
        i_width = 0;
    }

    /* space padding for right align */
    {
        if (
            (
                !(appl_buf_print_flag_zero & i_flags))
            && (
                !(appl_buf_print_flag_left & i_flags)))
        {
            while (
                i_width)
            {
                p_cur =
                    appl_buf_write(
                        p_cur,
                        p_buf_max,
                        ' ');

                i_width --;
            }
        }
    }

    /* sign */
    {
        if (b_sign)
        {
            p_cur =
                appl_buf_write(
                    p_cur,
                    p_buf_max,
                    i_sign);
        }
    }

    /* zero padding */
    {
        if (appl_buf_print_flag_zero & i_flags)
        {
            while (
                i_width)
            {
                p_cur =
                    appl_buf_write(
                        p_cur,
                        p_buf_max,
                        '0');

                i_width --;
            }
        }
    }

    /* digits */
    while (
        i_count)
    {
        i_count --;

        p_cur =
            appl_buf_write(
                p_cur,
                p_buf_max,
                a_digits[i_count]);
    }

    /* space padding for left align */
    {
        if (
            (appl_buf_print_flag_left & i_flags)
            && (
                !(appl_buf_print_flag_zero & i_flags)))
        {
            while (
                i_width)
            {
                p_cur =
                    appl_buf_write(
                        p_cur,
                        p_buf_max,
                        ' ');

                i_width --;
            }
        }
    }

    return
        p_cur;

} /* appl_buf_print_number() */

/*

*/
unsigned char const *
appl_buf_scan_number(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    signed long int * const
        p_value,
    int const
        i_flags)
{
    unsigned char const *
        p_buf_iterator;

    signed long int
        i_value;

    char
        b_more;

    char
        b_negative;

    signed long int
        i_base;

    if (
        appl_buf_scan_flag_binary & i_flags)
    {
        i_base =
            2l;
    }
    else if (
        appl_buf_scan_flag_octal & i_flags)
    {
        i_base =
            8l;
    }
    else if (
        appl_buf_scan_flag_hex & i_flags)
    {
        i_base =
            16l;
    }
    else
    {
        i_base =
            10l;
    }

    p_buf_iterator =
        p_buf_min;

    b_more =
        1;

    b_negative =
        0;

    i_value =
        0;

    while (
        b_more
        && (
            p_buf_iterator
            < p_buf_max))
    {
        unsigned char
            u_glyph;

        signed long int
            i_digit;

        char
            b_digit;

        u_glyph =
            *(
                p_buf_iterator);

        i_digit =
            0l;

        b_digit =
            0;

        if (
            ' ' == u_glyph)
        {
        }
        else if (
            '-' == u_glyph)
        {
            b_negative =
                1;
        }
        else if (
            '+' == u_glyph)
        {
        }
        else if (
            ('0' <= u_glyph)
            && ('9' >= u_glyph))
        {
            i_digit =
                (u_glyph - '0' + 0l);

            b_digit =
                1;
        }
        else if (
            ('a' <= u_glyph)
            && ('f' >= u_glyph))
        {
            i_digit =
                (u_glyph - 'a' + 10l);

            b_digit =
                1;
        }
        else if (
            ('A' <= u_glyph)
            && ('F' >= u_glyph))
        {
            i_digit =
                (u_glyph - 'A' + 10l);

            b_digit =
                1;
        }
        else
        {
            b_more =
                0;
        }

        if (
            b_digit)
        {
            if (
                (i_digit >= 0l)
                && (i_digit < i_base))
            {
                i_value =
                    (i_value * i_base) + i_digit;
            }
            else
            {
                b_more =
                    0;
            }
        }

        if (
            b_more)
        {
            p_buf_iterator ++;
        }
    }

    if (
        b_negative)
    {
        i_value =
            -(i_value);
    }

    *(p_value) =
        i_value;

    return
        p_buf_iterator;

} /* appl_buf_scan_number() */

/* end-of-file: appl_buf.cpp */
