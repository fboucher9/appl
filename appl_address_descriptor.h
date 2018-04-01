/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_DESCRIPTOR_H
#error include appl_address_descriptor.h once
#endif /* #if defined INC_APPL_ADDRESS_DESCRIPTOR_H */

#define INC_APPL_ADDRESS_DESCRIPTOR_H

/* Header file dependency */
#if ! defined INC_APPL_BUF_H
#error include appl_buf.h before
#endif /* #if ! defined INC_APPL_BUF_H */

/*

*/
struct appl_address_descriptor
{
    struct appl_buf
        o_name;

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

#define APPL_ADDRESS_PROPERTY_GUID (unsigned long int)(0xe0bfd095ul)

enum appl_address_property_id
{
    appl_address_property_id_guid = 0,

    appl_address_property_id_name = 1,

    appl_address_property_id_port = 2,

    appl_address_property_id_max = 3

}; /* enum appl_address_property_id */

/* end-of-file: appl_address_descriptor.h */
