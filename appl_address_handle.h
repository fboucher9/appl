/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_HANDLE_H
#error include appl_address_handle.h once
#endif /* #if defined INC_APPL_ADDRESS_HANDLE_H */

#define INC_APPL_ADDRESS_HANDLE_H

struct appl_object;

struct appl_address;

struct appl_address_property;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_address_create(
    struct appl_context * const
        p_context,
    struct appl_address_property const * const
        p_address_property,
    struct appl_address * * const
        r_address);

struct appl_object *
appl_address_parent(
    struct appl_address * const
        p_address);

struct appl_object const *
appl_address_const_parent(
    struct appl_address const * const
        p_address);

enum appl_status
appl_address_get_name_len(
    struct appl_address const * const
        p_address,
    unsigned long int * const
        r_name_len);

enum appl_status
appl_address_get_name(
    struct appl_address const * const
        p_address,
    unsigned char * const
        p_name_min,
    unsigned char * const
        p_name_max,
    unsigned char * * const
        r_name_cur);

enum appl_status
appl_address_get_port(
    struct appl_address const * const
        p_address,
    unsigned short int * const
        r_port);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_address_handle.h */
