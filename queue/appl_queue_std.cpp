/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_queue_handle.h>

#include <appl_object.h>

#include <appl_list.h>

#include <queue/appl_queue.h>

#include <queue/appl_queue_impl.h>

#include <queue/appl_queue_std.h>

#include <appl_unused.h>

#include <allocator/appl_allocator.h>

//
//
//
enum appl_status
    appl_queue_std::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_queue_descriptor const * const
            p_descriptor,
        struct appl_queue * * const
            r_queue)
{
    enum appl_status
        e_status;

    class appl_queue_std *
        p_queue_std;

    e_status =
        p_allocator->alloc_object(
            p_descriptor,
            &(
                p_queue_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_queue) =
            p_queue_std;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_queue_std::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_queue * const
            p_queue)
{
    return
        p_queue->v_destroy(
            p_allocator);

} // s_destroy()

//
//
//
appl_queue_std::appl_queue_std() :
    appl_queue(),
    m_queue_impl()
{
}

//
//
//
appl_queue_std::~appl_queue_std()
{
}

//
//
//
enum appl_status
    appl_queue_std::v_push(
        struct appl_list * const
            p_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    return
        m_queue_impl.f_push(
            p_node,
            i_wait_freq,
            i_wait_count);

} // v_push()

//
//
//
enum appl_status
    appl_queue_std::v_pop(
        struct appl_list * * const
            r_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    return
        m_queue_impl.f_pop(
            r_node,
            i_wait_freq,
            i_wait_count);

} // v_pop()

//
//
//
enum appl_status
    appl_queue_std::v_interrupt(void)
{
    return
        m_queue_impl.f_interrupt();

} // v_interrupt()

//
//
//
enum appl_status
    appl_queue_std::f_init(
        struct appl_queue_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    e_status =
        m_queue_impl.f_init(
            m_context,
            p_descriptor);

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_queue_std::v_cleanup(void)
{
    m_queue_impl.f_cleanup(
        m_context);

    return
        sizeof(class appl_queue_std);

} // v_cleanup()

/* end-of-file: appl_queue_std.cpp */
