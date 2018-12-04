/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <mutex/appl_mutex_mgr.h>

#include <mutex/appl_mutex_std_mgr.h>

#include <appl_allocator_handle.h>

#include <appl_pool_handle.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_mutex_std_mgr::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_mutex_mgr * * const
            r_mutex_mgr)
{
    enum appl_status
        e_status;

    class appl_mutex_std_mgr *
        p_mutex_std_mgr;

    e_status =
        appl_allocator_alloc_object(
            p_allocator,
            &(
                p_mutex_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_mutex_mgr) =
            p_mutex_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_mutex_std_mgr::appl_mutex_std_mgr() :
    appl_mutex_mgr(),
    m_pool(),
    m_pool_created()
{
}

//
//
//
appl_mutex_std_mgr::~appl_mutex_std_mgr()
{
}

appl_size_t
appl_mutex_std_node_sizeof(void);

//
//
//
enum appl_status
    appl_mutex_std_mgr::f_init(void)
{
    enum appl_status
        e_status;

    struct appl_pool_descriptor
        o_pool_descriptor;

    o_pool_descriptor.i_length =
        appl_mutex_std_node_sizeof();

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
    appl_mutex_std_mgr::v_cleanup(void)
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
        sizeof(class appl_mutex_std_mgr);

} // v_cleanup()

enum appl_status
appl_mutex_std_node_create(
    struct appl_allocator * const
        p_allocator,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex);

enum appl_status
appl_mutex_std_node_destroy(
    struct appl_allocator * const
        p_allocator,
    struct appl_mutex * const
        p_mutex);

//
//
//
enum appl_status
    appl_mutex_std_mgr::v_create_node(
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex * * const
            r_mutex)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_std_node_create(
            appl_pool_parent(
                m_pool),
            p_mutex_descriptor,
            r_mutex);

    return
        e_status;

} // v_create_node()

//
//
//
enum appl_status
    appl_mutex_std_mgr::v_destroy_node(
        struct appl_mutex * const
            p_mutex)
{
    return
        appl_mutex_std_node_destroy(
            appl_pool_parent(
                m_pool),
            p_mutex);

} // v_destroy_node()

/* end-of-file: appl_mutex_std_mgr.cpp */
