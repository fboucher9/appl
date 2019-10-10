/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <timer/appl_timer_mgr.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_timer_mgr::v_create_group(
        struct appl_timer_group * * const
            r_timer)
{
    appl_unused(
        r_timer);

    return
        appl_raise_not_implemented();

} // v_create_group()

//
//
//
enum appl_status
    appl_timer_mgr::v_destroy_group(
        struct appl_timer_group * const
            p_timer)
{
    appl_unused(
        p_timer);

    return
        appl_raise_not_implemented();

} // v_destroy_group()

//
//
//
appl_timer_mgr::appl_timer_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_timer_mgr::~appl_timer_mgr()
{
}

/* end-of-file: appl_timer_mgr.cpp */
