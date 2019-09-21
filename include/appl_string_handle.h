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
enum guard_appl_string_handle_h
{
    inc_appl_string_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

struct appl_context;

struct appl_string;

#include <appl_extern_c_begin.h>

enum appl_status
appl_string_create(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_alloc_len,
    struct appl_string * * const
        r_string);

enum appl_status
appl_string_destroy(
    struct appl_string * const
        p_string);

enum appl_status
appl_string_create_dup_buffer(
    struct appl_context const * const
        p_context,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    struct appl_string * * const
        r_string);

enum appl_status
appl_string_create_dup_buffer_n(
    struct appl_context const * const
        p_context,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_count,
    struct appl_string * * const
        r_string);

enum appl_status
appl_string_create_dup_object(
    struct appl_string const * const
        p_ref_string,
    struct appl_string * * const
        r_string);

enum appl_status
appl_string_create_dup_object_n(
    struct appl_string const * const
        p_ref_string,
    unsigned long int const
        i_count,
    struct appl_string * * const
        r_string);

struct appl_object *
appl_string_parent(
    struct appl_string * const
        p_string);

struct appl_object const *
appl_string_const_parent(
    struct appl_string const * const
        p_string);

enum appl_status
appl_string_length(
    struct appl_string const * const
        p_string,
    unsigned long int * const
        r_length);

enum appl_status
appl_string_get(
    struct appl_string const * const
        p_string,
    unsigned char * * const
        r_buf_min,
    unsigned char * * const
        r_buf_max);

#include <appl_extern_c_end.h>

/* end-of-file: appl_string_handle.h */
