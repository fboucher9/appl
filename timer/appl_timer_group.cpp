/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <timer/appl_timer_group.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_timer_group::v_create_node(
        struct appl_timer_node * * const
            r_timer)
{
    appl_unused(
        r_timer);

    return
        appl_raise_not_implemented();

} // v_create_node()

//
//
//
enum appl_status
    appl_timer_group::v_destroy_node(
        struct appl_timer_node * const
            p_timer)
{
    appl_unused(
        p_timer);

    return
        appl_raise_not_implemented();

} // v_destroy_node()

//
//
//
appl_timer_group::appl_timer_group(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_timer_group::~appl_timer_group()
{
}

/* end-of-file: appl_timer_group.cpp */
