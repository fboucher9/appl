/* See LICENSE for license details */

/**

@file

Environment variable interface.  Functions to get and set environment
variable values in operating-system independent manner.  Name and values
of environment variables are specified using utf-8 encoded strings.

*/

/* Included. */
#define INC_APPL_ENV_HANDLE_H

/* Reverse include guard */
enum guard_appl_env_handle_h
{
    inc_appl_env_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
};

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_string;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

/** Get value of environment variable.  Lookup table of environment variables
for an entry that matches given name string, and return value of the
environment variable into an appl_string object.  The caller is responsible
of destroying the returned appl_string object. */
enum appl_status
appl_env_get(
    /** Pointer to any object.  This is required to obtain context. */
    struct appl_object const * const
        p_object,
    /** Pointer to beginning of name string. */
    unsigned char const * const
        p_name_min,
    /** Pointer to end of name string. */
    unsigned char const * const
        p_name_max,
    /** Pointer to returned appl_string object */
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
