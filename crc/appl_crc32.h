/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_CRC32_H

/* Reverse include guard */
enum guard_appl_crc32_h
{
    inc_appl_crc32_h = 1
        /* Header file dependencies */
};

/*

Structure: appl_crc32_context

Description:
    State for appl_crc32 parser.  Access to members is reserved to appl_crc32
    implementation.

*/
struct appl_crc32_context
{
    unsigned long int
        a_private[2u];

}; /* struct appl_crc32_context */

#include <misc/appl_extern_c_begin.h>

unsigned long int
    appl_crc32(
        unsigned char const * const
            p_data_min,
        unsigned char const * const
            p_data_max);

void
    appl_crc32_init(
        struct appl_crc32_context * const
            p_crc32_context);

void
    appl_crc32_write(
        struct appl_crc32_context * const
            p_crc32_context,
        unsigned char const * const
            p_data_min,
        unsigned char const * const
            p_data_max);

unsigned long int
    appl_crc32_result(
        struct appl_crc32_context const * const
            p_crc32_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_crc32.h */
