/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object_handle.h"

#include "appl_property_handle.h"

#include "appl_object.h"

#include "appl_property.h"

/*

*/
enum appl_status
appl_property_create(
    struct appl_context * const
        p_context_handle,
    unsigned int const
        i_count,
    struct appl_property_handle * * const
        r_property_handle)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_context_handle);
    static_cast<void>(
        i_count);
    static_cast<void>(
        r_property_handle);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_property_create() */

/*

*/
enum appl_status
appl_property_set_ptr(
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

} /* appl_property_set_ptr() */

/*

*/
enum appl_status
appl_property_set_ulong(
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

} /* appl_property_set_ulong() */

/*

*/
enum appl_status
appl_property_set_slong(
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
            appl_property_type_slong,
            &(
                o_value));

    return
        e_status;

} /* appl_property_set_slong() */

/*

*/
enum appl_status
appl_property_get_ptr(
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

} /* appl_property_get_ptr() */

/*

*/
enum appl_status
appl_property_get_ulong(
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

} /* appl_property_get_ulong() */

/*

*/
enum appl_status
appl_property_get_slong(
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
            appl_property_type_slong,
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

} /* appl_property_get_slong() */

/* end-of-file: appl_property_handle.cpp */
