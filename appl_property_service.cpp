/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_property_service.h"

#include "appl_object_handle.h"

#include "appl_property_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_property.h"

#include "appl_context.h"

//
//
//
enum appl_status
appl_property_service::s_create(
    struct appl_context_handle * const
        p_context_handle,
    unsigned int const
        i_count,
    struct appl_property_handle * * const
        r_property_handle)
{
    enum appl_status
        e_status;

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_property *
        p_property;

    e_status =
        appl_property::s_create(
            p_context,
            i_count,
            &(
                p_property));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_property_handle) =
            p_property->get_handle();
    }

    return
        e_status;

} // s_create()

/*

*/
enum appl_status
appl_property_service::s_set_ptr(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    void * const
        p_value)
{
    enum appl_status
        e_status;

    class appl_property * const
        p_property =
        appl_property::convert_handle(
            p_property_handle);

    union appl_property_value
        o_value;

    o_value.p_value =
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

/*

*/
enum appl_status
appl_property_service::s_set_ulong(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int const
        u_value)
{
    enum appl_status
        e_status;

    class appl_property * const
        p_property =
        appl_property::convert_handle(
            p_property_handle);

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

/*

*/
enum appl_status
appl_property_service::s_set_long(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int const
        i_value)
{
    enum appl_status
        e_status;

    class appl_property * const
        p_property =
        appl_property::convert_handle(
            p_property_handle);

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

/*

*/
enum appl_status
appl_property_service::s_get_ptr(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    void * * const
        r_value)
{
    enum appl_status
        e_status;

    class appl_property * const
        p_property =
        appl_property::convert_handle(
            p_property_handle);

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

/*

*/
enum appl_status
appl_property_service::s_get_ulong(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int * const
        r_value)
{
    enum appl_status
        e_status;

    class appl_property * const
        p_property =
        appl_property::convert_handle(
            p_property_handle);

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

/*

*/
enum appl_status
appl_property_service::s_get_long(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int * const
        r_value)
{
    enum appl_status
        e_status;

    class appl_property * const
        p_property =
        appl_property::convert_handle(
            p_property_handle);

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
