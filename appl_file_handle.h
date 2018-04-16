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

struct appl_object;

struct appl_file;

struct appl_file_descriptor;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_file_create(
    struct appl_context * const
        p_context,
    struct appl_file_descriptor const * const
        p_file_descriptor,
    struct appl_file * * const
        r_file);

struct appl_object *
appl_file_parent(
    struct appl_file * const
        p_file);

struct appl_object const *
appl_file_const_parent(
    struct appl_file const * const
        p_file);

enum appl_status
appl_file_read(
    struct appl_file * const
        p_file,
    unsigned char * const
        p_buf_cur,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count);

enum appl_status
appl_file_write(
    struct appl_file * const
        p_file,
    unsigned char const * const
        p_buf_cur,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_file_handle.h */
