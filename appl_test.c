/* See LICENSE for license details */

#if defined APPL_BUILD_EXE

/* Include unistd.h for usleep() function */
#include <stdarg.h>

#include <unistd.h>

#include <stdio.h>

#include <appl.h>

static
void
appl_print(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    fwrite(
        p_buf_min,
        1,
        (unsigned long int)(
            p_buf_max
            - p_buf_min),
        stdout);

}

static
void
appl_print0(
    char const * const
        p_buf0)
{
    appl_print(
        (unsigned char const *)(
            p_buf0),
        (unsigned char const *)(
            p_buf0)
        + appl_buf0_len(
            (unsigned char const *)(
                p_buf0)));

}

static
void
appl_print_number(
    signed long int const
        i_value,
    int const
        i_flags,
    unsigned int const
        i_width)
{
    unsigned char
        a_msg[80u];

    appl_print(
        a_msg,
        appl_buf_print_number(
            a_msg,
            a_msg + sizeof a_msg,
            i_value,
            i_flags,
            i_width));
}

static
void
appl_test_sleep_msec(
    struct appl_context * const
        p_context,
    unsigned long int const
        i_msec_count)
{
    enum appl_status
        e_status;

    unsigned long int
        i_time_before;

    unsigned long int
        i_time_after;

    appl_clock_read(
        appl_context_parent(
            p_context),
        1000ul,
        &(
            i_time_before));

    e_status =
        appl_clock_delay(
            appl_context_parent(
                p_context),
            1000ul,
            i_msec_count);

    appl_clock_read(
        appl_context_parent(
            p_context),
        1000ul,
        &(
            i_time_after));

    appl_print0(
        "sleep ");
    appl_print_number(
        (signed long int)(
            i_msec_count),
        0,
        0);
    appl_print0(
        " msec took ");
    appl_print_number(
        (signed long int)(
            i_time_after
            - i_time_before),
        0,
        0);
    appl_print0(
        " msec\n");

    if (
        appl_status_not_implemented
        == e_status)
    {
        appl_print0("fallback sleep\n");

        usleep(
            (unsigned int)(
                i_msec_count * 1000u));
    }

}

static
void
appl_test_memory_leak(
    struct appl_context * const
        p_context)
{
    void *
        p_buf;

    enum appl_status
        e_status;

    e_status =
        appl_heap_alloc(
            appl_context_parent(
                p_context),
            123u,
            &(
                p_buf));

    if (
        appl_status_ok
        == e_status)
    {
    }
    else
    {
    }
}

struct appl_test_thread_context
{
    struct appl_context *
        p_context;

    struct appl_mutex *
        p_mutex;

    struct appl_event *
        p_event;

    void *
        pv_padding[1u];

    char
        b_event_signaled;

    char volatile
        b_kill;

    unsigned char
        uc_padding[6u];

}; /* struct appl_test_thread_context */

static
void *
appl_test_thread_entry(
    void * const
        p_context)
{
    struct appl_test_thread_context *
        p_test_thread_context;

    p_test_thread_context =
        (struct appl_test_thread_context *)(
            p_context);

    appl_print0(
        "hello world!\n");

    appl_test_sleep_msec(
        p_test_thread_context->p_context,
        100ul);

    appl_mutex_lock(
        p_test_thread_context->p_mutex);

    appl_print0(
        "thread wait 1 sec...\n");

    appl_test_sleep_msec(
        p_test_thread_context->p_context,
        1000ul);

    appl_print0(
        "... thread wait 1 sec\n");

    appl_mutex_unlock(
        p_test_thread_context->p_mutex);

    if (!(p_test_thread_context->b_kill))
    {
        appl_test_sleep_msec(
            p_test_thread_context->p_context,
            1000ul);

        if (!(p_test_thread_context->b_kill))
        {
            appl_mutex_lock(
                p_test_thread_context->p_mutex);

            appl_print0(
                "signal event!\n");

            p_test_thread_context->b_event_signaled =
                1;

            appl_event_signal(
                p_test_thread_context->p_event);

            appl_mutex_unlock(
                p_test_thread_context->p_mutex);
        }
    }

    return
        (void *)(0x1234);

} /* appl_test_thread_entry() */

