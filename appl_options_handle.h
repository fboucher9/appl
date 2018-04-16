/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_OPTIONS_HANDLE_H
#error include appl_options_handle.h once
#endif /* #if defined INC_APPL_OPTIONS_HANDLE_H */

#define INC_APPL_OPTIONS_HANDLE_H

struct appl_object;

struct appl_string;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_options_count(
    struct appl_object const * const
        p_object,
    unsigned long int * const
        r_count);

enum appl_status
appl_options_get(
    struct appl_object const * const
        p_object,
    unsigned long int const
        i_index,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_options_handle.h */
