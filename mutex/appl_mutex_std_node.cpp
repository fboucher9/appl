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

#include <mutex/appl_mutex_node.h>

#include <mutex/appl_mutex_impl.h>

#include <mutex/appl_mutex_std_node.h>

#include <appl_unused.h>

#include <appl_allocator_handle.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_mutex_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
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
        appl_new(
            p_allocator,
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
appl_mutex_std_node::appl_mutex_std_node(
    struct appl_context * const
        p_context) :
    appl_mutex(
        p_context),
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
        m_mutex_impl.f_init();

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
appl_size_t
    appl_mutex_std_node::v_cleanup(void)
{
    if (
        m_mutex_impl_initialized)
    {
        m_mutex_impl.f_cleanup();

        m_mutex_impl_initialized =
            false;
    }

    return
        sizeof(class appl_mutex_std_node);

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
        m_mutex_impl.f_lock();

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
        m_mutex_impl.f_unlock();

    return
        e_status;

} // v_unlock()

//
//
//
enum appl_status
    appl_mutex_std_node::v_sync(
        enum appl_status (*
            p_sync_callback)(
            void * const
                p_sync_context),
        void * const
            p_sync_context)
{
    enum appl_status
        e_status;

    e_status =
        m_mutex_impl.f_sync(
            p_sync_callback,
            p_sync_context);

    return
        e_status;

} // v_sync()

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
appl_mutex_std_node_create(
    struct appl_allocator * const
        p_allocator,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex)
{
    return
        appl_mutex_std_node::s_create(
            p_allocator,
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
appl_mutex_std_node_destroy(
    struct appl_allocator * const
        p_allocator,
    struct appl_mutex * const
        p_mutex)
{
    return
        appl_delete(
            p_allocator,
            p_mutex);

} // appl_mutex_std_node_destroy()

/* end-of-file: appl_mutex_std_node.cpp */
