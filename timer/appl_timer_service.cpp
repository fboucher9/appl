/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_timer_handle.h>

#include <timer/appl_timer_service.h>

#include <appl_object.h>

#include <appl_node.h>

#include <timer/appl_timer_mgr.h>

#include <timer/appl_timer_group.h>

#include <timer/appl_timer_node.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
appl_timer_service::s_create_group(
    struct appl_context * const
        p_context,
    struct appl_timer_group * * const
        r_timer_group)
{
    enum appl_status
        e_status;

    class appl_timer_mgr *
        p_timer_mgr;

    e_status =
        p_context->v_timer_mgr(
            &(
                p_timer_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_timer_mgr->v_create_group(
                r_timer_group);
    }

    return
        e_status;

} // s_create_group()

//
//
//
enum appl_status
appl_timer_service::s_destroy_group(
    struct appl_context * const
        p_context,
    struct appl_timer_group * const
        p_timer_group)
{
    enum appl_status
        e_status;

    class appl_timer_mgr *
        p_timer_mgr;

    e_status =
        p_context->v_timer_mgr(
            &(
                p_timer_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_timer_mgr->v_destroy_group(
                p_timer_group);
    }

    return
        e_status;

} // s_destroy_group()

//
//
//
struct appl_object *
appl_timer_service::s_parent_group(
    struct appl_timer_group * const
        p_timer_group)
{
    return
        p_timer_group;

} // s_parent_group()

//
//
//
struct appl_object const *
appl_timer_service::s_const_parent_group(
    struct appl_timer_group const * const
        p_timer_group)
{
    return
        p_timer_group;

} // s_const_parent_group()

//
//
//
enum appl_status
appl_timer_service::s_create_node(
    struct appl_timer_group * const
        p_timer_group,
    struct appl_timer_node * * const
        r_timer_node)
{
    enum appl_status
        e_status;

    struct appl_timer_node *
        p_timer_node;

    e_status =
        p_timer_group->v_create_node(
            &(
                p_timer_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_timer_node) =
            p_timer_node;
    }

    return
        e_status;

} // s_create_node()

//
//
//
enum appl_status
appl_timer_service::s_destroy_node(
    struct appl_timer_group * const
        p_timer_group,
    struct appl_timer_node * const
        p_timer_node)
{
    enum appl_status
        e_status;

    e_status =
        p_timer_group->v_destroy_node(
            p_timer_node);

    return
        e_status;

} // s_destroy_node()

//
//
//
struct appl_object *
appl_timer_service::s_parent_node(
    struct appl_timer_node * const
        p_timer_node)
{
    return
        p_timer_node;

} // s_parent_node()

//
//
//
struct appl_object const *
appl_timer_service::s_const_parent_node(
    struct appl_timer_node const * const
        p_timer_node)
{
    return
        p_timer_node;

} // s_const_parent_node()

//
//
//
enum appl_status
appl_timer_service::s_schedule_node(
    struct appl_timer_node * const
        p_timer_node,
    struct appl_timer_descriptor const * const
        p_timer_descriptor)
{
    return
        p_timer_node->v_schedule(
            p_timer_descriptor);

} // s_schedule_node()

/* end-of-file: appl_timer_service.cpp */
