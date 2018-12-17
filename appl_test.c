/* See LICENSE for license details */

#if defined APPL_BUILD_EXE

/* Include unistd.h for usleep() function */
#include <stdarg.h>

#include <unistd.h>

#include <stdio.h>

#include <string.h>

#include <appl.h>

#include <appl_chunk.h>

#include <object/appl_object_test.h>

#include <hash/appl_hash_test.h>

#include <pool/appl_pool_test.h>

#include <module/appl_module_test.h>

#include <timer/appl_timer_test.h>

#include <binary_heap/appl_binary_heap_test.h>

#include <options/appl_options_test.h>

#include <xlib/appl_xlib_test.h>

#include <appl_test_prompt.h>

#include <mutex/appl_mutex_test.h>

#include <clock/appl_clock_test.h>

#include <random/appl_random_test.h>

#include <event/appl_event_test.h>

#include <backtrace/appl_backtrace_test.h>

#include <env/appl_env_test.h>

#include <heap/appl_heap_test.h>

#include <allocator/appl_allocator_test.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_test.h>
#endif /* #if defined APPL_DEBUG */

#include <context/appl_context_test.h>

void
appl_thread_cache_test(
    struct appl_context * const
        p_context);

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

    appl_ull_t
        i_time_before;

    appl_ull_t
        i_time_after;

    appl_clock_read(
        p_context,
        1000ul,
        &(
            i_time_before));

    e_status =
        appl_clock_delay(
            p_context,
            1000ul,
            i_msec_count);

    appl_clock_read(
        p_context,
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

    struct appl_context *
        p_context_temp;

    (void)(
        p_context);

    e_status =
        appl_context_create(
            &(
                p_context_temp));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_heap_alloc(
                p_context_temp,
                123u,
                &(
                    p_buf));

        appl_context_destroy(
            p_context_temp);
    }

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

    struct appl_queue *
        p_queue;

    /* -- */

    struct appl_list
        o_dummy_result;

    /* -- */

    char volatile
        b_kill;

    char volatile
        b_done;

#define PADDING (2)
#include <appl_padding.h>

}; /* struct appl_test_thread_context */

static
void
appl_test_thread_entry(
    void * const
        p_context)
{
    struct appl_test_thread_context *
        p_test_thread_context;

    char
        b_continue;

    b_continue =
        1;

    p_test_thread_context =
        (struct appl_test_thread_context *)(
            p_context);

    if (
        p_test_thread_context->b_kill)
    {
        b_continue =
            0;
    }

    if (
        b_continue)
    {
        appl_print0(
            "hello world!\n");

        appl_test_sleep_msec(
            p_test_thread_context->p_context,
            100ul);
    }

    if (
        p_test_thread_context->b_kill)
    {
        b_continue =
            0;
    }

    if (
        b_continue)
    {
        appl_print0(
            "thread wait 1 sec...\n");

        appl_test_sleep_msec(
            p_test_thread_context->p_context,
            1000ul);

        appl_print0(
            "... thread wait 1 sec\n");
    }

    if (
        p_test_thread_context->b_kill)
    {
        b_continue =
            0;
    }

    if (
        b_continue)
    {
        appl_print0(
            "thread wait 1 sec...\n");

        appl_test_sleep_msec(
            p_test_thread_context->p_context,
            1000ul);

        appl_print0(
            "... thread wait 1 sec\n");
    }

    appl_print0(
        "signal event!\n");

    appl_queue_push(
        p_test_thread_context->p_queue,
        &(
            p_test_thread_context->o_dummy_result),
        1000ul,
        1000ul);

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

        appl_file_destroy(
            p_file);
    }

}

