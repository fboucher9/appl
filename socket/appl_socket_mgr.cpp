/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_socket_mgr.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
enum appl_status
    appl_socket_mgr::v_create_address(
        struct appl_address_property const * const
            p_property,
        struct appl_address * * const
            r_address)
{
    enum appl_status
        e_status;

    appl_unused(
        p_property,
        r_address);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "socket mgr create address not implemented\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_address()

//
//
//
enum appl_status
    appl_socket_mgr::v_destroy_address(
        struct appl_address * const
            p_address_node)
{
    enum appl_status
        e_status;

    appl_unused(
        p_address_node);

#if defined APPL_DEBUG
    {
        static char const s_msg[] =
            "socket mgr destroy address not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_destroy_address()


//
//
//
enum appl_status
    appl_socket_mgr::v_create_socket(
        struct appl_socket_property const * const
            p_socket_descriptor,
        struct appl_socket * * const
            r_socket)
{
    enum appl_status
        e_status;

    appl_unused(
        p_socket_descriptor,
        r_socket);

#if defined APPL_DEBUG
    {
        static char const s_msg[] =
            "socket mgr create socket not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_socket()

//
//
//
enum appl_status
    appl_socket_mgr::v_destroy_socket(
        struct appl_socket * const
            p_socket_node)
{
    enum appl_status
        e_status;

    appl_unused(
        p_socket_node);

#if defined APPL_DEBUG
    {
        static char const s_msg[] =
            "socket mgr destroy socket not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_destroy_socket()

//
//
//
enum appl_status
    appl_socket_mgr::v_poll(
        struct appl_poll_descriptor const * const
            p_poll_descriptor_min,
        struct appl_poll_descriptor const * const
            p_poll_descriptor_max,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    appl_unused(
        p_poll_descriptor_min,
        p_poll_descriptor_max,
        i_wait_freq,
        i_wait_count);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_poll()

//
//
//
enum appl_status
    appl_socket_mgr::v_resolve(
        struct appl_address_descriptor const * const
            p_address_descriptor,
        void (* p_callback)(
            void * const
                p_callback_context,
            struct appl_address_descriptor const * const
                p_address_descriptor),
        void * const
            p_callback_context)
{
    enum appl_status
        e_status;

    appl_unused(
        p_address_descriptor,
        p_callback,
        p_callback_context);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_resolve()

//
//
//
appl_socket_mgr::appl_socket_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_socket_mgr::~appl_socket_mgr()
{
}

/* end-of-file: appl_socket_mgr.cpp */
