/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <sys/socket.h>

#include <netinet/in.h>

#include <poll.h>

#include <netdb.h>

#include <string.h>

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_socket_mgr.h>

#include <socket/appl_socket_std_mgr.h>

#include <appl_socket_descriptor.h>

#include <socket/appl_socket_node.h>

#include <socket/appl_socket_std_node.h>

#include <socket/appl_address_node.h>

#include <socket/appl_address_std_node.h>

#include <appl_convert.h>

#include <appl_poll_descriptor.h>

#include <appl_allocator_handle.h>

#include <appl_heap_handle.h>

#include <context/appl_context.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#include <appl_address_descriptor.h>

#include <appl_address_family.h>

#include <appl_unused.h>

#include <appl_buf_iterator.h>

//
//
//
enum appl_status
    appl_socket_std_mgr::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_socket_mgr * * const
            r_socket_mgr)
{
    enum appl_status
        e_status;

    class appl_socket_std_mgr *
        p_socket_std_mgr;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_socket_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_socket_mgr) =
            p_socket_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_socket_std_mgr::s_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_socket_mgr * const
            p_socket_mgr)
{
    return
        appl_delete(
            p_allocator,
            p_socket_mgr);

} // s_destroy()

//
//
//
appl_socket_std_mgr::appl_socket_std_mgr(
    struct appl_context * const
        p_context) :
    appl_socket_mgr(
        p_context)
{
}

//
//
//
appl_socket_std_mgr::~appl_socket_std_mgr()
{
}

//
//
//
appl_size_t
    appl_socket_std_mgr::v_cleanup(void)
{
    return
        sizeof(class appl_socket_std_mgr);

} // v_cleanup()

//
//
//
enum appl_status
    appl_socket_std_mgr::v_create_address(
        struct appl_address_property const * const
            p_property,
        struct appl_address * * const
            r_address)
{
    enum appl_status
        e_status;

    e_status =
        appl_address_std_node::s_create(
            m_context->v_allocator(),
            p_property,
            r_address);

    return
        e_status;

} // v_create_address()

//
//
//
enum appl_status
    appl_socket_std_mgr::v_destroy_address(
        struct appl_address * const
            p_address_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_address_std_node::s_destroy(
            m_context->v_allocator(),
            p_address_node);

    return
        e_status;

} // v_destroy_address()

//
//
//
enum appl_status
    appl_socket_std_mgr::v_create_socket(
        struct appl_socket_property const * const
            p_socket_descriptor,
        struct appl_socket * * const
            r_socket)
{
    enum appl_status
        e_status;

    e_status =
        appl_socket_std_node::s_create(
            m_context->v_allocator(),
            p_socket_descriptor,
            r_socket);

    return
        e_status;

} // v_create_socket()

//
//
//
enum appl_status
    appl_socket_std_mgr::v_destroy_socket(
        struct appl_socket * const
            p_socket_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_socket_std_node::s_destroy(
            m_context->v_allocator(),
            p_socket_node);

    return
        e_status;

} // v_destroy_socket()

union appl_socket_std_node_ptr
{
    struct appl_socket *
        p_socket;

    class appl_socket_std_node *
        p_socket_std_node;

};

