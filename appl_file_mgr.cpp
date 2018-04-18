/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_file_mgr.h"

#include "appl_unused.h"

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
        p_file_descriptor);
    appl_unused(
        r_file_node);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_node()

//
//
//
appl_file_mgr::appl_file_mgr() :
    appl_object()
{
}

//
//
//
appl_file_mgr::~appl_file_mgr()
{
}

/* end-of-file: appl_file_mgr.cpp */
