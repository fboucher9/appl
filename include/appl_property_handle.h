/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_property_handle_h
{
    inc_appl_property_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

#include <appl_extern_c_begin.h>

enum appl_status
appl_property_create(
    struct appl_context * const
        p_context,
    unsigned int const
        i_count,
    struct appl_property * * const
        r_property);

enum appl_status
appl_property_destroy(
    struct appl_property * const
        p_property);

struct appl_object *
appl_property_parent(
    struct appl_property * const
        p_property);

struct appl_object const *
appl_property_const_parent(
    struct appl_property const * const
        p_property);

enum appl_status
appl_property_set_ptr(
    struct appl_property * const
        p_property,
    unsigned int const
        i_id,
    void const * const
        p_value);

enum appl_status
appl_property_set_ulong(
    struct appl_property * const
        p_property,
    unsigned int const
        i_id,
    unsigned long int const
        u_value);

enum appl_status
appl_property_set_long(
    struct appl_property * const
        p_property,
    unsigned int const
        i_id,
    signed long int const
        i_value);

enum appl_status
appl_property_get_ptr(
    struct appl_property const * const
        p_property,
    unsigned int const
        i_id,
    void * * const
        r_value);

enum appl_status
appl_property_get_ulong(
    struct appl_property const * const
        p_property,
    unsigned int const
        i_id,
    unsigned long int * const
        r_value);

enum appl_status
appl_property_get_long(
    struct appl_property const * const
        p_property,
    unsigned int const
        i_id,
    signed long int * const
        r_value);

#include <appl_extern_c_end.h>

/* end-of-file: appl_property_handle.h */
