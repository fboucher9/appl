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

//
//
//
enum appl_status
    appl_address_std_node::s_create(
        class appl_context * const
            p_context,
        class appl_property const * const
            p_property,
        class appl_address_node * * const
            r_address_node)
{
    return
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_address_std_node),
            &(
                appl_address_std_node::s_new),
            p_property,
            r_address_node);

} // s_create()

//
//
//
appl_address_std_node::appl_address_std_node() :
    appl_address_node(),
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

    struct appl_property_handle const * const
        p_property_handle =
        static_cast<struct appl_property_handle const *>(
            p_descriptor);

    struct appl_address_descriptor
        o_address_descriptor;

    if (
        appl_status_ok
        == appl_address_property_get_name(
            p_property_handle,
            &(
                o_address_descriptor.o_name.o_min.pc_uchar),
            &(
                o_address_descriptor.o_name.o_max.pc_uchar)))
    {
        o_address_descriptor.b_name =
            1;
    }

    if (
        appl_status_ok
        == appl_address_property_get_port(
            p_property_handle,
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
                o_address_descriptor.o_name.o_max.pc_uchar
                - o_address_descriptor.o_name.o_min.pc_uchar);

        if (
            i_name_len < 64u)
        {
            char
                ac_buffer[64u];

            memcpy(
                ac_buffer,
                o_address_descriptor.o_name.o_min.pc_uchar,
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
        struct appl_buf * const
            p_name_buf)
{
    enum appl_status
        e_status;

    struct sockaddr_in *
        p_sockaddr_in =
        reinterpret_cast<struct sockaddr_in *>(
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

        struct appl_buf
            o_buf_source;

        o_buf_source.o_min.pc_uchar =
            reinterpret_cast<unsigned char const *>(
                p_name0);

        o_buf_source.o_max.pc_uchar =
            reinterpret_cast<unsigned char const *>(
                p_name0 + i_name0_len);

        unsigned long int
            i_count;

        e_status =
            appl_buf_copy(
                p_name_buf,
                &(
                    o_buf_source),
                &(
                    i_count));
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
            r_port)
{
    enum appl_status
        e_status;

    struct sockaddr_in *
        p_sockaddr_in =
        reinterpret_cast<struct sockaddr_in *>(
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