static
enum appl_status
appl_test_line_create(
    struct appl_context * const
        p_context,
    struct appl_file * const
        p_stdin_file,
    struct appl_buf * const
        r_buf)
{
    enum appl_status
        e_status;

    struct appl_chunk *
        p_chunk;

    e_status =
        appl_chunk_create(
            p_context,
            &(
                p_chunk));

    if (
        appl_status_ok
        == e_status)
    {
        char
            b_continue;

        b_continue =
            1;

        while (
            (
                appl_status_ok
                == e_status)
            && b_continue)
        {
            unsigned char
                a_stdin_buf[32u];

            unsigned long int
                i_count;

            e_status =
                appl_file_read(
                    p_stdin_file,
                    a_stdin_buf,
                    a_stdin_buf + sizeof(a_stdin_buf),
                    &(
                        i_count));

            if (
                appl_status_ok
                == e_status)
            {
                unsigned char *
                    p_stdin_buf_iterator;

                p_stdin_buf_iterator =
                    a_stdin_buf;

                while (
                    p_stdin_buf_iterator < a_stdin_buf + i_count)
                {
                    unsigned char
                        c_stdin_buf_char;

                    c_stdin_buf_char =
                        *(
                            p_stdin_buf_iterator);

                    if (
                        '\n'
                        == c_stdin_buf_char)
                    {
                        b_continue =
                            0;
                    }
                    else if (
                        '\r'
                        == c_stdin_buf_char)
                    {
                    }
                    else
                    {
                        e_status =
                            appl_chunk_write(
                                p_chunk,
                                p_stdin_buf_iterator,
                                p_stdin_buf_iterator + 1);
                    }

                    p_stdin_buf_iterator ++;
                }
            }
        }

        if (
            appl_status_ok
            == e_status)
        {
            unsigned long int
                i_line_length;

            e_status =
                appl_chunk_length(
                    p_chunk,
                    &(
                        i_line_length));

            if (
                appl_status_ok
                == e_status)
            {
                union line_ptr
                {
                    void *
                        p_void;

                    unsigned char *
                        p_uchar;

                } o_line_ptr;

                e_status =
                    appl_heap_alloc(
                        p_context,
                        i_line_length,
                        &(
                            o_line_ptr.p_void));

                if (
                    appl_status_ok
                    == e_status)
                {
                    e_status =
                        appl_chunk_read(
                            p_chunk,
                            o_line_ptr.p_uchar,
                            o_line_ptr.p_uchar + i_line_length);

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        r_buf->o_min.p_uchar =
                            o_line_ptr.p_uchar;

                        r_buf->o_max.p_uchar =
                            o_line_ptr.p_uchar + i_line_length;

                    }

                    if (
                        appl_status_ok
                        != e_status)
                    {
                        appl_heap_free(
                            p_context,
                            i_line_length,
                            o_line_ptr.p_void);
                    }
                }
            }
        }

        appl_chunk_destroy(
            p_chunk);
    }

    return
        e_status;

} /* appl_test_line_create() */

static
void
appl_test_line_destroy(
    struct appl_context * const
        p_context,
    struct appl_buf * const
        p_line_buf)
{
    unsigned long int
        i_length;

    i_length =
        (unsigned long int)(
            p_line_buf->o_max.pc_uchar
            - p_line_buf->o_min.pc_uchar);

    appl_heap_free(
        p_context,
        i_length,
        p_line_buf->o_min.p_void);

} /* appl_test_line_destroy() */

static
enum appl_status
appl_test_line_decoder(
    struct appl_context * const
        p_context,
    struct appl_buf const * const
        p_line_buf)
{
    enum appl_status
        e_status;

    (void)(
        p_context);

    /* Process a single line */
    appl_print0("echo \'");
    appl_print(
        p_line_buf->o_min.pc_uchar,
        p_line_buf->o_max.pc_uchar);
    appl_print0("\'\n");

    e_status =
        appl_status_ok;

    return
        e_status;

} /* appl_test_line_decoder() */

/*

Function: appl_test_file_stdin

Description:

    Test stdin file handle.

*/
static
void
appl_test_file_stdin(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_file *
        p_stdin_file;

    struct appl_file_descriptor
        o_stdin_file_descriptor;

    o_stdin_file_descriptor.e_type =
        appl_file_type_stdin;

    o_stdin_file_descriptor.e_mode =
        appl_file_mode_read;

    appl_print0("line parser (press ctrl+d to stop)\n");

    e_status =
        appl_file_create(
            p_context,
            &(
                o_stdin_file_descriptor),
            &(
                p_stdin_file));

    if (
        appl_status_ok
        == e_status)
    {
        char
            b_more_lines;

        b_more_lines =
            1;

        while (
            (
                appl_status_ok
                == e_status)
            && b_more_lines)
        {
            struct appl_buf
                o_line_buf;

            e_status =
                appl_test_line_create(
                    p_context,
                    p_stdin_file,
                    &(
                        o_line_buf));

            if (
                appl_status_ok
                == e_status)
            {
                /* Split line into words */
                appl_test_line_decoder(
                    p_context,
                    &(
                        o_line_buf));

                appl_test_line_destroy(
                    p_context,
                    &(
                        o_line_buf));
            }
        }

        appl_file_destroy(
            p_stdin_file);
    }

} /* appl_test_file_stdin() */

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

