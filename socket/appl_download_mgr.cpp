/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_download_mgr.h>

#include <appl_unused.h>

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
    appl_download_mgr::v_create_node(
        struct appl_download_descriptor const * const
            p_descriptor,
        struct appl_download * * const
            r_handle)
{
    appl_unused(
        p_descriptor,
        r_handle);

    return
        appl_raise_not_implemented();

} // v_create_node()

//
//
//
enum appl_status
    appl_download_mgr::v_destroy_node(
        struct appl_download * const
            p_handle)
{
    appl_unused(
        p_handle);

    return
        appl_raise_not_implemented();

} // v_destroy_node()

/* end-of-file: appl_download_mgr.cpp */
