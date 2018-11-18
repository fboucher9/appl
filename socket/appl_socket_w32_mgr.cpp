/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <winsock2.h>

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <socket/appl_socket_mgr.h>

#include <socket/appl_socket_w32_mgr.h>

#include <appl_socket_descriptor.h>

#include <socket/appl_socket_node.h>

#include <socket/appl_socket_w32_node.h>

#include <socket/appl_address_node.h>

#include <socket/appl_address_std_node.h>

#include <appl_unused.h>

#include <allocator/appl_allocator.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
    appl_socket_w32_mgr::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_socket_mgr * * const
            r_socket_mgr)
{
    enum appl_status
        e_status;

    class appl_socket_w32_mgr *
        p_socket_w32_mgr;

    e_status =
        p_allocator->alloc_object(
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
enum appl_status
    appl_socket_w32_mgr::f_init(void)
{
    enum appl_status
        e_status;

    WORD
        wVersionRequested;

    int
        iWSAStartupResult;

    WSADATA
        oWSAStartupData;

    wVersionRequested =
        MAKEWORD(
            2,
            2);

    iWSAStartupResult =
        WSAStartup(
            wVersionRequested,
            &(
                oWSAStartupData));

    if (
        0 == iWSAStartupResult)
    {
        WORD
            wVersionAnswered;

        wVersionAnswered =
            oWSAStartupData.wVersion;

        if (
            (
                2 == LOBYTE(wVersionAnswered))
            && (
                2 == LOBYTE(wVersionAnswered)))
        {
            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        if (
            appl_status_ok
            != e_status)
        {
            WSACleanup();
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_socket_w32_mgr::v_cleanup(void)
{
    enum appl_status
        e_status;

    WSACleanup();

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

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
            m_context->m_allocator,
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
        struct appl_socket_property const * const
            p_socket_descriptor,
        struct appl_socket * * const
            r_socket)
{
    enum appl_status
        e_status;

    e_status =
        appl_socket_w32_node::s_create(
            m_context->m_allocator,
            p_socket_descriptor,
            r_socket);

    return
        e_status;

} // v_create_socket()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_socket_w32_mgr.cpp */
