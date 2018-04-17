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
    struct appl_context * const
        p_context,
    struct appl_poll_descriptor const * const
        p_poll_descriptor,
    struct appl_poll * * const
        r_poll)
{
    enum appl_status
        e_status;

    e_status =
        appl_poll_service::create_handle(
            p_context,
            p_poll_descriptor,
            r_poll);

    return
        e_status;

} /* appl_poll_create() */

/* end-of-file: appl_poll_handle.cpp */
