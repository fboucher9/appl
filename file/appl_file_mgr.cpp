/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <file/appl_file_mgr.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

//
//
//
enum appl_status
    appl_file_mgr::v_create_node(
        struct appl_file_descriptor const * const
            p_file_descriptor,
        struct appl_file * * const
            r_file_node)
{
    enum appl_status
        e_status;

    appl_unused(
        p_file_descriptor,
        r_file_node);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "file mgr create node not implemented\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_node()

//
//
//
enum appl_status
    appl_file_mgr::v_destroy_node(
        struct appl_file * const
            p_file_node)
{
    enum appl_status
        e_status;

    appl_unused(
        p_file_node);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "file mgr destroy node not implemented\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_destroy_node()

//
//
//
appl_file_mgr::appl_file_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_file_mgr::~appl_file_mgr()
{
}

/* end-of-file: appl_file_mgr.cpp */
