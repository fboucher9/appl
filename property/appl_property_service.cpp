/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <buf/appl_buf.h>

#include <property/appl_property_service.h>

#include <property/appl_property_types.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <property/appl_property.h>

#include <property/appl_property_std.h>

#include <context/appl_context_handle.h>

//
//
//
enum appl_status
appl_property_service::s_create(
    struct appl_context * const
        p_context,
    unsigned int const
        i_count,
    struct appl_property * * const
        r_property)
{
    enum appl_status
        e_status;

    struct appl_property *
        p_property;

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    e_status =
        appl_property_std::s_create(
            p_allocator,
            i_count,
            &(
                p_property));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_property) =
            p_property;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_property_service::s_destroy(
    struct appl_property * const
        p_property)
{
    struct appl_context * const
        p_context =
        p_property->get_context();

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_property_std::s_destroy(
            p_allocator,
            p_property);

} // s_destroy()

//
//
//
enum appl_status
appl_property_service::s_set_ptr(
    struct appl_property * const
        p_property,
    unsigned int const
        i_id,
    void const * const
        p_value)
{
    enum appl_status
        e_status;

    union appl_property_value
        o_value;

    o_value.pc_value =
        p_value;

    e_status =
        p_property->v_set(
            i_id,
            appl_property_type_ptr,
            &(
                o_value));

    return
        e_status;

} // s_set_ptr()

//
//
//
enum appl_status
appl_property_service::s_set_ulong(
    struct appl_property * const
        p_property,
    unsigned int const
        i_id,
    unsigned long int const
        u_value)
{
    enum appl_status
        e_status;

    union appl_property_value
        o_value;

    o_value.u_value =
        u_value;

    e_status =
        p_property->v_set(
            i_id,
            appl_property_type_ulong,
            &(
                o_value));

    return
        e_status;

} // s_set_ulong()

//
//
//
enum appl_status
appl_property_service::s_set_long(
    struct appl_property * const
        p_property,
    unsigned int const
        i_id,
    signed long int const
        i_value)
{
    enum appl_status
        e_status;

    union appl_property_value
        o_value;

    o_value.i_value =
        i_value;

    e_status =
        p_property->v_set(
            i_id,
            appl_property_type_long,
            &(
                o_value));

    return
        e_status;

} // s_set_long()

//
//
//
enum appl_status
appl_property_service::s_get_ptr(
    struct appl_property const * const
        p_property,
    unsigned int const
        i_id,
    void * * const
        r_value)
{
    enum appl_status
        e_status;

    union appl_property_value
        o_value;

    e_status =
        p_property->v_get(
            i_id,
            appl_property_type_ptr,
            &(
                o_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_value) =
            o_value.p_value;
    }

    return
        e_status;

} // s_get_ptr()

//
//
//
enum appl_status
appl_property_service::s_get_ulong(
    struct appl_property const * const
        p_property,
    unsigned int const
        i_id,
    unsigned long int * const
        r_value)
{
    enum appl_status
        e_status;

    union appl_property_value
        o_value;

    e_status =
        p_property->v_get(
            i_id,
            appl_property_type_ulong,
            &(
                o_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_value) =
            o_value.u_value;
    }

    return
        e_status;

} // s_get_ulong()

//
//
//
enum appl_status
appl_property_service::s_get_long(
    struct appl_property const * const
        p_property,
    unsigned int const
        i_id,
    signed long int * const
        r_value)
{
    enum appl_status
        e_status;

    union appl_property_value
        o_value;

    e_status =
        p_property->v_get(
            i_id,
            appl_property_type_long,
            &(
                o_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_value) =
            o_value.i_value;
    }

    return
        e_status;

} // s_get_long()

/* end-of-file: appl_property_handle.cpp */
