/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_PROPERTY_H
#error include appl_address_property.h once
#endif /* #if defined INC_APPL_ADDRESS_PROPERTY_H */

#define INC_APPL_ADDRESS_PROPERTY_H

struct appl_address_property;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_address_property_create(
    struct appl_context * const
        p_context,
    struct appl_address_property * * const
        r_property);

enum appl_status
appl_address_property_destroy(
    struct appl_address_property * const
        p_property);

struct appl_property *
appl_address_property_parent(
    struct appl_address_property * const
        p_property);

struct appl_property const *
appl_address_property_const_parent(
    struct appl_address_property const * const
        p_property);

enum appl_status
appl_address_property_set_name(
    struct appl_address_property * const
        p_property,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max);

enum appl_status
appl_address_property_set_port(
    struct appl_address_property * const
        p_property,
    unsigned short int const
        i_port);

enum appl_status
appl_address_property_get_name(
    struct appl_address_property const * const
        p_property,
    unsigned char const * * const
        r_name_min,
    unsigned char const * * const
        r_name_max);

enum appl_status
appl_address_property_get_port(
    struct appl_address_property const * const
        p_property,
    unsigned short int * const
        r_port);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_address_property.h */
