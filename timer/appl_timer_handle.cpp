/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_timer_handle.h>

#include <timer/appl_timer_service.h>

//
//
//
enum appl_status
appl_timer_group_create(
    struct appl_context * const
        p_context,
    struct appl_timer_group * * const
        r_timer_group)
{
    return
        appl_timer_service::s_create_group(
            p_context,
            r_timer_group);

} // appl_timer_group_create()

//
//
//
enum appl_status
appl_timer_group_destroy(
    struct appl_context * const
        p_context,
    struct appl_timer_group * const
        p_timer_group)
{
    return
        appl_timer_service::s_destroy_group(
            p_context,
            p_timer_group);

} // appl_timer_group_destroy()

//
//
//
struct appl_object *
appl_timer_group_parent(
    struct appl_timer_group * const
        p_timer_group)
{
    return
        appl_timer_service::s_parent_group(
            p_timer_group);

} // appl_timer_group_parent()

//
//
//
struct appl_object const *
appl_timer_group_const_parent(
    struct appl_timer_group const * const
        p_timer_group)
{
    return
        appl_timer_service::s_const_parent_group(
            p_timer_group);

} // appl_timer_group_const_parent()

//
//
//
enum appl_status
appl_timer_node_create(
    struct appl_timer_group * const
        p_timer_group,
    struct appl_timer_node * * const
        r_timer_node)
{
    return
        appl_timer_service::s_create_node(
            p_timer_group,
            r_timer_node);

} // appl_timer_node_create()

//
//
//
enum appl_status
appl_timer_node_destroy(
    struct appl_timer_group * const
        p_timer_group,
    struct appl_timer_node * const
        p_timer_node)
{
    return
        appl_timer_service::s_destroy_node(
            p_timer_group,
            p_timer_node);

} // appl_timer_node_destroy()

//
//
//
struct appl_object *
appl_timer_node_parent(
    struct appl_timer_node * const
        p_timer_node)
{
    return
        appl_timer_service::s_parent_node(
            p_timer_node);

} // appl_timer_node_parent()

//
//
//
struct appl_object const *
appl_timer_node_const_parent(
    struct appl_timer_node const * const
        p_timer_node)
{
    return
        appl_timer_service::s_const_parent_node(
            p_timer_node);

} // appl_timer_node_const_parent()

//
//
//
enum appl_status
appl_timer_node_schedule(
    struct appl_timer_node * const
        p_timer_node,
    struct appl_timer_descriptor const * const
        p_timer_descriptor)
{
    return
        appl_timer_service::s_schedule_node(
            p_timer_node,
            p_timer_descriptor);

} // appl_timer_node_schedule()

/* end-of-file: appl_timer_handle.cpp */
