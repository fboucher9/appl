/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <dir/appl_dir_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <dir/appl_dir_mgr.h>

//
//
//
enum appl_status
    appl_dir_service::s_enumerate(
        struct appl_context * const
            p_context,
        struct appl_dir_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    class appl_dir_mgr *
        p_dir_mgr;

    e_status =
        p_context->v_dir_mgr(
            &(
                p_dir_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_dir_mgr->v_enumerate(
                p_descriptor);
    }

    return
        e_status;

} // s_enumerate()

/* end-of-file: appl_dir_service.cpp */
