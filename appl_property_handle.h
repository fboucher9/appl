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

/*

Enumeration: appl_property_type

Description:

*/
enum appl_property_type
{
    appl_property_type_default = 0,

    appl_property_type_ptr = 1,

    appl_property_type_ulong = 3,

    appl_property_type_slong = 4

}; /* enum appl_property_type */

union appl_property_value;

/*

Structure: appl_property_value

Description:

*/
union appl_property_value
{
    void *
        p_value;

    unsigned long int
        u_value;

    signed long int
        i_value;

};

struct appl_property_handle;

struct appl_property_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_property_handle */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_property_create(
    struct appl_context * const
        p_context_handle,
    unsigned int const
        i_count,
    struct appl_property_handle * * const
        r_property_handle);

enum appl_status
appl_property_set_ptr(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    void * const
        p_value);

enum appl_status
appl_property_set_ulong(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int const
        u_value);

enum appl_status
appl_property_set_slong(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int const
        i_value);

enum appl_status
appl_property_get_ptr(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    void * * const
        r_value);

enum appl_status
appl_property_get_ulong(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int * const
        r_value);

enum appl_status
appl_property_get_slong(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int * const
        r_value);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_property_handle.h */
