/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_PROPERTY_H
#error include appl_address_property.h once
#endif /* #if defined INC_APPL_ADDRESS_PROPERTY_H */

#define INC_APPL_ADDRESS_PROPERTY_H

struct appl_string_handle;

struct appl_property_handle;

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
    struct appl_string_handle const * const
        p_name_handle);

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
    struct appl_string_handle const * * const
        r_name_handle);

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
