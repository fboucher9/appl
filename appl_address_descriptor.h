/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_DESCRIPTOR_H
#error include appl_address_descriptor.h once
#endif /* #if defined INC_APPL_ADDRESS_DESCRIPTOR_H */

#define INC_APPL_ADDRESS_DESCRIPTOR_H

/*

*/
struct appl_address_descriptor
{
    unsigned char const *
        p_name_min;

    unsigned char const *
        p_name_max;

    /* -- */

    unsigned short int
        i_port;

    unsigned short int
        us_padding[3u];

    /* -- */

    unsigned char
        b_name;

    unsigned char
        b_port;

    unsigned char
        uc_padding[6u];

}; /* struct appl_address_descriptor */

/* end-of-file: appl_address_descriptor.h */
