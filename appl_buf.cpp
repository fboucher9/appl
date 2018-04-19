/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_buf.h>

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

#if 0
/*

*/
enum appl_status
appl_buf_fill(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    while (
        p_buf->o_min.p_uchar < p_buf->o_max.p_uchar)
    {
        *(
            p_buf->o_min.p_uchar) =
            c_value;

        p_buf->o_min.p_uchar ++;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} /* appl_buf_fill() */
#endif

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
    unsigned char *
        p_cur;

    unsigned char const *
        p_src_it;

    p_cur =
        p_dst_min;

    p_src_it =
        p_src_min;

    while (
        (
            p_src_it
            < p_src_max)
        && (
            p_cur
            < p_dst_max))
    {
        *(
            p_cur) =
            *(
                p_src_it);

        p_cur ++;

        p_src_it ++;
    }

    return
        p_cur;

} /* appl_buf_copy() */

#if 0
/*

*/
enum appl_status
appl_buf_compare(
    struct appl_buf const * const
        p_buf_left,
    struct appl_buf const * const
        p_buf_right,
    signed int * const
        p_result)
{
    enum appl_status
        e_status;

    struct appl_buf
        o_buf_left_it;

    struct appl_buf
        o_buf_right_it;

    o_buf_left_it =
        *(
            p_buf_left);

    o_buf_right_it =
        *(
            p_buf_right);

    signed int
        i_result;

    i_result =
        0;

    while (
        (
            0
            == i_result)
        && (
            (
                o_buf_left_it.o_min.pc_uchar
                < o_buf_left_it.o_max.pc_uchar)
            || (
                o_buf_right_it.o_min.pc_uchar
                < o_buf_right_it.o_max.pc_uchar)))
    {
        unsigned char
            c_left;

        unsigned char
            c_right;

        if (
                o_buf_left_it.o_min.pc_uchar
                < o_buf_left_it.o_max.pc_uchar)
        {
            c_left =
                *(
                    o_buf_left_it.o_min.pc_uchar);

            o_buf_left_it.o_min.pc_uchar ++;
        }
        else
        {
            c_left =
                0u;
        }

        if (
            o_buf_right_it.o_min.pc_uchar
            < o_buf_right_it.o_max.pc_uchar)
        {
            c_right =
                *(
                    o_buf_right_it.o_min.pc_uchar);

            o_buf_right_it.o_min.pc_uchar ++;
        }
        else
        {
            c_right =
                0u;
        }

        i_result =
            static_cast<signed int>(
                static_cast<signed int>(
                    static_cast<unsigned int>(
                        c_left))
                - static_cast<signed int>(
                    static_cast<unsigned int>(
                        c_right)));
    }

    *(
        p_result) =
        i_result;

    e_status =
        appl_status_ok;

    return
        e_status;

} /* appl_buf_compare() */
#endif

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
            static_cast<unsigned int>(
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
    unsigned long int const
        i_flags)
{
    unsigned char *
        p_cur;

    unsigned char
        a_digits[64u];

    unsigned int
        i_count;

    unsigned int
        i_base;

    unsigned long int
        u_value;

    unsigned int
        i_width;

    char
        b_negative;

    unsigned char
        b_sign;

    unsigned char
        i_sign;

    p_cur =
        p_buf_min;

    if (APPL_BUF_PRINT_BINARY & i_flags)
    {
        i_base = 2u;
    }
    else if (APPL_BUF_PRINT_OCTAL & i_flags)
    {
        i_base = 8u;
    }
    else if (APPL_BUF_PRINT_HEXADECIMAL & i_flags)
    {
        i_base = 16u;
    }
    else
    {
        i_base = 10u;
    }

    if (APPL_BUF_PRINT_UNSIGNED & i_flags)
    {
        u_value =
            static_cast<unsigned long int>(
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
                static_cast<unsigned long int>(
                    i_value);

            b_negative =
                0;
        }
        else
        {
            u_value =
                static_cast<unsigned long int>(
                    -i_value);

            b_negative =
                1;
        }
    }

    i_width =
        static_cast<unsigned int>(
            APPL_BUF_PRINT_WIDTH_MASK & i_flags);

    if (APPL_BUF_PRINT_SIGN_SPACE & i_flags)
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
    else if (APPL_BUF_PRINT_SIGN_PLUS & i_flags)
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

    if (i_width > (i_count + static_cast<unsigned int>(b_sign)))
    {
        i_width = (i_width - i_count - static_cast<unsigned int>(b_sign));
    }

    /* space padding for right align */
    {
        if (
            (
                !(APPL_BUF_PRINT_PAD_ZERO & i_flags))
            && (
                !(APPL_BUF_PRINT_ALIGN_LEFT & i_flags)))
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
        if (APPL_BUF_PRINT_PAD_ZERO & i_flags)
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
            (APPL_BUF_PRINT_ALIGN_LEFT & i_flags)
            && (
                !(APPL_BUF_PRINT_PAD_ZERO & i_flags)))
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

/* end-of-file: appl_buf.cpp */