static void appl_test_thread(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_thread *
        p_thread;

    struct appl_queue *
        p_queue;

    struct appl_thread_property *
        p_property;

    struct appl_queue_descriptor
        o_queue_descriptor;

    struct appl_test_thread_context
        o_test_thread_context;

    struct appl_thread_descriptor
        o_thread_descriptor;

    o_queue_descriptor.i_max_count =
        1;

    e_status =
        appl_queue_create(
            p_context,
            &(
                o_queue_descriptor),
            &(
                p_queue));

    if (
        appl_status_ok
        == e_status)
    {
        o_test_thread_context.p_context =
            p_context;

        o_test_thread_context.p_queue =
            p_queue;

        appl_list_init(
            &(
                o_test_thread_context.o_dummy_result));

        o_test_thread_context.b_kill =
            0;

        appl_thread_property_create(
            p_context,
            &(
                p_property));

        o_thread_descriptor.b_callback =
            1;

        o_thread_descriptor.o_callback.p_entry =
            &(
                appl_test_thread_entry);

        o_thread_descriptor.o_callback.p_context =
            &(
                o_test_thread_context);

        e_status =
            appl_thread_create(
                p_context,
                p_property,
                &(
                    o_thread_descriptor),
                &(
                    p_thread));

        if (
            appl_status_ok
            == e_status)
        {
            char
                b_continue;

            appl_test_sleep_msec(
                p_context,
                200ul);

            b_continue =
                1;

            while (
                b_continue)
            {
                struct appl_list *
                    p_dummy_result;

                /* Use interrupt to stop the sleep */
                o_test_thread_context.b_kill =
                    1;

                appl_print0("interrupt thread\n");

                e_status =
                    appl_thread_interrupt(
                        p_thread);

                e_status =
                    appl_queue_pop(
                        p_queue,
                        &(
                            p_dummy_result),
                        1000ul,
                        1000ul);

                if (
                    appl_status_ok
                    == e_status)
                {
                    b_continue =
                        0;
                }
                else
                {
                    appl_print0("queue pop timeout\n");
                }
            }

            if (
                appl_status_ok
                == e_status)
            {
            }

            appl_thread_destroy(
                p_thread);
        }

        appl_thread_property_destroy(
            p_property);

        appl_queue_destroy(
            p_queue);
    }

}

struct appl_test_socket_descriptor
{
    char
        b_server;

}; /* struct appl_test_socket_descriptor */

static
void
appl_test_socket_fill_descriptor(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_options,
    struct appl_test_socket_descriptor * const
        p_descriptor)
{
    enum appl_status
        e_status;

    unsigned long int
        argc;

    (void)(
        p_context);

    p_descriptor->b_server =
        0;

    e_status =
        appl_options_count(
            p_options,
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
                    p_options,
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
                    p_descriptor->b_server =
                        1;
                }
            }
        }
    }
}

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

    appl_address_destroy(
        p_test_socket_connection_context->p_remote_address);

    appl_socket_destroy(
        p_test_socket_connection_context->p_remote_socket);

    appl_heap_free(
        p_test_socket_connection_context->p_context,
        (unsigned long int)(
            sizeof(
                *p_test_socket_connection_context)),
        (void *)(
            p_test_socket_connection_context));

    appl_print0("connection ...leave\n");

#if 0
    appl_thread_detach(
        p_test_socket_connection_context->p_thread);
#endif

} /* appl_test_socket_connection_thread_handler() */

