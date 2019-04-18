/* See LICENSE for license details */

/*

*/

#include <socket/appl_socket_test.h>

#include <appl_status.h>

#include <appl_address_family.h>

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

#include <appl_options_handle.h>

#include <appl_buf.h>

#include <appl_buf0.h>

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
        void
            s_print_msg(
                char const * const
                    p_msg0);

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
                int const
                    e_family,
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
                int const
                    e_family,
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
                int const
                    e_bind_family,
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
                int const
                    e_connect_family,
                struct appl_socket * * const
                    r_instance);

        static
        enum appl_status
            s_create_udp_socket(
                struct appl_context * const
                    p_context,
                int const
                    e_family,
                struct appl_address const * const
                    p_bind_address,
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

        static
        enum appl_status
            s_parse_family_option(
                struct appl_options const * const
                    p_options,
                unsigned int const
                    i_shift,
                int * const
                    r_family);

        static
        enum appl_status
            s_parse_port_option(
                struct appl_options const * const
                    p_options,
                unsigned int const
                    i_shift,
                unsigned short int * const
                    r_port);

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
        int const
            e_family,
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
        if (
            p_name_min != p_name_max)
        {
            appl_address_property_set_name(
                p_address_property,
                p_name_min,
                p_name_max);
        }

        if (
            i_port)
        {
            appl_address_property_set_port(
                p_address_property,
                i_port);
        }

        if (
            e_family)
        {
            appl_address_property_set_family(
                p_address_property,
                e_family);
        }

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
        int const
            e_family,
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
            e_family,
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
void
    appl_socket_test_service::s_print_msg(
        char const * const
            p_msg0)
{
    printf("%s", p_msg0);
}

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

    struct appl_thread *
        p_thread_node;

    struct appl_thread_descriptor
        o_thread_descriptor;

    appl_thread_descriptor_init(
        &(
            o_thread_descriptor));

    appl_thread_descriptor_set_callback(
        &(
            o_thread_descriptor),
        p_thread_callback,
        p_thread_context);

    e_status =
        appl_thread_create(
            p_context,
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
        int const
            e_bind_family,
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
                e_bind_family,
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
        int const
            e_connect_family,
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
                e_connect_family,
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
enum appl_status
    appl_socket_test_service::s_create_udp_socket(
        struct appl_context * const
            p_context,
        int const
            e_family,
        struct appl_address const * const
            p_bind_address,
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
        struct appl_socket *
            p_socket_node;

        appl_socket_property_set_protocol(
            p_socket_property,
            appl_socket_protocol_udp_dgram);

        appl_socket_property_set_bind_address(
            p_socket_property,
            p_bind_address);

        appl_socket_property_set_family(
            p_socket_property,
            e_family);

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
            *(r_instance) =
                p_socket_node;
        }

        appl_socket_property_destroy(
            p_socket_property);
    }

    return
        e_status;

} // s_create_udp_socket()

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

    appl_socket_test_service::s_print_msg("server thread enter ...\n");

    struct appl_context * const
        p_context =
        static_cast<struct appl_context *>(
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

    appl_socket_test_service::s_print_msg("server thread create socket ...\n");

    e_status =
        appl_socket_test_service::s_create_server_socket(
            p_context,
            g_bind_name,
            g_bind_name + sizeof(g_bind_name),
            6000u,
            appl_address_family_inet,
            &(
                p_socket_server_node));

    if (
        appl_status_ok
        == e_status)
    {
        appl_socket_test_service::s_print_msg("server thread - socket created\n");

        struct appl_socket *
            p_socket_client_node;

        struct appl_address *
            p_address_client;

        appl_socket_parent(
            p_socket_server_node);

        appl_socket_const_parent(
            p_socket_server_node);

        appl_socket_test_service::s_print_msg("server thread accept ...\n");

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
            appl_socket_test_service::s_print_msg("server thread - accepted\n");

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

    appl_socket_test_service::s_print_msg("server thread ... leave\n");

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
        static_cast<struct appl_context *>(
            p_thread_context);

    appl_socket_test_service::s_print_msg("client thread enter ...\n");

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

    appl_socket_test_service::s_print_msg("client thread create socket ...\n");

    e_status =
        appl_socket_test_service::s_create_client_socket(
            p_context,
            g_connect_name,
            g_connect_name + sizeof(g_connect_name),
            6000u,
            appl_address_family_inet,
            &(
                p_socket_client_node));

    if (
        appl_status_ok
        == e_status)
    {
        appl_socket_test_service::s_print_msg("client thread - created\n");

        appl_socket_test_service::s_message_exchange(
            p_context,
            p_socket_client_node);

        appl_socket_destroy(
            p_socket_client_node);
    }

    appl_socket_test_service::s_print_msg("client thread ... leave\n");

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
enum appl_status
    appl_socket_test_service::s_parse_family_option(
        struct appl_options const * const
            p_options,
        unsigned int const
            i_shift,
        int * const
            r_family)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_family_min;

    unsigned char const *
        p_family_max;

    e_status =
        appl_options_get(
            p_options,
            i_shift,
            &(
                p_family_min),
            &(
                p_family_max));

    if (
        appl_status_ok
        == e_status)
    {
        static unsigned char const s_ref_inet[] =
        {
            'i',
            'n',
            'e',
            't'
        };

        static unsigned char const s_ref_inet6[] =
        {
            'i',
            'n',
            'e',
            't',
            '6'
        };

        static unsigned char const s_ref_unspec[] =
        {
            'u',
            'n',
            's',
            'p',
            'e',
            'c'
        };

        if (
            0
            == appl_buf_compare(
                p_family_min,
                p_family_max,
                s_ref_inet,
                s_ref_inet + sizeof(s_ref_inet)))
        {
            *(r_family) =
                appl_address_family_inet;
        }
        else if(
            0
            == appl_buf_compare(
                p_family_min,
                p_family_max,
                s_ref_inet6,
                s_ref_inet6 + sizeof(s_ref_inet6)))
        {
            *(r_family) =
                appl_address_family_inet6;
        }
        else if (
            0
            == appl_buf_compare(
                p_family_min,
                p_family_max,
                s_ref_unspec,
                s_ref_unspec + sizeof(s_ref_unspec)))
        {
            *(r_family) =
                appl_address_family_unspecified;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;

}

//
//
//
enum appl_status
    appl_socket_test_service::s_parse_port_option(
        struct appl_options const * const
            p_options,
        unsigned int const
            i_shift,
        unsigned short int * const
            r_port)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_port_min;

    unsigned char const *
        p_port_max;

    e_status =
        appl_options_get(
            p_options,
            i_shift,
            &(
                p_port_min),
            &(
                p_port_max));

    if (
        appl_status_ok
        == e_status)
    {
        signed long int
            i_value;

        i_value =
            0l;

        appl_buf_scan_number(
            p_port_min,
            p_port_max,
            &(
                i_value),
            0);

        *(
            r_port) =
            static_cast<unsigned short int>(
                i_value);
    }

    return
        e_status;

} // s_parse_port_option()

//
//
//
void
    appl_socket_test_1(
        struct appl_context * const
            p_context)
{
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

                int
                    e_family;

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

                appl_address_property_get_family(
                    p_address_property,
                    &(
                        e_family));
            }

            appl_address_property_set_name(
                p_address_property,
                g_name,
                g_name + sizeof(g_name));

            appl_address_property_set_port(
                p_address_property,
                6000u);

            appl_address_property_set_family(
                p_address_property,
                appl_address_family_inet);

            {
                unsigned char const *
                    p_name_min;

                unsigned char const *
                    p_name_max;

                unsigned short int
                    i_port;

                int
                    e_family;

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

                appl_address_property_get_family(
                    p_address_property,
                    &(
                        e_family));
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

                {
                    int
                        e_family;

                    appl_address_get_family(
                        p_address_node,
                        &(
                            e_family));
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

            p_address_node->v_get_family(
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
                appl_socket_test_service::s_print_msg("socket test : wait for server and client threads ...\n");

                appl_clock_delay(
                    p_context,
                    1000ul,
                    1000ul);

                appl_socket_test_service::s_print_msg("socket test : ... done wait for server and client\n");
            }
        }
    }

    // Test of udp sockets
    {
        enum appl_status
            e_status;

        struct appl_address *
            p_udp_address_1;

        e_status =
            appl_socket_test_service::s_create_address(
                p_context,
                g_name,
                g_name + sizeof(g_name),
                6020u,
                appl_address_family_inet,
                &(
                    p_udp_address_1));

        if (
            appl_status_ok
            == e_status)
        {
            struct appl_address *
                p_udp_address_2;

            e_status =
                appl_socket_test_service::s_create_address(
                    p_context,
                    g_name,
                    g_name + sizeof(g_name),
                    6030u,
                    appl_address_family_inet,
                    &(
                        p_udp_address_2));

            if (
                appl_status_ok
                == e_status)
            {
                struct appl_socket *
                    p_udp_socket_1;

                e_status =
                    appl_socket_test_service::s_create_udp_socket(
                        p_context,
                        appl_address_family_inet,
                        p_udp_address_1,
                        &(
                            p_udp_socket_1));

                if (
                    appl_status_ok
                    == e_status)
                {
                    struct appl_socket *
                        p_udp_socket_2;

                    e_status =
                        appl_socket_test_service::s_create_udp_socket(
                            p_context,
                            appl_address_family_inet,
                            p_udp_address_2,
                            &(
                                p_udp_socket_2));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        static unsigned char s_buf[] =
                        {
                            1,
                            2,
                            3,
                            4
                        };

                        unsigned long int
                            i_count;

                        // test of send to
                        e_status =
                            appl_socket_sendto(
                                p_udp_socket_1,
                                s_buf,
                                s_buf + sizeof(s_buf),
                                &(
                                    i_count),
                                p_udp_address_2);

                        unsigned char
                            a_buf[5u];

                        // test of recv from
                        e_status =
                            appl_socket_recvfrom(
                                p_udp_socket_2,
                                a_buf,
                                a_buf + sizeof(a_buf),
                                &(
                                    i_count),
                                p_udp_address_1);

                        appl_socket_destroy(
                            p_udp_socket_2);
                    }

                    appl_socket_destroy(
                        p_udp_socket_1);
                }

                appl_address_destroy(
                    p_udp_address_2);
            }

            appl_address_destroy(
                p_udp_address_1);
        }
    }

} // appl_socket_test_1()

