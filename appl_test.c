/* See LICENSE for license details */

/* Include unistd.h for usleep() function */
#include <stdarg.h>

#include <unistd.h>

#include <stdio.h>

#include "appl.h"

#if defined __GNUC__ && ! defined __clang__
#pragma GCC diagnostic ignored "-Wsuggest-attribute=format"
#endif
static
void
appl_printf(
    char const * const
        p_format, ...)
{
    va_list
        o_args;

    va_start(
        o_args, p_format);

#if defined __clang__
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#endif
    vfprintf(stdout, p_format, o_args);
#if defined __clang__
#pragma GCC diagnostic warning "-Wformat-nonliteral"
#endif
    fflush(stdout);

    va_end(
        o_args);

}
#if defined __GNUC__ && ! defined __clang__
#pragma GCC diagnostic warning "-Wsuggest-attribute=format"
#endif

static
void
appl_test_sleep_msec(
    struct appl_context_handle * const
        p_context_handle,
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
        &(
            p_context_handle->o_object_handle),
        1000ul,
        &(
            i_time_before));

    e_status =
        appl_clock_delay(
            &(
                p_context_handle->o_object_handle),
            1000ul,
            i_msec_count);

    appl_clock_read(
        &(
            p_context_handle->o_object_handle),
        1000ul,
        &(
            i_time_after));

    appl_printf(
        "sleep %lu msec took %ld msec\n",
        i_msec_count,
        (
            i_time_after
            - i_time_before));

    if (
        appl_status_not_implemented
        == e_status)
    {
        appl_printf("fallback sleep\n");

        usleep(
            (unsigned int)(
                i_msec_count * 1000u));
    }

}

static
void
appl_test_memory_leak(
    struct appl_context_handle * const
        p_context_handle)
{
    void *
        p_buf;

    enum appl_status
        e_status;

    e_status =
        appl_heap_alloc(
            &(
                p_context_handle->o_object_handle),
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
    struct appl_context_handle *
        p_context_handle;

    struct appl_mutex_handle *
        p_mutex_handle;

    struct appl_event_handle *
        p_event_handle;

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

    appl_printf(
        "hello world!\n");

    appl_test_sleep_msec(
        p_test_thread_context->p_context_handle,
        100ul);

    appl_mutex_lock(
        p_test_thread_context->p_mutex_handle);

    appl_printf(
        "thread wait 1 sec...\n");

    appl_test_sleep_msec(
        p_test_thread_context->p_context_handle,
        1000ul);

    appl_printf(
        "... thread wait 1 sec\n");

    appl_mutex_unlock(
        p_test_thread_context->p_mutex_handle);

    if (!(p_test_thread_context->b_kill))
    {
        appl_test_sleep_msec(
            p_test_thread_context->p_context_handle,
            1000ul);

        if (!(p_test_thread_context->b_kill))
        {
            appl_mutex_lock(
                p_test_thread_context->p_mutex_handle);

            appl_printf(
                "signal event!\n");

            p_test_thread_context->b_event_signaled =
                1;

            appl_event_signal(
                p_test_thread_context->p_event_handle);

            appl_mutex_unlock(
                p_test_thread_context->p_mutex_handle);
        }
    }

    return
        (void *)(0x1234);

} /* appl_test_thread_entry() */

static
void
appl_test_file_stdout(
    struct appl_context_handle * const
        p_context_handle)
{
    struct appl_file_handle *
        p_file_handle;

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
            p_context_handle,
            &(
                o_file_descriptor),
            &(
                p_file_handle));

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
                p_file_handle,
                g_msg,
                g_msg + sizeof(g_msg),
                &(
                    i_count));

        appl_object_destroy(
            &(
                p_file_handle->o_object_handle));
    }

}

static
void
appl_test_print_number(
    signed long int const
        i_value,
    unsigned long int const
        i_flags)
{
    static unsigned char s_msg[128u];

    unsigned char *
        p_msg_end;

    p_msg_end =
        appl_buf_print_number(
            s_msg,
            s_msg + sizeof s_msg,
            i_value,
            i_flags);

    appl_printf("msg = [%.*s]\n",
        (int)(p_msg_end - s_msg),
        s_msg);
}

static void appl_test_options(
    struct appl_context_handle * const
        p_context_handle)
{
    enum appl_status
        e_status;

    unsigned long int
        argc;

    unsigned long int
        argi;

    e_status =
        appl_options_count(
            &(
                p_context_handle->o_object_handle),
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
                &(
                    p_context_handle->o_object_handle),
                argi,
                &(
                    p_buf_min),
                &(
                    p_buf_max));

        if (
            appl_status_ok == e_status)
        {
            appl_printf(
                "[%3u] [%.*s]\n",
                argi,
                (int)(
                    p_buf_max
                    - p_buf_min),
                (char const *)(
                    p_buf_min));
        }

        argi ++;
    }
}

