/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_poll_descriptor_h
{
    inc_appl_poll_descriptor_h =
        1
};

struct appl_socket;

struct appl_poll_descriptor;

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

    void *
        pv_padding[1u];

    /* -- */

    signed int
        i_poll_flags;

    unsigned int
        ui_padding[3u];

}; /* struct appl_poll_descriptor */

/* end-of-file: appl_poll_descriptor.h */
