/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_queue_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_list.h>

#include <appl_queue.h>

#include <appl_queue_impl.h>

#include <appl_queue_std.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_queue_std::s_create(
        struct appl_context * const
            p_context,
        struct appl_queue_descriptor const * const
            p_descriptor,
        struct appl_queue * * const
            r_queue)
{
    appl_unused(
        p_context,
        p_descriptor,
        r_queue);

    return
        appl_status_not_implemented;

} // s_create()

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
void
    appl_queue_std::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_queue_std;

} // s_new()

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

    appl_unused(
        p_descriptor);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_queue_std::v_cleanup(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_cleanup()

/* end-of-file: appl_queue_std.cpp */
