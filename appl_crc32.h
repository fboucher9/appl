/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_CRC32_H

/* Reverse include guard */
enum guard_appl_crc32_h
{
    inc_appl_crc32_h =
        /* Header file dependencies */
        1
};

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

unsigned long int
    appl_crc32(
        unsigned char const * const
            p_data,
        unsigned long int const
            i_data_len);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_crc32.h */
