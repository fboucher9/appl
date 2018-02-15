/* See LICENSE for license details */

/*

*/

#include <poll.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_list.h"

#include "appl_node.h"

#include "appl_poll_mgr.h"

#include "appl_mutex_node.h"

#include "appl_poll_descriptor.h"

#include "appl_poll_node.h"

#include "appl_context.h"

#include "appl_heap.h"

#include "appl_buf.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_poll_table
{
    struct appl_buf
        o_allocation;

    /* -- */

    class appl_poll_node * *
        a_nodes;

    struct pollfd *
        a_events;

    /* -- */

    unsigned int
        i_count;

    unsigned int
        ui_padding[3u];

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

    p_mutex_node->v_lock();

    // count number of elements
    struct appl_iterator
        o_iterator;

    appl_iterator_init(
        &(
            o_iterator),
        o_nodes.get_list());

    p_poll_table->i_count =
        0u;

    while (
        appl_iterator_next(
            &(
                o_iterator)))
    {
        class appl_poll_node * const
            p_poll_node =
            static_cast<class appl_poll_node *>(
                appl_node::get_node(
                    o_iterator.o_cur.p_node));

        if (
            p_poll_node->m_avail)
        {
            p_poll_table->i_count ++;
        }
    }

    // allocate an array
    class appl_heap * const
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
                class appl_poll_node *)
            * p_poll_table->i_count);

    e_status =
        p_heap->alloc_memory(
            &(
                p_poll_table->o_allocation),
            i_allocation_length);

    if (
        appl_status_ok
        == e_status)
    {
        p_poll_table->a_nodes =
            static_cast<class appl_poll_node * *>(
                p_poll_table->o_allocation.o_min.p_void);

        p_poll_table->a_events =
            static_cast<struct pollfd *>(
                static_cast<void *>(
                    p_poll_table->a_nodes + p_poll_table->i_count));

        // fill array(s)
        appl_iterator_init(
            &(
                o_iterator),
            o_nodes.get_list());

        unsigned int
            i_index;

        i_index =
            0u;

        while (
            appl_iterator_next(
                &(
                    o_iterator)))
        {
            class appl_poll_node * const
                p_poll_node =
                reinterpret_cast<class appl_poll_node *>(
                    o_iterator.o_cur.p_node + 1);

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

    p_mutex_node->v_unlock();

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
    p_mutex_node->v_lock();

    // release the nodes

    struct appl_iterator
        o_iterator;

    appl_iterator_init(
        &(
            o_iterator),
        o_nodes.get_list());

    while (
        appl_iterator_next(
            &(
                o_iterator)))
    {
        class appl_poll_node * const
            p_poll_node =
            static_cast<class appl_poll_node *>(
                appl_node::get_node(
                    o_iterator.o_cur.p_node));

        if (
            p_poll_node->m_busy)
        {
            p_poll_node->m_busy =
                false;
        }
    }

    p_mutex_node->v_unlock();

    // free the tables
    class appl_heap * const
        p_heap =
        m_context->m_heap;

    p_heap->free_memory(
        &(
            p_poll_table->o_allocation));

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
        if (m_kill)
        {
            b_continue =
                false;
        }

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

/* end-of-file: appl_poll_mgr.cpp */
