/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_PROPERTY_HANDLE_H
#error include appl_property_handle.h once
#endif /* #if defined INC_APPL_PROPERTY_HANDLE_H */

#define INC_APPL_PROPERTY_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_HANDLE_H
#error include appl_object_handle.h before
#endif /* #if ! defined INC_APPL_OBJECT_HANDLE_H */

struct appl_context;

struct appl_property;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_property_create(
    struct appl_context * const
        p_context,
    unsigned int const
        i_count,
    struct appl_property * * const
        r_property);

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

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_property_handle.h */
