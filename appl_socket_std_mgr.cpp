/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <sys/socket.h>

#include <netinet/in.h>

#include <poll.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_socket_mgr.h>

#include <appl_socket_std_mgr.h>

#include <appl_socket_descriptor.h>

#include <appl_socket_node.h>

#include <appl_socket_std_node.h>

#include <appl_address_node.h>

#include <appl_address_std_node.h>

#include <appl_convert.h>

#include <appl_poll_descriptor.h>

#include <appl_heap.h>

#include <appl_context.h>

//
//
//
enum appl_status
    appl_socket_std_mgr::s_create(
        struct appl_heap * const
            p_heap,
        class appl_socket_mgr * * const
            r_socket_mgr)
{
    enum appl_status
        e_status;

    class appl_socket_std_mgr *
        p_socket_std_mgr;

    e_status =
        p_heap->alloc_object(
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
appl_socket_std_mgr::appl_socket_std_mgr() :
    appl_socket_mgr()
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
            m_context->m_heap,
            p_property,
            r_address);

    return
        e_status;

} // v_create_address()

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
            m_context->m_heap,
            p_socket_descriptor,
            r_socket);

    return
        e_status;

} // v_create_socket()

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
        m_context->m_heap->alloc_structure_array(
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

        m_context->m_heap->free_structure_array(
            i_count,
            p_pollfd_array);
    }

    return
        e_status;

} // v_poll()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_socket_std_mgr.cpp */
