/* See LICENSE for license details */

/*

*/

#include <appl_crc_test.h>

#include <appl_crc16.h>

#include <appl_crc32.h>

#include <appl_unused.h>

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
                static_cast<unsigned long int>(
                    sizeof(
                        g_crc_vector)));

        appl_unused(
            i_crc16_result);
    }

    {
        unsigned long int
            i_crc32_result;

        i_crc32_result =
            appl_crc32(
                g_crc_vector,
                static_cast<unsigned long int>(
                    sizeof(
                        g_crc_vector)));

        appl_unused(
            i_crc32_result);
    }

} // appl_crc_test_1()

/* end-of-file: appl_crc_test.cpp */
