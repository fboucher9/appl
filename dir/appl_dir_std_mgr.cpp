/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_object.h>

#include <dir/appl_dir_mgr.h>

#include <dir/appl_dir_std_mgr.h>

#include <appl_unused.h>

//
//
//
appl_dir_std_mgr::appl_dir_std_mgr(
    struct appl_context * const
        p_context) :
    appl_dir_mgr(
        p_context)
{
}

//
//
//
appl_dir_std_mgr::~appl_dir_std_mgr()
{
}

//
//
//
enum appl_status
    appl_dir_std_mgr::v_enumerate(
        struct appl_dir_descriptor const * const
            p_descriptor)
{
    appl_unused(
        p_descriptor);

    return
        appl_raise_not_implemented();

} // v_enumerate()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_dir_std_mgr.cpp */
