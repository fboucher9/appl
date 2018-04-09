/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_address_property.h"

#include "appl_object_handle.h"

#include "appl_property_handle.h"

#define APPL_ADDRESS_PROPERTY_GUID (unsigned long int)(0xe0bfd095ul)

enum appl_address_property_id
{
    appl_address_property_id_guid = 0,

    appl_address_property_id_name = 1,

    appl_address_property_id_port = 2,

    appl_address_property_id_max = 3

}; /* enum appl_address_property_id */

/*

*/
enum appl_status
appl_address_property_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_property_handle * * const
        r_property_handle)
{
    enum appl_status
        e_status;

    struct appl_property_handle *
        p_property_handle;

    e_status =
        appl_property_create(
            p_context_handle,
            appl_address_property_id_max,
            &(
                p_property_handle));

    if (
        appl_status_ok
        == e_status)
    {
        appl_property_set_ulong(
            p_property_handle,
            appl_address_property_id_guid,
            APPL_ADDRESS_PROPERTY_GUID);

        *(
            r_property_handle) =
            p_property_handle;
    }

    return
        e_status;

} /* appl_address_property_create() */

/*

*/
#if defined APPL_DEBUG
static
void
appl_address_property_assert_guid(
    struct appl_property_handle const * const
        p_property_handle)
{
    enum appl_status
        e_status;

    unsigned long int
        u_value;

    e_status =
        appl_property_get_ulong(
            p_property_handle,
            appl_address_property_id_guid,
            &(
                u_value));

    if (
        (
            appl_status_ok
            == e_status)
        && (
            APPL_ADDRESS_PROPERTY_GUID
            == u_value))
    {
    }
    else
    {
    }
}
#endif /* #if defined APPL_DEBUG */

/*

*/
enum appl_status
appl_address_property_set_name(
    struct appl_property_handle * const
        p_property_handle,
    struct appl_string_handle const * const
        p_name_handle)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_property_handle);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_set_ptr(
            p_property_handle,
            appl_address_property_id_name,
            p_name_handle);

} /* appl_address_property_set_name() */

/*

*/
enum appl_status
appl_address_property_set_port(
    struct appl_property_handle * const
        p_property_handle,
    unsigned short int const
        i_port)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_property_handle);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_set_ulong(
            p_property_handle,
            appl_address_property_id_port,
            static_cast<unsigned long int>(
                i_port));

} /* appl_address_property_set_port() */

/*

*/
enum appl_status
appl_address_property_get_name(
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_string_handle const * * const
        r_name_buf)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_property_handle);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_get_ptr(
            p_property_handle,
            appl_address_property_id_name,
            const_cast<void * *>(
                reinterpret_cast<void const * *>(
                    r_name_buf)));

} /* appl_address_property_get_name() */

/*

*/
enum appl_status
appl_address_property_get_port(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned short int * const
        r_port)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_property_handle);
#endif /* #if defined APPL_DEBUG */

    enum appl_status
        e_status;

    unsigned long int
        u_value;

    e_status =
        appl_property_get_ulong(
            p_property_handle,
            appl_address_property_id_port,
            &(
                u_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_port) =
            static_cast<unsigned short int>(
                u_value);
    }

    return
        e_status;

} /* appl_address_property_get_port() */

/* end-of-file: appl_address_property.cpp */
