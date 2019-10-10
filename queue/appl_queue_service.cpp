/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_queue_handle.h>

#include <queue/appl_queue_service.h>

#include <appl_object.h>

#include <list/appl_list.h>

#include <queue/appl_queue.h>

#include <queue/appl_queue_impl.h>

#include <queue/appl_queue_std.h>

#include <appl_context_handle.h>

//
//
//
enum appl_status
    appl_queue_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_queue_descriptor const * const
            p_descriptor,
        struct appl_queue * * const
            r_instance)
{
    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_queue_std::s_create(
            p_allocator,
            p_descriptor,
            r_instance);

} // s_create()

//
//
//
enum appl_status
    appl_queue_service::s_destroy(
        struct appl_queue * const
            p_queue)
{
    struct appl_context * const
        p_context =
        p_queue->get_context();

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_queue_std::s_destroy(
            p_allocator,
            p_queue);

} // s_destroy()

//
//
//
struct appl_object *
    appl_queue_service::s_parent(
        struct appl_queue * const
            p_queue)
{
    return
        p_queue;

} // s_parent()

//
//
//
enum appl_status
    appl_queue_service::s_push(
        struct appl_queue * const
            p_queue,
        struct appl_list * const
            p_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    return
        p_queue->v_push(
            p_node,
            i_wait_freq,
            i_wait_count);

} // s_push()

//
//
//
enum appl_status
    appl_queue_service::s_pop(
        struct appl_queue * const
            p_queue,
        struct appl_list * * const
            r_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    return
        p_queue->v_pop(
            r_node,
            i_wait_freq,
            i_wait_count);

} // s_pop()

//
//
//
enum appl_status
    appl_queue_service::s_interrupt(
        struct appl_queue * const
            p_queue)
{
    return
        p_queue->v_interrupt();

} // s_interrupt()

/* end-of-file: appl_queue_service.cpp */
