/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_file_descriptor_h
{
    inc_appl_file_descriptor_h = 1
        + inc_appl_status_h
};

/*

*/
enum appl_file_type
{
    appl_file_type_stdin = 1,

    appl_file_type_stdout = 2,

    appl_file_type_stderr = 3,

    appl_file_type_disk = 4

}; /* enum appl_file_type */

/*

*/
enum appl_file_mode
{
    appl_file_mode_read = 1,

    appl_file_mode_write = 2,

    appl_file_mode_modify = 3,

    appl_file_mode_append = 4

}; /* enum appl_file_mode */

#include <misc/appl_extern_c_begin.h>

enum appl_status
appl_file_descriptor_create(
    struct appl_context * const
        p_context,
    struct appl_file_descriptor * * const
        r_file_descriptor);

enum appl_status
appl_file_descriptor_destroy(
    struct appl_file_descriptor * const
        p_file_descriptor);

enum appl_status
appl_file_descriptor_set_type(
    struct appl_file_descriptor * const
        p_file_descriptor,
    enum appl_file_type const
        e_type);

enum appl_status
appl_file_descriptor_set_mode(
    struct appl_file_descriptor * const
        p_file_descriptor,
    enum appl_file_mode const
        e_mode);

enum appl_status
appl_file_descriptor_set_name(
    struct appl_file_descriptor * const
        p_file_descriptor,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_file_descriptor.h */