//
//
//
static
void
    appl_socket_test_2_addr(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned int const
            i_shift)
{
    enum appl_status
        e_status;

    //
    //  Options:
    //      [0]     cmd
    //      [1]     family
    //      [2]     name
    //      [3]     port
    //

    // Get family
    int
        e_family;

    e_status =
        appl_socket_test_service::s_parse_family_option(
            p_options,
            i_shift + 1u,
            &(
                e_family));

    if (
        appl_status_ok
        == e_status)
    {
        // Get address
        unsigned char const *
            p_name_min;

        unsigned char const *
            p_name_max;

        e_status =
            appl_options_get(
                p_options,
                i_shift + 2u,
                &(
                    p_name_min),
                &(
                    p_name_max));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned short int
                i_port;

            e_status =
                appl_socket_test_service::s_parse_port_option(
                    p_options,
                    i_shift + 3u,
                    &(
                        i_port));

            if (
                appl_status_ok
                == e_status)
            {
                struct appl_address *
                    p_address;

                e_status =
                    appl_socket_test_service::s_create_address(
                        p_context,
                        p_name_min,
                        p_name_max,
                        i_port,
                        e_family,
                        &(
                            p_address));

                if (
                    appl_status_ok
                    == e_status)
                {
                    unsigned char
                        a_name_value[64u];

                    unsigned char *
                        p_name_value_cur;

                    e_status =
                        appl_address_get_name(
                            p_address,
                            a_name_value,
                            a_name_value + sizeof(a_name_value),
                            &(
                                p_name_value_cur));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        unsigned short int
                            i_port_value;

                        e_status =
                            appl_address_get_port(
                                p_address,
                                &(
                                    i_port_value));

                        if (
                            appl_status_ok
                            == e_status)
                        {
                            int
                                e_family_value;

                            e_status =
                                appl_address_get_family(
                                    p_address,
                                    &(
                                        e_family_value));

                            if (
                                appl_status_ok
                                == e_status)
                            {
                                printf(
                                    "[%.*s]:%u %d\n",
                                    static_cast<int>(
                                        appl_buf_len(
                                            a_name_value,
                                            p_name_value_cur)),
                                    a_name_value,
                                    static_cast<unsigned int>(
                                        i_port_value),
                                    static_cast<int>(
                                        e_family_value));
                            }
                            else
                            {
                                appl_socket_test_service::s_print_msg("unable to get family value\n");
                            }
                        }
                        else
                        {
                            appl_socket_test_service::s_print_msg("unable to get port value\n");
                        }
                    }
                    else
                    {
                        appl_socket_test_service::s_print_msg("unable to get name value\n");
                    }

                    appl_address_destroy(
                        p_address);
                }
                else
                {
                    appl_socket_test_service::s_print_msg("unable to create address\n");
                }
            }
            else
            {
                appl_socket_test_service::s_print_msg("unable to get port option\n");
            }
        }
        else
        {
            appl_socket_test_service::s_print_msg("unable to get name option\n");
        }
    }
    else
    {
    }
}

