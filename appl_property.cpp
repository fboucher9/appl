/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_property_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_property.h"

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
    appl_object()
{
}

//
//
//
appl_property::~appl_property()
{
}

/* end-of-file: appl_property.cpp */
