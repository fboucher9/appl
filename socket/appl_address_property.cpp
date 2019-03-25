/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_address_property.h>

#include <appl_property_handle.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_object_handle.h>

#include <property/appl_property_types.h>

#include <property/appl_property.h>

#include <property/appl_property_std.h>

#if defined APPL_DEBUG

#include <debug/appl_debug_impl.h>

#endif /* #if defined APPL_DEBUG */

#include <appl_convert.h>

#include <appl_heap_handle.h>

#define APPL_ADDRESS_PROPERTY_GUID (0xe0bfd095ul)

enum appl_address_property_id
{
    appl_address_property_id_guid = 0,

    appl_address_property_id_name_min = 1,

    appl_address_property_id_name_max = 2,

    appl_address_property_id_port = 3,

    appl_address_property_id_family = 4,

    appl_address_property_id_index = 5,

    appl_address_property_id_max = 6

}; /* enum appl_address_property_id */

union appl_address_property_ptr
{
    struct appl_address_property *
        p_address_property;

    struct appl_property *
        p_base_property;

    struct appl_address_property const *
        pc_address_property;

    struct appl_property const *
        pc_base_property;

};

/*

*/
enum appl_status
appl_address_property_create(
    struct appl_context * const
        p_context,
    struct appl_address_property * * const
        r_address_property)
{
    enum appl_status
        e_status;

    union appl_address_property_ptr
        o_address_property_ptr;

    e_status =
        appl_property_create(
            p_context,
            appl_address_property_id_max,
            &(
                o_address_property_ptr.p_base_property));

    if (
        appl_status_ok
        == e_status)
    {
        appl_property_set_ulong(
            o_address_property_ptr.p_base_property,
            appl_address_property_id_guid,
            APPL_ADDRESS_PROPERTY_GUID);

        *(
            r_address_property) =
            o_address_property_ptr.p_address_property;
    }

    return
        e_status;

} /* create() */

/*

*/
enum appl_status
appl_address_property_destroy(
    struct appl_address_property * const
        p_address_property)
{
    union appl_address_property_ptr
        o_address_property_ptr;

    o_address_property_ptr.p_address_property =
        p_address_property;

    return
        appl_property_destroy(
            o_address_property_ptr.p_base_property);

} /* destroy() */

/*

*/
struct appl_property *
appl_address_property_parent(
    struct appl_address_property * const
        p_address_property)
{
    union appl_address_property_ptr
        o_address_property_ptr;

    o_address_property_ptr.p_address_property =
        p_address_property;

    return
        o_address_property_ptr.p_base_property;

} /* parent() */

/*

*/
struct appl_property const *
appl_address_property_const_parent(
    struct appl_address_property const * const
        p_address_property)
{
    union appl_address_property_ptr
        o_address_property_ptr;

    o_address_property_ptr.pc_address_property =
        p_address_property;

    return
        o_address_property_ptr.pc_base_property;

} /* const_parent() */

/*

*/
#if defined APPL_DEBUG
static
void
appl_address_property_assert_guid(
    struct appl_address_property const * const
        p_address_property)
{
    enum appl_status
        e_status;

    unsigned long int
        u_value;

    union appl_address_property_ptr
        o_address_property_ptr;

    o_address_property_ptr.pc_address_property =
        p_address_property;

    e_status =
        appl_property_get_ulong(
            o_address_property_ptr.pc_base_property,
            appl_address_property_id_guid,
            &(
                u_value));

    appl_debug_impl::s_validate(
        (
            appl_status_ok
            == e_status)
        && (
            APPL_ADDRESS_PROPERTY_GUID
            == u_value),
        "invalid guid for appl_address_property object\n");
}
#endif /* #if defined APPL_DEBUG */

