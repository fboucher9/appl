/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <library/appl_library_mgr.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_handle.h>
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
    return
        appl_raise_not_implemented();
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
    return
        appl_raise_not_implemented();
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
