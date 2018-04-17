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

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_address_node.h"

#include "appl_address_std_node.h"

#include "appl_buf.h"

#include "appl_address_descriptor.h"

#include "appl_address_property.h"

#include "appl_property_types.h"

#include "appl_property.h"

#include "appl_object_handle.h"

#include "appl_string_handle.h"

//
//
//
enum appl_status
    appl_address_std_node::s_create(
        struct appl_context * const
            p_context,
        struct appl_property const * const
            p_property,
        struct appl_address * * const
            r_address)
{
    return
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_address_std_node),
            &(
                appl_address_std_node::s_new),
            p_property,
            r_address);

} // s_create()

//
//
//
appl_address_std_node::appl_address_std_node() :
    appl_address(),
    m_sockaddr_storage()
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
void
    appl_address_std_node::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_address_std_node;

} // s_new()

//
//
//
enum appl_status
    appl_address_std_node::init(
        void const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_property const * const
        p_property =
        static_cast<struct appl_property const *>(
            p_descriptor);

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
        reinterpret_cast<struct sockaddr_in *>(
            &(
                m_sockaddr_storage));

    memset(
        &(
            m_sockaddr_storage),
        0u,
        sizeof(
            m_sockaddr_storage));

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
        appl_size_t
            i_name_len;

        i_name_len =
            static_cast<appl_size_t>(
                o_address_descriptor.p_name_max
                - o_address_descriptor.p_name_min);

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

} // init()

//
//
//
enum appl_status
    appl_address_std_node::v_get_name(
        unsigned char * * const
            pp_name_cur,
        unsigned char * const
            p_name_max) const
{
    enum appl_status
        e_status;

    struct sockaddr_in const *
        p_sockaddr_in =
        reinterpret_cast<struct sockaddr_in const *>(
            &(
                m_sockaddr_storage));

    // convert sin_addr to string
    char * const
        p_name0 =
        inet_ntoa(
            p_sockaddr_in->sin_addr);

    if (
        p_name0)
    {
        int const
            i_name0_len =
            static_cast<int>(
                strlen(
                    p_name0));

        *(pp_name_cur) =
            appl_buf_copy(
                *(pp_name_cur),
                p_name_max,
                reinterpret_cast<unsigned char const *>(
                    p_name0),
                reinterpret_cast<unsigned char const *>(
                    p_name0 + i_name0_len));

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
        reinterpret_cast<struct sockaddr_in const *>(
            &(
                m_sockaddr_storage));

    unsigned short int
        i_port;

    i_port =
        static_cast<unsigned short int>(
            ntohs(
                p_sockaddr_in->sin_port));

    *(
        r_port) =
        i_port;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_get_port()

/* end-of-file: appl_address_std_node.cpp */
