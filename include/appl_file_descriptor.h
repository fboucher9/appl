/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_FILE_DESCRIPTOR_H)
#error include appl_file_descriptor.h once
#endif /* #if defined(INC_APPL_FILE_DESCRIPTOR_H) */

#define INC_APPL_FILE_DESCRIPTOR_H

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

/*

*/
struct appl_file_descriptor
{
    unsigned char const *
        p_name_min;

    unsigned char const *
        p_name_max;

    /* -- */

    enum appl_file_type
        e_type;

    enum appl_file_mode
        e_mode;

    unsigned int
        ui_padding[2u];

    /* -- */

}; /* struct appl_file_descriptor */

/* end-of-file: appl_file_descriptor.h */