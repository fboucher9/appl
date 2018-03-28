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

enum appl_property_type
{
    appl_property_type_default = 0,

    appl_property_type_handle = 1,

    appl_property_type_buffer = 2,

    appl_property_type_unsigned_integer = 3,

    appl_property_type_signed_integer = 4,

    appl_property_type_unsigned_fraction = 5,

    appl_property_type_signed_fraction = 6

}; /* enum appl_property_type */

struct appl_property_buffer
{
    unsigned char const *
        p_min;

    unsigned char const *
        p_max;

}; /* struct appl_property_buffer */

struct appl_property_unsigned_fraction
{
    unsigned long int
        u_num;

    unsigned long int
        u_den;

}; /* struct appl_property_unsigned_fraction */

struct appl_property_signed_fraction
{
    signed long int
        i_num;

    signed long int
        i_den;

}; /* struct appl_property_signed_fraction */

union appl_property_value
{
    void *
        p_value;

    unsigned long int
        u_value;

    signed long int
        i_value;

    struct appl_property_buffer
        o_buffer;

    struct appl_property_unsigned_fraction
        o_unsigned_fraction;

    struct appl_property_signed_fraction
        o_signed_fraction;

}; /* union appl_property_data */

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
appl_property_write(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    enum appl_property_type const
        e_type,
    union appl_property_value const * const
        p_value);

enum appl_status
appl_property_write_handle(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    void * const
        p_value);

enum appl_status
appl_property_write_buffer(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned char const * const
        p_buffer_min,
    unsigned char const * const
        p_buffer_max);

enum appl_status
appl_property_write_unsigned_integer(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int const
        u_value);

enum appl_status
appl_property_write_signed_integer(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int const
        u_value);

enum appl_status
appl_property_write_unsigned_fraction(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int const
        u_num,
    unsigned long int const
        u_den);

enum appl_status
appl_property_write_signed_fraction(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int const
        i_num,
    signed long int const
        i_den);

enum appl_status
appl_property_read(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    enum appl_property_type const
        e_type,
    union appl_property_value * const
        p_value);

enum appl_status
appl_property_read_handle(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    void * * const
        r_value);

enum appl_status
appl_property_read_buffer(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned char const * * const
        r_buffer_min,
    unsigned char const * * const
        r_buffer_max);

enum appl_status
appl_property_read_unsigned_integer(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int * const
        r_value);

enum appl_status
appl_property_read_signed_integer(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int * const
        r_value);

enum appl_status
appl_property_read_unsigned_fraction(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int * const
        u_num,
    unsigned long int * const
        r_den);

enum appl_status
appl_property_read_signed_fraction(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int * const
        r_num,
    signed long int * const
        r_den);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_property_handle.h */
