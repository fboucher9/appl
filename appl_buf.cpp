/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_buf.h"

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

/*

*/
enum appl_status
appl_buf_write(
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
        *(
            p_buf->o_min.p_uchar) =
            c_value;

        p_buf->o_min.p_uchar ++;

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

} /* appl_buf_write() */

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

/*

*/
enum appl_status
appl_buf_copy(
    struct appl_buf * const
        p_buf,
    struct appl_buf const * const
        p_buf_source,
    unsigned long int * const
        p_count)
{
    enum appl_status
        e_status;

    unsigned long int
        i_count;

    struct appl_buf
        o_buf_source_it;

    i_count =
        0ul;

    o_buf_source_it =
        *(
            p_buf_source);

    while (
        (
            o_buf_source_it.o_min.pc_uchar
            < o_buf_source_it.o_max.pc_uchar)
        && (
            p_buf->o_min.p_uchar
            < p_buf->o_max.p_uchar))
    {
        *(
            p_buf->o_min.p_uchar) =
            *(
                o_buf_source_it.o_min.pc_uchar);

        o_buf_source_it.o_min.pc_uchar ++;

        p_buf->o_min.p_uchar ++;

        i_count ++;
    }

    *(
        p_count) =
        i_count;

    e_status =
        appl_status_ok;

    return
        e_status;

} /* appl_buf_copy() */

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
enum appl_status
appl_buf_print_number(
    struct appl_buf * const
        p_buf,
    signed long int const
        i_value,
    unsigned long int const
        i_flags)
{
    enum appl_status
        e_status;

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

    char
        b_sign;

    unsigned char
        i_sign;

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

    e_status =
        appl_status_ok;

    if (i_width > (i_count + b_sign))
    {
        i_width = (i_width - i_count - b_sign);
    }

    /* space padding for right align */
    if (
        appl_status_ok
        == e_status)
    {
        if (
            (
                !(APPL_BUF_PRINT_PAD_ZERO & i_flags))
            && (
                !(APPL_BUF_PRINT_ALIGN_LEFT & i_flags)))
        {
            while (
                (
                    appl_status_ok == e_status)
                && (
                    i_width))
            {
                e_status =
                    appl_buf_write(
                        p_buf,
                        ' ');

                i_width --;
            }
        }
    }

    /* sign */
    if (
        appl_status_ok
        == e_status)
    {
        if (b_sign)
        {
            e_status =
                appl_buf_write(
                    p_buf,
                    i_sign);
        }
    }

    /* zero padding */
    if (
        appl_status_ok
        == e_status)
    {
        if (APPL_BUF_PRINT_PAD_ZERO & i_flags)
        {
            while (
                (
                    appl_status_ok == e_status)
                && (
                    i_width))
            {
                e_status =
                    appl_buf_write(
                        p_buf,
                        '0');

                i_width --;
            }
        }
    }

    /* digits */
    while (
        (
            appl_status_ok
            == e_status)
        && i_count)
    {
        i_count --;

        e_status =
            appl_buf_write(
                p_buf,
                a_digits[i_count]);
    }

    /* space padding for left align */
    if (
        appl_status_ok
        == e_status)
    {
        if (
            (APPL_BUF_PRINT_ALIGN_LEFT & i_flags)
            && (
                !(APPL_BUF_PRINT_PAD_ZERO & i_flags)))
        {
            while (
                (
                    appl_status_ok == e_status)
                && (
                    i_width))
            {
                e_status =
                    appl_buf_write(
                        p_buf,
                        ' ');

                i_width --;
            }
        }
    }

    return
        e_status;

} /* appl_buf_print_number() */

/* end-of-file: appl_buf.cpp */
