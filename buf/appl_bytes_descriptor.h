/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bytes_descriptor_h
{
    inc_appl_bytes_descriptor_h = 1
        /* Header file dependencies */
        /* ... */
}; /* enum guard_appl_bytes_descriptor_h */

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
struct appl_bytes_descriptor
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

}; /* struct appl_bytes_descriptor */

#include <appl_extern_c_begin.h>

void
    appl_bytes_descriptor_init(
        struct appl_bytes_descriptor * const
            p_descriptor);

#include <appl_extern_c_end.h>

/* end-of-file: appl_bytes_descriptor.h */
