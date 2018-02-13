/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_POLL_DESCRIPTOR_H)
#error include appl_poll_descriptor.h
#endif /* #if defined(INC_APPL_POLL_DESCRIPTOR_H) */

#define INC_APPL_POLL_DESCRIPTOR_H

struct appl_poll_descriptor;

#define APPL_POLL_FLAG_READ 1u

#define APPL_POLL_FLAG_WRITE 2u

#define APPL_POLL_FLAG_ERROR 4u

/*

*/
struct appl_poll_descriptor
{
    struct appl_socket_handle *
        p_socket_handle;

    enum appl_status
        (* p_callback)(
            void * const
                p_context,
            unsigned int
                i_poll_flags);

    /* -- */

    void *
        p_context;

    void *
        pv_padding[1u];

    /* -- */

    unsigned int
        i_poll_flags;

    unsigned int
        ui_padding[3u];

}; /* struct appl_poll_descriptor */

/* end-of-file: appl_poll_descriptor.h */
