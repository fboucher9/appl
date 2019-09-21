/* See LICENSE for license details */

/*

*/

#include <appl_predefines.h>

#include <buf/appl_buf_test.h>

#include <appl_buf.h>

#include <appl_buf_filter.h>

#include <appl_unused.h>

#include <stdio.h>

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
        appl_buf_zero(
            a_buf,
            a_buf + sizeof(a_buf));
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
            -12345,
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
            -12345,
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
            -12345,
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

    {
        static unsigned char const s_values[] =
        {
            'c',
            'd',
            'e',
            'a',
            'b'
        };

        {
            unsigned char
                c_min_value;

            c_min_value =
                appl_buf_min_value(
                    s_values,
                    s_values + sizeof(s_values));

            if (
                'a' == c_min_value)
            {
            }
            else
            {
                printf("!!! ERROR !!!\n");
            }
        }

        {
            unsigned char
                c_max_value;

            c_max_value =
                appl_buf_max_value(
                    s_values,
                    s_values + sizeof(s_values));

            if (
                'e' == c_max_value)
            {
            }
            else
            {
                printf("!!! ERROR !!!\n");
            }
        }
    }

    {
        static unsigned char const s_filter1[] =
        {
            'a',
            0x02u
        };

        struct appl_buf
            o_buf_filter;

        o_buf_filter.o_min.pc_uchar =
            s_filter1;

        o_buf_filter.o_max.pc_uchar =
            s_filter1 + sizeof(s_filter1);

        char
            b_result;

        b_result =
            appl_buf_filter_test(
                &(
                    o_buf_filter),
                'a');

        printf(
            "filter test a = %d\n",
            static_cast<int>(
                b_result));

        b_result =
            appl_buf_filter_test(
                &(
                    o_buf_filter),
                'b');

        printf(
            "filter test b = %d\n",
            static_cast<int>(
                b_result));

        b_result =
            appl_buf_filter_test(
                &(
                    o_buf_filter),
                'c');

        printf(
            "filter test c = %d\n",
            static_cast<int>(
                b_result));

        b_result =
            appl_buf_filter_test(
                &(
                    o_buf_filter),
                ' ');

        printf(
            "filter test sp = %d\n",
            static_cast<int>(
                b_result));

        b_result =
            appl_buf_filter_test(
                &(
                    o_buf_filter),
                0xa2u);

        printf(
            "filter test a2 = %d\n",
            static_cast<int>(
                b_result));

    }

    {
        static unsigned char const s_list[] =
        {
            'c',
            'd',
            'e',
            'f',
            'g',
            'm',
            'l'
        };

        struct appl_buf
            o_ref_list;

        o_ref_list.o_min.pc_uchar =
            s_list;

        o_ref_list.o_max.pc_uchar =
            s_list + sizeof(s_list);

        unsigned long int
            i_length;

        i_length =
            appl_buf_filter_get_list_length(
                &(
                    o_ref_list));

        if (
            3ul
            == i_length)
        {
            unsigned char
                a_filter[3u];

            struct appl_buf
                o_filter;

            o_filter.o_min.p_uchar =
                a_filter;

            o_filter.o_max.p_uchar =
                a_filter + sizeof(a_filter);

            appl_buf_filter_convert_list(
                &(
                    o_filter),
                &(
                    o_ref_list));

            printf(
                "convert list -> \'%c\' %02hx %02hx\n",
                static_cast<unsigned short int>(
                    a_filter[0u]),
                static_cast<unsigned short int>(
                    a_filter[1u]),
                static_cast<unsigned short int>(
                    a_filter[2u]));
        }
    }

    {
        static unsigned char const s_ref_class[] =
        {
            'c',
            '-',
            'g',
            'm',
            '-',
            'l'
        };

        struct appl_buf
            o_ref_class;

        o_ref_class.o_min.pc_uchar =
            s_ref_class;

        o_ref_class.o_max.pc_uchar =
            s_ref_class + sizeof(s_ref_class);

        unsigned long int
            i_length;

        i_length =
            appl_buf_filter_get_class_length(
                &(
                    o_ref_class));

        if (
            3ul
            == i_length)
        {
            unsigned char
                a_filter[3u];

            struct appl_buf
                o_filter;

            o_filter.o_min.p_uchar =
                a_filter;

            o_filter.o_max.p_uchar =
                a_filter + sizeof(a_filter);

            appl_buf_filter_convert_class(
                &(
                    o_filter),
                &(
                    o_ref_class));

            printf("convert class -> \'%c\' %02hx %02hx\n",
                static_cast<char>(
                    a_filter[0u]),
                static_cast<unsigned short int>(
                    a_filter[1u]),
                static_cast<unsigned short int>(
                    a_filter[2u]));
        }
    }

} // appl_buf_test_1()

/* end-of-file: appl_buf_test.cpp */
