/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <thread/appl_thread_mgr.h>

#include <appl_unused.h>

#include <appl_assert_cplusplus.h>

//
//
//
enum appl_status
    appl_thread_mgr::v_create_node(
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_thread * * const
            r_thread)
{
    appl_unused(
        p_thread_descriptor,
        r_thread);
    return
        appl_status_not_implemented;
} // v_create_node()

//
//
//
enum appl_status
    appl_thread_mgr::v_destroy_node(
        struct appl_thread * const
            p_thread)
{
    appl_unused(
        p_thread);
    return
        appl_status_not_implemented;
} // v_destroy_node()

//
//
//
appl_thread_mgr::appl_thread_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_thread_mgr::~appl_thread_mgr()
{
}

/* end-of-file: appl_thread_mgr.cpp */
