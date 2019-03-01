/* See LICENSE for license details */

/*

*/

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <url/appl_percent.h>

#include <appl_buf.h>

static
void
    dispatch_enc(
        int const
            argc,
        char const * const * const
            argv)
{
    if (
        argc > 1)
    {
        static unsigned char s_filter[] =
        {
            'a',
            0xFFu,
            0xFFu,
            0xFFu
        };

        struct appl_buf
            o_input;

        struct appl_buf
            o_filter;

        struct appl_buf
            o_output;

        unsigned long int
            i_length;

        static unsigned char s_output[4096u];

        o_filter.o_min.pc_uchar =
            s_filter;

        o_filter.o_max.pc_uchar =
            s_filter + sizeof(s_filter);

        o_input.o_min.pc_char =
            argv[1u];

        o_input.o_max.pc_char =
            argv[1u] + strlen(argv[1u]);

        i_length =
            appl_percent_encoder_length(
                &(
                    o_input),
                &(
                    o_filter));

        if (
            i_length <= sizeof(s_output))
        {
            o_output.o_min.p_uchar =
                s_output;

            o_output.o_max.p_uchar =
                s_output + sizeof(s_output);

            appl_percent_encoder_convert(
                &(
                    o_input),
                &(
                    o_filter),
                &(
                    o_output));

            printf("result = \'%.*s\'\n",
                (int)(
                    i_length),
                (char const *)(
                    s_output));

        }
    }
}

static
void
    dispatch_dec(
        int const
            argc,
        char const * const * const
            argv)
{
    if (
        argc > 1)
    {
        struct appl_buf
            o_input;

        struct appl_buf
            o_output;

        unsigned long int
            i_length;

        static unsigned char s_output[4096u];

        o_input.o_min.pc_uchar =
            argv[1u];

        o_input.o_max.pc_uchar =
            argv[1u] + strlen(argv[1u]);

        i_length =
            appl_percent_decoder_length(
                &(
                    o_input));

        if (
            i_length <= sizeof(s_output))
        {
            o_output.o_min.p_uchar =
                s_output;

            o_output.o_max.p_uchar =
                s_output + sizeof(s_output);

            appl_percent_decoder_convert(
                &(
                    o_input),
                &(
                    o_output));

            printf(
                "result = \'%.*s\'\n",
                (int)(
                    appl_buf_len(
                        s_output,
                        o_output.o_min.p_uchar)),
                (char const *)(
                    s_output));
        }
    }
}

int
    main(
        int const
            argc,
        char const * const * const
            argv)
{
    if (
        argc > 1)
    {
        if (
            0
            == strcmp(
                argv[1u],
                "enc"))
        {
            dispatch_enc(
                argc - 1,
                argv + 1);
        }
        else if (
            0
            == strcmp(
                argv[1u],
                "dec"))
        {
            dispatch_dec(
                argc - 1,
                argv + 1);
        }
    }

    return
        0;

}