/*

*/
enum appl_status
appl_address_property_set_name(
    struct appl_address_property * const
        p_address_property,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    union appl_address_property_ptr
        o_address_property_ptr;

    o_address_property_ptr.p_address_property =
        p_address_property;

    e_status =
        appl_property_set_ptr(
            o_address_property_ptr.p_base_property,
            appl_address_property_id_name_min,
            p_name_min);

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_property_set_ptr(
                o_address_property_ptr.p_base_property,
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
        p_address_property,
    unsigned short int const
        i_port)
{
    union appl_address_property_ptr
        o_address_property_ptr;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    o_address_property_ptr.p_address_property =
        p_address_property;

    return
        appl_property_set_ulong(
            o_address_property_ptr.p_base_property,
            appl_address_property_id_port,
            i_port);

} /* appl_address_property_set_port() */

/*

*/
enum appl_status
appl_address_property_set_family(
    struct appl_address_property * const
        p_address_property,
    int const
        e_family)
{
    union appl_address_property_ptr
        o_address_property_ptr;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    o_address_property_ptr.p_address_property =
        p_address_property;

    signed long int const
        i_value =
        e_family;

    return
        appl_property_set_long(
            o_address_property_ptr.p_base_property,
            appl_address_property_id_family,
            i_value);

} /* appl_address_property_set_family() */

/*

*/
enum appl_status
appl_address_property_set_index(
    struct appl_address_property * const
        p_address_property,
    unsigned int const
        i_index)
{
    union appl_address_property_ptr
        o_address_property_ptr;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    o_address_property_ptr.p_address_property =
        p_address_property;

    unsigned long int const
        i_value =
        i_index;

    return
        appl_property_set_ulong(
            o_address_property_ptr.p_base_property,
            appl_address_property_id_index,
            i_value);

} /* appl_address_property_set_index() */

/*

*/
enum appl_status
appl_address_property_get_name(
    struct appl_address_property const * const
        p_address_property,
    unsigned char const * * const
        r_name_min,
    unsigned char const * * const
        r_name_max)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    union appl_address_property_ptr
        o_address_property_ptr;

    o_address_property_ptr.pc_address_property =
        p_address_property;

    union appl_buf_ptr
        o_name_min;

    e_status =
        appl_property_get_ptr(
            o_address_property_ptr.pc_base_property,
            appl_address_property_id_name_min,
            &(
                o_name_min.p_void));

    if (
        appl_status_ok
        == e_status)
    {
        union appl_buf_ptr
            o_name_max;

        e_status =
            appl_property_get_ptr(
                o_address_property_ptr.pc_base_property,
                appl_address_property_id_name_max,
                &(
                    o_name_max.p_void));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_name_min) =
                o_name_min.pc_uchar;

            *(
                r_name_max) =
                o_name_max.pc_uchar;
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
        p_address_property,
    unsigned short int * const
        r_port)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    enum appl_status
        e_status;

    union appl_address_property_ptr
        o_address_property_ptr;

    o_address_property_ptr.pc_address_property =
        p_address_property;

    unsigned long int
        u_value;

    e_status =
        appl_property_get_ulong(
            o_address_property_ptr.pc_base_property,
            appl_address_property_id_port,
            &(
                u_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_port) =
            appl_convert::to_ushort(
                u_value);
    }

    return
        e_status;

} /* appl_address_property_get_port() */

/*

*/
enum appl_status
appl_address_property_get_family(
    struct appl_address_property const * const
        p_address_property,
    int * const
        r_family)
{
    enum appl_status
        e_status;

    union appl_address_property_ptr
        o_address_property_ptr;

    o_address_property_ptr.pc_address_property =
        p_address_property;

    signed long int
        i_value;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_get_long(
            o_address_property_ptr.pc_base_property,
            appl_address_property_id_family,
            &(
                i_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_family) =
            appl_convert::to_int(
                i_value);
    }

    return
        e_status;

} /* appl_address_property_get_family() */

/*

*/
enum appl_status
appl_address_property_get_index(
    struct appl_address_property const * const
        p_address_property,
    unsigned int * const
        r_index)
{
    enum appl_status
        e_status;

    union appl_address_property_ptr
        o_address_property_ptr;

    o_address_property_ptr.pc_address_property =
        p_address_property;

    unsigned long int
        i_value;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_get_ulong(
            o_address_property_ptr.pc_base_property,
            appl_address_property_id_index,
            &(
                i_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_index) =
            appl_convert::to_uint(
                i_value);
    }

    return
        e_status;

} /* appl_address_property_get_index() */

/* end-of-file: appl_address_property.cpp */
