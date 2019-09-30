/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_dir_descriptor_h
{
    inc_appl_dir_descriptor_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_buf_h
}; /* enum guard_appl_dir_descriptor_h */

/*

*/
struct appl_dir_item
{
    struct appl_buf
        o_name;

    /* -- */

    /* optional extra information */

}; /* struct appl_dir_item */

typedef
enum appl_status
(appl_dir_enumerate_callback)(
    void * const
        p_void,
    struct appl_dir_item const * const
        p_dir_item);

/*

*/
struct appl_dir_descriptor
{
    struct appl_buf
        o_name;

    /* -- */

    appl_dir_enumerate_callback *
        p_callback;

    void *
        p_void;

}; /* struct appl_dir_descriptor */

/* end-of-file: appl_dir_descriptor.h */
