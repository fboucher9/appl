/* See LICENSE for license details */

/*

Module: appl_string_handle.h

Description:

Comments:

    -   Support for two types of strings
        -   Static constant string (i_alloc_len = 0)
        -   Dynamic writeable string with initial content (copied from ref)

*/

/* Reverse include guard */
#if defined INC_APPL_STRING_HANDLE_H
#error include appl_string_handle.h once
#endif /* #if defined INC_APPL_STRING_HANDLE_H */

#define INC_APPL_STRING_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_HANDLE_H
#error include appl_object_handle.h before
#endif /* #if ! defined INC_APPL_OBJECT_HANDLE_H */

struct appl_buf;

struct appl_string_handle;

struct appl_string_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_string_handle */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_string_create(
    struct appl_object_handle * const
        p_object_handle,
    struct appl_buf const * const
        p_ref_buf,
    unsigned long int const
        i_alloc_len,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_length(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned long int * const
        r_buf_len);

enum appl_status
appl_string_read(
    struct appl_string_handle const * const
        p_string_handle,
    struct appl_buf * const
        p_buf);

enum appl_status
appl_string_write(
    struct appl_string_handle * const
        p_string_handle,
    struct appl_buf * const
        p_buf);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_string_handle.h */
