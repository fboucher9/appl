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

#include <appl_poll_descriptor.h>

#include <appl_object.h>

#include <socket/appl_address_node.h>

#include <socket/appl_socket_mgr.h>

#include <socket/appl_socket_node.h>

#include <appl_thread_descriptor.h>

#include <appl_thread_property.h>

#include <appl_thread_handle.h>

#include <appl_heap_handle.h>

#include <appl_clock_handle.h>

#include <appl_unused.h>

#include <stdio.h>

static
struct appl_thread *
g_server_thread_node =
0;

static
struct appl_thread *
g_client_thread_node =
0;

//
//
//
class appl_socket_test_service
{
    public:

        static
        enum appl_status
            s_create_address_property(
                struct appl_context * const
                    p_context,
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                unsigned short int const
                    i_port,
                struct appl_address_property * * const
                    r_instance);

        static
        enum appl_status
            s_create_address(
                struct appl_context * const
                    p_context,
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                unsigned short int const
                    i_port,
                struct appl_address * * const
                    r_instance);

        static
        enum appl_status
            s_create_thread(
                struct appl_context * const
                    p_context,
                void (* p_thread_callback)(
                    void * const
                        p_thread_context),
                void * const
                    p_thread_context,
                struct appl_thread * * const
                    r_instance);

        static
        enum appl_status
            s_create_server_socket(
                struct appl_context * const
                    p_context,
                unsigned char const * const
                    p_bind_name_min,
                unsigned char const * const
                    p_bind_name_max,
                unsigned short int const
                    i_bind_port,
                struct appl_socket * * const
                    r_instance);

        static
        enum appl_status
            s_create_client_socket(
                struct appl_context * const
                    p_context,
                unsigned char const * const
                    p_connect_name_min,
                unsigned char const * const
                    p_connect_name_max,
                unsigned short int const
                    i_connect_port,
                struct appl_socket * * const
                    r_instance);

        static
        void
            s_server_thread(
                void * const
                    p_thread_context);

        static
        void
            s_client_thread(
                void * const
                    p_thread_context);

        static
        void
            s_message_exchange(
                struct appl_context * const
                    p_context,
                struct appl_socket * const
                    p_socket_node);

        static
        void
            s_poll_callback(
                void * const
                    p_callback_context,
                int const
                    i_poll_flags);

}; // class appl_socket_test_service

//
//
//
enum appl_status
    appl_socket_test_service::s_create_address_property(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        unsigned short int const
            i_port,
        struct appl_address_property * * const
            r_instance)
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
        appl_address_property_set_name(
            p_address_property,
            p_name_min,
            p_name_max);

        appl_address_property_set_port(
            p_address_property,
            i_port);

        *(
            r_instance) =
            p_address_property;
    }

    return
        e_status;

} // s_create_address_property

//
//
//
enum appl_status
    appl_socket_test_service::s_create_address(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        unsigned short int const
            i_port,
        struct appl_address * * const
            r_instance)
{
    enum appl_status
        e_status;

    struct appl_address_property *
        p_address_property;

    e_status =
        appl_socket_test_service::s_create_address_property(
            p_context,
            p_name_min,
            p_name_max,
            i_port,
            &(
                p_address_property));

    if (
        appl_status_ok
        == e_status)
    {
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
            *(r_instance) =
                p_address_node;
        }

        appl_address_property_destroy(
            p_address_property);
    }

    return
        e_status;

} // s_create_address()

//
//
//
enum appl_status
    appl_socket_test_service::s_create_thread(
        struct appl_context * const
            p_context,
        void (* p_thread_callback)(
            void * const
                p_thread_context),
        void * const
            p_thread_context,
        struct appl_thread * * const
            r_instance)
{
    enum appl_status
        e_status;

    struct appl_thread_property *
        p_thread_property;

    e_status =
        appl_thread_property_create(
            p_context,
            &(
                p_thread_property));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_thread *
            p_thread_node;

        struct appl_thread_descriptor
            o_thread_descriptor;

        o_thread_descriptor.b_callback =
            1;

        o_thread_descriptor.b_name =
            0;

        o_thread_descriptor.b_stack =
            0;

        o_thread_descriptor.b_scheduling =
            0;

        o_thread_descriptor.o_callback.p_entry =
            p_thread_callback;

        o_thread_descriptor.o_callback.p_context =
            p_thread_context;

        e_status =
            appl_thread_create(
                p_context,
                p_thread_property,
                &(
                    o_thread_descriptor),
                &(
                    p_thread_node));

        if (
            appl_status_ok
            == e_status)
        {
            *(r_instance) =
                p_thread_node;
        }

        appl_thread_property_destroy(
            p_thread_property);
    }

    return
        e_status;

} // s_create_thread()

