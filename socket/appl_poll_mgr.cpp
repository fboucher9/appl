/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <poll.h>

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <appl_list.h>

#include <appl_node.h>

#include <socket/appl_poll_mgr.h>

#include <mutex/appl_mutex_node.h>

#include <appl_poll_descriptor.h>

#include <socket/appl_poll_node.h>

#include <context/appl_context.h>

#include <allocator/appl_allocator.h>

#include <heap/appl_heap.h>

#include <appl_buf.h>

#include <appl_node_iterator.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_poll_table
{
    void *
        p_allocation;

    appl_size_t
        i_allocation_length;

    /* -- */

    struct appl_poll * *
        a_nodes;

    struct pollfd *
        a_events;

    /* -- */

    unsigned int
        i_count;

#define PADDING (APPL_SIZEOF_INT)
#include <appl_padding.h>

}; // struct appl_poll_table

//
//
//
enum appl_status
    appl_poll_mgr::create_poll_table(
        struct appl_poll_table * const
            p_poll_table)
{
    enum appl_status
        e_status;

    p_mutex->v_lock();

    // count number of elements
    {
        class appl_node_iterator
            o_iterator(
                &(
                    o_nodes));

        p_poll_table->i_count =
            0u;

        while (
            o_iterator.next())
        {
            struct appl_poll * const
                p_poll_node =
                static_cast<struct appl_poll *>(
                    o_iterator.p_cur);

            if (
                p_poll_node->m_avail)
            {
                p_poll_table->i_count ++;
            }
        }
    }

    // allocate an array
    struct appl_heap * const
        p_heap =
        m_context->m_heap;

    appl_size_t
        i_allocation_length;

    i_allocation_length =
        (
            sizeof(
                struct pollfd)
            * p_poll_table->i_count)
        + (
            sizeof(
                struct appl_poll *)
            * p_poll_table->i_count);

    e_status =
        p_heap->v_alloc(
            i_allocation_length,
            &(
                p_poll_table->p_allocation));

    if (
        appl_status_ok
        == e_status)
    {
        p_poll_table->i_allocation_length =
            i_allocation_length;

        p_poll_table->a_nodes =
            static_cast<struct appl_poll * *>(
                p_poll_table->p_allocation);

        p_poll_table->a_events =
            static_cast<struct pollfd *>(
                static_cast<void *>(
                    p_poll_table->a_nodes + p_poll_table->i_count));

        // fill array(s)
        {
            class appl_node_iterator
                o_iterator(
                    &(
                        o_nodes));

            unsigned int
                i_index;

            i_index =
                0u;

            while (
                o_iterator.next())
            {
                struct appl_poll * const
                    p_poll_node =
                    static_cast<struct appl_poll *>(
                        o_iterator.p_cur);

                if (
                    p_poll_node->m_avail)
                {
                    p_poll_node->m_busy =
                        true;

                    p_poll_table->a_events[i_index].fd =
                        p_poll_node->m_fd;

                    p_poll_table->a_events[i_index].events =
                        0;

                    p_poll_table->a_events[i_index].revents =
                        0;

                    p_poll_table->a_nodes[i_index] =
                        p_poll_node;
                }
            }
        }
    }

    p_mutex->v_unlock();

    return
        e_status;

} // create_poll_table()

//
//
//
void
    appl_poll_mgr::destroy_poll_table(
        struct appl_poll_table * const
            p_poll_table)
{
    p_mutex->v_lock();

    // release the nodes

    class appl_node_iterator
        o_iterator(
            &(
                o_nodes));

    while (
        o_iterator.next())
    {
        struct appl_poll * const
            p_poll_node =
            static_cast<struct appl_poll *>(
                o_iterator.p_cur);

        if (
            p_poll_node->m_busy)
        {
            p_poll_node->m_busy =
                false;
        }
    }

    p_mutex->v_unlock();

    // free the tables
    struct appl_heap * const
        p_heap =
        m_context->m_heap;

    p_heap->v_free(
        p_poll_table->i_allocation_length,
        p_poll_table->p_allocation);

} // destroy_poll_table()

//
//
//
void
    appl_poll_mgr::thread_step(void)
{
    enum appl_status
        e_status;

    struct appl_poll_table
        o_table;

    // create a pollfd table
    e_status =
        create_poll_table(
            &(
                o_table));

    if (
        appl_status_ok
        == e_status)
    {
        int
            i_poll_result;

        i_poll_result =
            poll(
                o_table.a_events,
                o_table.i_count,
                100 /* milliseconds */);

        if (
            0 == i_poll_result)
        {
            // timeout
        }
        else if (
            0 < i_poll_result)
        {
            // verify kill

            // dispatch callbacks...
        }
        else
        {
            // error
        }

        destroy_poll_table(
            &(
                o_table));
    }

}

//
//
//
void
    appl_poll_mgr::thread_handler(void)
{
    bool
        b_continue;

    b_continue =
        true;

    while (
        b_continue)
    {
        // verify kill flag
        p_mutex->v_lock();

        if (m_kill)
        {
            b_continue =
                false;
        }

        p_mutex->v_unlock();

        if (
            b_continue)
        {
            thread_step();
        }
    }

} // thread_handler()

//
//
//
void *
    appl_poll_mgr::thread_entry(
        void * const
            p_thread_context)
{
    class appl_poll_mgr *
        p_poll_mgr;

    p_poll_mgr =
        static_cast<class appl_poll_mgr *>(
            p_thread_context);

    p_poll_mgr->thread_handler();

    return
        static_cast<void *>(
            0);

} // thread_entry()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_poll_mgr.cpp */
