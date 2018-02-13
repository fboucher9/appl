/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_poll_handle.h"

#include "appl_poll_service.h"

/*

*/
enum appl_status
appl_poll_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_poll_descriptor const * const
        p_poll_descriptor,
    struct appl_poll_handle * * const
        r_poll_handle)
{
    enum appl_status
        e_status;

    e_status =
        appl_poll_service::create_handle(
            p_context_handle,
            p_poll_descriptor,
            r_poll_handle);

    return
        e_status;

} /* appl_poll_create() */

/* end-of-file: appl_poll_handle.cpp */