//
//
//
static
void
    appl_socket_test_2_udp(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned int const
            i_shift)
{
    //
    //  argv[0] = udp
    //  argv[1] = family
    //  argv[2] = bindaddr
    //  argv[3] = bindport
    //  argv[4] = destaddr
    //  argv[5] = destport
    //
    appl_unused(
        p_context,
        p_options,
        i_shift);

    enum appl_status
        e_status;

    int
        e_family;

    e_status =
        appl_socket_test_service::s_parse_family_option(
            p_options,
            i_shift + 1u,
            &(
                e_family));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char const *
            p_bind_name_min;

        unsigned char const *
            p_bind_name_max;

        e_status =
            appl_options_get(
                p_options,
                i_shift + 2u,
                &(
                    p_bind_name_min),
                &(
                    p_bind_name_max));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned short int
                i_bind_port;

            e_status =
                appl_socket_test_service::s_parse_port_option(
                    p_options,
                    i_shift + 3u,
                    &(
                        i_bind_port));

            if (
                appl_status_ok
                == e_status)
            {
                unsigned char const *
                    p_dest_name_min;

                unsigned char const *
                    p_dest_name_max;

                e_status =
                    appl_options_get(
                        p_options,
                        i_shift + 4u,
                        &(
                            p_dest_name_min),
                        &(
                            p_dest_name_max));

                if (
                    appl_status_ok
                    == e_status)
                {
                    unsigned short int
                        i_dest_port;

                    e_status =
                        appl_socket_test_service::s_parse_port_option(
                            p_options,
                            i_shift + 5u,
                            &(
                                i_dest_port));

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
                                e_family,
                                &(
                                    p_bind_address));

                        if (
                            appl_status_ok
                            == e_status)
                        {
                            struct appl_address *
                                p_dest_address;

                            e_status =
                                appl_socket_test_service::s_create_address(
                                    p_context,
                                    p_dest_name_min,
                                    p_dest_name_max,
                                    i_dest_port,
                                    e_family,
                                    &(
                                        p_dest_address));

                            if (
                                appl_status_ok
                                == e_status)
                            {
                                struct appl_socket *
                                    p_udp_socket;

                                e_status =
                                    appl_socket_test_service::s_create_udp_socket(
                                        p_context,
                                        e_family,
                                        p_bind_address,
                                        &(
                                            p_udp_socket));

                                if (
                                    appl_status_ok
                                    == e_status)
                                {
                                    // create a recv thread
                                    unsigned char a_msg[80u];

                                    if (
                                        NULL
                                        != fgets(
                                            reinterpret_cast<char *>(
                                                a_msg),
                                            sizeof(
                                                a_msg) - 1u,
                                            stdin))
                                    {
                                        unsigned long int
                                            i_count;

                                        // send
                                        e_status =
                                            appl_socket_sendto(
                                                p_udp_socket,
                                                a_msg,
                                                a_msg + appl_buf0_len(
                                                    a_msg),
                                                &(
                                                    i_count),
                                                p_dest_address);

                                        if (
                                            appl_status_ok
                                            == e_status)
                                        {
                                            unsigned char a_result[80u];

                                            // recv
                                            e_status =
                                                appl_socket_recvfrom(
                                                    p_udp_socket,
                                                    a_result,
                                                    a_result + sizeof(a_result),
                                                    &(
                                                        i_count),
                                                    p_dest_address);

                                            if (
                                                appl_status_ok
                                                == e_status)
                                            {
                                                unsigned char
                                                    a_remote_name[64u];

                                                unsigned short int
                                                    i_remote_port;

                                                unsigned char *
                                                    p_remote_name_cur;

                                                p_remote_name_cur =
                                                    a_remote_name;

                                                appl_address_get_name(
                                                    p_dest_address,
                                                    a_remote_name,
                                                    a_remote_name + sizeof(a_remote_name),
                                                    &(
                                                        p_remote_name_cur));

                                                i_remote_port =
                                                    0u;

                                                appl_address_get_port(
                                                    p_dest_address,
                                                    &(
                                                        i_remote_port));

                                                printf(
                                                    "[%.*s]:%u -> {%.*s}\n",
                                                    static_cast<int>(appl_buf_len(
                                                            a_remote_name,
                                                            p_remote_name_cur)),
                                                    a_remote_name,
                                                    static_cast<unsigned int>(
                                                        i_remote_port),
                                                    static_cast<int>(i_count),
                                                    a_result);
                                            }
                                            else
                                            {
                                                appl_socket_test_service::s_print_msg("recvfrom error!\n");
                                            }
                                        }
                                    }

                                    appl_socket_destroy(
                                        p_udp_socket);
                                }

                                appl_address_destroy(
                                    p_dest_address);
                            }

                            appl_address_destroy(
                                p_bind_address);
                        }

                    }
                }
            }
        }
    }
}

