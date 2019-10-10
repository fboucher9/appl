/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <dir/appl_dir_mgr.h>

#include <misc/appl_unused.h>

//
//
//
appl_dir_mgr::appl_dir_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_dir_mgr::~appl_dir_mgr()
{
}

//
//
//
enum appl_status
    appl_dir_mgr::v_enumerate(
        struct appl_dir_descriptor const * const
            p_descriptor)
{
    appl_unused(
        p_descriptor);

    return
        appl_raise_not_implemented();

} // v_enumerate()

/* end-of-file: appl_dir_mgr.cpp */
