/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_netlink_handle_h
{
    inc_appl_netlink_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_types_h

}; /* enum guard_appl_netlink_handle_h */

/* Included. */
#define INC_APPL_NETLINK_HANDLE_H

/* Predefine */
struct appl_netlink;

#define APPL_NETLINK_FLAG_INTERFACE (1ul << 0u)

#define APPL_NETLINK_FLAG_IPV4_ADDRESS (1ul << 1u)

#define APPL_NETLINK_FLAG_IPV6_ADDRESS (1ul << 2u)

struct appl_netlink_event;

/*

*/
struct appl_netlink_descriptor
{
    enum appl_status
        (* p_callback_function)(
            void * const
                p_callback_context,
            struct appl_netlink_event const * const
                p_netlink_event);

    void *
        p_callback_context;

    /* -- */

    unsigned long int
        i_flags;

#define PADDING (APPL_SIZEOF_LONG)
#include <appl_padding.h>

}; /* struct appl_netlink_descriptor */

#include <appl_extern_c_begin.h>

enum appl_status
    appl_netlink_create(
        struct appl_context * const
            p_context,
        struct appl_netlink_descriptor const * const
            p_descriptor,
        struct appl_netlink * * const
            r_netlink);

enum appl_status
    appl_netlink_destroy(
        struct appl_netlink * const
            p_netlink);

#include <appl_extern_c_end.h>

/* end-of-file: appl_netlink_handle.h */
