/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_poll_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_list.h"

#include "appl_poll_mgr.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_poll_service::create_handle(
        struct appl_context_handle * const
            p_context_handle,
        struct appl_poll_descriptor const * const
            p_poll_descriptor,
        struct appl_poll_handle * * const
            r_poll_handle)
{
    enum appl_status
        e_status;

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_poll_mgr * const
        p_poll_mgr =
        p_context->m_poll_mgr;

    e_status =
        p_poll_mgr->v_create(
            p_poll_descriptor,
            reinterpret_cast<class appl_poll_node * *>(
                r_poll_handle));

    return
        e_status;

} // create_handle()

/* end-of-file: appl_poll_service.cpp */