//
//
//
enum appl_status
    appl_socket_test_service::s_create_server_socket(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_bind_name_min,
        unsigned char const * const
            p_bind_name_max,
        unsigned short int const
            i_bind_port,
        struct appl_socket * * const
            r_instance)
{
    enum appl_status
        e_status;

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
        struct appl_address *
            p_bind_address;

        e_status =
            appl_socket_test_service::s_create_address(
                p_context,
                p_bind_name_min,
                p_bind_name_max,
                i_bind_port,
                &(
                    p_bind_address));

        if (
            appl_status_ok
            == e_status)
        {
            appl_socket_property_set_protocol(
                p_socket_property,
                appl_socket_protocol_tcp_stream);

            appl_socket_property_set_bind_address(
                p_socket_property,
                p_bind_address);

            appl_socket_property_set_listen_count(
                p_socket_property,
                10ul);

            struct appl_socket *
                p_socket_server_node;

            e_status =
                appl_socket_create(
                    p_context,
                    p_socket_property,
                    &(
                        p_socket_server_node));

            if (
                appl_status_ok
                == e_status)
            {
                *(r_instance) =
                    p_socket_server_node;
            }

            appl_address_destroy(
                p_bind_address);
        }

        appl_socket_property_destroy(
            p_socket_property);
    }

    return
        e_status;

} // s_create_server_socket()

//
//
//
enum appl_status
    appl_socket_test_service::s_create_client_socket(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_connect_name_min,
        unsigned char const * const
            p_connect_name_max,
        unsigned short int const
            i_connect_port,
        struct appl_socket * * const
            r_instance)
{
    enum appl_status
        e_status;

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
        struct appl_address *
            p_connect_address;

        e_status =
            appl_socket_test_service::s_create_address(
                p_context,
                p_connect_name_min,
                p_connect_name_max,
                i_connect_port,
                &(
                    p_connect_address));

        if (
            appl_status_ok
            == e_status)
        {
            appl_socket_property_set_protocol(
                p_socket_property,
                appl_socket_protocol_tcp_stream);

            appl_socket_property_set_connect_address(
                p_socket_property,
                p_connect_address);

            struct appl_socket *
                p_socket_client_node;

            e_status =
                appl_socket_create(
                    p_context,
                    p_socket_property,
                    &(
                        p_socket_client_node));

            if (
                appl_status_ok
                == e_status)
            {
                *(r_instance) =
                    p_socket_client_node;
            }

            appl_address_destroy(
                p_connect_address);
        }

        appl_socket_property_destroy(
            p_socket_property);
    }

    return
        e_status;

} // s_create_client_socket()

//
//
//
void
    appl_socket_test_service::s_server_thread(
        void * const
            p_thread_context)
{
    enum appl_status
        e_status;

    printf("server thread enter ...\n");

    struct appl_context * const
        p_context =
        (struct appl_context *)(
            p_thread_context);

    struct appl_socket *
        p_socket_server_node;

    static unsigned char const g_bind_name[] =
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

    printf("server thread create socket ...\n");

    e_status =
        appl_socket_test_service::s_create_server_socket(
            p_context,
            g_bind_name,
            g_bind_name + sizeof(g_bind_name),
            6000u,
            &(
                p_socket_server_node));

    if (
        appl_status_ok
        == e_status)
    {
        printf("server thread - socket created\n");

        struct appl_socket *
            p_socket_client_node;

        struct appl_address *
            p_address_client;

        appl_socket_parent(
            p_socket_server_node);

        appl_socket_const_parent(
            p_socket_server_node);

        printf("server thread accept ...\n");

        e_status =
            appl_socket_accept(
                p_socket_server_node,
                &(
                    p_socket_client_node),
                &(
                    p_address_client));

        if (
            appl_status_ok
            == e_status)
        {
            printf("server thread - accepted\n");

            appl_socket_test_service::s_message_exchange(
                p_context,
                p_socket_client_node);

            appl_address_destroy(
                p_address_client);

            appl_socket_destroy(
                p_socket_client_node);
        }

        appl_socket_destroy(
            p_socket_server_node);
    }

    printf("server thread ... leave\n");

    appl_thread_destroy(
        g_server_thread_node);

    g_server_thread_node =
        0;

} // s_server_thread()

