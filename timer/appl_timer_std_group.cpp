/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_node.h>

#include <timer/appl_timer_mgr.h>

#include <timer/appl_timer_std_mgr.h>

#include <timer/appl_timer_group.h>

#include <timer/appl_timer_node.h>

#include <appl_list.h>

#include <timer/appl_timer_std_group.h>

#include <timer/appl_timer_std_node.h>

#include <appl_allocator_handle.h>

#include <appl_context_handle.h>

//
//
//
enum appl_status
    appl_timer_std_group::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_timer_group * * const
            r_timer_group)
{
    enum appl_status
        e_status;

    class appl_timer_std_group *
        p_timer_std_group;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_timer_std_group));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_timer_group) =
            p_timer_std_group;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_timer_std_group::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_timer_group * const
            p_timer_group)
{
    enum appl_status
        e_status;

    e_status =
        appl_delete(
            p_allocator,
            p_timer_group);

    return
        e_status;

} // s_destroy()

//
//
//
appl_timer_std_group::appl_timer_std_group(
    struct appl_context * const
        p_context) :
    appl_timer_group(
        p_context)
{
}

//
//
//
appl_timer_std_group::~appl_timer_std_group()
{
}

//
//
//
enum appl_status
    appl_timer_std_group::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_timer_std_group::v_cleanup(void)
{
    return
        sizeof(class appl_timer_std_group);
} // v_cleanup()

//
//
//
enum appl_status
    appl_timer_std_group::v_create_node(
        struct appl_timer_node * * const
            r_timer_node)
{
    struct appl_context * const
        p_context =
        get_context();

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_timer_std_node::s_create(
            p_allocator,
            this,
            r_timer_node);

} // v_create_node()

//
//
//
enum appl_status
    appl_timer_std_group::v_destroy_node(
        struct appl_timer_node * const
            p_timer_node)
{
    struct appl_context * const
        p_context =
        get_context();

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_timer_std_node::s_destroy(
            p_allocator,
            p_timer_node);

} // v_destroy_node()

/* end-of-file: appl_timer_std_group.cpp */
