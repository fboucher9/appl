/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <pthread.h>

#else /* #if defined APPL_OS_LINUX */

#include <windows.h>

#endif /* #if defined APPL_OS_LINUX */

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_pool_object.h>

#include <appl_mutex_node.h>

#include <appl_mutex_impl.h>

#include <appl_mutex_std_node.h>

#include <appl_unused.h>

#include <appl_pool.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_mutex_std_node::s_create(
        struct appl_pool * const
            p_pool,
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex * * const
            r_mutex)
{
    enum appl_status
        e_status;

    class appl_mutex_std_node *
        p_mutex_std_node;

    e_status =
        p_pool->alloc_object(
            p_mutex_descriptor,
            &(
                p_mutex_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_mutex) =
            p_mutex_std_node;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_mutex_std_node::appl_mutex_std_node() :
    appl_mutex(),
    m_mutex_impl(),
    m_mutex_impl_initialized()
{
}

//
//
//
appl_mutex_std_node::~appl_mutex_std_node()
{
}

//
//
//
class appl_mutex_std_node *
appl_mutex_std_node::convert_handle(
    struct appl_mutex * const
        p_mutex)
{
    union appl_mutex_std_node_ptr
    {
        struct appl_mutex *
            p_mutex;

        class appl_mutex_std_node *
            p_mutex_std_node;

    } o_mutex_std_node_ptr;

    o_mutex_std_node_ptr.p_mutex =
        p_mutex;

    return
        o_mutex_std_node_ptr.p_mutex_std_node;

} // convert_handle()

//
//
//
enum appl_status
    appl_mutex_std_node::f_init(
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor)
{
    enum appl_status
        e_status;

    appl_unused(
        p_mutex_descriptor);

    e_status =
        m_mutex_impl.init();

    if (
        appl_status_ok
        == e_status)
    {
        m_mutex_impl_initialized =
            true;
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_mutex_std_node::v_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        m_mutex_impl_initialized)
    {
        m_mutex_impl.cleanup();

        m_mutex_impl_initialized =
            false;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

//
//
//
enum appl_status
    appl_mutex_std_node::v_lock(void)
{
    enum appl_status
        e_status;

    e_status =
        m_mutex_impl.lock();

    return
        e_status;

} // v_lock()

//
//
//
enum appl_status
    appl_mutex_std_node::v_unlock(void)
{
    enum appl_status
        e_status;

    e_status =
        m_mutex_impl.unlock();

    return
        e_status;

} // v_unlock()

enum appl_status
appl_mutex_std_node_create(
    struct appl_pool * const
        p_pool,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex);

//
//
//
enum appl_status
appl_mutex_std_node_create(
    struct appl_pool * const
        p_pool,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex)
{
    return
        appl_mutex_std_node::s_create(
            p_pool,
            p_mutex_descriptor,
            r_mutex);

} // appl_mutex_std_node_create()

appl_size_t
appl_mutex_std_node_sizeof(void);

/*

*/
appl_size_t
appl_mutex_std_node_sizeof(void)
{
    return
        sizeof(
            class appl_mutex_std_node);

} /* sizeof() */

/* end-of-file: appl_mutex_std_node.cpp */
