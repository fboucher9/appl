/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_FILE_HANDLE_H)
#error include appl_file_handle.h once
#endif /* #if defined(INC_APPL_FILE_HANDLE_H) */

#define INC_APPL_FILE_HANDLE_H

/* Header file dependencies */
#if !defined(INC_APPL_STATUS_H)
#error include appl_status.h before
#endif /* #if !defined(INC_APPL_STATUS_H) */

/* Header file dependencies */
#if !defined(INC_APPL_OBJECT_HANDLE_H)
#error include appl_object_handle.h before
#endif /* #if !defined(INC_APPL_OBJECT_HANDLE_H) */

struct appl_file_handle;

struct appl_file_descriptor;

struct appl_file_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_file_handle */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_file_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_file_descriptor const * const
        p_file_descriptor,
    struct appl_file_handle * * const
        r_file_handle);

enum appl_status
appl_file_read(
    struct appl_file_handle * const
        p_file_handle,
    unsigned char * const
        p_buffer,
    unsigned long int const
        i_buffer_max_length,
    unsigned long int * const
        p_actual_length);

enum appl_status
appl_file_write(
    struct appl_file_handle * const
        p_file_handle,
    unsigned char const * const
        p_buffer,
    unsigned long int const
        i_buffer_max_length,
    unsigned long int * const
        p_actual_length);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_file_handle.h */
