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
    inc_appl_crc16_h =
        /* Header file dependencies */
        1
};

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

/** Calculate 16-bit crc of given buffer.

Apply crc algorithm on each byte of the given buffer to obtain a 16-bit
integer value.  The algorithm is implemented according to standard crc
used by usb packets.

*/
unsigned short int
appl_crc16(
    /** Pointer to buffer */
    unsigned char const * const
        p_buf,
    /** Length in bytes of buffer */
    unsigned long int const
        i_buf_len);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_crc16.h */
