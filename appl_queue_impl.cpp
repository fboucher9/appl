/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_object_handle.h>

#include <appl_queue_handle.h>

#include <appl_mutex_handle.h>

#include <appl_event_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_pool_object.h>

#include <appl_mutex_node.h>

#include <appl_event_node.h>

#include <appl_mutex_mgr.h>

#include <appl_event_mgr.h>

#include <appl_list.h>

#include <appl_queue_impl.h>

#include <appl_context.h>

#include <appl_unused.h>

//
//
//
appl_queue_impl::appl_queue_impl() :
    m_lock(),
    m_event(),
    m_list(),
    m_descriptor(),
    m_count()
{
}

//
//
//
appl_queue_impl::~appl_queue_impl()
{
}

//
//
//
enum appl_status
    appl_queue_impl::f_init(
        struct appl_context * const
            p_context,
        struct appl_queue_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor =
        *(
            p_descriptor);

    appl_list_init(
        &(
            m_list));

    struct appl_mutex_descriptor
        o_mutex_descriptor;

    e_status =
        p_context->m_mutex_mgr->v_create(
            &(
                o_mutex_descriptor),
            &(
                m_lock));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_event_descriptor
            o_event_descriptor;

        e_status =
            p_context->m_event_mgr->v_create(
                &(
                    o_event_descriptor),
                &(
                    m_event));

        if (
            appl_status_ok
            == e_status)
        {
            if (
                appl_status_ok
                != e_status)
            {
                appl_object_destroy(
                    appl_event_parent(
                        m_event));
            }
        }

        if (
            appl_status_ok
            != e_status)
        {
            appl_object_destroy(
                appl_mutex_parent(
                    m_lock));
        }
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_queue_impl::f_cleanup(void)
{
    enum appl_status
        e_status;

    // Free all nodes?

    appl_object_destroy(
        appl_event_parent(
            m_event));

    appl_object_destroy(
        appl_mutex_parent(
            m_lock));

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_cleanup()

//
//
//
enum appl_status
    appl_queue_impl::f_push(
        struct appl_list * const
            p_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    if (
        appl_status_ok
        == m_lock->v_lock())
    {
        if (
            m_count >= m_descriptor.i_max_count)
        {
            if (
                appl_status_ok
                == m_event->v_wait(
                    m_lock,
                    i_wait_freq,
                    i_wait_count))
            {
            }
        }

        if (
            m_count < m_descriptor.i_max_count)
        {
            appl_list_join(
                p_node,
                &(
                    m_list));

            m_count ++;

            m_event->v_signal();

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        m_lock->v_unlock();
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_push()

//
//
//
enum appl_status
    appl_queue_impl::f_pop(
        struct appl_list * * const
            r_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    if (
        appl_status_ok
        == m_lock->v_lock())
    {
        if (
            0
            == m_count)
        {
            if (
                appl_status_ok
                == m_event->v_wait(
                    m_lock,
                    i_wait_freq,
                    i_wait_count))
            {
            }
        }

        if (
            0
            != m_count)
        {
            struct appl_list *
                p_node;

            p_node =
                m_list.o_next.p_node;

            appl_list_join(
                p_node,
                p_node);

            m_count --;

            m_event->v_signal();

            *(
                r_node) =
                p_node;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        m_lock->v_unlock();
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_pop()

//
//
//
enum appl_status
    appl_queue_impl::f_interrupt(void)
{
    enum appl_status
        e_status;

    if (
        appl_status_ok
        == m_lock->v_lock())
    {
        m_event->v_signal();

        e_status =
            appl_status_ok;

        m_lock->v_unlock();
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_interrupt()

/* end-of-file: appl_queue_impl.cpp */
