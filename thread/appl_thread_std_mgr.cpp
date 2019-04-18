/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <thread/appl_thread_mgr.h>

#include <thread/appl_thread_std_mgr.h>

#include <appl_allocator_handle.h>

#include <appl_pool_handle.h>

//
//
//
enum appl_status
    appl_thread_std_mgr::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_thread_mgr * * const
            r_thread_mgr)
{
    enum appl_status
        e_status;

    class appl_thread_std_mgr *
        p_thread_std_mgr;

    e_status =
        appl_new(
            p_allocator,
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

enum appl_status
    appl_thread_std_mgr::s_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_thread_mgr * const
            p_thread_mgr)
{
    return
        appl_delete(
            p_allocator,
            p_thread_mgr);

} // s_destroy()

//
//
//
appl_thread_std_mgr::appl_thread_std_mgr(
    struct appl_context * const
        p_context) :
    appl_thread_mgr(
        p_context),
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

    struct appl_pool_descriptor
        o_pool_descriptor;

    o_pool_descriptor.i_length =
        appl_thread_std_node_sizeof();

    o_pool_descriptor.i_count_min =
        0u;

    o_pool_descriptor.i_count_max =
        0u;

    e_status =
        appl_pool_create(
            m_context,
            &(
                o_pool_descriptor),
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
appl_size_t
    appl_thread_std_mgr::v_cleanup(void)
{
    if (
        m_pool_created)
    {
        appl_pool_destroy(
            m_pool);

        m_pool =
            0;

        m_pool_created =
            false;
    }

    return
        sizeof(class appl_thread_std_mgr);

} // v_cleanup()

enum appl_status
    appl_thread_std_node_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_thread * * const
            r_thread);

enum appl_status
    appl_thread_std_node_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread * const
            p_thread);

//
//
//
enum appl_status
    appl_thread_std_mgr::v_create_node(
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_thread * * const
            r_thread)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_std_node_create(
            appl_pool_parent(
                m_pool),
            p_thread_descriptor,
            r_thread);

    return
        e_status;

} // v_create_node()

//
//
//
enum appl_status
    appl_thread_std_mgr::v_destroy_node(
        struct appl_thread * const
            p_thread)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_std_node_destroy(
            appl_pool_parent(
                m_pool),
            p_thread);

    return
        e_status;

} // v_destroy_node()

/* end-of-file: appl_thread_std_mgr.cpp */
