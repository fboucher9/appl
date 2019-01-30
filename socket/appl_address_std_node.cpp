/* See LICENSE for license details */

/*

Module: appl_address_std_node.cpp

Description:
    Standard implementation of address node.

*/

#include <string.h>

#if defined APPL_OS_LINUX

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <netdb.h>

#elif defined APPL_OS_WINDOWS

#include <winsock2.h>

#include <ws2ipdef.h>

#include <ws2tcpip.h>

#endif

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_address_property.h>

#include <socket/appl_address_node.h>

#include <socket/appl_address_std_node.h>

#include <appl_buf.h>

#include <socket/appl_address_descriptor.h>

#include <property/appl_property_types.h>

#include <property/appl_property.h>

#include <appl_convert.h>

#include <appl_buf0.h>

#include <appl_allocator_handle.h>

//
//
//
enum appl_status
    appl_address_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_address_property const * const
            p_property,
        struct appl_address * * const
            r_address)
{
    enum appl_status
        e_status;

    class appl_address_std_node *
        p_address_std_node;

    e_status =
        appl_new(
            p_allocator,
            p_property,
            &(
                p_address_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_address) =
            p_address_std_node;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_address_std_node::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_address * const
            p_address)
{
    enum appl_status
        e_status;

    e_status =
        appl_delete(
            p_allocator,
            p_address);

    return
        e_status;

} // s_destroy()

//
//
//
appl_address_std_node::appl_address_std_node(
    struct appl_context * const
        p_context) :
    appl_address(
        p_context),
    m_sockaddr(),
    m_sockaddr_len()
{
}

//
//
//
appl_address_std_node::~appl_address_std_node()
{
}

//
//
//
enum appl_status
    appl_address_std_node::f_init(
        struct appl_address_property const * const
            p_property)
{
    enum appl_status
        e_status;

    struct appl_address_descriptor
        o_address_descriptor;

    if (
        appl_status_ok
        == appl_address_property_get_name(
            p_property,
            &(
                o_address_descriptor.p_name_min),
            &(
                o_address_descriptor.p_name_max)))
    {
        o_address_descriptor.b_name =
            1;
    }
    else
    {
        o_address_descriptor.b_name =
            0;
    }

    if (
        appl_status_ok
        == appl_address_property_get_port(
            p_property,
            &(
                o_address_descriptor.i_port)))
    {
        o_address_descriptor.b_port =
            1;
    }
    else
    {
        o_address_descriptor.b_port =
            0;
    }

    if (
        appl_status_ok
        == appl_address_property_get_family(
            p_property,
            &(
                o_address_descriptor.e_family)))
    {
        o_address_descriptor.b_family =
            1;
    }
    else
    {
        o_address_descriptor.b_family =
            0;
    }

    memset(
        &(
            m_sockaddr),
        0u,
        sizeof(
            m_sockaddr));

    if (
        o_address_descriptor.b_port
        || o_address_descriptor.b_name)
    {
        // Do getaddrinfo...
        unsigned char
            ac_port[16u];

        union appl_buf_ptr
            o_port_ptr;

        if (
            o_address_descriptor.b_port)
        {
            unsigned char *
                p_port_end;

            p_port_end =
                appl_buf_print_number(
                    ac_port,
                    ac_port + sizeof(ac_port),
                    o_address_descriptor.i_port,
                    0,
                    0);

            *(
                p_port_end) =
                '\000';

            o_port_ptr.p_uchar =
                ac_port;
        }
        else
        {
            o_port_ptr.p_uchar =
                0;
        }

        unsigned char
            ac_buffer[256u];

        union appl_buf_ptr
            o_name_ptr;

        if (
            o_address_descriptor.b_name)
        {
            unsigned long int
                i_name_len;

            i_name_len =
                appl_buf_len(
                    o_address_descriptor.p_name_min,
                    o_address_descriptor.p_name_max);

            if (
                i_name_len < sizeof(ac_buffer))
            {
                memcpy(
                    ac_buffer,
                    o_address_descriptor.p_name_min,
                    i_name_len);

                ac_buffer[i_name_len] =
                    '\000';
            }

            o_name_ptr.p_uchar =
                ac_buffer;
        }
        else
        {
            o_name_ptr.p_uchar =
                0;
        }

        int
            i_addrinfo_result;

        struct addrinfo *
            p_addrinfo_list;

        struct addrinfo
            o_hints;

        if (
            o_name_ptr.pc_char)
        {
            o_hints.ai_flags =
                AI_V4MAPPED
                | AI_ADDRCONFIG;
        }
        else
        {
            o_hints.ai_flags =
                AI_V4MAPPED
                | AI_ADDRCONFIG
                | AI_PASSIVE;
        }

        o_hints.ai_family =
            AF_UNSPEC;

        o_hints.ai_socktype =
            SOCK_STREAM;

        o_hints.ai_protocol =
            0;

        i_addrinfo_result =
            getaddrinfo(
                o_name_ptr.pc_char,
                o_port_ptr.pc_char,
                &(o_hints),
                &(p_addrinfo_list));

        if (
            0
            == i_addrinfo_result)
        {
            if (
                p_addrinfo_list->ai_addr)
            {
                memcpy(
                    &(
                        m_sockaddr.o_sockaddr_storage),
                    p_addrinfo_list->ai_addr,
                    p_addrinfo_list->ai_addrlen);

                m_sockaddr_len =
                    p_addrinfo_list->ai_addrlen;

                e_status =
                    appl_status_ok;
            }
            else
            {
                e_status =
                    appl_status_fail;
            }
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        /* This is an empty address */
        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_address_std_node::v_cleanup(void)
{
    return
        sizeof(class appl_address_std_node);

} // v_cleanup()

//
//
//
enum appl_status
    appl_address_std_node::v_get_name_len(
        unsigned long int * const
            r_name_len) const
{
    enum appl_status
        e_status;

    *(
        r_name_len) =
        49u;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_get_name_len()

//
//
//
enum appl_status
    appl_address_std_node::v_get_name(
        unsigned char * const
            p_name_min,
        unsigned char * const
            p_name_max,
        unsigned char * * const
            r_name_cur) const
{
    enum appl_status
        e_status;

    struct sockaddr_in const *
        p_sockaddr_in =
        &(
            m_sockaddr.o_sockaddr_in);

    // convert sin_addr to string
    char const * const
        p_name0 =
        inet_ntoa(
            p_sockaddr_in->sin_addr);

    if (
        p_name0)
    {
        unsigned char const * const
            p_name0u =
            appl_convert::to_uchar_ptr(
                p_name0);

        unsigned long int const
            i_name0_len =
            appl_buf0_len(
                p_name0u);

        *(r_name_cur) =
            appl_buf_copy(
                p_name_min,
                p_name_max,
                p_name0u,
                p_name0u + i_name0_len);

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    // copy string to name buffer

    return
        e_status;

} // v_get_name()

//
//
//
enum appl_status
    appl_address_std_node::v_get_port(
        unsigned short int * const
            r_port) const
{
    enum appl_status
        e_status;

    if (
        AF_INET
        == m_sockaddr.o_sockaddr_storage.ss_family)
    {
        struct sockaddr_in const *
            p_sockaddr_in =
            &(
                m_sockaddr.o_sockaddr_in);

        unsigned short int
            i_port;

        i_port =
            ntohs(
                p_sockaddr_in->sin_port);

        *(
            r_port) =
            i_port;

        e_status =
            appl_status_ok;
    }
    else if (
        AF_INET6
        == m_sockaddr.o_sockaddr_storage.ss_family)
    {
        struct sockaddr_in6 const *
            p_sockaddr_in6 =
            &(
                m_sockaddr.o_sockaddr_in6);

        unsigned short int
            i_port;

        i_port =
            htons(
                p_sockaddr_in6->sin6_port);

        *(
            r_port) =
            i_port;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_get_port()

//
//
//
enum appl_status
    appl_address_std_node::v_get_family(
        enum appl_address_family * const
            r_family) const
{
    enum appl_status
        e_status;

    if (
        AF_INET
        == m_sockaddr.o_sockaddr_storage.ss_family)
    {
        *(
            r_family) =
            appl_address_family_inet;

        e_status =
            appl_status_ok;
    }
    else if (
        AF_INET6
        == m_sockaddr.o_sockaddr_storage.ss_family)
    {
        *(
            r_family) =
            appl_address_family_inet6;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_get_family()

/* end-of-file: appl_address_std_node.cpp */
