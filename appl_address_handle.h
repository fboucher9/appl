/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_HANDLE_H
#error include appl_address_handle.h once
#endif /* #if defined INC_APPL_ADDRESS_HANDLE_H */

#define INC_APPL_ADDRESS_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_HANDLE_H
#error include appl_object_handle.h before
#endif /* #if ! defined INC_APPL_OBJECT_HANDLE_H */

struct appl_address_handle;

struct appl_address_descriptor;

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

struct appl_address_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_address_handle */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_address_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_address_descriptor const * const
        p_address_descriptor,
    struct appl_address_handle * * const
        r_address_handle);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_address_handle.h */
