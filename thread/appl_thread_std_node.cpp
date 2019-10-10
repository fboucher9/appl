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

#include <object/appl_object.h>

#include <thread/appl_thread_descriptor.h>

#include <buf/appl_buf.h>

#include <thread/appl_thread_descriptor_impl.h>

#include <thread/appl_thread_node.h>

#include <thread/appl_thread_impl.h>

#include <thread/appl_thread_std_node.h>

#include <allocator/appl_allocator_handle.h>

#include <misc/appl_unused.h>

/*

*/
struct appl_thread_std_node_descriptor
{
    struct appl_thread_descriptor const *
        p_thread_descriptor;

}; /* struct appl_thread_std_node_descriptor */

//
//
//
enum appl_status
    appl_thread_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_thread * * const
            r_thread)
{
    enum appl_status
        e_status;

    class appl_thread_std_node *
        p_thread_std_node;

    struct appl_thread_std_node_descriptor
        o_thread_std_node_descriptor;

    o_thread_std_node_descriptor.p_thread_descriptor =
        p_thread_descriptor;

    e_status =
        appl_new(
            p_allocator,
            &(
                o_thread_std_node_descriptor),
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
enum appl_status
    appl_thread_std_node::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread * const
            p_thread)
{
    enum appl_status
        e_status;

    e_status =
        appl_delete(
            p_allocator,
            p_thread);

    return
        e_status;

} // s_destroy()

//
//
//
appl_thread_std_node::appl_thread_std_node(
    struct appl_context * const
        p_context) :
    appl_thread(
        p_context),
    m_thread_impl(
        p_context)
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
        struct appl_thread_std_node_descriptor const * const
            p_thread_std_node_property)
{
    enum appl_status
        e_status;

    e_status =
        m_thread_impl.f_init(
            p_thread_std_node_property->p_thread_descriptor);

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_thread_std_node::v_cleanup(void)
{
    m_thread_impl.f_cleanup();

    return
        sizeof(class appl_thread_std_node);

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
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_thread * * const
            r_thread);

/*

*/
enum appl_status
    appl_thread_std_node_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_thread * * const
            r_thread)
{
    return
        appl_thread_std_node::s_create(
            p_allocator,
            p_thread_descriptor,
            r_thread);

} /* appl_thread_std_node_create() */

enum appl_status
    appl_thread_std_node_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread * const
            p_thread);

enum appl_status
    appl_thread_std_node_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_thread * const
            p_thread)
{
    return
        appl_thread_std_node::s_destroy(
            p_allocator,
            p_thread);

} /* appl_thread_std_node_destroy() */

/* end-of-file: appl_thread_std_node.cpp */
