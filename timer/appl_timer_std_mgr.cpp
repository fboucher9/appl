/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <timer/appl_timer_mgr.h>

#include <timer/appl_timer_std_mgr.h>

#include <timer/appl_timer.h>

#include <appl_list.h>

#include <timer/appl_timer_std_node.h>

#include <appl_allocator_handle.h>

#include <appl_context_handle.h>

//
//
//
enum appl_status
    appl_timer_std_mgr::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_timer_mgr * * const
            r_timer_mgr)
{
    enum appl_status
        e_status;

    class appl_timer_std_mgr *
        p_timer_std_mgr;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_timer_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_timer_mgr) =
            p_timer_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_timer_std_mgr::appl_timer_std_mgr() :
    appl_timer_mgr()
{
}

//
//
//
appl_timer_std_mgr::~appl_timer_std_mgr()
{
}

//
//
//
enum appl_status
    appl_timer_std_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_timer_std_mgr::v_cleanup(void)
{
    return
        sizeof(class appl_timer_std_mgr);
} // v_cleanup()

//
//
//
enum appl_status
    appl_timer_std_mgr::v_create_node(
        struct appl_timer * * const
            r_timer)
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
            r_timer);

} // v_create_node()

//
//
//
enum appl_status
    appl_timer_std_mgr::v_destroy_node(
        struct appl_timer * const
            p_timer)
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
            p_timer);

} // v_destroy_node()

/* end-of-file: appl_timer_std_mgr.cpp */