static void appl_test_thread(
    struct appl_context_handle * const
        p_context_handle)
{
    enum appl_status
        e_status;

    struct appl_thread_handle *
        p_thread_handle;

    struct appl_mutex_handle *
        p_mutex_handle;

    struct appl_event_handle *
        p_event_handle;

    struct appl_thread_property_handle *
        p_property_handle;

    struct appl_mutex_descriptor
        o_mutex_descriptor;

    struct appl_event_descriptor
        o_event_descriptor;

    struct appl_test_thread_context
        o_test_thread_context;

    appl_mutex_create(
        p_context_handle,
        &(
            o_mutex_descriptor),
        &(
            p_mutex_handle));

    appl_event_create(
        p_context_handle,
        &(
            o_event_descriptor),
        &(
            p_event_handle));

    o_test_thread_context.p_context_handle =
        p_context_handle;

    o_test_thread_context.p_mutex_handle =
        p_mutex_handle;

    o_test_thread_context.p_event_handle =
        p_event_handle;

    o_test_thread_context.b_event_signaled =
        0;

    o_test_thread_context.b_kill =
        0;

    appl_thread_property_create(
        p_context_handle,
        &(
            p_property_handle));

    appl_thread_property_set_callback(
        p_property_handle,
        &(
            appl_test_thread_entry));

    appl_thread_property_set_context(
        p_property_handle,
        &(
            o_test_thread_context));

    e_status =
        appl_thread_create(
            &(
                p_context_handle->o_object_handle),
            p_property_handle,
            &(
                p_thread_handle));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_thread_start(
                p_thread_handle);

        if (
            appl_status_ok
            == e_status)
        {
            void *
                p_thread_result;

            appl_test_sleep_msec(
                p_context_handle,
                200ul);

#if 0
            appl_mutex_lock(
                p_mutex_handle);

            appl_printf(
                "main sleep 1 sec ...\n");

            appl_test_sleep_msec(
                p_context_handle,
                1000ul);

            appl_printf(
                "... main sleep 1 sec\n");

            appl_mutex_unlock(
                p_mutex_handle);
#endif

#if 0
            /* Wait for event */
            appl_mutex_lock(
                p_mutex_handle);

            appl_printf(
                "wait for event...\n");

            while (!(o_test_thread_context.b_event_signaled))
            {
                appl_event_wait(
                    p_event_handle,
                    p_mutex_handle);
            }

            appl_printf(
                "... wait done.\n");

            appl_mutex_unlock(
                p_mutex_handle);
#endif

#if 1
            /* Use interrupt to stop the sleep */
            o_test_thread_context.b_kill =
                1;

            e_status =
                appl_thread_interrupt(
                    p_thread_handle);
#endif

            e_status =
                appl_thread_stop(
                    p_thread_handle,
                    1,
                    1,
                    &(
                        p_thread_result));

            if (
                appl_status_ok
                == e_status)
            {
                appl_printf(
                    "thread result = %p\n",
                    p_thread_result);
            }
        }

        appl_object_destroy(
            &(
                p_thread_handle->o_object_handle));
    }

    appl_object_destroy(
        &(
            p_property_handle->o_property_handle.o_object_handle));

    appl_object_destroy(
        &(
            p_event_handle->o_object_handle));

    appl_object_destroy(
        &(
            p_mutex_handle->o_object_handle));

}

static
void
appl_test_socket(
    struct appl_context_handle * const
        p_context_handle)
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
        '0'
    };

    enum appl_status
        e_status;

    struct appl_address_handle *
        p_address_handle;

    {
        struct appl_property_handle *
            p_address_descriptor;

        appl_address_property_create(
            p_context_handle,
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
                p_context_handle,
                p_address_descriptor,
                &(
                    p_address_handle));

        appl_object_destroy(
            &(
                p_address_descriptor->o_object_handle));
    }

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_socket_handle *
            p_socket_handle;

        {
            unsigned char
                a_name[64u];

            unsigned char *
                p_name_cur;

            p_name_cur =
                a_name;

            e_status =
                appl_address_get_name(
                    p_address_handle,
                    &(
                        p_name_cur),
                    a_name + sizeof a_name);

            if (
                appl_status_ok
                == e_status)
            {
                appl_printf(
                    "name=[%.*s]\n",
                    (int)(
                        p_name_cur
                        - a_name),
                    (char const *)(
                        a_name));
            }
        }

        {
            unsigned short int
                i_port;

            e_status =
                appl_address_get_port(
                    p_address_handle,
                    &(
                        i_port));

            if (
                appl_status_ok
                == e_status)
            {
                appl_printf(
                    "port=[%u]\n",
                    (unsigned int)(
                        i_port));
            }
        }

        {
            struct appl_property_handle *
                p_socket_descriptor;

            e_status =
                appl_socket_property_create(
                    p_context_handle,
                    &(
                        p_socket_descriptor));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_socket_property_set_bind_address(
                        p_socket_descriptor,
                        p_address_handle);

                if (
                    appl_status_ok
                    == e_status)
                {
                    e_status =
                        appl_socket_create(
                            p_context_handle,
                            p_socket_descriptor,
                            &(
                                p_socket_handle));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        appl_object_destroy(
                            &(
                                p_socket_handle->o_object_handle));
                    }

                }

                appl_object_destroy(
                    &(
                        p_socket_descriptor->o_object_handle));
            }
        }

        appl_object_destroy(
            &(
                p_address_handle->o_object_handle));
    }

} /* appl_test_socket() */

