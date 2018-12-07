/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_buf.h>

#include <property/appl_property_types.h>

#include <appl_types.h>

#include <appl_object.h>

#include <property/appl_property.h>

#include <appl_unused.h>

#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_property::v_set(
        unsigned int const
            i_id,
        enum appl_property_type const
            e_type,
        union appl_property_value const * const
            p_value)
{
    appl_unused(
        i_id,
        e_type,
        p_value);

    return
        appl_status_not_implemented;

} // v_set()

//
//
//
enum appl_status
    appl_property::v_get(
        unsigned int const
            i_id,
        enum appl_property_type const
            e_type,
        union appl_property_value * const
            p_value) const
{
    appl_unused(
        i_id,
        e_type,
        p_value);

    return
        appl_status_not_implemented;

} // v_get()

//
//
//
enum appl_status
    appl_property::get_ptr(
        unsigned int const
            i_id,
        void * * const
            r_value) const
{
    enum appl_status
        e_status;

    union appl_property_value
        o_value;

    e_status =
        v_get(
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

} // get_ptr()

//
//
//
enum appl_status
    appl_property::get_ulong(
        unsigned int const
            i_id,
        unsigned long int * const
            r_value) const
{
    enum appl_status
        e_status;

    union appl_property_value
        o_value;

    e_status =
        v_get(
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

} // get_ulong()

//
//
//
enum appl_status
    appl_property::get_long(
        unsigned int const
            i_id,
        signed long int * const
            r_value) const
{
    enum appl_status
        e_status;

    union appl_property_value
        o_value;

    e_status =
        v_get(
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

} // get_long()

//
//
//
appl_property::appl_property(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_property::~appl_property()
{
}

/* end-of-file: appl_property.cpp */
