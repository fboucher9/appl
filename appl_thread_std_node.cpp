/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <pthread.h>

#include <signal.h>

#else /* #if defined APPL_OS_Xx */

#include <windows.h>

#endif /* #if defined APPL_OS_Xx */

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_thread_descriptor.h>

#include <appl_thread_property.h>

#include <appl_thread_node.h>

#include <appl_thread_impl.h>

#include <appl_thread_std_node.h>

#include <appl_allocator.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_thread_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread_property const * const
            p_thread_property,
        struct appl_thread * * const
            r_thread)
{
    enum appl_status
        e_status;

    class appl_thread_std_node *
        p_thread_std_node;

    e_status =
        p_allocator->alloc_object(
            p_thread_property,
            &(
                p_thread_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_thread) =
            p_thread_std_node;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_thread_std_node::appl_thread_std_node() :
    appl_thread(),
    m_thread_impl()
{
}

//
//
//
appl_thread_std_node::~appl_thread_std_node()
{
}

//
//
//
enum appl_status
appl_thread_std_node::v_start(
    struct appl_thread_descriptor const * const
        p_thread_descriptor)
{
    enum appl_status
        e_status;

    e_status =
        m_thread_impl.f_start(
            p_thread_descriptor);

    return
        e_status;

} // v_start()

//
//
//
enum appl_status
    appl_thread_std_node::v_interrupt(void)
{
    enum appl_status
        e_status;

    e_status =
        m_thread_impl.f_interrupt();

    return
        e_status;

} // v_interrupt()

//
//
//
enum appl_status
    appl_thread_std_node::f_init(
        struct appl_thread_property const * const
            p_thread_property)
{
    enum appl_status
        e_status;

    e_status =
        m_thread_impl.f_init(
            p_thread_property);

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_thread_std_node::v_cleanup(void)
{
    enum appl_status
        e_status;

    e_status =
        m_thread_impl.f_cleanup();

    return
        e_status;

} // v_cleanup()

appl_size_t
    appl_thread_std_node_sizeof(void);

/*

*/
appl_size_t
    appl_thread_std_node_sizeof(void)
{
    return
        sizeof(
            class appl_thread_std_node);

} /* appl_thread_std_node_sizeof() */

enum appl_status
    appl_thread_std_node_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread_property const * const
            p_thread_property,
        struct appl_thread * * const
            r_thread);

/*

*/
enum appl_status
    appl_thread_std_node_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread_property const * const
            p_thread_property,
        struct appl_thread * * const
            r_thread)
{
    return
        appl_thread_std_node::s_create(
            p_allocator,
            p_thread_property,
            r_thread);

} /* appl_thread_std_node_create() */

/* end-of-file: appl_thread_std_node.cpp */
