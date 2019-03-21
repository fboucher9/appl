/* See LICENSE for license details */

/*

Installation:
    gcc -I. -Iinclude \
        url/appl_percent_main.c \
        url/appl_percent.cpp \
        buf/appl_buf.cpp \
        buf/appl_buf_filter.cpp

*/

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <appl.h>

#include <url/appl_percent_main.h>

#include <url/appl_percent.h>

static
enum appl_status
    dispatch_enc(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_arg_min;

    unsigned char const *
        p_arg_max;

    (void)(
        p_context);

    e_status =
        appl_options_get(
            p_options,
            i_shift + 1ul,
            &(
                p_arg_min),
            &(
                p_arg_max));

    if (
        appl_status_ok
        == e_status)
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

        o_input.o_min.pc_uchar =
            p_arg_min;

        o_input.o_max.pc_uchar =
            p_arg_max;

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
        else
        {
            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;

}

static
enum appl_status
    dispatch_dec(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_arg_min;

    unsigned char const *
        p_arg_max;

    (void)(
        p_context);

    e_status =
        appl_options_get(
            p_options,
            i_shift + 1ul,
            &(
                p_arg_min),
            &(
                p_arg_max));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_buf
            o_input;

        struct appl_buf
            o_output;

        unsigned long int
            i_length;

        static unsigned char s_output[4096u];

        o_input.o_min.pc_uchar =
            p_arg_min;

        o_input.o_max.pc_uchar =
            p_arg_max;

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
        else
        {
            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;

}

enum appl_status
    appl_percent_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_arg_min;

    unsigned char const *
        p_arg_max;

    e_status =
        appl_options_get(
            p_options,
            i_shift + 1ul,
            &(
                p_arg_min),
            &(
                p_arg_max));

    if (
        appl_status_ok
        == e_status)
    {
        static unsigned char const s_ref_enc[] =
        {
            'e',
            'n',
            'c'
        };

        static unsigned char const s_ref_dec[] =
        {
            'd',
            'e',
            'c'
        };

        if (
            0
            == appl_buf_compare(
                p_arg_min,
                p_arg_max,
                s_ref_enc,
                s_ref_enc + sizeof(s_ref_enc)))
        {
            e_status =
                dispatch_enc(
                    p_context,
                    p_options,
                    i_shift + 1ul);
        }
        else if (
            0
            == appl_buf_compare(
                p_arg_min,
                p_arg_max,
                s_ref_dec,
                s_ref_dec + sizeof(s_ref_dec)))
        {
            e_status =
                dispatch_dec(
                    p_context,
                    p_options,
                    i_shift + 1ul);
        }
        else
        {
            e_status =
                appl_status_invalid_param;
        }
    }

    return
        e_status;

}

