/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_types.h"

#include "appl_object.h"

/*

*/
enum appl_status
appl_object_destroy(
    struct appl_object* const
        p_object)
{
    return
        p_object->destroy();

} /* appl_object_destroy() */

/*

*/
struct appl_context *
appl_object_get_context(
    struct appl_object const * const
        p_object)
{
    return
        p_object->get_context();

} /* appl_object_get_context() */

/* end-of-file: appl_object_handle.cpp */