static
void
appl_test_file_stdout(
    struct appl_context * const
        p_context)
{
    struct appl_file *
        p_file;

    enum appl_status
        e_status;

    struct appl_file_descriptor
        o_file_descriptor;

    o_file_descriptor.p_name_min =
        (unsigned char const *)(
            0);

    o_file_descriptor.p_name_max =
        (unsigned char const *)(
            0);

    o_file_descriptor.e_type =
        appl_file_type_stdout;

    e_status =
        appl_file_create(
            p_context,
            &(
                o_file_descriptor),
            &(
                p_file));

    if (
        appl_status_ok
        == e_status)
    {
        static unsigned char const g_msg[] =
        {
            's',
            't',
            'd',
            'o',
            'u',
            't',
            '\n'
        };

        unsigned long int
            i_count;

        e_status =
            appl_file_write(
                p_file,
                g_msg,
                g_msg + sizeof(g_msg),
                &(
                    i_count));

        appl_object_destroy(
            appl_file_parent(
                p_file));
    }

}

static
void
appl_test_print_number(
    signed long int const
        i_value,
    int const
        i_flags,
    unsigned int const
        i_width)
{
    appl_print0("msg = [");
    appl_print_number(i_value, i_flags, i_width);
    appl_print0("]\n");
}

static void appl_test_options(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    unsigned long int
        argc;

    unsigned long int
        argi;

    e_status =
        appl_options_count(
            appl_context_parent(
                p_context),
            &(
                argc));

    argi = 0;

    while (
        argi < argc)
    {
        unsigned char const *
            p_buf_min;

        unsigned char const *
            p_buf_max;

        e_status =
            appl_options_get(
                appl_context_parent(
                    p_context),
                argi,
                &(
                    p_buf_min),
                &(
                    p_buf_max));

        if (
            appl_status_ok == e_status)
        {
            appl_print0("[");
            appl_print_number((signed long int)(argi), 0, 0);
            appl_print0("] [");
            appl_print(p_buf_min, p_buf_max);
            appl_print0("]\n");
        }

        argi ++;
    }
}

static void appl_test_thread(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_thread *
        p_thread;

    struct appl_mutex *
        p_mutex;

    struct appl_event *
        p_event;

    struct appl_thread_property *
        p_property;

    struct appl_mutex_descriptor
        o_mutex_descriptor;

    struct appl_event_descriptor
        o_event_descriptor;

    struct appl_test_thread_context
        o_test_thread_context;

    appl_mutex_create(
        p_context,
        &(
            o_mutex_descriptor),
        &(
            p_mutex));

    appl_event_create(
        p_context,
        &(
            o_event_descriptor),
        &(
            p_event));

    o_test_thread_context.p_context =
        p_context;

    o_test_thread_context.p_mutex =
        p_mutex;

    o_test_thread_context.p_event =
        p_event;

    o_test_thread_context.b_event_signaled =
        0;

    o_test_thread_context.b_kill =
        0;

    appl_thread_property_create(
        p_context,
        &(
            p_property));

    appl_thread_property_set_callback(
        p_property,
        &(
            appl_test_thread_entry));

    appl_thread_property_set_context(
        p_property,
        &(
            o_test_thread_context));

    e_status =
        appl_thread_create(
            appl_context_parent(
                p_context),
            p_property,
            &(
                p_thread));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_thread_start(
                p_thread);

        if (
            appl_status_ok
            == e_status)
        {
            void *
                p_thread_result;

            appl_test_sleep_msec(
                p_context,
                200ul);

#if 0
            appl_mutex_lock(
                p_mutex);

            appl_print0(
                "main sleep 1 sec ...\n");

            appl_test_sleep_msec(
                p_context,
                1000ul);

            appl_print0(
                "... main sleep 1 sec\n");

            appl_mutex_unlock(
                p_mutex);
#endif

#if 0
            /* Wait for event */
            appl_mutex_lock(
                p_mutex);

            appl_print0(
                "wait for event...\n");

            while (!(o_test_thread_context.b_event_signaled))
            {
                appl_event_wait(
                    p_event,
                    p_mutex);
            }

            appl_print0(
                "... wait done.\n");

            appl_mutex_unlock(
                p_mutex);
#endif

#if 1
            /* Use interrupt to stop the sleep */
            o_test_thread_context.b_kill =
                1;

            e_status =
                appl_thread_interrupt(
                    p_thread);
#endif

            e_status =
                appl_thread_stop(
                    p_thread,
                    1,
                    1,
                    &(
                        p_thread_result));

            if (
                appl_status_ok
                == e_status)
            {
                appl_print0(
                    "thread result = ");
                appl_print_number(
                    (signed long int)(appl_ptrdiff_t)(
                        p_thread_result),
                    appl_buf_print_flag_hex
                    | appl_buf_print_flag_unsigned,
                    0);
                appl_print0(
                    "\n");
            }
        }

        appl_object_destroy(
            appl_thread_parent(
                p_thread));
    }

    appl_object_destroy(
        appl_property_parent(
            appl_thread_property_parent(
                p_property)));

    appl_object_destroy(
        appl_event_parent(
            p_event));

    appl_object_destroy(
        appl_mutex_parent(
            p_mutex));

}

