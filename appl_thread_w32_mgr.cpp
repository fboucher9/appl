/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <pthread.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_thread_mgr.h>

#include <appl_thread_w32_mgr.h>

#include <appl_thread_node.h>

#include <appl_thread_descriptor.h>

#include <appl_thread_impl.h>

#include <appl_thread_w32_node.h>

//
//
//
enum appl_status
    appl_thread_w32_mgr::create_instance(
        struct appl_context * const
            p_context,
        class appl_thread_mgr * * const
            r_thread_mgr)
{
    enum appl_status
        e_status;

    class appl_thread_w32_mgr *
        p_thread_w32_mgr;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_thread_w32_mgr::placement_new),
            &(
                p_thread_w32_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_thread_mgr) =
            p_thread_w32_mgr;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_thread_w32_mgr::appl_thread_w32_mgr() :
    appl_thread_mgr()
{
}

//
//
//
appl_thread_w32_mgr::~appl_thread_w32_mgr()
{
}

//
//
//
void
    appl_thread_w32_mgr::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_thread_w32_mgr;

} // placement_new()

//
//
//
enum appl_status
    appl_thread_w32_mgr::v_create(
        struct appl_context * const
            p_context,
        struct appl_thread_property const * const
            p_thread_property,
        struct appl_thread * * const
            r_thread)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_w32_node::create_instance(
            p_context,
            p_thread_property,
            r_thread);

    return
        e_status;

} // v_create()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_thread_w32_mgr.cpp */
