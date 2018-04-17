/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_property_types.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_property.h"

/*

*/
struct appl_property_descriptor
{
    unsigned int
        i_count;

}; /* struct appl_property_descriptor */

//
//
//
enum appl_status
    appl_property::s_create(
        struct appl_context * const
            p_context,
        unsigned int const
            i_count,
        struct appl_property * * const
            r_property)
{
    enum appl_status
        e_status;

    struct appl_property_descriptor
        o_property_descriptor;

    o_property_descriptor.i_count =
        i_count;

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                struct appl_property)
            + (
                sizeof(
                    struct appl_property_node)
                * i_count),
            &(
                appl_property::s_new),
            &(
                o_property_descriptor),
            r_property);

    return
        e_status;

} // s_create()

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
    enum appl_status
        e_status;

    if (
        i_id < m_count)
    {
        a_nodes[i_id].e_type =
            e_type;

        a_nodes[i_id].o_value =
            *(
                p_value);

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

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
    enum appl_status
        e_status;

    if (
        i_id < m_count)
    {
        if (
            e_type == a_nodes[i_id].e_type)
        {
            *(
                p_value) =
                a_nodes[i_id].o_value;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

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
appl_property::appl_property() :
    appl_object(),
    m_count()
{
}

//
//
//
appl_property::~appl_property()
{
}

//
//
//
void
    appl_property::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        struct appl_property;

} // s_new()

//
//
//
enum appl_status
    appl_property::init(
        void const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_property_descriptor const * const
        p_property_descriptor =
        static_cast<struct appl_property_descriptor const *>(
            p_descriptor);

    m_count =
        p_property_descriptor->i_count;

    {
        unsigned int
            i;

        for (
            i = 0u;
            i < m_count;
            i ++)
        {
            a_nodes[i].e_type =
                appl_property_type_default;

            a_nodes[i].o_value.p_value =
                0;
        }
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // init()

//
//
//
enum appl_status
    appl_property::cleanup(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

/* end-of-file: appl_property.cpp */
