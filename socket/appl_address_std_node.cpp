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

#elif defined APPL_OS_WINDOWS

#include <winsock2.h>

#endif

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <socket/appl_address_node.h>

#include <socket/appl_address_std_node.h>

#include <appl_buf.h>

#include <socket/appl_address_descriptor.h>

#include <appl_address_property.h>

#include <property/appl_property_types.h>

#include <property/appl_property.h>

#include <appl_convert.h>

#include <appl_buf0.h>

#include <appl_context.h>

#include <allocator/appl_allocator.h>

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
        p_allocator->alloc_object(
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
appl_address_std_node::appl_address_std_node() :
    appl_address(),
    m_sockaddr()
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

    struct sockaddr_in *
        p_sockaddr_in =
        &(
            m_sockaddr.o_sockaddr_in);

    memset(
        &(
            m_sockaddr),
        0u,
        sizeof(
            m_sockaddr));

    p_sockaddr_in->sin_family =
        AF_INET;

    if (
        o_address_descriptor.b_port)
    {
        p_sockaddr_in->sin_port =
            htons(
                o_address_descriptor.i_port);
    }

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
            i_name_len < 64u)
        {
            char
                ac_buffer[64u];

            memcpy(
                ac_buffer,
                o_address_descriptor.p_name_min,
                i_name_len);

            ac_buffer[i_name_len] =
                '\000';

            p_sockaddr_in->sin_addr.s_addr =
                inet_addr(
                    ac_buffer);
        }
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

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

    return
        e_status;

} // v_get_port()

/* end-of-file: appl_address_std_node.cpp */
