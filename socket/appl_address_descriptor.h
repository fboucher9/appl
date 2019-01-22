/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_address_descriptor_h
{
    inc_appl_address_descriptor_h = 1
        + inc_appl_address_property_h
};

/*

*/
struct appl_address_descriptor
{
    unsigned char const *
        p_name_min;

    unsigned char const *
        p_name_max;

    /* -- */

    enum appl_address_family
        e_family;

    unsigned short int
        i_port;

    unsigned char
        b_name;

    unsigned char
        b_port;

#define PADDING (4 + APPL_SIZEOF_INT)
#include <appl_padding.h>

}; /* struct appl_address_descriptor */

/* end-of-file: appl_address_descriptor.h */
