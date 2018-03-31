/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_property_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_property.h"

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
        class appl_context * const
            p_context,
        unsigned int const
            i_count,
        class appl_property * * const
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
                class appl_property)
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
class appl_property *
    appl_property::convert_handle(
        struct appl_property_handle * const
            p_property_handle)
{
    return
        reinterpret_cast<class appl_property *>(
            p_property_handle);

} // convert_handle()

//
//
//
struct appl_property_handle *
    appl_property::get_handle(void)
{
    return
        reinterpret_cast<struct appl_property_handle *>(
            this);

} // get_handle()

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
    static_cast<void>(
        i_id);
    static_cast<void>(
        e_type);
    static_cast<void>(
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
            p_value)
{
    static_cast<void>(
        i_id);
    static_cast<void>(
        e_type);
    static_cast<void>(
        p_value);
    return
        appl_status_not_implemented;
} // v_get()

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
        class appl_property;

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
