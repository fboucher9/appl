/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_file_handle_h
{
    inc_appl_file_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

struct appl_object;

struct appl_file;

struct appl_file_descriptor;

#include <appl_extern_c_begin.h>

enum appl_status
appl_file_get_stdin(
    struct appl_context * const
        p_context,
    struct appl_file * * const
        r_stdin_file);

enum appl_status
appl_file_get_stdout(
    struct appl_context * const
        p_context,
    struct appl_file * * const
        r_stdout_file);

enum appl_status
appl_file_get_stderr(
    struct appl_context * const
        p_context,
    struct appl_file * * const
        r_stderr_file);

enum appl_status
appl_file_create(
    struct appl_context * const
        p_context,
    struct appl_file_descriptor const * const
        p_file_descriptor,
    struct appl_file * * const
        r_file);

enum appl_status
appl_file_destroy(
    struct appl_file * const
        p_file);

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

#include <appl_extern_c_end.h>

/* end-of-file: appl_file_handle.h */
