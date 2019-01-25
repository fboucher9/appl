/* See LICENSE for license details */

/*

*/

#include <buf/appl_buf_test.h>

#include <appl_buf.h>

#include <appl_unused.h>

//
//
//
void
    appl_buf_test_1(
        struct appl_context * const
            p_context)
{
    static unsigned char const s_buf[] =
    {
        'h',
        'e',
        'l',
        'l',
        'o'
    };

    appl_unused(
        p_context);

    unsigned char
        a_buf[10u];

    {
        appl_buf_len(
            s_buf,
            s_buf + sizeof(s_buf));
    }

    {
        appl_buf_write(
            a_buf,
            a_buf + sizeof(a_buf),
            123u);
    }

    {
        appl_buf_fill(
            a_buf,
            a_buf + sizeof(a_buf),
            123u);
    }

    {
        appl_buf_copy(
            a_buf,
            a_buf + sizeof(a_buf),
            s_buf,
            s_buf + sizeof(s_buf));
    }

    {
        appl_buf_compare(
            a_buf,
            a_buf + sizeof(a_buf),
            s_buf,
            s_buf + sizeof(s_buf));

        appl_buf_compare(
            s_buf,
            s_buf + sizeof(s_buf),
            a_buf,
            a_buf + sizeof(a_buf));
    }

    {
        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            12345u,
            0,
            0);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            12345u,
            appl_buf_print_flag_binary,
            0);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            12345u,
            appl_buf_print_flag_octal,
            0);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            12345u,
            appl_buf_print_flag_hex,
            0);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            12345u,
            appl_buf_print_flag_unsigned,
            0);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            -12345u,
            0,
            0);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            12345u,
            appl_buf_print_flag_space,
            10);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            -12345u,
            appl_buf_print_flag_space,
            10);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            12345u,
            appl_buf_print_flag_plus,
            10);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            -12345u,
            appl_buf_print_flag_plus,
            10);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            12345u,
            appl_buf_print_flag_zero,
            10);

        appl_buf_print_number(
            a_buf,
            a_buf + sizeof(a_buf),
            12345u,
            appl_buf_print_flag_left,
            10);
    }

    {
        static unsigned char const s_number_base2[] =
        {
            '1',
            '1',
            '0',
            '1'
        };

        signed long int i_value;

        appl_buf_scan_number(
            s_number_base2,
            s_number_base2 + sizeof(s_number_base2),
            &(i_value),
            appl_buf_scan_flag_binary);

        static unsigned char const s_number_base8[] =
        {
            '2',
            '7',
            '3'
        };

        appl_buf_scan_number(
            s_number_base8,
            s_number_base8 + sizeof(s_number_base8),
            &(i_value),
            appl_buf_scan_flag_octal);

        static unsigned char const s_number_base10[] =
        {
            '1',
            '2',
            '3',
            '4',
            '5'
        };

        appl_buf_scan_number(
            s_number_base10,
            s_number_base10 + sizeof(s_number_base10),
            &(i_value),
            0);

        static unsigned char const s_number_base10_neg[] =
        {
            '-',
            '1',
            '2',
            '3',
            '4',
            '5'
        };

        appl_buf_scan_number(
            s_number_base10_neg,
            s_number_base10_neg + sizeof(s_number_base10_neg),
            &(i_value),
            0);

        static unsigned char const s_number_base16[] =
        {
            'b',
            'E',
            'e',
            'F'
        };

        appl_buf_scan_number(
            s_number_base16,
            s_number_base16 + sizeof(s_number_base16),
            &(i_value),
            appl_buf_scan_flag_hex);

        appl_buf_scan_number(
            s_number_base16,
            s_number_base16 + sizeof(s_number_base16),
            &(i_value),
            0);

        appl_buf_scan_number(
            s_buf,
            s_buf + sizeof(s_buf),
            &(i_value),
            0);
    }

} // appl_buf_test_1()

/* end-of-file: appl_buf_test.cpp */
