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
struct appl_context;

/* Predefine */
struct appl_string;

#include <appl_extern_c_begin.h>

/** Get value of environment variable.  Lookup table of environment variables
for an entry that matches given name string, and return value of the
environment variable into an appl_string object.  The caller is responsible
of destroying the returned appl_string object. */
enum appl_status
appl_env_get(
    /** Pointer to context */
    struct appl_context * const
        p_context,
    /** Pointer to beginning of name string. */
    unsigned char const * const
        p_name_min,
    /** Pointer to end of name string. */
    unsigned char const * const
        p_name_max,
    /** Pointer to returned appl_string object */
    struct appl_string * * const
        r_string);

/** Get value of environment variable.  Return value of the environment
variable via a callback function. */
enum appl_status
appl_env_query(
    /** Pointer to context */
    struct appl_context * const
        p_context,
    /** Pointer to beginning of name string. */
    unsigned char const * const
        p_name_min,
    /** Pointer to end of name string. */
    unsigned char const * const
        p_name_max,
    /** User callback function */
    void (* p_query_callback)(
        void * const
            p_query_context,
        unsigned char const * const
            p_value_min,
        unsigned char const * const
            p_value_max),
    /** User context for callback function */
    void * const
        p_query_context);

/** Set value of environment variable.  Lookup table of environment variables
for an entry that matches given name string else create a new entry.  Update
the value of the entry with the given value string. */
enum appl_status
appl_env_set(
    /** Pointer to appl_context instance */
    struct appl_context * const
        p_context,
    /** Pointer to beginning of name string. */
    unsigned char const * const
        p_name_min,
    /** Pointer to end of name string. */
    unsigned char const * const
        p_name_max,
    /** Pointer to beginning of value string. */
    unsigned char const * const
        p_value_min,
    /** Pointer to end of value string. */
    unsigned char const * const
        p_value_max);

#include <appl_extern_c_end.h>

/* end-of-file: appl_env_handle.h */
