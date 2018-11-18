/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <timer/appl_timer_mgr.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_timer_mgr::v_create(
        struct appl_timer * * const
            r_timer)
{
    appl_unused(
        r_timer);

    return
        appl_status_not_implemented;

} // v_create()

//
//
//
appl_timer_mgr::appl_timer_mgr() :
    appl_object()
{
}

//
//
//
appl_timer_mgr::~appl_timer_mgr()
{
}

/* end-of-file: appl_timer_mgr.cpp */