//
//
//
static
void
    appl_socket_test_2_srv(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned int const
            i_shift)
{
    appl_unused(
        p_context,
        p_options,
        i_shift);
}

//
//
//
static
void
    appl_socket_test_2_cli(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned int const
            i_shift)
{
    appl_unused(
        p_context,
        p_options,
        i_shift);
}

//
//
//
void
    appl_socket_test_2_manual(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned int const
            i_shift)
{
    enum appl_status
        e_status;

    // Parsing of arguments...

    // [0] program
    // [1] type
    // [2] bind addr
    // [3] bind port

    unsigned char const *
        p_cmd_min;

    unsigned char const *
        p_cmd_max;

    e_status =
        appl_options_get(
            p_options,
            i_shift + 1u,
            &(
                p_cmd_min),
            &(
                p_cmd_max));

    if (
        appl_status_ok
        == e_status)
    {
        // Compare with: udp, server or client
        static unsigned char const g_ref_udp[] =
        {
            'u',
            'd',
            'p'
        };

        static unsigned char const g_ref_srv[] =
        {
            's',
            'r',
            'v'
        };

        static unsigned char const g_ref_cli[] =
        {
            'c',
            'l',
            'i'
        };

        static unsigned char const g_ref_addr[] =
        {
            'a',
            'd',
            'd',
            'r'
        };

        if (
            0
            == appl_buf_compare(
                p_cmd_min,
                p_cmd_max,
                g_ref_udp,
                g_ref_udp + sizeof(g_ref_udp)))
        {
            appl_socket_test_2_udp(
                p_context,
                p_options,
                i_shift + 1u);
        }
        else if (
            0
            == appl_buf_compare(
                p_cmd_min,
                p_cmd_max,
                g_ref_srv,
                g_ref_srv + sizeof(g_ref_srv)))
        {
            appl_socket_test_2_srv(
                p_context,
                p_options,
                i_shift + 1u);
        }
        else if (
            0
            == appl_buf_compare(
                p_cmd_min,
                p_cmd_max,
                g_ref_cli,
                g_ref_cli + sizeof(g_ref_cli)))
        {
            appl_socket_test_2_cli(
                p_context,
                p_options,
                i_shift + 1u);
        }
        else if (
            0
            == appl_buf_compare(
                p_cmd_min,
                p_cmd_max,
                g_ref_addr,
                g_ref_addr + sizeof(g_ref_addr)))
        {
            appl_socket_test_2_addr(
                p_context,
                p_options,
                i_shift + 1u);
        }
        else
        {
        }
    }

} // appl_socket_test_2_manual()

/* end-of-file: appl_socket_test.cpp */
