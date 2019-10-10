/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <list/appl_node.h>

#include <timer/appl_timer_node.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
    appl_timer_node::v_schedule(
        struct appl_timer_descriptor const * const
            p_timer_descriptor)
{
    appl_unused(
        p_timer_descriptor);

    return
        appl_raise_not_implemented();

} // v_schedule()

//
//
//
appl_timer_node::appl_timer_node(
    struct appl_context * const
        p_context) :
    appl_node(
        p_context)
{
}

//
//
//
appl_timer_node::~appl_timer_node()
{
}

/* end-of-file: appl_timer_node.cpp */