static
void
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
            p_context,
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
            struct appl_thread_descriptor
                o_thread_descriptor;

            memset(
                &(
                    o_thread_descriptor),
                0,
                sizeof(
                    o_thread_descriptor));

            o_thread_descriptor.b_callback =
                1;

            o_thread_descriptor.o_callback.p_entry =
                &(
                    appl_test_socket_connection_thread_entry);

            o_thread_descriptor.o_callback.p_context =
                p_test_socket_connection_context;

            e_status =
                appl_thread_create(
                    p_context,
                    p_thread_property,
                    &(
                        o_thread_descriptor),
                    &(
                        p_test_socket_connection_context->p_thread));

            if (
                appl_status_ok
                == e_status)
            {
                b_free_connection_context =
                    0;

                if (
                    b_free_connection_context)
                {
                    appl_thread_destroy(
                        p_test_socket_connection_context->p_thread);
                }
            }

            appl_thread_property_destroy(
                p_thread_property);
        }

        if (
            b_free_connection_context)
        {
            appl_address_destroy(
                p_test_socket_connection_context->p_remote_address);

            appl_socket_destroy(
                p_test_socket_connection_context->p_remote_socket);

            appl_heap_free(
                p_context,
                (unsigned long int)(
                    sizeof(
                        struct appl_test_socket_connection_context)),
                (void *)(
                    p_test_socket_connection_context));
        }
    }
}

