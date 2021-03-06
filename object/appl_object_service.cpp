/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <object/appl_object_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

//
//
//
struct appl_context *
appl_object_service::s_get_context(
    struct appl_object const * const
        p_object)
{
    return
        p_object->get_context();

} // s_get_context()

/* end-of-file: appl_object_service.cpp */