struct appl_test_socket_descriptor
{
    char
        b_server;

}; /* struct appl_test_socket_descriptor */

static
void
appl_test_socket_handshake(
    struct appl_socket * const
        p_socket)
{
    enum appl_status
        e_status;

    unsigned long int
        i_count;

    /* test of write */
    {
        static unsigned char a_buf[] =
        {
            'h',
            'e',
            'l',
            'l',
            'o',
            '!',
            '\n'
        };

        e_status =
            appl_socket_send(
                p_socket,
                a_buf,
                a_buf + sizeof(a_buf),
                &(
                    i_count));

        if (
            appl_status_ok
            == e_status)
        {
            appl_print0("sent ");
            appl_print_number((signed long int)(i_count), 0, 0);
            appl_print0(" bytes\n");
        }
        else
        {
            appl_print0("socket send error\n");
        }
    }

    /* test of read */
    {
        unsigned char a_result[64u];

        e_status =
            appl_socket_recv(
                p_socket,
                a_result,
                a_result + sizeof(a_result),
                &(
                    i_count));

        if (
            appl_status_ok
            == e_status)
        {
            appl_print0("recv result = [");
            appl_print(a_result, a_result + i_count);
            appl_print0("]\n");
        }
        else
        {
            appl_print0("socket recv error\n");
        }
    }
}

struct appl_test_socket_connection_context
{
    struct appl_context *
        p_context;

    struct appl_socket *
        p_remote_socket;

    struct appl_address *
        p_remote_address;

    struct appl_thread *
        p_thread;

}; /* struct appl_test_socket_connection_context */

static
void
appl_test_socket_connection_thread_handler(
    struct appl_test_socket_connection_context * const
        p_test_socket_connection_context)
{
    appl_print0("connection enter...\n");

    /* Use this socket ... */
    appl_test_socket_handshake(
        p_test_socket_connection_context->p_remote_socket);

    appl_object_destroy(
        appl_address_parent(
            p_test_socket_connection_context->p_remote_address));

    appl_object_destroy(
        appl_socket_parent(
            p_test_socket_connection_context->p_remote_socket));

    appl_heap_free(
        appl_context_parent(
            p_test_socket_connection_context->p_context),
        (void *)(
            p_test_socket_connection_context));

    appl_print0("connection ...leave\n");

    appl_thread_detach(
        p_test_socket_connection_context->p_thread);

} /* appl_test_socket_connection_thread_handler() */

static
void *
appl_test_socket_connection_thread_entry(
    void * const
        p_thread_context)
{
    struct appl_test_socket_connection_context *
        p_test_socket_connection_context;

    p_test_socket_connection_context =
        (struct appl_test_socket_connection_context *)(
            p_thread_context);

    appl_test_socket_connection_thread_handler(
        p_test_socket_connection_context);

    return
        (void *)(
            0);

} /* appl_test_socket_connection_thread_entry() */

