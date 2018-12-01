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

#include <event/appl_event_node.h>

#include <event/appl_event_impl.h>

#include <event/appl_event_std_node.h>

#include <mutex/appl_mutex_node.h>

#include <mutex/appl_mutex_impl.h>

#include <mutex/appl_mutex_std_node.h>

#include <appl_unused.h>

#include <appl_convert.h>

#include <allocator/appl_allocator.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_event_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_event_descriptor const * const
            p_event_descriptor,
        struct appl_event * * const
            r_event_node)
{
    enum appl_status
        e_status;

    class appl_event_std_node *
        p_event_std_node;

    e_status =
        p_allocator->alloc_object(
            p_event_descriptor,
            &(
                p_event_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_event_node) =
            p_event_std_node;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_event_std_node::appl_event_std_node() :
    appl_event(),
    m_event_impl(),
    m_event_impl_initialized()
{
}

//
//
//
appl_event_std_node::~appl_event_std_node()
{
}

//
//
//
enum appl_status
    appl_event_std_node::f_init(
        struct appl_event_descriptor const * const
            p_event_descriptor)
{
    enum appl_status
        e_status;

    appl_unused(
        p_event_descriptor);

    e_status =
        m_event_impl.init();

    if (
        appl_status_ok
        == e_status)
    {
        m_event_impl_initialized =
            true;
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_event_std_node::v_cleanup(void)
{
    if (
        m_event_impl_initialized)
    {
        m_event_impl.cleanup();

        m_event_impl_initialized =
            false;
    }

    return
        sizeof(class appl_event_std_node);

} // v_cleanup()

//
//
//
enum appl_status
    appl_event_std_node::v_signal(void)
{
    enum appl_status
        e_status;

    if (
        m_event_impl_initialized)
    {
        e_status =
            m_event_impl.signal();
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_signal()

//
//
//
enum appl_status
    appl_event_std_node::v_wait(
        struct appl_mutex * const
            p_mutex_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    if (
        m_event_impl_initialized)
    {
        class appl_mutex_std_node *
            p_mutex_std_node;

        p_mutex_std_node =
            appl_mutex_std_node::convert_handle(
                p_mutex_node);

        e_status =
            m_event_impl.wait(
                &(
                    p_mutex_std_node->m_mutex_impl),
                i_wait_freq,
                i_wait_count);
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_wait()

enum appl_status
    appl_event_std_node_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_event_descriptor const * const
            p_event_descriptor,
        struct appl_event * * const
            r_event);

//
//
//
enum appl_status
    appl_event_std_node_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_event_descriptor const * const
            p_event_descriptor,
        struct appl_event * * const
            r_event)
{
    return
        appl_event_std_node::s_create(
            p_allocator,
            p_event_descriptor,
            r_event);

} // appl_event_std_node_create()

appl_size_t
appl_event_std_node_sizeof(void);

//
//
//
appl_size_t
appl_event_std_node_sizeof(void)
{
    return
        sizeof(
            class appl_event_std_node);

} // appl_event_std_node_sizeof()

/* end-of-file: appl_event_std_node.cpp */
