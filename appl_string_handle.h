/* See LICENSE for license details */

/*

Module: appl_string_handle.h

Description:

Comments:

    -   Support for two types of strings
        -   Static constant string (i_alloc_len = 0)
        -   Dynamic writeable string with initial empty content

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
    struct appl_object_handle const * const
        p_object_handle,
    unsigned long int const
        i_alloc_len,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_create_ref_buffer(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_create_ref_buffer_n(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_count,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_create_ref_object(
    struct appl_string_handle const * const
        p_ref_string_handle,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_create_ref_object_n(
    struct appl_string_handle const * const
        p_ref_string_handle,
    unsigned long int const
        i_count,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_create_dup_buffer(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_create_dup_buffer_n(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_count,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_create_dup_object(
    struct appl_string_handle const * const
        p_ref_string_handle,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_create_dup_object_n(
    struct appl_string_handle const * const
        p_ref_string_handle,
    unsigned long int const
        i_count,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_create_extern(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    struct appl_string_handle * * const
        r_string_handle);

enum appl_status
appl_string_length(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned long int * const
        r_length);

enum appl_status
appl_string_read(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max);

enum appl_status
appl_string_begin_write(
    struct appl_string_handle * const
        p_string_handle,
    unsigned char * * const
        r_buf_it,
    unsigned char * * const
        r_buf_max);

enum appl_status
appl_string_end_write(
    struct appl_string_handle * const
        p_string_handle,
    unsigned char * const
        r_buf_it);

enum appl_status
appl_string_write_char(
    struct appl_string_handle * const
        p_string_handle,
    unsigned char const
        i_value);

enum appl_status
appl_string_write_buffer(
    struct appl_string_handle * const
        p_string_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max);

enum appl_status
appl_string_write_buffer_n(
    struct appl_string_handle * const
        p_string_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_count);

enum appl_status
appl_string_write_object(
    struct appl_string_handle * const
        p_string_handle,
    struct appl_string_handle const * const
        p_ref_string_handle);

enum appl_status
appl_string_write_object_n(
    struct appl_string_handle * const
        p_string_handle,
    struct appl_string_handle const * const
        p_ref_string_handle,
    unsigned long int const
        i_count);

enum appl_status
appl_string_compare_buffer(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    signed int * const
        r_result);

enum appl_status
appl_string_compare_buffer_n(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_compare_len,
    signed int * const
        r_result);

enum appl_status
appl_string_compare_object(
    struct appl_string_handle const * const
        p_string_handle,
    struct appl_string_handle const * const
        p_ref_string_handle,
    signed int * const
        r_result);

enum appl_status
appl_string_compare_object_n(
    struct appl_string_handle const * const
        p_string_handle,
    struct appl_string_handle const * const
        p_ref_string_handle,
    unsigned long int const
        i_compare_len,
    signed int * const
        r_result);

enum appl_status
appl_string_case_compare_buffer(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    signed int * const
        r_result);

enum appl_status
appl_string_case_compare_buffer_n(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_compare_len,
    signed int * const
        r_result);

enum appl_status
appl_string_case_compare_object(
    struct appl_string_handle const * const
        p_string_handle,
    struct appl_string_handle const * const
        p_ref_string_handle,
    signed int * const
        r_result);

enum appl_status
appl_string_case_compare_object_n(
    struct appl_string_handle const * const
        p_string_handle,
    struct appl_string_handle const * const
        p_ref_string_handle,
    unsigned long int const
        i_compare_len,
    signed int * const
        r_result);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_string_handle.h */
