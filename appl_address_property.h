/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_PROPERTY_H
#error include appl_address_property.h once
#endif /* #if defined INC_APPL_ADDRESS_PROPERTY_H */

#define INC_APPL_ADDRESS_PROPERTY_H

#define APPL_ADDRESS_PROPERTY_GUID (unsigned long int)(0xe0bfd095ul)

struct appl_property_handle;

enum appl_address_property_id
{
    appl_address_property_id_guid = 0,

    appl_address_property_id_name = 1,

    appl_address_property_id_port = 2,

    appl_address_property_id_max = 3

}; /* enum appl_address_property_id */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_address_property_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_property_handle * * const
        r_property_handle);

enum appl_status
appl_address_property_set_name(
    struct appl_property_handle * const
        p_property_handle,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max);

enum appl_status
appl_address_property_set_port(
    struct appl_property_handle * const
        p_property_handle,
    unsigned short int const
        i_port);

enum appl_status
appl_address_property_get_name(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned char const * * const
        r_name_min,
    unsigned char const * * const
        r_name_max);

enum appl_status
appl_address_property_get_port(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned short int * const
        r_port);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_address_property.h */
