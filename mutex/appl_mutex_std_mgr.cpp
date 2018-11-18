/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <mutex/appl_mutex_mgr.h>

#include <mutex/appl_mutex_std_mgr.h>

#include <appl_context.h>

#include <appl_allocator.h>

#include <pool/appl_pool_mgr.h>

#include <pool/appl_pool.h>

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
        p_allocator->alloc_object(
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

    appl_size_t const
        i_node_len =
        appl_mutex_std_node_sizeof();

    e_status =
        m_context->m_pool_mgr->v_create_node(
            i_node_len,
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
    appl_mutex_std_mgr::v_cleanup(void)
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
appl_mutex_std_node_create(
    struct appl_allocator * const
        p_allocator,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex);

//
//
//
enum appl_status
    appl_mutex_std_mgr::v_create(
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex * * const
            r_mutex)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_std_node_create(
            m_pool,
            p_mutex_descriptor,
            r_mutex);

    return
        e_status;

} // v_create()

/* end-of-file: appl_mutex_std_mgr.cpp */