static
void
appl_test_socket_process_client(
    struct appl_context * const
        p_context,
    struct appl_socket * const
        p_remote_socket,
    struct appl_address * const
        p_remote_address)
{
    enum appl_status
        e_status;

    struct appl_test_socket_connection_context *
        p_test_socket_connection_context;

    e_status =
        appl_heap_alloc(
            appl_context_parent(
                p_context),
            (unsigned long int)(
                sizeof(
                    struct appl_test_socket_connection_context)),
            (void * *)(
                &(
                    p_test_socket_connection_context)));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char
            b_free_connection_context;

        /* create a thread for client */
        struct appl_thread_property *
            p_thread_property;

        b_free_connection_context =
            1;

        p_test_socket_connection_context->p_context =
            p_context;

        p_test_socket_connection_context->p_remote_socket =
            p_remote_socket;

        p_test_socket_connection_context->p_remote_address =
            p_remote_address;

        e_status =
            appl_thread_property_create(
                p_context,
                &(
                    p_thread_property));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                appl_thread_property_set_callback(
                    p_thread_property,
                    &(
                        appl_test_socket_connection_thread_entry));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_thread_property_set_context(
                        p_thread_property,
                        (void *)(
                            p_test_socket_connection_context));
            }

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_thread_create(
                        appl_context_parent(
                            p_context),
                        p_thread_property,
                        &(
                            p_test_socket_connection_context->p_thread));

                if (
                    appl_status_ok
                    == e_status)
                {
                    e_status =
                        appl_thread_start(
                            p_test_socket_connection_context->p_thread);

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        b_free_connection_context =
                            0;
                    }

                    if (
                        b_free_connection_context)
                    {
                        appl_object_destroy(
                            appl_thread_parent(
                                p_test_socket_connection_context->p_thread));
                    }
                }
            }

            appl_object_destroy(
                appl_property_parent(
                    appl_thread_property_parent(
                        p_thread_property)));
        }

        if (
            b_free_connection_context)
        {
            appl_object_destroy(
                appl_address_parent(
                    p_test_socket_connection_context->p_remote_address));

            appl_object_destroy(
                appl_socket_parent(
                    p_test_socket_connection_context->p_remote_socket));

            appl_heap_free(
                appl_context_parent(
                    p_context),
                (void *)(
                    p_test_socket_connection_context));
        }
    }
}

