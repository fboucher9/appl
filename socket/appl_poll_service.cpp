/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <socket/appl_poll_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <list/appl_list.h>

#include <list/appl_node.h>

#include <socket/appl_poll_mgr.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
enum appl_status
    appl_poll_service::create_handle(
        struct appl_context * const
            p_context,
        struct appl_poll_descriptor const * const
            p_poll_descriptor,
        struct appl_poll * * const
            r_poll)
{
    enum appl_status
        e_status;

    class appl_poll_mgr *
        p_poll_mgr;

    e_status =
        p_context->v_poll_mgr(
            &(
                p_poll_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_poll_mgr->v_create(
                p_poll_descriptor,
                r_poll);
    }

    return
        e_status;

} // create_handle()

/* end-of-file: appl_poll_service.cpp */
