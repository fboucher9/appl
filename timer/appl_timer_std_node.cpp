/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_timer_handle.h>

#include <appl_object.h>

#include <appl_node.h>

#include <timer/appl_timer_node.h>

#include <appl_list.h>

#include <appl_mutex_handle.h>

#include <appl_thread_descriptor.h>

#include <property/appl_property_types.h>

#include <property/appl_property.h>

#include <appl_property_handle.h>

#include <appl_thread_handle.h>

#include <appl_event_handle.h>

#include <timer/appl_timer_std_node.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

#include <appl_heap_handle.h>

#include <appl_clock_handle.h>

#include <appl_convert.h>

#include <appl_unused.h>

#include <appl_buf.h>

//
//
//
enum appl_status
    appl_timer_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_timer_std_group * const
            p_timer_std_group,
        struct appl_timer_node * * const
            r_timer_node)
{
    enum appl_status
        e_status;

    class appl_timer_std_node *
        p_timer_std_node;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_timer_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        p_timer_std_node->m_timer_group =
            p_timer_std_group;

        *(
            r_timer_node) =
            p_timer_std_node;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_timer_std_node::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_timer_node * const
            p_timer_node)
{
    return
        appl_delete(
            p_allocator,
            p_timer_node);

} // s_destroy()

//
//
//
appl_timer_std_node::appl_timer_std_node(
    struct appl_context * const
        p_context) :
    appl_timer_node(
        p_context),
    m_descriptor(),
    m_timer_group(),
    m_state()
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
    enum appl_status
        e_status;

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_timer_std_node::v_cleanup(void)
{
    return
        sizeof(class appl_timer_std_node);

} // v_cleanup()

//
//
//
enum appl_status
    appl_timer_std_node::v_schedule(
        struct appl_timer_descriptor const * const
            p_timer_descriptor)
{
    enum appl_status
        e_status;

    appl_unused(
        p_timer_descriptor);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_schedule()

/* end-of-file: appl_timer_std_node.cpp */
