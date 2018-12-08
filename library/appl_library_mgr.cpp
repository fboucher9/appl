/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <library/appl_library_mgr.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_library_mgr::v_create_node(
        struct appl_library_descriptor const * const
            p_library_descriptor,
        struct appl_library * * const
            r_library)
{
    appl_unused(
        p_library_descriptor,
        r_library);
#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "library mgr create node not implemented\n");
#endif /* #if defined APPL_DEBUG */
    return
        appl_status_not_implemented;
} // v_create_node()

//
//
//
enum appl_status
    appl_library_mgr::v_destroy_node(
        struct appl_library * const
            p_library)
{
    appl_unused(
        p_library);
#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "library mgr destroy node not implemented\n");
#endif /* #if defined APPL_DEBUG */
    return
        appl_status_not_implemented;
} // v_destroy_node()

//
//
//
appl_library_mgr::appl_library_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_library_mgr::~appl_library_mgr()
{
}

/* end-of-file: appl_library_mgr.cpp */