static
void
appl_test_socket_accept_cb(
    void * const
        p_callback_context,
    signed int const
        i_poll_flags)
{
    enum appl_status
        e_status;

    struct appl_socket *
        p_remote_socket;

    struct appl_address *
        p_remote_address;

    struct appl_socket *
        p_socket;

    struct appl_context *
        p_context;

    (void)(
        i_poll_flags);

    p_socket =
        (struct appl_socket *)(
            p_callback_context);

    p_context =
        appl_object_get_context(
            appl_socket_parent(
                p_socket));

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
    else
    {
        appl_print0("failed accept...\n");
    }

} /* appl_test_socket_accept_cb() */

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
        '7'
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

                    appl_socket_property_set_connect_timeout(
                        p_socket_descriptor,
                        100ul);
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
                        /* Setup recv and send timeouts */
                        appl_socket_property_set_recv_timeout(
                            p_socket_descriptor,
                            1000ul);

                        appl_socket_property_set_send_timeout(
                            p_socket_descriptor,
                            1000ul);

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
                                char
                                    b_found_client;

                                b_found_client =
                                    0;

                                while (
                                    !b_found_client)
                                {
                                    /* First do a poll to verify if accept is
                                    ready to be called... */

                                    struct appl_poll_descriptor
                                        a_poll_descriptor[1u];

                                    a_poll_descriptor[0u].p_socket =
                                        p_socket;

                                    a_poll_descriptor[0u].p_callback =
                                        &(
                                            appl_test_socket_accept_cb);

                                    a_poll_descriptor[0u].p_context =
                                        p_socket;

                                    a_poll_descriptor[0u].i_poll_flags =
                                        appl_poll_flag_read;

                                    e_status =
                                        appl_socket_poll(
                                            p_context,
                                            a_poll_descriptor,
                                            a_poll_descriptor + 1u,
                                            1000ul,
                                            1000ul);

                                    if (
                                        appl_status_ok
                                        == e_status)
                                    {
                                        b_found_client =
                                            1;
                                    }
                                    else
                                    {
                                        /* error or timeout */
                                    }
                                }
                            }
                            else
                            {
                                appl_test_socket_handshake(
                                    p_socket);
                            }

                            appl_socket_destroy(
                                p_socket);
                        }
                    }

                }

                appl_socket_property_destroy(
                    p_socket_descriptor);
            }
        }

        appl_address_destroy(
            p_address);
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

        appl_property_destroy(
            p_property);
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
            p_context,
            sc_home_name,
            sc_home_name + sizeof sc_home_name,
            &(
                p_home_value));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char *
            p_value_min;

        unsigned char *
            p_value_max;

        e_status =
            appl_string_get(
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

        appl_string_destroy(
            p_home_value);
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
                | appl_buf_print_flag_zero
                | appl_buf_print_flag_unsigned,
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

/*

*/
struct appl_test_tree_node
{
    struct appl_tree_node
        o_tree_node;

    char const *
        p_value;

}; /* struct appl_test_tree_node */

/*

*/
static
struct appl_test_tree_node *
appl_test_tree_node_create(
    struct appl_context * const
        p_context,
    char const * const
        p_value)
{
    enum appl_status
        e_status;

    struct appl_test_tree_node *
        p_test_tree_node;

    e_status =
        appl_heap_alloc(
            p_context,
            (unsigned long int)(
                sizeof(
                    struct appl_test_tree_node)),
            (void * *)(
                &(
                    p_test_tree_node)));

    if (
        appl_status_ok
        == e_status)
    {
        appl_tree_init(
            &(
                p_test_tree_node->o_tree_node));

        p_test_tree_node->p_value =
            p_value;
    }
    else
    {
        p_test_tree_node =
            (struct appl_test_tree_node *)(
                0);
    }

    return
        p_test_tree_node;

} /* appl_test_tree_node_create() */

static
int
appl_test_tree_compare(
    void * const
        p_context,
    struct appl_tree_node const * const
        p_tree_node_1,
    struct appl_tree_node const * const
        p_tree_node_2)
{
    int
        i_result;

    struct appl_test_tree_node const *
        p_test_tree_node_1;

    struct appl_test_tree_node const *
        p_test_tree_node_2;

    (void)(
        p_context);

    p_test_tree_node_1 =
        (struct appl_test_tree_node const *)(
            p_tree_node_1);

    p_test_tree_node_2 =
        (struct appl_test_tree_node const *)(
            p_tree_node_2);

    i_result =
        strcmp(
            p_test_tree_node_1->p_value,
            p_test_tree_node_2->p_value);

    return
        i_result;

} /* appl_test_tree_compare() */

static
void
appl_test_tree_dump(
    struct appl_context * const
        p_context,
    struct appl_tree_node const * const
        p_tree_node,
    unsigned int const
        i_level)
{
    if (
        p_tree_node)
    {
        struct appl_test_tree_node const *
            p_test_tree_node;

        p_test_tree_node =
            (struct appl_test_tree_node const *)(
                p_tree_node);

        /* Print node */
        printf(
            "%.*s (%u/%u) %s\n",
            (int)(i_level),
            "----------",
            p_test_tree_node->o_tree_node.i_count,
            p_test_tree_node->o_tree_node.i_height,
            p_test_tree_node->p_value);

        /* Print children */
        appl_test_tree_dump(
            p_context,
            p_test_tree_node->o_tree_node.p_child_left,
            i_level + 1);

        appl_test_tree_dump(
            p_context,
            p_test_tree_node->o_tree_node.p_child_right,
            i_level + 1);
    }
}

static
struct appl_tree_node *
appl_test_tree_free(
    struct appl_context * const
        p_context,
    struct appl_tree_node * const
        p_tree_node)
{
    if (
        p_tree_node)
    {
        p_tree_node->p_child_left =
            appl_test_tree_free(
                p_context,
                p_tree_node->p_child_left);

        p_tree_node->p_child_right =
            appl_test_tree_free(
                p_context,
                p_tree_node->p_child_right);

        appl_heap_free(
            p_context,
            (unsigned long int)(
                sizeof(
                    struct appl_test_tree_node)),
            (void *)(
                p_tree_node));
    }

    return
        (struct appl_tree_node *)(
            0);

}

/*

Function: appl_test_tree()

Description:
    Test tree interface.

*/
static
void
appl_test_tree(
    struct appl_context * const
        p_context)
{
    struct appl_tree_intf
        o_tree_intf;

    struct appl_tree_node *
        p_tree_root;

    o_tree_intf.p_compare =
        &(
            appl_test_tree_compare);

    o_tree_intf.p_context =
        (void *)(
            0);

    p_tree_root =
        (struct appl_tree_node *)(
            0);

    /* Attach some nodes to tree */
    {
        static char const * const a_values[] =
        {
            "a",
            "b",
            "c",
            "d",
            "e",
            "f",
            "g"
        };

        unsigned int
            i;

        i = 0u;

        while (i < sizeof(a_values) / sizeof(a_values[0u]))
        {
            struct appl_test_tree_node *
                p_test_tree_node;

            p_test_tree_node =
                appl_test_tree_node_create(
                    p_context,
                    a_values[i]);

            if (
                p_test_tree_node)
            {
                p_tree_root =
                    appl_tree_attach(
                        &(
                            o_tree_intf),
                        p_tree_root,
                        &(
                            p_test_tree_node->o_tree_node));
            }

            i++;
        }
    }

    /* Dump state of tree */
    {
        appl_test_tree_dump(
            p_context,
            p_tree_root,
            1);
    }

    /* Detach root node */
    {
        struct appl_tree_node *
            p_node;

        p_node =
            p_tree_root;

        p_tree_root =
            appl_tree_detach(
                &(
                    o_tree_intf),
                p_tree_root,
                p_node);

        appl_test_tree_dump(
            p_context,
            p_tree_root,
            1);

        appl_test_tree_free(
            p_context,
            p_node);
    }

    /* Free memory of tree */
    {
        p_tree_root =
            appl_test_tree_free(
                p_context,
                p_tree_root);
    }

} /* appl_test_tree() */

/*

*/
static
void
appl_test_thread_cache(
    struct appl_context const * const
        p_context)
{
    (void)(
        p_context);

    /* Create a thread */

    /* Reuse same thread */

    /* Create a second thread */

    /* Reuse one of the threads */

} /* appl_test_thread_cache() */

static
enum appl_status
    appl_test_main_default(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options)
{
    enum appl_status
        e_status;

    if (1)
    {
        appl_object_test_1(
            p_context);

        appl_object_test_2(
            p_context);
    }

    if (1)
    {
        appl_heap_test_1(
            p_context);
    }

    if (1)
    {
        appl_env_test_1(
            p_context);
    }

    if (1)
    {
        appl_backtrace_test_1(
            p_context);
    }

    if (1)
    {
        appl_clock_test_1(
            p_context);
    }

    if (1)
    {
        appl_mutex_test_1(
            p_context);

        appl_mutex_test_2(
            p_context);

        appl_mutex_test_3(
            p_context);
    }

    if (1)
    {
        appl_event_test_1(
            p_context);

        appl_event_test_2(
            p_context);
    }

    /* Print the argument list */
    if (1)
    {
        appl_options_test_1(
            p_context,
            p_options);
    }

    if (1)
    {
        appl_options_test_2(
            p_context);
    }

    if (1)
    {
        appl_allocator_test_1(
            p_context);
    }

#if defined APPL_HAVE_XLIB
    /* Test X11/Xlib */
    if (1)
    {
        appl_xlib_test_1(
            p_context);
    }
#endif /* #if defined APPL_HAVE_XLIB */

    /* Test memory leak */
    if (1)
    {
        appl_test_memory_leak(
            p_context);
    }

    /* Test thread */
    if (1)
    {
        appl_test_thread(
            p_context);
    }

    /* Test module */
    if (1)
    {
        appl_module_test_1(
            p_context);
    }

#if defined APPL_DEBUG
    if (1)
    {
        appl_debug_test_1(
            p_context);

        appl_debug_test_2(
            p_context);
    }
#endif /* #if defined APPL_DEBUG */

    if ((1))
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

    /* Prompt */
    if (0)
    {
        struct appl_file *
            p_file;

        struct appl_file_descriptor
            o_file_descriptor;

        o_file_descriptor.e_type =
            appl_file_type_stdin;

        o_file_descriptor.e_mode =
            appl_file_mode_read;

        appl_print0("test prompt (press ctrl+d to stop)\n");

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
            appl_test_prompt(
                p_context,
                p_file);

            appl_file_destroy(
                p_file);
        }
    }

    if ((0))
    {
        appl_test_file_stdin(
            p_context);
    }

    if ((1))
    {
        struct appl_test_socket_descriptor
            o_test_socket_descriptor;

        appl_test_socket_fill_descriptor(
            p_context,
            p_options,
            &(
                o_test_socket_descriptor));

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

    if ((1))
    {
        appl_test_library(
            p_context);
    }

    if ((1))
    {
        appl_random_test_1(
            p_context);
    }

    if (1)
    {
        appl_test_tree(
            p_context);
    }

    if ((1))
    {
        static unsigned char const s_msg[] =
        {
            'b',
            'y',
            'e'
        };

        appl_log_print(
            p_context,
            appl_log_level_info,
            s_msg,
            s_msg + sizeof(s_msg));
    }

    if (1)
    {
        /* Test of thread cache... */
        appl_test_thread_cache(
            p_context);
    }

    if (1)
    {
        appl_hash_test(
            p_context);
    }

    if (1)
    {
        char
            b_result;

        b_result =
            appl_pool_test_1(
                p_context);

        appl_print0(
            "appl_pool_test_1 : ");

        appl_print0(
            b_result
            ? "pass."
            : "FAIL!");

        appl_print0(
            "\n");

        b_result =
            appl_pool_test_2(
                p_context);

        appl_print0(
            "appl_pool_test_2 : ");

        appl_print0(
            b_result
            ? "pass."
            : "FAIL!");

        appl_print0(
            "\n");

        b_result =
            appl_pool_test_3(
                p_context);

        appl_print0(
            "appl_pool_test_3 : ");

        appl_print0(
            b_result
            ? "pass."
            : "FAIL!");

        appl_print0(
            "\n");

    }

    if (1)
    {
        appl_thread_cache_test(
            p_context);
    }

    if (1)
    {
        appl_timer_test_1(
            p_context);
    }

    if (1)
    {
        appl_binary_heap_test_1(
            p_context);
    }

    e_status =
        appl_status_ok;

    return
        e_status;

}

static
enum appl_status
appl_test_main(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_options)
{
    enum appl_status
        e_status;

    unsigned long int
        i_count;

    e_status =
        appl_options_count(
            p_options,
            &(
                i_count));

    if (
        appl_status_ok
        == e_status)
    {
        if (
            1ul
            >= i_count)
        {
            e_status =
                appl_test_main_default(
                    p_context,
                    p_options);
        }
        else
        {
            unsigned long int
                i_index;

            i_index =
                1ul;

            while (
                (
                    appl_status_ok
                    == e_status)
                && (
                    i_index
                    < i_count))
            {
                unsigned char const *
                    p_buf_min;

                unsigned char const *
                    p_buf_max;

                e_status =
                    appl_options_get(
                        p_options,
                        i_index,
                        &(
                            p_buf_min),
                        &(
                            p_buf_max));

                if (
                    appl_status_ok
                    == e_status)
                {
                    static unsigned char const g_ref_clock[] =
                    {
                        'c',
                        'l',
                        'o',
                        'c',
                        'k'
                    };

#if defined APPL_DEBUG
                    static unsigned char const g_ref_debug[] =
                    {
                        'd',
                        'e',
                        'b',
                        'u',
                        'g'
                    };
#endif /* #if defined APPL_DEBUG */

                    static unsigned char const g_ref_backtrace[] =
                    {
                        'b',
                        'a',
                        'c',
                        'k',
                        't',
                        'r',
                        'a',
                        'c',
                        'e'
                    };

                    static unsigned char const g_ref_context[] =
                    {
                        'c',
                        'o',
                        'n',
                        't',
                        'e',
                        'x',
                        't'
                    };

                    if (
                        0
                        == appl_buf_compare(
                            p_buf_min,
                            p_buf_max,
                            g_ref_clock,
                            g_ref_clock + sizeof(g_ref_clock)))
                    {
                        appl_clock_test_1(
                            p_context);
                    }
#if defined APPL_DEBUG
                    else if (
                        0
                        == appl_buf_compare(
                            p_buf_min,
                            p_buf_max,
                            g_ref_debug,
                            g_ref_debug + sizeof(g_ref_debug)))
                    {
                        appl_debug_test_1(
                            p_context);

                        appl_debug_test_2(
                            p_context);
                    }
#endif /* #if defined APPL_DEBUG */
                    else if (
                        0
                        == appl_buf_compare(
                            p_buf_min,
                            p_buf_max,
                            g_ref_backtrace,
                            g_ref_backtrace + sizeof(g_ref_backtrace)))
                    {
                        appl_backtrace_test_1(
                            p_context);
                    }
                    else if (
                        0
                        == appl_buf_compare(
                            p_buf_min,
                            p_buf_max,
                            g_ref_context,
                            g_ref_context + sizeof(g_ref_context)))
                    {
                        appl_context_test_1(
                            p_context);
                    }
                    else
                    {
                        appl_print0(
                            "unknown arg\n");
                    }

                    i_index ++;
                }
            }
        }
    }

    return
        e_status;

}

int
main(
    int argc,
    char** argv)
{
    return
        appl_main(
            argc,
            argv,
            &(
                appl_test_main));
}

#else /* #if defined APPL_BUILD_EXE */

typedef void appl_dummy;

#endif /* #if defined APPL_BUILD_EXE */

/* end-of-file: appl_test.c */
