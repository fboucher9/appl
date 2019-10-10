/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <socket/appl_download_handle.h>

#include <socket/appl_download_service.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <socket/appl_download_mgr.h>

#include <list/appl_node.h>

#include <socket/appl_download_node.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
    appl_download_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_download_descriptor const * const
            p_descriptor,
        struct appl_download * * const
            r_handle)
{
    enum appl_status
        e_status;

    class appl_download_mgr *
        p_download_mgr;

    e_status =
        p_context->v_download_mgr(
            &(
                p_download_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_download_mgr->v_create_node(
                p_descriptor,
                r_handle);
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_download_service::s_destroy(
        struct appl_download * const
            p_handle)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_handle->get_context();

    class appl_download_mgr *
        p_download_mgr;

    e_status =
        p_context->v_download_mgr(
            &(
                p_download_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_download_mgr->v_destroy_node(
                p_handle);
    }

    return
        e_status;

} // s_destroy()

//
//
//
enum appl_status
    appl_download_service::s_cancel(
        struct appl_download * const
            p_handle)
{
    enum appl_status
        e_status;

    e_status =
        p_handle->v_cancel();

    return
        e_status;

} // s_cancel()

//
//
//
enum appl_status
    appl_download_service::s_wait(
        struct appl_download * const
            p_handle,
        unsigned long int const
            i_timeout_msec,
        enum appl_download_status * const
            r_status)
{
    enum appl_status
        e_status;

    e_status =
        p_handle->v_wait(
            i_timeout_msec,
            r_status);

    return
        e_status;

} // s_wait()

/* end-of-file: appl_download_service.cpp */
