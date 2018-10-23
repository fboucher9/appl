/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_thread_mgr.h>

#include <appl_thread_std_mgr.h>

#include <appl_context.h>

#include <appl_pool.h>

#include <appl_pool_mgr.h>

#include <appl_heap.h>

//
//
//
enum appl_status
    appl_thread_std_mgr::s_create(
        struct appl_heap * const
            p_heap,
        class appl_thread_mgr * * const
            r_thread_mgr)
{
    enum appl_status
        e_status;

    class appl_thread_std_mgr *
        p_thread_std_mgr;

    e_status =
        p_heap->alloc_object(
            &(
                p_thread_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_thread_mgr) =
            p_thread_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_thread_std_mgr::appl_thread_std_mgr() :
    appl_thread_mgr(),
    m_pool(),
    m_pool_created()
{
}

//
//
//
appl_thread_std_mgr::~appl_thread_std_mgr()
{
}

appl_size_t
appl_thread_std_node_sizeof(void);

//
//
//
enum appl_status
    appl_thread_std_mgr::f_init(void)
{
    enum appl_status
        e_status;

    appl_size_t const
        i_buf_len =
        appl_thread_std_node_sizeof();

    e_status =
        m_context->m_pool_mgr->v_create_node(
            i_buf_len,
            &(
                m_pool));

    if (
        appl_status_ok
        == e_status)
    {
        m_pool_created =
            true;
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_thread_std_mgr::v_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        m_pool_created)
    {
        m_pool->v_destroy();

        m_pool =
            0;

        m_pool_created =
            false;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

enum appl_status
    appl_thread_std_node_create(
        struct appl_pool * const
            p_pool,
        struct appl_thread_property const * const
            p_thread_property,
        struct appl_thread * * const
            r_thread);

//
//
//
enum appl_status
    appl_thread_std_mgr::v_create(
        struct appl_thread_property const * const
            p_thread_property,
        struct appl_thread * * const
            r_thread)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_std_node_create(
            m_pool,
            p_thread_property,
            r_thread);

    return
        e_status;

} // v_create()

/* end-of-file: appl_thread_std_mgr.cpp */
