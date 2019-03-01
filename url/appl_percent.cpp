/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <url/appl_percent.h>

#include <appl_buf.h>

#include <appl_buf_filter.h>

#include <appl_convert.h>

#include <appl_unused.h>

union write_context_ptr
{
    void *
        p_write_context;

    unsigned long int *
        p_length;

    struct appl_buf *
        p_buf;

};

//
//
//
static
void
    length_callback(
        void * const
            p_write_context,
        unsigned char const
            c_data)
{
    appl_unused(
        c_data);

    union write_context_ptr
        o_write_context_ptr;

    o_write_context_ptr.p_write_context =
        p_write_context;

    (*o_write_context_ptr.p_length) ++;

} // length_callback()

//
//
//
static
void
convert_callback(
    void * const
        p_write_context,
    unsigned char const
        c_data)
{
    union write_context_ptr
        o_write_context_ptr;

    o_write_context_ptr.p_write_context =
        p_write_context;

    o_write_context_ptr.p_buf->o_min.p_uchar =
        appl_buf_write(
            o_write_context_ptr.p_buf->o_min.p_uchar,
            o_write_context_ptr.p_buf->o_max.p_uchar,
            c_data);

} // convert_callback()

//
//
//
class appl_percent_service
{
    public:

        static
        void
            s_decoder_run(
                struct appl_buf * const
                    p_input_iterator,
                void (* p_write_callback)(
                    void * const
                        p_write_context,
                    unsigned char const
                        c_data),
                void * const
                    p_write_context);

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
        void
            s_encoder_run(
                struct appl_buf * const
                    p_input_iterator,
                struct appl_buf const * const
                    p_filter,
                void (* p_write_callback)(
                    void * const
                        p_write_context,
                    unsigned char const
                        c_data),
                void * const
                    p_write_context);

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
void
    appl_percent_service::s_decoder_run(
        struct appl_buf * const
            p_input_iterator,
        void (* p_write_callback)(
            void * const
                p_write_context,
            unsigned char const
                c_data),
        void * const
            p_write_context)
{
    while (
        p_input_iterator->o_min.pc_uchar
        < p_input_iterator->o_max.pc_uchar)
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

            (*p_write_callback)(
                p_write_context,
                appl_convert::to_uchar(
                    (
                        i_hexdigit_low & 0x0Fu)
                    + (
                        (
                            i_hexdigit_high & 0x0Fu)
                        << 4u)));

            p_input_iterator->o_min.pc_uchar += 3u;
        }
        else
        {
            (*p_write_callback)(
                p_write_context,
                c_data);

            p_input_iterator->o_min.pc_uchar ++;
        }
    }
}

//
//
//
unsigned long int
    appl_percent_service::s_decoder_length(
        struct appl_buf const * const
            p_input)
{
    struct appl_buf
        o_input_iterator;

    o_input_iterator =
        *(
            p_input);

    unsigned long int
        i_length;

    i_length =
        0ul;

    appl_percent_service::s_decoder_run(
        &(
            o_input_iterator),
        &(
            length_callback),
        &(
            i_length));

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
    appl_percent_service::s_decoder_run(
        p_input_iterator,
        &(
            convert_callback),
        p_output_iterator);

} // s_decoder_convert()

//
//
//
void
    appl_percent_service::s_encoder_run(
        struct appl_buf * const
            p_input_iterator,
        struct appl_buf const * const
            p_filter,
        void (* p_write_callback)(
            void * const
                p_write_context,
            unsigned char const
                c_data),
        void * const
            p_write_context)
{
    while (
        p_input_iterator->o_min.pc_uchar
        < p_input_iterator->o_max.pc_uchar)
    {
        unsigned char const
            c_data =
            *(
                p_input_iterator->o_min.pc_uchar);

        p_input_iterator->o_min.pc_uchar ++;

        if (
            appl_percent_service::s_test_filter(
                p_filter,
                c_data))
        {
            (*p_write_callback)(
                p_write_context,
                c_data);
        }
        else
        {
            unsigned char const
                c_nibble_high =
                appl_percent_service::s_hex_to_ascii(
                    (c_data >> 4u) & 0x0Fu);

            unsigned char const
                c_nibble_low =
                appl_percent_service::s_hex_to_ascii(
                    (c_data >> 0u) & 0x0Fu);

            (*p_write_callback)(
                p_write_context,
                '%');

            (*p_write_callback)(
                p_write_context,
                c_nibble_high);

            (*p_write_callback)(
                p_write_context,
                c_nibble_low);
        }
    }

} // s_encoder_run()

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
    struct appl_buf
        o_input_iterator;

    o_input_iterator =
        *(
            p_input);

    unsigned long int
        i_length;

    i_length =
        0u;

    appl_percent_service::s_encoder_run(
        &(
            o_input_iterator),
        p_filter,
        &(
            length_callback),
        &(
            i_length));

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
    appl_percent_service::s_encoder_run(
        p_input_iterator,
        p_filter,
        &(
            convert_callback),
        p_output_iterator);

} // s_encoder_convert()

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

//
//
//
void
    appl_percent_decoder_run(
        struct appl_buf * const
            p_input_iterator,
        void (* p_write_callback)(
            void * const
                p_write_context,
            unsigned char const
                c_data),
        void * const
            p_write_context)
{
    appl_percent_service::s_decoder_run(
        p_input_iterator,
        p_write_callback,
        p_write_context);

} // appl_percent_decoder_run()

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
//  Function: appl_percent_encoder_run()
//
//  Description:
//      Scan the input buffer and do percent encoding on characters that do
//      not match the filter.  Then feed each output character to callback
//      function.
//
//  Parameters:
//      p_input_iterator
//          Pointer to input buffer, this buffer will be iterated, so min
//          is advanced to end of input buffer.
//      p_filter
//          Pointer to filter buffer.  Characters that match the filter are
//          stored directly into output buffer without any encoding, all
//          other characters are percent encoded.
//      p_write_callback
//          Pointer to callback function.  Each output character of percent
//          encoding process is fed to this function.
//      p_write_context
//          Context for callback function.
//
//  Returns: none.
//
//  Comments: none.
//
void
    appl_percent_encoder_run(
        struct appl_buf * const
            p_input_iterator,
        struct appl_buf const * const
            p_filter,
        void (* p_write_callback)(
            void * const
                p_write_context,
            unsigned char const
                c_data),
        void * const
            p_write_context)
{
    appl_percent_service::s_encoder_run(
        p_input_iterator,
        p_filter,
        p_write_callback,
        p_write_context);

} // appl_percent_encoder_run()

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

/* end-of-file: appl_percent.cpp */
