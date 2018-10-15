/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#if defined APPL_OS_LINUX

#include <signal.h>

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS

#include <windows.h>

#endif /* #if defined APPL_OS_WINDOWS */

#include <appl_status.h>

#include <appl_types.h>

#include <appl_buf.h>

#include <appl_object.h>

#include <appl_thread_descriptor.h>

#include <appl_object_handle.h>

#include <appl_property_handle.h>

#include <appl_thread_property.h>

#include <appl_thread_node.h>

#include <appl_mutex_impl.h>

#include <appl_event_impl.h>

#include <appl_thread_impl.h>

#include <appl_thread_std_node.h>

#if defined APPL_DEBUG

#include <appl_debug.h>

#include <appl_context.h>

#endif /* #if defined APPL_DEBUG */

#include <appl_unused.h>

#include <appl_convert.h>

//
//
//
enum appl_status
    appl_thread_std_node::create_instance(
        struct appl_context * const
            p_context,
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
        appl_object::s_create(
            p_context,
            (&
                appl_thread_std_node::placement_new),
            (&
                appl_thread_std_node::init),
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
void
    appl_thread_std_node::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_thread_std_node;

} // placement_new()

//
//
//
enum appl_status
    appl_thread_std_node::init(
        struct appl_thread_property const * const
            p_thread_property)
{
    enum appl_status
        e_status;

    appl_unused(
        p_thread_property);

    e_status =
        appl_status_ok;

    return
        e_status;

} // init()

//
//
//
enum appl_status
    appl_thread_std_node::v_cleanup(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

/* end-of-file: appl_thread_std_node.cpp */
