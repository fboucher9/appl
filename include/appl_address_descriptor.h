/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_address_descriptor_h
{
    inc_appl_address_descriptor_h = 1
        + inc_appl_types_h
};

/* Included. */
#define INC_APPL_ADDRESS_DESCRIPTOR_H

/* Flags for descriptor */

/* Flag to select p_name_min and p_name_max fields */
#define APPL_ADDRESS_FLAG_NAME (1u << 0u)

/* Flag to select i_port field */
#define APPL_ADDRESS_FLAG_PORT (1u << 1u)

/* Flag to select e_family field */
#define APPL_ADDRESS_FLAG_FAMILY (1u << 2u)

/* Flag to select i_index */
#define APPL_ADDRESS_FLAG_INDEX (1u << 3u)

/*

Structure: appl_address_descriptor

Description:
    Descriptor for initialization of appl_address object.

*/
struct appl_address_descriptor
{
    unsigned char const *
        p_name_min;

    unsigned char const *
        p_name_max;

    /* -- */

    int
        e_family;

    unsigned int
        i_index;

    unsigned short int
        i_flags;

    unsigned short int
        i_port;

#define PADDING (4 + 2*APPL_SIZEOF_INT)
#include <appl_padding.h>

}; /* struct appl_address_descriptor */

/* end-of-file: appl_address_descriptor.h */