static
void
appl_test_property(
    struct appl_context_handle * const
        p_context_handle)
{
    enum appl_status
        e_status;

    struct appl_property_handle *
        p_property_handle;

    e_status =
        appl_property_create(
            p_context_handle,
            3,
            &(
                p_property_handle));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_property_set_ptr(
                p_property_handle,
                0,
                (void *)(
                    7777));

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
                p_property_handle,
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
                p_property_handle,
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
                    p_property_handle,
                    0,
                    &(
                        p_value));

            if (
                appl_status_ok
                == e_status)
            {
                appl_printf(
                    "property 0=%p\n",
                    p_value);
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
                    p_property_handle,
                    1,
                    &(
                        u_value));

            if (
                appl_status_ok
                == e_status)
            {
                appl_printf(
                    "property 1=%lu\n",
                    u_value);
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
                    p_property_handle,
                    2,
                    &(
                        i_value));

            if (
                appl_status_ok
                == e_status)
            {
                appl_printf(
                    "property 2=%ld\n",
                    i_value);
            }
            else
            {
            }
        }

        appl_object_destroy(
            &(
                p_property_handle->o_object_handle));
    }

} /* appl_test_property() */

static
void
appl_test_env(
    struct appl_context_handle * const
        p_context_handle)
{
    struct appl_string_handle *
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
            &(
                p_context_handle->o_object_handle),
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
            appl_printf(
                "appl_test_env: home=[%.*s]\n",
                (int)(
                    p_value_max
                    - p_value_min),
                (char const *)(
                    p_value_min));
        }
        else
        {
            appl_printf(
                "appl_test_env: failed string read\n");
        }

        appl_object_destroy(
            &(
                p_home_value->o_object_handle));
    }
    else
    {
        appl_printf(
            "appl_test_env: failed env get\n");
    }

} /* appl_test_env() */

enum appl_status
appl_main(
    struct appl_context_handle * const
        p_context_handle)
{
    enum appl_status
        e_status;

    /* Print the argument list */
    {
        appl_test_options(
            p_context_handle);
    }

    /* Test memory leak */
    {
        appl_test_memory_leak(
            p_context_handle);
    }

    /* Test thread */
    {
        appl_test_thread(
            p_context_handle);
    }

#if defined APPL_DEBUG
    {
        static char g_test_debug_break = 0;

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
                &(
                    p_context_handle->o_object_handle),
                g_msg,
                g_msg + sizeof(g_msg));

            appl_debug_break(
                &(
                    p_context_handle->o_object_handle));
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

                appl_printf(
                    "%u\n",
                    (unsigned int)(
                        c_value));

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
                0);

            appl_test_print_number(
                123456789l,
                APPL_BUF_PRINT_SIGN_SPACE | 0);

            appl_test_print_number(
                123456789l,
                APPL_BUF_PRINT_SIGN_PLUS | 0);

            appl_test_print_number(
                123456789l,
                20);

            appl_test_print_number(
                123456789l,
                APPL_BUF_PRINT_SIGN_SPACE | 20);

            appl_test_print_number(
                123456789l,
                APPL_BUF_PRINT_SIGN_PLUS | 20);

            appl_test_print_number(
                123456789l,
                APPL_BUF_PRINT_PAD_ZERO | 20);

            appl_test_print_number(
                123456789l,
                APPL_BUF_PRINT_SIGN_SPACE | APPL_BUF_PRINT_PAD_ZERO | 20);

            appl_test_print_number(
                123456789l,
                APPL_BUF_PRINT_SIGN_PLUS | APPL_BUF_PRINT_PAD_ZERO | 20);

            appl_test_print_number(
                123456789l,
                APPL_BUF_PRINT_ALIGN_LEFT | 20);

            appl_test_print_number(
                -123456789l,
                0);

            appl_test_print_number(
                -123456789l,
                20);

            appl_test_print_number(
                -123456789l,
                APPL_BUF_PRINT_UNSIGNED | APPL_BUF_PRINT_HEXADECIMAL | 20);

        }
    }

    if (1)
    {
        appl_test_file_stdout(
            p_context_handle);
    }

    if (1)
    {
        appl_test_socket(
            p_context_handle);
    }

    if (1)
    {
        appl_test_property(
            p_context_handle);
    }

    if (1)
    {
        appl_test_env(
            p_context_handle);
    }

    e_status =
        appl_status_ok;

    return
        e_status;

}
