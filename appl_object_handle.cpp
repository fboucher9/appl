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
    struct appl_object_handle * const
        p_object_handle)
{
    class appl_object * const
        p_object =
        appl_object::convert_handle(
            p_object_handle);

    return
        p_object->destroy();

} /* appl_object_destroy() */

/*

*/
struct appl_context_handle *
appl_object_get_context_handle(
    struct appl_object_handle const * const
        p_object_handle)
{
    class appl_object const * const
        p_object =
        appl_object::convert_const_handle(
            p_object_handle);

    return
        p_object->get_context_handle();

} /* appl_object_get_context_handle() */

/* end-of-file: appl_object_handle.cpp */
