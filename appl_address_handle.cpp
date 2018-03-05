/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_address_handle.h"

#include "appl_address_service.h"

/*

*/
enum appl_status
appl_address_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_address_descriptor const * const
        p_address_descriptor,
    struct appl_address_handle * * const
        r_address_handle)
{
    return
        appl_address_service::s_create(
            p_context_handle,
            p_address_descriptor,
            r_address_handle);

} /* appl_address_create() */

/* end-of-file: appl_address_handle.cpp */
