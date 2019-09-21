/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_poll_descriptor_h
{
    inc_appl_poll_descriptor_h =
        inc_appl_types_h
};

/*

*/
enum appl_poll_flag
{
    appl_poll_flag_read = 1,

    appl_poll_flag_write = 2,

    appl_poll_flag_error = 4

}; /* enum appl_poll_flag */

/*

*/
struct appl_poll_descriptor
{
    struct appl_socket *
        p_socket;

    void
        (* p_callback)(
            void * const
                p_context,
            signed int const
                i_poll_flags);

    /* -- */

    void *
        p_context;

    signed int
        i_poll_flags;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_INT)
#include <appl_padding.h>

}; /* struct appl_poll_descriptor */

/* end-of-file: appl_poll_descriptor.h */
