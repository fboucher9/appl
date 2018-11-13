/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_timer.h>

#include <appl_list.h>

#include <appl_mutex_handle.h>

#include <appl_mutex_node.h>

#include <appl_mutex_mgr.h>

#include <appl_thread_descriptor.h>

#include <appl_property_types.h>

#include <appl_property.h>

#include <appl_property_handle.h>

#include <appl_thread_property.h>

#include <appl_thread_node.h>

#include <appl_thread_mgr.h>

#include <appl_event_handle.h>

#include <appl_event_node.h>

#include <appl_event_mgr.h>

#include <appl_timer_std_node.h>

#include <appl_timer_handle.h>

#include <appl_context.h>

#include <appl_allocator.h>

#include <appl_heap.h>

#include <appl_clock.h>

#include <appl_convert.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_timer_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_timer * * const
            r_timer)
{
    enum appl_status
        e_status;

    class appl_timer_std_node *
        p_timer_std_node;

    e_status =
        p_allocator->alloc_object(
            &(
                p_timer_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_timer) =
            p_timer_std_node;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_timer_std_node::appl_timer_std_node() :
    appl_timer(),
    m_used_list(),
    m_free_list(),
    m_thread(),
    m_lock(),
    m_event(),
    m_thread_kill(),
    m_thread_killed()
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

    // Initialize used linked list
    {
        appl_list_init(
            &(
                m_used_list));
    }

    // Initialize free linked list
    {
        appl_list_init(
            &(
                m_free_list));
    }

    // Initialize mutex
    struct appl_mutex_descriptor
        o_mutex_descriptor;

    e_status =
        m_context->m_mutex_mgr->v_create(
            &(
                o_mutex_descriptor),
            &(
                m_lock));

    if (
        appl_status_ok
        == e_status)
    {
        // Initialize event
        struct appl_event_descriptor
            o_event_descriptor;

        e_status =
            m_context->m_event_mgr->v_create(
                &(
                    o_event_descriptor),
                &(
                    m_event));

        if (
            appl_status_ok
            == e_status)
        {
            // Initialize thread
            struct appl_thread_property *
                p_thread_property;

            e_status =
                appl_thread_property_create(
                    m_context,
                    &(
                        p_thread_property));

            if (
                appl_status_ok
                == e_status)
            {
                struct appl_thread_descriptor
                    o_thread_descriptor;

                o_thread_descriptor.p_entry =
                    (&
                        appl_timer_std_node::s_worker);

                o_thread_descriptor.p_context =
                    this;

                e_status =
                    m_context->m_thread_mgr->v_create(
                        p_thread_property,
                        &(
                            o_thread_descriptor),
                        &(
                            m_thread));

                if (
                    appl_status_ok
                    == e_status)
                {
                    // etc.
                }

                appl_thread_property_parent(
                    p_thread_property)->v_destroy();
            }

            if (
                appl_status_ok
                != e_status)
            {
                m_event->v_destroy();
            }
        }

        if (
            appl_status_ok
            != e_status)
        {
            m_lock->v_destroy();
        }
    }

    return
        e_status;

} // f_init()

struct appl_timer_std_event
{
    struct appl_list
        o_list;

    struct appl_timer_descriptor
        o_timer_descriptor;

};

union appl_timer_std_event_ptr
{
    struct appl_list *
        p_list;

    struct appl_timer_std_event *
        p_timer_std_event;

};

//
//
//
enum appl_status
    appl_timer_std_node::v_cleanup(void)
{
    while (
        !(
            m_thread_killed))
    {
        m_lock->v_lock();

        m_thread_kill =
            1l;

        m_event->v_signal();

        m_lock->v_unlock();

        if (
            !m_thread_killed)
        {
            m_context->m_clock->v_delay(
                1000ul,
                100ul);
        }
    }

    m_thread->v_destroy();

    m_event->v_destroy();

    m_lock->v_destroy();

    // Release all active nodes
    {
        while (
            m_used_list.o_next.p_node
            != &(m_used_list))
        {
            struct appl_list * const
                p_node =
                m_used_list.o_next.p_node;

            appl_list_join(
                p_node,
                p_node);

            appl_list_join(
                p_node,
                &(
                    m_free_list));
        }
    }

    // Free all unused nodes
    {
        while (
            m_free_list.o_next.p_node
            != &(m_free_list))
        {
            union appl_timer_std_event_ptr
                o_timer_std_event_ptr;

            o_timer_std_event_ptr.p_list =
                m_free_list.o_next.p_node;

            // Detach from list
            appl_list_join(
                o_timer_std_event_ptr.p_list,
                o_timer_std_event_ptr.p_list);

            m_context->m_heap->free_structure(
                o_timer_std_event_ptr.p_timer_std_event);
        }
    }

    return
        appl_status_ok;

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

    // Allocate a node
    struct appl_timer_std_event *
        p_timer_std_event;

    m_lock->v_lock();

    if (
        m_free_list.o_next.p_node
        != &(m_free_list))
    {
        {
            union appl_timer_std_event_ptr
                o_timer_std_event_ptr;

            o_timer_std_event_ptr.p_list =
                m_free_list.o_next.p_node;

            p_timer_std_event =
                o_timer_std_event_ptr.p_timer_std_event;
        }

        appl_list_join(
            &(
                p_timer_std_event->o_list),
            &(
                p_timer_std_event->o_list));

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            m_context->m_heap->alloc_structure(
                &(
                    p_timer_std_event));

        if (
            appl_status_ok
            == e_status)
        {
            appl_list_init(
                &(
                    p_timer_std_event->o_list));
        }
    }

    if (
        appl_status_ok
        == e_status)
    {
        p_timer_std_event->o_timer_descriptor =
            *(
                p_timer_descriptor);

        appl_list_join(
            &(
                p_timer_std_event->o_list),
            &(
                m_used_list));
    }

    m_lock->v_unlock();

    return
        e_status;

} // v_schedule()

union appl_timer_std_node_ptr
{
    void *
        p_thread_context;

    class appl_timer_std_node *
        p_timer_std_node;

}; /* union appl_timer_std_node_ptr */

//
//
//
void
    appl_timer_std_node::s_worker(
        void * const
            p_thread_context)
{
    union appl_timer_std_node_ptr
        o_timer_std_node_ptr;

    o_timer_std_node_ptr.p_thread_context =
        p_thread_context;

    o_timer_std_node_ptr.p_timer_std_node->f_worker();

} // s_worker()

//
//
//
void
    appl_timer_std_node::f_worker(void)
{
    bool
        b_continue;

    b_continue =
        true;

    while (
        b_continue)
    {
        appl_ull_t
            i_now_usec;

        appl_ull_t
            i_min_usec;

        bool
            b_found;

        struct appl_timer_descriptor
            o_found_descriptor;

        i_now_usec =
            f_read_clock();

        b_found =
            false;

        i_min_usec =
            i_now_usec + 100000ul;

        m_lock->v_lock();

        if (
            !(
                m_thread_kill))
        {
            // Verify list of events
            union appl_timer_std_event_ptr
                o_timer_std_event_ptr;

            o_timer_std_event_ptr.p_list =
                m_used_list.o_next.p_node;

            while (
                (
                    !(b_found))
                && (
                    o_timer_std_event_ptr.p_list
                    != &( m_used_list)))
            {
                struct appl_timer_std_event * const
                    p_timer_std_event =
                    o_timer_std_event_ptr.p_timer_std_event;

                appl_ull_t const
                    i_abstime_usec =
                    p_timer_std_event->o_timer_descriptor.i_abstime_usec;

                if (
                    i_abstime_usec
                    <= i_now_usec)
                {
                    appl_list_join(
                        &(
                            p_timer_std_event->o_list),
                        &(
                            p_timer_std_event->o_list));

                    appl_list_join(
                        &(
                            p_timer_std_event->o_list),
                        &(
                            m_free_list));

                    b_found =
                        true;

                    o_found_descriptor =
                        p_timer_std_event->o_timer_descriptor;
                }
                else
                {
                    if (
                        i_abstime_usec
                        < i_min_usec)
                    {
                        i_min_usec =
                            i_abstime_usec;
                    }

                    o_timer_std_event_ptr.p_list =
                        o_timer_std_event_ptr.p_list->o_next.p_node;
                }
            }

            // Wait for something to do...
            if (
                !b_found)
            {
                m_event->v_wait(
                    m_lock,
                    1000000ul,
                    appl_convert::to_ulong(
                        i_min_usec - i_now_usec));
            }
        }
        else
        {
            m_thread_killed =
                1l;

            b_continue =
                false;
        }

        m_lock->v_unlock();

        // Do something
        if (
            b_continue
            && b_found)
        {
            (*(o_found_descriptor.p_timer_callback))(
                o_found_descriptor.p_timer_context);
        }
    }

} // f_worker()

//
//
//
appl_ull_t
    appl_timer_std_node::f_read_clock(void)
{
    appl_ull_t
        i_count_usec;

    i_count_usec =
        0u;

    m_context->m_clock->v_read(
        1000000ul,
        &(
            i_count_usec));

    return
        i_count_usec;

} // f_read_clock()

/* end-of-file: appl_timer_std_node.cpp */
