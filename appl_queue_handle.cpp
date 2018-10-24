/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_queue_handle.h>

#include <appl_queue_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

/*

*/
enum appl_status
    appl_queue_create(
        struct appl_context * const
            p_context,
        struct appl_queue_descriptor const * const
            p_descriptor,
        struct appl_queue * * const
            r_instance)
{
    return
        appl_queue_service::s_create(
            p_context->m_allocator,
            p_descriptor,
            r_instance);

} /* appl_queue_create() */

/*

*/
struct appl_object *
    appl_queue_parent(
        struct appl_queue * const
            p_queue)
{
    return
        appl_queue_service::s_parent(
            p_queue);

} /* appl_queue_parent() */

/*

*/
enum appl_status
    appl_queue_push(
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
        appl_queue_service::s_push(
            p_queue,
            p_node,
            i_wait_freq,
            i_wait_count);

} /* appl_queue_push() */

/*

*/
enum appl_status
    appl_queue_pop(
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
        appl_queue_service::s_pop(
            p_queue,
            r_node,
            i_wait_freq,
            i_wait_count);

} /* appl_queue_pop() */

/*

*/
enum appl_status
    appl_queue_interrupt(
        struct appl_queue * const
            p_queue)
{
    return
        appl_queue_service::s_interrupt(
            p_queue);

} /* appl_queue_interrupt() */

/* end-of-file: appl_queue_handle.cpp */
