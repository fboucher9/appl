/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <url/appl_percent.h>

#include <appl_buf.h>

#include <appl_buf_filter.h>

#include <appl_convert.h>

#include <appl_unused.h>

//
//
//
class appl_percent_service
{
    public:

        static
        unsigned long int
            s_decoder_length(
                struct appl_buf const * const
                    p_input);

        static
        void
            s_decoder_convert(
                struct appl_buf * const
                    p_input_iterator,
                struct appl_buf * const
                    p_output_iterator);

        static
        unsigned long int
            s_encoder_length(
                struct appl_buf const * const
                    p_input,
                struct appl_buf const * const
                    p_filter);

        static
        void
            s_encoder_convert(
                struct appl_buf * const
                    p_input_iterator,
                struct appl_buf const * const
                    p_filter,
                struct appl_buf * const
                    p_output_iterator);

        static
        unsigned char
            s_ascii_to_hex(
                unsigned char const
                    c_ascii);

        static
        unsigned char
            s_hex_to_ascii(
                unsigned char const
                    i_hexdigit);

        static
        bool
            s_test_filter(
                struct appl_buf const * const
                    p_filter,
                unsigned char const
                    c_data);

}; // class appl_percent_service

//
//
//
unsigned long int
    appl_percent_service::s_decoder_length(
        struct appl_buf const * const
            p_input)
{
    unsigned long int
        i_length;

    i_length =
        0ul;

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

        if (
            (
                '%'
                == c_data)
            && (
               (p_input_iterator + 2u)
               < p_input->o_max.pc_uchar))
        {
            i_length ++;
            p_input_iterator += 3u;
        }
        else
        {
            i_length ++;
            p_input_iterator ++;
        }
    }

    return
        i_length;

} // s_decoder_length()

//
//
//
void
    appl_percent_service::s_decoder_convert(
        struct appl_buf * const
            p_input_iterator,
        struct appl_buf * const
            p_output_iterator)
{
    while (
        (
            p_input_iterator->o_min.pc_uchar
            < p_input_iterator->o_max.pc_uchar)
        && (
            p_output_iterator->o_min.pc_uchar
            < p_output_iterator->o_max.pc_uchar))
    {
        unsigned char const
            c_data =
            *(
                p_input_iterator->o_min.pc_uchar);

        if (
            (
                '%'
                == c_data)
            && (
            (p_input_iterator->o_min.pc_uchar + 2u)
            < p_input_iterator->o_max.pc_uchar))
        {
            unsigned char const
                c_nibble_high =
                *(
                    p_input_iterator->o_min.pc_uchar + 1u);

            unsigned char const
                c_nibble_low =
                *(
                    p_input_iterator->o_min.pc_uchar + 2u);

            unsigned char const
                i_hexdigit_high =
                appl_percent_service::s_ascii_to_hex(
                    c_nibble_high);

            unsigned char const
                i_hexdigit_low =
                appl_percent_service::s_ascii_to_hex(
                    c_nibble_low);

            *(
                p_output_iterator->o_min.p_uchar) =
                appl_convert::to_uchar(
                    (
                        i_hexdigit_low & 0x0Fu)
                    + (
                        (
                            i_hexdigit_high & 0x0Fu)
                        << 4u));

            p_input_iterator->o_min.pc_uchar += 3u;
        }
        else
        {
            *(
                p_output_iterator->o_min.p_uchar) =
                c_data;

            p_input_iterator->o_min.pc_uchar ++;
        }

        p_output_iterator->o_min.pc_uchar ++;
    }

} // s_decoder_convert()

//
//
//
unsigned long int
    appl_percent_service::s_encoder_length(
        struct appl_buf const * const
            p_input,
        struct appl_buf const * const
            p_filter)
{
    unsigned long int
        i_length;

    i_length =
        0u;

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

        if (
            appl_percent_service::s_test_filter(
                p_filter,
                c_data))
        {
            i_length ++;
        }
        else
        {
            i_length += 3u;
        }
    }

    return
        i_length;

} // s_encoder_length()

//
//
//
void
    appl_percent_service::s_encoder_convert(
        struct appl_buf * const
            p_input_iterator,
        struct appl_buf const * const
            p_filter,
        struct appl_buf * const
            p_output_iterator)
{
    appl_unused(
        p_input_iterator,
        p_filter,
        p_output_iterator);

} // s_encoder_convert()

//
//
//
unsigned long int
    appl_percent_decoder_length(
        struct appl_buf const * const
            p_input)
{
    return
        appl_percent_service::s_decoder_length(
            p_input);

} // appl_percent_decoder_length()

//
//
//
void
    appl_percent_decoder_convert(
        struct appl_buf * const
            p_input_iterator,
        struct appl_buf * const
            p_output_iterator)
{
    appl_percent_service::s_decoder_convert(
        p_input_iterator,
        p_output_iterator);

} // appl_percent_decoder_convert()

//
//
//
unsigned long int
    appl_percent_encoder_length(
        struct appl_buf const * const
            p_input,
        struct appl_buf const * const
            p_filter)
{
    return
        appl_percent_service::s_encoder_length(
            p_input,
            p_filter);

} // appl_percent_encoder_length()

//
//
//
void
    appl_percent_encoder_convert(
        struct appl_buf * const
            p_input_iterator,
        struct appl_buf const * const
            p_filter,
        struct appl_buf * const
            p_output_iterator)
{
    appl_percent_service::s_encoder_convert(
        p_input_iterator,
        p_filter,
        p_output_iterator);

} // appl_percent_encoder_convert()

//
//
//
unsigned char
    appl_percent_service::s_ascii_to_hex(
        unsigned char const
            c_ascii)
{
    unsigned char
        i_hexdigit;

    if (
        (
            '0' <= c_ascii)
        && (
            '9' >= c_ascii))
    {
        i_hexdigit =
            appl_convert::to_uchar(
                c_ascii - '0' + 0u);
    }
    else if (
        (
            'a' <= c_ascii)
        && (
            'f' >= c_ascii))
    {
        i_hexdigit =
            appl_convert::to_uchar(
                c_ascii - 'a' + 10u);
    }
    else if (
        (
            'A' <= c_ascii)
        && (
            'F' >= c_ascii))
    {
        i_hexdigit =
            appl_convert::to_uchar(
                c_ascii - 'A' + 10u);
    }
    else
    {
        i_hexdigit =
            0u;
    }

    return
        i_hexdigit;

} // s_ascii_to_hex()

//
//
//
unsigned char
    appl_percent_service::s_hex_to_ascii(
        unsigned char const
            i_hexdigit)
{
    static unsigned char const s_hex_to_ascii_table[16u] =
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
        'A',
        'B',
        'C',
        'D',
        'E',
        'F'
    };

    unsigned char
        c_ascii;

    c_ascii =
        s_hex_to_ascii_table[
            i_hexdigit & 0x0Fu];

    return
        c_ascii;

} // s_hex_to_ascii()

//
//
//
bool
    appl_percent_service::s_test_filter(
        struct appl_buf const * const
            p_filter,
        unsigned char const
            c_data)
{
    bool
        b_result;

    b_result =
        appl_buf_filter_test(
            p_filter,
            c_data);

    return
        b_result;

} // s_test_filter()

/* end-of-file: appl_percent.cpp */
