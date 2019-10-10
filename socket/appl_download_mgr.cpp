/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_download_mgr.h>

#include <context/appl_context.h>

#include <appl_allocator_handle.h>

#include <socket/appl_download_handle.h>

#include <list/appl_node.h>

#include <socket/appl_download_node.h>

#include <misc/appl_unused.h>

//
//
//
appl_download_mgr::appl_download_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_download_mgr::~appl_download_mgr()
{
}

//
//
//
enum appl_status
    appl_download_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_download_mgr::v_cleanup(void)
{
    return
        sizeof(
            class appl_download_mgr);

} // v_cleanup()

//
//
//
enum appl_status
    appl_download_mgr::v_create_node(
        struct appl_download_descriptor const * const
            p_descriptor,
        struct appl_download * * const
            r_handle)
{
    enum appl_status
        e_status;

    e_status =
        appl_new(
            m_context->v_allocator(),
            p_descriptor,
            r_handle);

    return
        e_status;

} // v_create_node()

//
//
//
enum appl_status
    appl_download_mgr::v_destroy_node(
        struct appl_download * const
            p_handle)
{
    enum appl_status
        e_status;

    e_status =
        appl_delete(
            m_context->v_allocator(),
            p_handle);

    return
        e_status;

} // v_destroy_node()

/* end-of-file: appl_download_mgr.cpp */