static
void
appl_test_socket(
    struct appl_context * const
        p_context,
    struct appl_test_socket_descriptor const * const
        p_descriptor)
{
    static unsigned char const g_name[] =
    {
        '1',
        '9',
        '2',
        '.',
        '1',
        '6',
        '8',
        '.',
        '0',
        '.',
        '1',
        '0',
        '4'
    };

    enum appl_status
        e_status;

    struct appl_address *
        p_address;

    {
        struct appl_address_property *
            p_address_descriptor;

        appl_address_property_create(
            p_context,
            &(
                p_address_descriptor));

        appl_address_property_set_name(
            p_address_descriptor,
            g_name,
            g_name + sizeof(g_name));

        appl_address_property_set_port(
            p_address_descriptor,
            13013u);

        e_status =
            appl_address_create(
                p_context,
                p_address_descriptor,
                &(
                    p_address));

        appl_address_property_destroy(
            p_address_descriptor);
    }

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_socket *
            p_socket;

        {
            unsigned char
                a_name[64u];

            unsigned char *
                p_name_cur;

            e_status =
                appl_address_get_name(
                    p_address,
                    a_name,
                    a_name + sizeof a_name,
                    &(
                        p_name_cur));

            if (
                appl_status_ok
                == e_status)
            {
                appl_print0("name=[");
                appl_print(a_name, p_name_cur);
                appl_print0("]\n");
            }
        }

        {
            unsigned short int
                i_port;

            e_status =
                appl_address_get_port(
                    p_address,
                    &(
                        i_port));

            if (
                appl_status_ok
                == e_status)
            {
                appl_print0("port=[");
                appl_print_number(
                    (signed long int)(
                        i_port),
                    0,
                    0);
                appl_print0("]\n");
            }
        }

        {
            struct appl_socket_property *
                p_socket_descriptor;

            e_status =
                appl_socket_property_create(
                    p_context,
                    &(
                        p_socket_descriptor));

            if (
                appl_status_ok
                == e_status)
            {
                if (
                    p_descriptor->b_server)
                {
                    /* setup bind address ... */
                    e_status =
                        appl_socket_property_set_bind_address(
                            p_socket_descriptor,
                            p_address);
                }
                else
                {
                    /* setup connect address ... */
                    e_status =
                        appl_socket_property_set_connect_address(
                            p_socket_descriptor,
                            p_address);
                }

                if (
                    appl_status_ok
                    == e_status)
                {
                    if (
                        p_descriptor->b_server)
                    {
                        e_status =
                            appl_socket_property_set_listen_count(
                                p_socket_descriptor,
                                10);
                    }

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        e_status =
                            appl_socket_create(
                                p_context,
                                p_socket_descriptor,
                                &(
                                    p_socket));

                        if (
                            appl_status_ok
                            == e_status)
                        {
                            if (
                                p_descriptor->b_server)
                            {
                                struct appl_socket *
                                    p_remote_socket;

                                struct appl_address *
                                    p_remote_address;

                                e_status =
                                    appl_socket_accept(
                                        p_socket,
                                        &(
                                            p_remote_socket),
                                        &(
                                            p_remote_address));

                                if (
                                    appl_status_ok
                                    == e_status)
                                {
                                    appl_test_socket_process_client(
                                        p_context,
                                        p_remote_socket,
                                        p_remote_address);

                                    /* wait for thread to finish */
                                    appl_test_sleep_msec(
                                        p_context,
                                        1000ul);
                                }
                            }
                            else
                            {
                                appl_test_socket_handshake(
                                    p_socket);
                            }

                            appl_object_destroy(
                                appl_socket_parent(
                                    p_socket));
                        }
                    }

                }

                appl_socket_property_destroy(
                    p_socket_descriptor);
            }
        }

        appl_object_destroy(
            appl_address_parent(
                p_address));
    }

} /* appl_test_socket() */

static
void
appl_test_property(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_property *
        p_property;

    e_status =
        appl_property_create(
            p_context,
            3,
            &(
                p_property));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_property_set_ptr(
                p_property,
                0,
                (void *)(
                    0x77777777));

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
        }

        e_status =
            appl_property_set_ulong(
                p_property,
                1,
                8080ul);

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
        }

        e_status =
            appl_property_set_long(
                p_property,
                2,
                -1234l);

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
        }

        {
            void *
                p_value;

            e_status =
                appl_property_get_ptr(
                    p_property,
                    0,
                    &(
                        p_value));

            if (
                appl_status_ok
                == e_status)
            {
                appl_print0("property 0=[");
                appl_print_number((signed long int)(appl_ptrdiff_t)(p_value), appl_buf_print_flag_hex, 0);
                appl_print0("]\n");
            }
            else
            {
            }
        }

        {
            unsigned long int
                u_value;

            e_status =
                appl_property_get_ulong(
                    p_property,
                    1,
                    &(
                        u_value));

            if (
                appl_status_ok
                == e_status)
            {
                appl_print0("property 1=[");
                appl_print_number((signed long int)(u_value), appl_buf_print_flag_unsigned, 0);
                appl_print0("]\n");
            }
            else
            {
            }

        }

        {
            signed long int
                i_value;

            e_status =
                appl_property_get_long(
                    p_property,
                    2,
                    &(
                        i_value));

            if (
                appl_status_ok
                == e_status)
            {
                appl_print0("property 2=[");
                appl_print_number(i_value, 0, 0);
                appl_print0("]\n");
            }
            else
            {
            }
        }

        appl_object_destroy(
            appl_property_parent(
                p_property));
    }

} /* appl_test_property() */

