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

//
//
//
enum appl_status
    appl_address_std_node::s_create(
        class appl_context * const
            p_context,
        struct appl_address_descriptor const * const
            p_address_descriptor,
        class appl_address_node * * const
            r_address_node)
{
    return
        appl_object::create_instance(
            p_context,
            static_cast<unsigned long int>(
                sizeof(
                    class appl_address_std_node)),
            &(
                appl_address_std_node::s_new),
            static_cast<void const *>(
                p_address_descriptor),
            reinterpret_cast<class appl_object * *>(
                r_address_node));

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

    struct appl_address_descriptor const * const
        p_address_descriptor =
        static_cast<struct appl_address_descriptor const *>(
            p_descriptor);

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
        p_address_descriptor->b_port)
    {
        p_sockaddr_in->sin_port =
            htons(
                p_address_descriptor->i_port);
    }

    if (
        p_address_descriptor->b_name)
    {
        appl_size_t
            i_name_len;

        i_name_len =
            static_cast<appl_size_t>(
                p_address_descriptor->o_name.o_max.pc_uchar
                - p_address_descriptor->o_name.o_min.pc_uchar);

        if (
            i_name_len < 64u)
        {
            char
                ac_buffer[64u];

            memcpy(
                ac_buffer,
                p_address_descriptor->o_name.o_min.pc_uchar,
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

/* end-of-file: appl_address_std_node.cpp */