//
//
//
enum appl_status
    appl_socket_std_mgr::v_poll(
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

    // allocate a pollfd array
    unsigned long int const
        i_count =
        appl_convert::to_ulong(
            appl_convert::to_unsigned(
                p_poll_descriptor_max
                - p_poll_descriptor_min));

    struct pollfd *
        p_pollfd_array;

    e_status =
        appl_heap_alloc_structure_array(
            m_context,
            i_count,
            &(
                p_pollfd_array));

    if (
        appl_status_ok
        == e_status)
    {
        {
            unsigned long int
                i_index;

            i_index =
                0ul;

            while (
                i_index < i_count)
            {
                struct appl_poll_descriptor const * const
                    p_poll_descriptor =
                    p_poll_descriptor_min + i_index;

                union appl_socket_std_node_ptr
                    o_socket_std_node_ptr;

                o_socket_std_node_ptr.p_socket =
                    p_poll_descriptor->p_socket;

                class appl_socket_std_node * const
                    p_socket_std_node =
                    o_socket_std_node_ptr.p_socket_std_node;

                struct pollfd * const
                    p_pollfd_node =
                    p_pollfd_array + i_index;

                p_pollfd_node->fd =
                    p_socket_std_node->m_fd;

                p_pollfd_node->events =
                    0;

                if (
                    appl_poll_flag_read
                    & p_poll_descriptor->i_poll_flags)
                {
                    p_pollfd_node->events |= POLLIN;
                }

                if (
                    appl_poll_flag_write
                    & p_poll_descriptor->i_poll_flags)
                {
                    p_pollfd_node->events |= POLLOUT;
                }

                p_pollfd_node->revents =
                    0;

                i_index ++;
            }
        }

        nfds_t const
            i_pollfd_count =
            appl_convert::to_uint(
                i_count);

        appl_ull_t const
            ll_wait_count =
            i_wait_count;

        appl_ull_t const
            ll_timeout =
            ((ll_wait_count * 1000ul) / i_wait_freq);

        int const
            i_timeout =
            appl_convert::to_int(
                ll_timeout);

        int const
            i_poll_result =
            poll(
                p_pollfd_array,
                i_pollfd_count,
                i_timeout);

        if (
            0 == i_poll_result)
        {
            e_status =
                appl_status_timeout;
        }
        else if (
            0 < i_poll_result)
        {
            /* Do callbacks... */
            unsigned long int
                i_index;

            i_index =
                0ul;

            while (
                i_index < i_count)
            {
                struct pollfd const * const
                    p_pollfd_node =
                    p_pollfd_array + i_index;

                struct appl_poll_descriptor const * const
                    p_poll_descriptor =
                    p_poll_descriptor_min + i_index;

                int
                    i_poll_flags;

                i_poll_flags =
                    0;

                if (
                    POLLIN
                    & p_pollfd_node->revents)
                {
                    i_poll_flags |=
                        appl_poll_flag_read;
                }

                if (
                    POLLOUT
                    & p_pollfd_node->revents)
                {
                    i_poll_flags |=
                        appl_poll_flag_write;
                }

                if (
                    POLLERR
                    & p_pollfd_node->events)
                {
                    i_poll_flags |=
                        appl_poll_flag_error;
                }

                (*(p_poll_descriptor->p_callback))(
                    p_poll_descriptor->p_context,
                    i_poll_flags);

                i_index ++;
            }

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        appl_heap_free_structure_array(
            m_context,
            i_count,
            p_pollfd_array);
    }

    return
        e_status;

} // v_poll()

//
//
//
enum appl_status
    appl_socket_std_mgr::v_resolve(
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

    union appl_buf_ptr
        o_name_ptr;

    if (
        APPL_ADDRESS_FLAG_NAME & p_address_descriptor->i_flags)
    {
        e_status =
            appl_buf0_create(
                m_context,
                p_address_descriptor->p_name_min,
                p_address_descriptor->p_name_max,
                &(
                    o_name_ptr.p_uchar));
    }
    else
    {
        o_name_ptr.p_void =
            0;

        e_status =
            appl_status_ok;
    }

    if (
        appl_status_ok
        == e_status)
    {
        union appl_buf_ptr
            o_service_ptr;

        unsigned char
            a_service[6u];

        if (
            APPL_ADDRESS_FLAG_PORT & p_address_descriptor->i_flags)
        {
            struct appl_buf
                o_service_it;

            o_service_it.o_min.p_uchar =
                a_service;

            o_service_it.o_max.p_uchar =
                a_service + sizeof(a_service);

            if (
                appl_buf_iterator_print_number(
                    &(
                        o_service_it),
                    p_address_descriptor->i_port,
                    0,
                    0))
            {
                if (
                    appl_buf_iterator_write(
                        &(
                            o_service_it),
                        '\000'))
                {
                    o_service_ptr.p_uchar =
                        a_service;

                    e_status =
                        appl_status_ok;
                }
                else
                {
                    o_service_ptr.p_void =
                        0;

                    e_status =
                        appl_raise_fail();
                }
            }
            else
            {
                o_service_ptr.p_void =
                    0;

                e_status =
                    appl_raise_fail();
            }
        }
        else
        {
            o_service_ptr.p_void =
                0;

            e_status =
                appl_status_ok;
        }

        if (
            appl_status_ok
            == e_status)
        {
            struct addrinfo
                o_hints;

            struct addrinfo *
                p_addrinfo_list;

            union appl_buf_ptr
                o_hints_ptr;

            o_hints_ptr.p_void =
                &(
                    o_hints);

            appl_buf_zero(
                o_hints_ptr.p_uchar,
                o_hints_ptr.p_uchar + sizeof(o_hints));

            /* Set hints flags */
            o_hints.ai_socktype =
                SOCK_STREAM;

            /* Set hints family */
            if (
                APPL_ADDRESS_FLAG_FAMILY
                & p_address_descriptor->i_flags)
            {
                if (
                    appl_address_family_inet
                    == p_address_descriptor->e_family)
                {
                    o_hints.ai_family =
                        AF_INET;
                }
                else if (
                    appl_address_family_inet6
                    == p_address_descriptor->e_family)
                {
                    o_hints.ai_family =
                        AF_INET6;
                }
            }

            int
                i_result;

            i_result =
                getaddrinfo(
                    o_name_ptr.pc_char,
                    o_service_ptr.pc_char,
                    &(
                        o_hints),
                    &(
                        p_addrinfo_list));

            if (
                0
                == i_result)
            {
                struct addrinfo *
                    p_addrinfo_iterator;

                p_addrinfo_iterator =
                    p_addrinfo_list;

                while (
                    p_addrinfo_iterator)
                {
                    /* Use getnameinfo */
                    int
                        i_getnameinfo_result;

                    unsigned char
                        a_nameinfo_host[64u];

                    unsigned char
                        a_nameinfo_serv[16u];

                    i_getnameinfo_result =
                        getnameinfo(
                            p_addrinfo_iterator->ai_addr,
                            p_addrinfo_iterator->ai_addrlen,
                            appl_convert::to_char_ptr(
                                a_nameinfo_host),
                            sizeof(a_nameinfo_host),
                            appl_convert::to_char_ptr(
                                a_nameinfo_serv),
                            sizeof(a_nameinfo_serv),
                            NI_NUMERICHOST | NI_NUMERICSERV);

                    if (
                        0
                        == i_getnameinfo_result)
                    {
                        /* Convert addrinfo to an address descriptor */
                        struct appl_address_descriptor
                            o_address_descriptor;

                        o_address_descriptor.i_flags =
                            0u;

                        o_address_descriptor.p_name_min =
                            a_nameinfo_host;

                        o_address_descriptor.p_name_max =
                            a_nameinfo_host
                            + appl_buf0_len(
                                a_nameinfo_host);

                        o_address_descriptor.i_flags |=
                            APPL_ADDRESS_FLAG_NAME;

                        signed long int
                            i_value;

                        i_value =
                            0;

                        appl_buf_scan_number(
                            a_nameinfo_serv,
                            a_nameinfo_serv + appl_buf0_len(
                                a_nameinfo_serv),
                            &(
                                i_value),
                            0);

                        if (
                            i_value)
                        {
                            o_address_descriptor.i_flags |=
                                APPL_ADDRESS_FLAG_PORT;

                            o_address_descriptor.i_port =
                                appl_convert::to_ushort(
                                    appl_convert::to_unsigned(
                                        i_value));
                        }

                        if (
                            AF_INET
                            == p_addrinfo_iterator->ai_family)
                        {
                            o_address_descriptor.i_flags |=
                                APPL_ADDRESS_FLAG_FAMILY;

                            o_address_descriptor.e_family =
                                appl_address_family_inet;
                        }
                        else if (
                            AF_INET6
                            == p_addrinfo_iterator->ai_family)
                        {
                            o_address_descriptor.i_flags |=
                                APPL_ADDRESS_FLAG_FAMILY;

                            o_address_descriptor.e_family =
                                appl_address_family_inet6;
                        }

                        /* Check if there's an index */
                        if (
                            AF_INET6
                            == p_addrinfo_iterator->ai_family)
                        {
                            union appl_sockaddr_ptr
                            {
                                struct sockaddr const *
                                    pc_sockaddr;

                                struct sockaddr_in const *
                                    pc_sockaddr_in;

                                struct sockaddr_in6 const *
                                    pc_sockaddr_in6;
                            } o_sockaddr_ptr;

                            o_sockaddr_ptr.pc_sockaddr =
                                p_addrinfo_iterator->ai_addr;

                            if (
                                o_sockaddr_ptr.pc_sockaddr_in6->sin6_scope_id)
                            {
                                o_address_descriptor.i_flags |=
                                    APPL_ADDRESS_FLAG_INDEX;

                                o_address_descriptor.i_index =
                                    appl_convert::to_uint(
                                        o_sockaddr_ptr.pc_sockaddr_in6->sin6_scope_id);
                            }
                        }

                        (*p_callback)(
                            p_callback_context,
                            &(
                                o_address_descriptor));
                    }

                    p_addrinfo_iterator =
                        p_addrinfo_iterator->ai_next;
                }

                freeaddrinfo(
                    p_addrinfo_list);

                e_status =
                    appl_status_ok;
            }
        }

        if (
            o_name_ptr.p_uchar)
        {
            appl_buf0_destroy(
                m_context,
                o_name_ptr.p_uchar);

            o_name_ptr.p_uchar =
                0;
        }
    }

    return
        e_status;

} // v_resolve()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_socket_std_mgr.cpp */
