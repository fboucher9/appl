/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_address_property_h
{
    inc_appl_address_property_h =
        /* Header file dependencies */
        inc_appl_status_h
};

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
