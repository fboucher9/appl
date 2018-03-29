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
}

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
}

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
}

//
//
//
appl_property::appl_property()
{
}

//
//
//
appl_property::~appl_property()
{
}

/* end-of-file: appl_property.cpp */
