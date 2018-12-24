/* See LICENSE for license details */

/*

*/

#include <socket/appl_socket_test.h>

#include <appl_status.h>

#include <appl_address_property.h>

#include <appl_address_handle.h>

#include <appl_socket_descriptor.h>

#include <appl_socket_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_address_node.h>

#include <socket/appl_socket_mgr.h>

#include <socket/appl_socket_node.h>

#include <appl_heap_handle.h>

//
//
//
void
    appl_socket_test_1(
        struct appl_context * const
            p_context)
{
    // address property sanity check
    // address handle sanity check
    // socket property sanity check
    // socket handle sanity check
    {
        enum appl_status
            e_status;

        struct appl_address_property *
            p_address_property;

        e_status =
            appl_address_property_create(
                p_context,
                &(
                    p_address_property));

        if (
            appl_status_ok
            == e_status)
        {
            appl_address_property_parent(
                p_address_property);

            appl_address_property_const_parent(
                p_address_property);

            {
                unsigned char const *
                    p_name_min;

                unsigned char const *
                    p_name_max;

                unsigned short int
                    i_port;

                appl_address_property_get_name(
                    p_address_property,
                    &(
                        p_name_min),
                    &(
                        p_name_max));

                appl_address_property_get_port(
                    p_address_property,
                    &(
                        i_port));
            }

            static unsigned char const g_name[] =
            {
                '1',
                '2',
                '7',
                '.',
                '0',
                '.',
                '0',
                '.',
                '1'
            };

            appl_address_property_set_name(
                p_address_property,
                g_name,
                g_name + sizeof(g_name));

            appl_address_property_set_port(
                p_address_property,
                6000u);

            {
                unsigned char const *
                    p_name_min;

                unsigned char const *
                    p_name_max;

                unsigned short int
                    i_port;

                appl_address_property_get_name(
                    p_address_property,
                    &(
                        p_name_min),
                    &(
                        p_name_max));

                appl_address_property_get_port(
                    p_address_property,
                    &(
                        i_port));
            }

            struct appl_address *
                p_address_node;

            e_status =
                appl_address_create(
                    p_context,
                    p_address_property,
                    &(
                        p_address_node));

            if (
                appl_status_ok
                == e_status)
            {
                appl_address_parent(
                    p_address_node);

                appl_address_const_parent(
                    p_address_node);

                {
                    unsigned short int
                        i_port;

                    appl_address_get_port(
                        p_address_node,
                        &(
                            i_port));
                }

                {
                    unsigned long int
                        i_name_len;

                    appl_address_get_name_len(
                        p_address_node,
                        &(
                            i_name_len));
                }

                {
                    unsigned char
                        a_name[64u];

                    unsigned char *
                        p_name_cur;

                    appl_address_get_name(
                        p_address_node,
                        a_name,
                        a_name + sizeof(a_name),
                        &(
                            p_name_cur));
                }

                // Create a socket descriptor
                struct appl_socket_property *
                    p_socket_property;

                e_status =
                    appl_socket_property_create(
                        p_context,
                        &(
                            p_socket_property));

                if (
                    appl_status_ok
                    == e_status)
                {
                    appl_socket_property_parent(
                        p_socket_property);

                    appl_socket_property_const_parent(
                        p_socket_property);

                    {
                        enum appl_socket_protocol
                            e_socket_protocol;

                        e_socket_protocol =
                            appl_socket_protocol_tcp_stream;

                        appl_socket_property_set_protocol(
                            p_socket_property,
                            e_socket_protocol);

                        appl_socket_property_get_protocol(
                            p_socket_property,
                            &(
                                e_socket_protocol));
                    }

                    {
                        struct appl_address const *
                            p_bind_address;

                        p_bind_address =
                            p_address_node;

                        appl_socket_property_set_bind_address(
                            p_socket_property,
                            p_bind_address);

                        appl_socket_property_get_bind_address(
                            p_socket_property,
                            &(
                                p_bind_address));
                    }

                    {
                        struct appl_address const *
                            p_connect_address;

                        p_connect_address =
                            p_address_node;

                        appl_socket_property_set_connect_address(
                            p_socket_property,
                            p_connect_address);

                        appl_socket_property_get_connect_address(
                            p_socket_property,
                            &(
                                p_connect_address));
                    }

                    {
                        unsigned long int
                            i_listen_count;

                        i_listen_count =
                            10;

                        appl_socket_property_set_listen_count(
                            p_socket_property,
                            i_listen_count);

                        appl_socket_property_get_listen_count(
                            p_socket_property,
                            &(
                                i_listen_count));
                    }

                    {
                        unsigned long int
                            i_timeout;

                        i_timeout =
                            1000ul;

                        appl_socket_property_set_recv_timeout(
                            p_socket_property,
                            i_timeout);

                        appl_socket_property_set_send_timeout(
                            p_socket_property,
                            i_timeout);

                        appl_socket_property_get_recv_timeout(
                            p_socket_property,
                            &(
                                i_timeout));

                        appl_socket_property_get_send_timeout(
                            p_socket_property,
                            &(
                                i_timeout));
                    }

                    {
                        unsigned long int
                            i_buffer_size;

                        i_buffer_size =
                            256ul * 1024ul;

                        appl_socket_property_set_recv_buffer(
                            p_socket_property,
                            i_buffer_size);

                        appl_socket_property_set_send_buffer(
                            p_socket_property,
                            i_buffer_size);

                        appl_socket_property_get_recv_buffer(
                            p_socket_property,
                            &(
                                i_buffer_size));

                        appl_socket_property_get_send_buffer(
                            p_socket_property,
                            &(
                                i_buffer_size));
                    }

                    {
                        unsigned long int
                            i_timeout;

                        i_timeout =
                            2000ul;

                        appl_socket_property_set_connect_timeout(
                            p_socket_property,
                            i_timeout);

                        appl_socket_property_set_accept_timeout(
                            p_socket_property,
                            i_timeout);

                        appl_socket_property_get_connect_timeout(
                            p_socket_property,
                            &(
                                i_timeout));

                        appl_socket_property_get_accept_timeout(
                            p_socket_property,
                            &(
                                i_timeout));
                    }

                    {
                        struct appl_address const *
                            p_join_address;

                        p_join_address =
                            p_address_node;

                        appl_socket_property_set_join_address(
                            p_socket_property,
                            p_join_address);

                        appl_socket_property_get_join_address(
                            p_socket_property,
                            &(
                                p_join_address));
                    }

                    {
                        struct appl_address const *
                            p_join_interface;

                        p_join_interface =
                            p_address_node;

                        appl_socket_property_set_join_interface(
                            p_socket_property,
                            p_join_interface);

                        appl_socket_property_get_join_interface(
                            p_socket_property,
                            &(
                                p_join_interface));
                    }

#if 0
                    struct appl_socket *
                        p_socket_node;

                    e_status =
                        appl_socket_create(
                            p_context,
                            p_socket_property,
                            &(
                                p_socket_node));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        appl_socket_parent(
                            p_socket_node);

                        appl_socket_const_parent(
                            p_socket_node);

                        appl_socket_destroy(
                            p_socket_node);
                    }
#endif

                    appl_socket_property_destroy(
                        p_socket_property);
                }

                appl_address_destroy(
                    p_address_node);
            }

            appl_address_property_destroy(
                p_address_property);
        }
    }

    // Verify address node base class
    {
        struct appl_address *
            p_address_node;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_address_node));

        if (
            appl_status_ok
            == e_status)
        {
            p_address_node->v_get_name_len(
                0);

            p_address_node->v_get_name(
                0,
                0,
                0);

            p_address_node->v_get_port(
                0);

            appl_delete(
                p_context,
                p_address_node);
        }
    }

    // Verify socket manager base class
    {
        class appl_socket_mgr *
            p_socket_mgr;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_socket_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            p_socket_mgr->v_create_address(
                0,
                0);

            p_socket_mgr->v_destroy_address(
                0);

            p_socket_mgr->v_create_socket(
                0,
                0);

            p_socket_mgr->v_destroy_socket(
                0);

            p_socket_mgr->v_poll(
                0,
                0,
                0,
                0);

            appl_delete(
                p_context,
                p_socket_mgr);
        }
    }

    // Verify socket node base class
    {
        struct appl_socket *
            p_socket_node;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_socket_node));

        if (
            appl_status_ok
            == e_status)
        {
            p_socket_node->v_accept(
                0,
                0);

            p_socket_node->v_send(
                0,
                0,
                0);

            p_socket_node->v_recv(
                0,
                0,
                0);

            p_socket_node->v_sendto(
                0,
                0,
                0,
                0);

            p_socket_node->v_recvfrom(
                0,
                0,
                0,
                0);

            p_socket_node->v_wait(
                appl_socket_wait_send,
                0,
                0);

            appl_delete(
                p_context,
                p_socket_node);
        }
    }

} // appl_socket_test_1()

/* end-of-file: appl_socket_test.cpp */
