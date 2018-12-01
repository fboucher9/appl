/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_object_handle.h>

#include <object/appl_object_service.h>

/*

*/
struct appl_context *
appl_object_get_context(
    struct appl_object const * const
        p_object)
{
    return
        appl_object_service::s_get_context(
            p_object);

} /* appl_object_get_context() */

/* end-of-file: appl_object_handle.cpp */
