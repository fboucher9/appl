/* See LICENSE for license details */

/*

*/

#include <mutex/appl_mutex_defs.h>

#include <event/appl_event_defs.h>

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <event/appl_event_node.h>

#include <event/appl_event_impl.h>

#include <event/appl_event_std_node.h>

#include <event/appl_event_service.h>

#include <mutex/appl_mutex_node.h>

#include <mutex/appl_mutex_impl.h>

#include <mutex/appl_mutex_std_node.h>

#include <misc/appl_unused.h>

#include <misc/appl_convert.h>

#include <allocator/appl_allocator_handle.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

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

    e_status =
        appl_event_service::s_validate(
            (0 != p_allocator)
            && (0 != p_event_descriptor)
            && (0 != r_event_node));

    if (
        appl_status_ok
        == e_status)
    {
        class appl_event_std_node *
            p_event_std_node;

        e_status =
            appl_new(
                p_allocator,
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
    }

    return
        e_status;

} // create_instance()

//
//
//
enum appl_status
    appl_event_std_node::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_event * const
            p_event)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_service::s_validate(
            (0 != p_allocator)
            && (0 != p_event));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_delete(
                p_allocator,
                p_event);
    }

    return
        e_status;

} // s_destroy()

//
//
//
appl_event_std_node::appl_event_std_node(
    struct appl_context * const
        p_context) :
    appl_event(
        p_context),
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

    e_status =
        appl_event_service::s_validate(
            (0 != p_event_descriptor));

    if (
        appl_status_ok
        == e_status)
    {
        appl_unused(
            p_event_descriptor);

        e_status =
            m_event_impl.f_init();

        if (
            appl_status_ok
            == e_status)
        {
            m_event_impl_initialized =
                true;
        }
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
    appl_size_t
        i_cleanup_result;

    if (
        m_event_impl_initialized)
    {
        m_event_impl.f_cleanup();

        m_event_impl_initialized =
            false;
    }

    i_cleanup_result =
        sizeof(class appl_event_std_node);

    return
        i_cleanup_result;

} // v_cleanup()

//
//
//
enum appl_status
    appl_event_std_node::v_signal(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_service::s_validate(
            m_event_impl_initialized);

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            m_event_impl.f_signal();
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

    e_status =
        appl_event_service::s_validate(
            m_event_impl_initialized
            && (0 != p_mutex_node)
            && (0 != i_wait_freq));

    if (
        appl_status_ok
        == e_status)
    {
        class appl_mutex_std_node * const
            p_mutex_std_node =
            appl_mutex_std_node::convert_handle(
                p_mutex_node);

        e_status =
            m_event_impl.f_wait(
                &(
                    p_mutex_std_node->m_mutex_impl),
                i_wait_freq,
                i_wait_count);
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

enum appl_status
    appl_event_std_node_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_event * const
            p_event);

//
//
//
enum appl_status
    appl_event_std_node_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_event * const
            p_event)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_std_node::s_destroy(
            p_allocator,
            p_event);

    return
        e_status;

} // appl_event_std_node_destroy()

/* end-of-file: appl_event_std_node.cpp */
