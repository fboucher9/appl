/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_address_property.h>

#include <appl_object_handle.h>

#include <appl_property_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_property_types.h>

#include <appl_property.h>

#define APPL_ADDRESS_PROPERTY_GUID (0xe0bfd095ul)

enum appl_address_property_id
{
    appl_address_property_id_guid = 0,

    appl_address_property_id_name_min = 1,

    appl_address_property_id_name_max = 2,

    appl_address_property_id_port = 3,

    appl_address_property_id_max = 4

}; /* enum appl_address_property_id */

//
//
//
struct appl_address_property : public appl_property
{
}; // struct appl_address_property

/*

*/
enum appl_status
appl_address_property_create(
    struct appl_context * const
        p_context,
    struct appl_address_property * * const
        r_property)
{
    enum appl_status
        e_status;

    struct appl_property *
        p_property;

    e_status =
        appl_property_create(
            p_context,
            appl_address_property_id_max,
            &(
                p_property));

    if (
        appl_status_ok
        == e_status)
    {
        appl_property_set_ulong(
            p_property,
            appl_address_property_id_guid,
            APPL_ADDRESS_PROPERTY_GUID);

        *(
            r_property) =
            static_cast<struct appl_address_property *>(
                p_property);
    }

    return
        e_status;

} /* appl_address_property_create() */

enum appl_status
appl_address_property_destroy(
    struct appl_address_property * const
        p_property)
{
    return
        appl_object_destroy(
            appl_property_parent(
                p_property));

}

struct appl_property *
appl_address_property_parent(
    struct appl_address_property * const
        p_property)
{
    return
        p_property;

}

struct appl_property const *
appl_address_property_const_parent(
    struct appl_address_property const * const
        p_property)
{
    return
        p_property;

}

/*

*/
#if defined APPL_DEBUG
static
void
appl_address_property_assert_guid(
    struct appl_address_property const * const
        p_property)
{
    enum appl_status
        e_status;

    unsigned long int
        u_value;

    e_status =
        appl_property_get_ulong(
            p_property,
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
    struct appl_address_property * const
        p_property,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_set_ptr(
            p_property,
            appl_address_property_id_name_min,
            p_name_min);

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_property_set_ptr(
                p_property,
                appl_address_property_id_name_max,
                p_name_max);
    }

    return
        e_status;

} /* appl_address_property_set_name() */

/*

*/
enum appl_status
appl_address_property_set_port(
    struct appl_address_property * const
        p_property,
    unsigned short int const
        i_port)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_property);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_set_ulong(
            p_property,
            appl_address_property_id_port,
            static_cast<unsigned long int>(
                i_port));

} /* appl_address_property_set_port() */

/*

*/
enum appl_status
appl_address_property_get_name(
    struct appl_address_property const * const
        p_property,
    unsigned char const * * const
        r_name_min,
    unsigned char const * * const
        r_name_max)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_property);
#endif /* #if defined APPL_DEBUG */

    void *
        p_name_min;

    e_status =
        appl_property_get_ptr(
            p_property,
            appl_address_property_id_name_min,
            &(
                p_name_min));

    if (
        appl_status_ok
        == e_status)
    {
        void *
            p_name_max;

        e_status =
            appl_property_get_ptr(
                p_property,
                appl_address_property_id_name_max,
                &(
                    p_name_max));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_name_min) =
                static_cast<unsigned char const *>(
                    p_name_min);

            *(
                r_name_max) =
                static_cast<unsigned char const *>(
                    p_name_max);
        }
    }

    return
        e_status;

} /* appl_address_property_get_name() */

/*

*/
enum appl_status
appl_address_property_get_port(
    struct appl_address_property const * const
        p_property,
    unsigned short int * const
        r_port)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_property);
#endif /* #if defined APPL_DEBUG */

    enum appl_status
        e_status;

    unsigned long int
        u_value;

    e_status =
        appl_property_get_ulong(
            p_property,
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
