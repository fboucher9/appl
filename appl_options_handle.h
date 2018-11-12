/* See LICENSE for license details */

/*

Module: appl_options_handle.h

Description:

    Command-line options.

*/

/* Reverse include guard */
#if defined INC_APPL_OPTIONS_HANDLE_H
#error include appl_options_handle.h once
#endif /* #if defined INC_APPL_OPTIONS_HANDLE_H */

#define INC_APPL_OPTIONS_HANDLE_H

struct appl_object;

struct appl_options;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_options_create(
    struct appl_context * const
        p_context,
    struct appl_options * * const
        r_instance);

struct appl_object *
appl_options_parent(
    struct appl_options * const
        p_options);

struct appl_object const *
appl_options_const_parent(
    struct appl_options const * const
        p_options);

enum appl_status
appl_options_count(
    struct appl_options const * const
        p_options,
    unsigned long int * const
        r_count);

enum appl_status
appl_options_get(
    struct appl_options const * const
        p_options,
    unsigned long int const
        i_index,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max);

enum appl_status
appl_options_write(
    struct appl_options * const
        p_options,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        p_count,
    char * const
        p_ready);

enum appl_status
appl_options_append_argument(
    struct appl_options * const
        p_options,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_options_handle.h */
