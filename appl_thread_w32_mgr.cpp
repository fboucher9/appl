/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_thread_mgr.h"

#include "appl_thread_w32_mgr.h"

#include "appl_thread_node.h"

#include "appl_thread_w32_node.h"

//
//
//
enum appl_status
    appl_thread_w32_mgr::create_instance(
        class appl_context * const
            p_context,
        class appl_thread_mgr * * const
            r_thread_mgr)
{
    return
        appl_object::create_instance(
            p_context,
            sizeof(
                class appl_thread_w32_mgr),
            &(
                appl_thread_w32_mgr::placement_new),
            0,
            reinterpret_cast<class appl_object * *>(
                r_thread_mgr));

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
        class appl_context * const
            p_context,
        class appl_property const * const
            p_property,
        class appl_thread_node * * const
            r_thread_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_w32_node::create_instance(
            p_context,
            p_property,
            r_thread_node);

    return
        e_status;

} // v_create()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_thread_w32_mgr.cpp */