/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <winsock2.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_socket_mgr.h>

#include <appl_socket_w32_mgr.h>

#include <appl_socket_descriptor.h>

#include <appl_socket_node.h>

#include <appl_socket_w32_node.h>

#include <appl_address_node.h>

#include <appl_address_std_node.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_socket_w32_mgr::s_create(
        struct appl_context * const
            p_context,
        class appl_socket_mgr * * const
            r_socket_mgr)
{
    enum appl_status
        e_status;

    class appl_socket_w32_mgr *
        p_socket_w32_mgr;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_socket_w32_mgr::s_new),
            &(
                p_socket_w32_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_socket_mgr) =
            p_socket_w32_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_socket_w32_mgr::appl_socket_w32_mgr() :
    appl_socket_mgr()
{
}

//
//
//
appl_socket_w32_mgr::~appl_socket_w32_mgr()
{
}

//
//
//
void
    appl_socket_w32_mgr::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_socket_w32_mgr;

} // s_new()

//
//
//
enum appl_status
    appl_socket_w32_mgr::v_create_address(
        struct appl_address_property const * const
            p_property,
        struct appl_address * * const
            r_address)
{
    enum appl_status
        e_status;

    e_status =
        appl_address_std_node::s_create(
            m_context,
            p_property,
            r_address);

    return
        e_status;

} // v_create_address()

//
//
//
enum appl_status
    appl_socket_w32_mgr::v_create_socket(
        struct appl_property const * const
            p_socket_descriptor,
        struct appl_socket * * const
            r_socket)
{
    enum appl_status
        e_status;

    e_status =
        appl_socket_w32_node::s_create(
            m_context,
            p_socket_descriptor,
            r_socket);

    return
        e_status;

} // v_create_socket()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_socket_w32_mgr.cpp */
