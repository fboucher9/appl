/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_object_service.h>

#include <appl_types.h>

#include <appl_object.h>

//
//
//
enum appl_status
appl_object_service::s_destroy(
    struct appl_object * const
        p_object)
{
    return
        p_object->v_destroy();

} // s_destroy()

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
