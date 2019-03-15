/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_crc_test.h>

#include <appl_crc16.h>

#include <appl_crc32.h>

#include <appl_unused.h>

#include <appl_options_handle.h>

#include <appl_buf.h>

#include <stdio.h>

//
//
//
enum appl_status
    appl_crc_main(
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

    appl_unused(
        p_context);

    e_status =
        appl_options_get(
            p_options,
            i_shift + 1u,
            &(
                p_arg_min),
            &(
                p_arg_max));

    if (
        appl_status_ok
        == e_status)
    {
        static unsigned char const s_ref_16[] =
        {
            '1',
            '6'
        };

        static unsigned char const s_ref_32[] =
        {
            '3',
            '2'
        };

        unsigned char
            i_crc_type;

        if (
            0
            == appl_buf_compare(
                p_arg_min,
                p_arg_max,
                s_ref_16,
                s_ref_16 + sizeof(s_ref_16)))
        {
            i_crc_type =
                16u;
        }
        else if (
            0
            == appl_buf_compare(
                p_arg_min,
                p_arg_max,
                s_ref_32,
                s_ref_32 + sizeof(s_ref_32)))
        {
            i_crc_type =
                32u;
        }
        else
        {
            i_crc_type =
                0u;
        }

        unsigned char const *
            p_data_min;

        unsigned char const *
            p_data_max;

        e_status =
            appl_options_get(
                p_options,
                i_shift + 2u,
                &(
                    p_data_min),
                &(
                    p_data_max));

        if (
            appl_status_ok
            == e_status)
        {
            if (
                16u
                == i_crc_type)
            {
                struct appl_crc16_context
                    o_crc16_context;

                appl_crc16_init(
                    &(
                        o_crc16_context));

                appl_crc16_write(
                    &(
                        o_crc16_context),
                    p_data_min,
                    p_data_max);

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
            else if (
                32u
                == i_crc_type)
            {
                struct appl_crc32_context
                    o_crc32_context;

                appl_crc32_init(
                    &(
                        o_crc32_context));

                appl_crc32_write(
                    &(
                        o_crc32_context),
                    p_data_min,
                    p_data_max);

                unsigned long int
                    i_result;

                i_result =
                    appl_crc32_result(
                        &(
                            o_crc32_context));

                printf(
                    "%08lx\n",
                    i_result);
            }
            else
            {
            }
        }
    }

    return
        e_status;

} // appl_crc_main()

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