static
void
appl_test_env(
    struct appl_context * const
        p_context)
{
    struct appl_string *
        p_home_value;

    static unsigned char const sc_home_name[] =
    {
        'H',
        'O',
        'M',
        'E'
    };

    enum appl_status
        e_status;

    e_status =
        appl_env_get(
            appl_context_parent(
                p_context),
            sc_home_name,
            sc_home_name + sizeof sc_home_name,
            &(
                p_home_value));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char const *
            p_value_min;

        unsigned char const *
            p_value_max;

        e_status =
            appl_string_read(
                p_home_value,
                &(
                    p_value_min),
                &(
                    p_value_max));

        if (
            appl_status_ok
            == e_status)
        {
            appl_print0(
                "appl_test_env: home=[");

            appl_print(
                p_value_min,
                p_value_max);

            appl_print0(
                "]\n");
        }
        else
        {
            appl_print0(
                "appl_test_env: failed string read\n");
        }

        appl_object_destroy(
            appl_string_parent(
                p_home_value));
    }
    else
    {
        appl_print0(
            "appl_test_env: failed env get\n");
    }

} /* appl_test_env() */

static
void
appl_test_library(
    struct appl_context * const
        p_context)
{
    static unsigned char const g_library_name [] =
    {
#if defined APPL_OS_WINDOWS
        'u', 's', 'e', 'r', '3', '2'
#else /* #if defined APPL_OS_WINDOWS */
        'l', 'i', 'b', 'r', 't', '.', 's', 'o'
#endif /* #if defined APPL_OS_WINDOWS */
    };

    enum appl_status
        e_status;

    struct appl_library_descriptor
        o_library_descriptor;

    struct appl_library *
        p_library;

    o_library_descriptor.p_name_min =
        g_library_name;

    o_library_descriptor.p_name_max =
        g_library_name + sizeof(g_library_name);

    e_status =
        appl_library_create(
            p_context,
            &(
                o_library_descriptor),
            &(
                p_library));

    if (
        appl_status_ok
        == e_status)
    {
        static unsigned char const g_function_name[] =
        {
#if defined APPL_OS_WINDOWS
            'R', 'e', 'l', 'e', 'a', 's', 'e', 'D', 'C'
#else /* #if defined APPL_OS_WINDOWS */
            'c', 'l', 'o', 'c', 'k', '_', 'g', 'e', 't', 't', 'i', 'm', 'e'
#endif /* #if defined APPL_OS_WINDOWS */
        };

        void *
            p_value;

        e_status =
            appl_library_query(
                p_library,
                g_function_name,
                g_function_name + sizeof(g_function_name),
                &(
                    p_value));

        if (
            appl_status_ok
            == e_status)
        {
            appl_print0("query = [");
            appl_print_number(
                (signed long int)(appl_ptrdiff_t)(
                    p_value),
                appl_buf_print_flag_hex
                | appl_buf_print_flag_zero,
                16);
            appl_print0("]\n");
        }
        else
        {
            appl_print0("unable to query symbol\n");
        }

        appl_library_destroy(
            p_library);
    }
    else
    {
        appl_print0("unable to load library\n");
    }

} /* appl_test_library() */

