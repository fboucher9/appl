/* See LICENSE for license details */

/*

Module: appl_chunk_handle.h

Description:

    Memory storage for serial data.  When reading data from a source of
    unknown length, store the data into appl_chunk for an efficient use
    of memory.  This object is designed to avoid repeated use of realloc()
    to store serial data into a growing vector.

Notes:

    -   Append only to end of buffer.
    -   Read only from beginning of buffer.
    -   Memory is freed on destroy.

Example:

    struct appl_chunk * p_chunk;
    e_status = appl_chunk_create(p_context, &(p_chunk));
    if (appl_status_ok == e_status)
    {
        while ((appl_status_ok == e_status) && !feof(stdin))
        {
            unsigned char a_input[4u];
            int n = fread(a_input, 1, 4, stdin);
            if (n > 0)
            {
                e_status = appl_chunk_write(p_chunk, a_input, a_input + n);
            }
        }
        if (appl_status_ok == e_status)
        {
            unsigned long int i_total_len;
            e_status = appl_chunk_length(p_chunk, &(i_total_len));
            if (appl_status_ok == e_status)
            {
                union result_ptr {
                    void * p_void;
                    unsigned char * p_uchar
                } o_result;
                e_status = appl_heap_alloc(
                    appl_context_parent(p_context),
                    i_total_len, &(o_result.p_void));
                if (appl_status_ok == e_status)
                {
                    e_status = appl_chunk_read(
                        p_chunk, o_result.p_uchar,
                        o_result.p_uchar + i_total_len);
                    if (appl_status_ok == e_status)
                    {
                    }
                    appl_heap_free(appl_context_parent(p_context),
                        o_result.p_void);
                }
            }
        }
        appl_chunk_destroy(p_chunk);
    }

*/

/* Included. */
#define INC_APPL_CHUNK_HANDLE_H

/* Reverse include guard */
enum guard_appl_chunk_handle_h
{
    inc_appl_chunk_handle_h =
        /* Header file dependency */
        inc_appl_status_h
};

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

enum appl_status
appl_chunk_reset(
    struct appl_chunk * const
        p_chunk);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_chunk_handle.h */