//
//
//
void
    appl_socket_test_service::s_client_thread(
        void * const
            p_thread_context)
{
    struct appl_context * const
        p_context =
        (struct appl_context *)(
            p_thread_context);

    printf("client thread enter ...\n");

    enum appl_status
        e_status;

    static unsigned char const g_connect_name[] =
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

    struct appl_socket *
        p_socket_client_node;

    printf("client thread create socket ...\n");

    e_status =
        appl_socket_test_service::s_create_client_socket(
            p_context,
            g_connect_name,
            g_connect_name + sizeof(g_connect_name),
            6000u,
            &(
                p_socket_client_node));

    if (
        appl_status_ok
        == e_status)
    {
        printf("client thread - created\n");

        appl_socket_test_service::s_message_exchange(
            p_context,
            p_socket_client_node);

        appl_socket_destroy(
            p_socket_client_node);
    }

    printf("client thread ... leave\n");

    appl_thread_destroy(
        g_client_thread_node);

    g_client_thread_node =
        0;

} // s_client_thread()

//
//
//
void
    appl_socket_test_service::s_poll_callback(
        void * const
            p_callback_context,
        int const
            i_poll_flags)
{
    appl_unused(
        p_callback_context,
        i_poll_flags);

} // s_poll_callback()

//
//
//
void
    appl_socket_test_service::s_message_exchange(
        struct appl_context * const
            p_context,
        struct appl_socket * const
            p_socket_node)
{
    enum appl_status
        e_status;

    appl_socket_parent(
        p_socket_node);

    appl_socket_const_parent(
        p_socket_node);

    // Send a greating
    {
        static unsigned char const g_msg[] =
        {
            'h',
            'e',
            'l',
            'l',
            'o'
        };

        unsigned long int
            i_count;

        e_status =
            appl_socket_send(
                p_socket_node,
                g_msg,
                g_msg + sizeof(g_msg),
                &(
                    i_count));
    }

    // Use wait
    {
        e_status =
            appl_socket_wait(
                p_socket_node,
                appl_socket_wait_recv,
                1000ul,
                100ul);
    }

    // Use poll
    {
        struct appl_poll_descriptor
            a_poll_descriptor[1u];

        a_poll_descriptor[0u].p_socket =
            p_socket_node;

        a_poll_descriptor[0u].p_callback =
            &(
                appl_socket_test_service::s_poll_callback);

        a_poll_descriptor[0u].p_context =
            0;

        a_poll_descriptor[0u].i_poll_flags =
            appl_poll_flag_read;

        e_status =
            appl_socket_poll(
                p_context,
                a_poll_descriptor,
                a_poll_descriptor + 1u,
                1000u,
                100u);
    }

    // Wait for a request
    {
        unsigned char
            a_buf[64u];

        unsigned long int
            i_count;

        e_status =
            appl_socket_recv(
                p_socket_node,
                a_buf,
                a_buf + sizeof(a_buf),
                &(
                    i_count));
    }

    appl_unused(
        e_status);

}

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

    // Create a server thread
    // Create a client thread
    {
        enum appl_status
            e_status;

        e_status =
            appl_socket_test_service::s_create_thread(
                p_context,
                &(
                    appl_socket_test_service::s_server_thread),
                p_context,
                &(
                    g_server_thread_node));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                appl_socket_test_service::s_create_thread(
                    p_context,
                    &(
                        appl_socket_test_service::s_client_thread),
                    p_context,
                    &(
                        g_client_thread_node));

            if (
                appl_status_ok
                == e_status)
            {
                // Wait for test to complete
                printf("socket test : wait for server and client threads ...\n");

                appl_clock_delay(
                    p_context,
                    1000ul,
                    1000ul);

                printf("socket test : ... done wait for server and client\n");
            }
        }
    }
} // appl_socket_test_1()

/* end-of-file: appl_socket_test.cpp */
