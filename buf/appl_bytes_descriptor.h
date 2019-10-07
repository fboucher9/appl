/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bytes_descriptor_h
{
    inc_appl_bytes_descriptor_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_buf_h
        /* ... */
}; /* enum guard_appl_bytes_descriptor_h */

/*

*/
enum appl_bytes_type
{
    appl_bytes_type_custom = 1,

    appl_bytes_type_mem = 2

}; /* enum appl_bytes_type */

typedef
enum appl_status
    (appl_bytes_consume)(
        void * const
            p_void,
        unsigned char * const
            r_value);

typedef
enum appl_status
    (appl_bytes_produce)(
        void * const
            p_void,
        unsigned char const
            i_value);

/*

*/
struct appl_bytes_custom_descriptor
{
    appl_bytes_consume *
        p_consume;

    appl_bytes_produce *
        p_produce;

    /* -- */

    void *
        p_void;

    void *
        pv_padding[1u];

}; /* struct appl_bytes_custom_descriptor */

/*

*/
struct appl_bytes_mem_descriptor
{
    struct appl_buf
        o_buf;

}; /* struct appl_bytes_mem_descriptor */


/*

*/
struct appl_bytes_descriptor
{
    enum appl_bytes_type
        e_type;

    unsigned int
        ui_padding[3u];

    /* -- */

    union appl_bytes_descriptor_data
    {
        struct appl_bytes_custom_descriptor
            o_custom_descriptor;

        struct appl_bytes_mem_descriptor
            o_mem_descriptor;

    } u;

}; /* struct appl_bytes_descriptor */

#include <misc/appl_extern_c_begin.h>

void
    appl_bytes_descriptor_init(
        struct appl_bytes_descriptor * const
            p_descriptor);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_bytes_descriptor.h */
