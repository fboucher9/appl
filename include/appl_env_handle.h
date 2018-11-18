/* See LICENSE for license details */

/*

*/

#if defined INC_APPL_ENV_HANDLE_H
#error include appl_env_handle.h once
#endif /* #if defined INC_APPL_ENV_HANDLE_H */

#define INC_APPL_ENV_HANDLE_H

struct appl_object;

struct appl_string;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_env_get(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    struct appl_string * * const
        r_string);

enum appl_status
appl_env_set(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    unsigned char const * const
        p_value_min,
    unsigned char const * const
        p_value_max);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_env_handle.h */
