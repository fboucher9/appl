/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_crc_test.h>

#include <appl_crc16.h>

#include <appl_crc32.h>

#include <appl_unused.h>

#include <appl_options_handle.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <stdio.h>

enum appl_status
    appl_crc16_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    struct appl_crc16_context
        o_crc16_context;

    appl_unused(
        p_context);

    appl_crc16_init(
        &(
            o_crc16_context));

    unsigned long int
        i_options_count;

    e_status =
        appl_options_count(
            p_options,
            &(
                i_options_count));

    if (
        appl_status_ok
        == e_status)
    {
        if (
            i_options_count
            > (i_shift + 1u))
        {
            bool
                b_more_options;

            b_more_options =
                true;

            unsigned long int
                i_options_index;

            i_options_index =
                i_shift + 1u;

            while (
                b_more_options)
            {
                unsigned char const *
                    p_data_min;

                unsigned char const *
                    p_data_max;

                if (
                    appl_status_ok
                    == appl_options_get(
                        p_options,
                        i_options_index,
                        &(
                            p_data_min),
                        &(
                            p_data_max)))
                {
                    appl_crc16_write(
                        &(
                            o_crc16_context),
                        p_data_min,
                        p_data_max);

                    i_options_index ++;
                }
                else
                {
                    b_more_options =
                        false;
                }
            }
        }
        else
        {
            /* Read from stdin */
            while (!feof(stdin))
            {
                static unsigned char a_chunk[1024u];
                appl_size_t i_chunk_length;

                i_chunk_length =
                    fread(
                        a_chunk,
                        1u,
                        1024u,
                        stdin);

                if (
                    (
                        i_chunk_length
                        > 0)
                    && (
                        i_chunk_length <= 1024u))
                {
                    appl_crc16_write(
                        &(
                            o_crc16_context),
                        a_chunk,
                        a_chunk + i_chunk_length);
                }
            }
        }

        unsigned short int
            i_result;

        i_result =
            appl_crc16_result(
                &(
                    o_crc16_context));

        printf(
            "%04hx\n",
            i_result);
    }

    return
        e_status;

}

enum appl_status
    appl_crc32_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    struct appl_crc32_context
        o_crc32_context;

    appl_unused(
        p_context);

    appl_crc32_init(
        &(
            o_crc32_context));

    unsigned long int
        i_options_count;

    e_status =
        appl_options_count(
            p_options,
            &(
                i_options_count));

    if (
        appl_status_ok
        == e_status)
    {
        if (
            i_options_count
            > (i_shift + 1u))
        {
            bool
                b_more_options;

            b_more_options =
                true;

            unsigned long int
                i_options_index;

            i_options_index =
                i_shift + 1u;

            while (
                b_more_options)
            {
                unsigned char const *
                    p_data_min;

                unsigned char const *
                    p_data_max;

                if (
                    appl_status_ok
                    == appl_options_get(
                        p_options,
                        i_options_index,
                        &(
                            p_data_min),
                        &(
                            p_data_max)))
                {
                    appl_crc32_write(
                        &(
                            o_crc32_context),
                        p_data_min,
                        p_data_max);

                    i_options_index ++;
                }
                else
                {
                    b_more_options =
                        false;
                }
            }
        }
        else
        {
            /* Read from stdin */
            while (!feof(stdin))
            {
                static unsigned char a_chunk[1024u];
                appl_size_t i_chunk_length;

                i_chunk_length =
                    fread(
                        a_chunk,
                        1u,
                        1024u,
                        stdin);

                if (
                    (
                        i_chunk_length
                        > 0)
                    && (
                        i_chunk_length <= 1024u))
                {
                    appl_crc32_write(
                        &(
                            o_crc32_context),
                        a_chunk,
                        a_chunk + i_chunk_length);
                }
            }
        }
    }

    unsigned long int
        i_result;

    i_result =
        appl_crc32_result(
            &(
                o_crc32_context));

    printf(
        "%08lx\n",
        i_result);

    return
        e_status;

}

//
//
//
void
    appl_crc_test_1(
        struct appl_context * const
            p_context)
{
    static unsigned char g_crc_vector[] =
    {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8
    };

    appl_unused(
        p_context);

    {
        unsigned short int
            i_crc16_result;

        i_crc16_result =
            appl_crc16(
                g_crc_vector,
                g_crc_vector + sizeof(g_crc_vector));

        appl_unused(
            i_crc16_result);
    }

    {
        unsigned long int
            i_crc32_result;

        i_crc32_result =
            appl_crc32(
                g_crc_vector,
                g_crc_vector + sizeof(g_crc_vector));

        appl_unused(
            i_crc32_result);
    }

} // appl_crc_test_1()

/* end-of-file: appl_crc_test.cpp */
