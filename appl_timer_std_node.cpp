/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_timer.h>

#include <appl_timer_std_node.h>

#include <appl_timer_handle.h>

#include <appl_allocator.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_timer_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_timer * * const
            r_timer)
{
    enum appl_status
        e_status;

    class appl_timer_std_node *
        p_timer_std_node;

    e_status =
        p_allocator->alloc_object(
            &(
                p_timer_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_timer) =
            p_timer_std_node;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_timer_std_node::appl_timer_std_node() :
    appl_timer()
{
}

//
//
//
appl_timer_std_node::~appl_timer_std_node()
{
}

//
//
//
enum appl_status
    appl_timer_std_node::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
enum appl_status
    appl_timer_std_node::v_schedule(
        struct appl_timer_descriptor const * const
            p_timer_descriptor)
{
    appl_unused(
        p_timer_descriptor);

    return
        appl_status_fail;

} // v_schedule()

/* end-of-file: appl_timer_std_node.cpp */
