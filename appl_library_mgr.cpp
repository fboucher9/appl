/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_library_mgr.h>

#include <appl_unused.h>

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
        appl_status_not_implemented;
} // v_create_node()

//
//
//
appl_library_mgr::appl_library_mgr() :
    appl_object()
{
}

//
//
//
appl_library_mgr::~appl_library_mgr()
{
}

/* end-of-file: appl_library_mgr.cpp */
