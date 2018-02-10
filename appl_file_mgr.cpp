/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_file_mgr.h"

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
        class appl_file_node * * const
            r_file_node)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_file_descriptor);
    static_cast<void>(
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