enum appl_status
appl_main(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    /* Print the argument list */
    {
        appl_test_options(
            p_context);
    }

    /* Test memory leak */
    {
        appl_test_memory_leak(
            p_context);
    }

    /* Test thread */
    {
        appl_test_thread(
            p_context);
    }

#if defined APPL_DEBUG
    {
        static char g_test_debug_break = 0;

        appl_debug_print0(
            appl_context_parent(
                p_context),
            (unsigned char const *)(
                "debug_print0 number=["));

        appl_debug_print_number(
            appl_context_parent(
                p_context),
            666,
            0,
            0);

        appl_debug_print0(
            appl_context_parent(
                p_context),
            (unsigned char const *)(
                "]\n"));

        if (g_test_debug_break)
        {
            static unsigned char const g_msg[] =
            {
                'd',
                'e',
                'b',
                'u',
                'g',
                '_',
                'p',
                'r',
                'i',
                'n',
                't',
                '\n'
            };

            appl_debug_print(
                appl_context_parent(
                    p_context),
                g_msg,
                g_msg + sizeof(g_msg));

            appl_debug_break(
                appl_context_parent(
                    p_context));
        }
    }
#endif /* #if defined APPL_DEBUG */

    if (1)
    {
        /* test read */
        if (1)
        {
            static unsigned char const g_data[] =
            {
                1,
                2,
                3,
                4,
                5
            };

            static unsigned char const * g_data_end =
                g_data + sizeof g_data;

            unsigned char
                c_value;

            unsigned char const *
                p_cur;

            p_cur =
                g_data;

            while (
                (signed long int)(
                    g_data_end
                    - p_cur) > 0)
            {
                c_value =
                    *(
                        p_cur);

                appl_print_number(
                    (signed long int)(
                        c_value),
                    0,
                    0);
                appl_print0("\n");

                p_cur ++;
            }
        }

        /* test write */
        if (1)
        {
        }

        /* test copy */
        if (1)
        {
        }

        /* test compare */
        if (1)
        {
        }

        /* test case compare */
        if (1)
        {
        }

        /* print number */
        if (1)
        {
            appl_test_print_number(
                123456789l,
                0,
                0);

            appl_test_print_number(
                123456789l,
                appl_buf_print_flag_space,
                0);

            appl_test_print_number(
                123456789l,
                appl_buf_print_flag_plus,
                0);

            appl_test_print_number(
                123456789l,
                0,
                20);

            appl_test_print_number(
                123456789l,
                appl_buf_print_flag_space,
                20);

            appl_test_print_number(
                123456789l,
                appl_buf_print_flag_plus,
                20);

            appl_test_print_number(
                123456789l,
                appl_buf_print_flag_zero,
                20);

            appl_test_print_number(
                123456789l,
                appl_buf_print_flag_space | appl_buf_print_flag_zero,
                20);

            appl_test_print_number(
                123456789l,
                appl_buf_print_flag_plus | appl_buf_print_flag_zero,
                20);

            appl_test_print_number(
                123456789l,
                appl_buf_print_flag_left,
                20);

            appl_test_print_number(
                -123456789l,
                0,
                0);

            appl_test_print_number(
                -123456789l,
                0,
                20);

            appl_test_print_number(
                -123456789l,
                appl_buf_print_flag_unsigned | appl_buf_print_flag_hex,
                20);

        }
    }

    if (1)
    {
        appl_test_file_stdout(
            p_context);
    }

    if (1)
    {
        struct appl_test_socket_descriptor
            o_test_socket_descriptor;

        o_test_socket_descriptor.b_server =
            0;

        {
            unsigned long int
                argc;

            e_status =
                appl_options_count(
                    appl_context_parent(
                        p_context),
                    &(
                        argc));

            if (
                appl_status_ok
                == e_status)
            {
                if (
                    argc > 1)
                {
                    unsigned char const *
                        p_arg_min;

                    unsigned char const *
                        p_arg_max;

                    e_status =
                        appl_options_get(
                            appl_context_parent(
                                p_context),
                            1u,
                            &(
                                p_arg_min),
                            &(
                                p_arg_max));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        if (
                            ('-' == p_arg_min[0u])
                            && ('s' == p_arg_min[1u]))
                        {
                            o_test_socket_descriptor.b_server =
                                1;
                        }
                    }
                }
            }
        }

        appl_test_socket(
            p_context,
            &(
                o_test_socket_descriptor));
    }

    if (1)
    {
        appl_test_property(
            p_context);
    }

    if (1)
    {
        appl_test_env(
            p_context);
    }

    if (1)
    {
        appl_test_library(
            p_context);
    }

    e_status =
        appl_status_ok;

    return
        e_status;

}

#else /* #if defined APPL_BUILD_EXE */

typedef void appl_dummy;

#endif /* #if defined APPL_BUILD_EXE */

/* end-of-file: appl_test.c */
