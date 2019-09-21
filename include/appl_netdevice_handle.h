/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_netdevice_handle_h
{
    inc_appl_netdevice_handle_h = 1
        + inc_appl_status_h
};

/* Included. */
#define INC_APPL_NETDEVICE_HANDLE_H

/*

Enumeration: appl_netdevice_type

Description:
    Type of network device being enumerated.

*/
enum appl_netdevice_type
{
    /* Network device is UP and RUNNING */
    appl_netdevice_type_normal = 1,

    /* Network device is a LOOPBACK */
    appl_netdevice_type_loopback = 2

}; /* enum appl_netdevice_type */

/* Presence of p_name_min and p_name_max fields */
#define APPL_NETDEVICE_FLAGS_NAME (1u << 0u)

/* Presence of p_address_min and p_address_max fields */
#define APPL_NETDEVICE_FLAGS_ADDRESS (1u << 1u)

/* Presence of e_family field */
#define APPL_NETDEVICE_FLAGS_FAMILY (1u << 2u)

/* Presence of i_index field */
#define APPL_NETDEVICE_FLAGS_INDEX (1u << 3u)

/* Presence of e_type field */
#define APPL_NETDEVICE_FLAGS_TYPE (1u << 4u)

/*

*/
struct appl_netdevice_descriptor
{
    unsigned char const *
        p_name_min;

    unsigned char const *
        p_name_max;

    /* -- */

    unsigned char const *
        p_address_min;

    unsigned char const *
        p_address_max;

    /* -- */

    /* enum appl_address_family */
    int
        e_family;

    unsigned int
        i_index;

    /* enum appl_netdevice_type */
    int
        e_type;

    /* see APPL_NETDEVICE_FLAGS_Xx */
    unsigned int
        i_flags;

}; /* struct appl_netdevice_descriptor */

#include <appl_extern_c_begin.h>

enum appl_status
    appl_netdevice_enumerate(
        struct appl_context * const
            p_context,
        struct appl_netdevice_descriptor const * const
            p_netdevice_filter,
        void (* p_callback)(
            void * const
                p_callback_context,
            struct appl_netdevice_descriptor const * const
                p_netdevice_descriptor),
        void * p_callback_context);

#include <appl_extern_c_end.h>

/* end-of-file: appl_netdevice_handle.h */
