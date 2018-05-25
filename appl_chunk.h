/* See LICENSE for license details */

/*

Notes:

    -   Append only to end of buffer.

    -   Read only from beginning of buffer.

*/

/* Reverse include guard */
#if defined INC_APPL_CHUNK_H
#error include appl_chunk.h once
#endif /* #if defined INC_APPL_CHUNK_H */

#define INC_APPL_CHUNK_H

struct appl_context;

struct appl_chunk;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_chunk_create(
    struct appl_context * const
        p_context,
    struct appl_chunk * * const
        r_chunk);

enum appl_status
appl_chunk_destroy(
    struct appl_chunk * const
        p_chunk);

enum appl_status
appl_chunk_write(
    struct appl_chunk * const
        p_chunk,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max);

enum appl_status
appl_chunk_length(
    struct appl_chunk const * const
        p_chunk,
    unsigned long int * const
        r_length);

enum appl_status
appl_chunk_read(
    struct appl_chunk const * const
        p_chunk,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_chunk.h */
