/* See LICENSE for license details */

/**

@file appl_crc16.h

Calculate 16-bit crc.

Group of functions and definitions related to 16-bit crc.

*/

/* Included. */
#define INC_APPL_CRC16_H

/* Reverse include guard */
enum guard_appl_crc16_h
{
    inc_appl_crc16_h = 1
        /* Header file dependencies */
};

#include <appl_extern_c_begin.h>

/** Calculate 16-bit crc of given buffer.

Apply crc algorithm on each byte of the given buffer to obtain a 16-bit
integer value.  The algorithm is implemented according to standard crc
used by usb packets.

*/
unsigned short int
appl_crc16(
    /** Pointer to start of buffer */
    unsigned char const * const
        p_buf_min,
    /** Pointer to end of buffer */
    unsigned char const * const
        p_buf_max);

/*

*/
struct appl_crc16_context
{
    unsigned short int
        a_private[4u];

}; /* struct appl_crc16_context */

void
    appl_crc16_init(
        struct appl_crc16_context * const
            p_crc16_context);

void
    appl_crc16_write(
        struct appl_crc16_context * const
            p_crc16_context,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max);

unsigned short int
    appl_crc16_result(
        struct appl_crc16_context * const
            p_crc16_context);

#include <appl_extern_c_end.h>

/* end-of-file: appl_crc16.h */
