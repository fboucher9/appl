/* See LICENSE for license details */

/* Include unistd.h for usleep() function */
#include <stdarg.h>

#include <unistd.h>

#include <stdio.h>

#include <appl.h>

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

    appl_printf(
        "hello world!\n");

    appl_test_sleep_msec(
        p_test_thread_context->p_context,
        100ul);

    appl_mutex_lock(
        p_test_thread_context->p_mutex);

    appl_printf(
        "thread wait 1 sec...\n");

    appl_test_sleep_msec(
        p_test_thread_context->p_context,
        1000ul);

    appl_printf(
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

            appl_printf(
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

            appl_printf(
                "main sleep 1 sec ...\n");

            appl_test_sleep_msec(
                p_context,
                1000ul);

            appl_printf(
                "... main sleep 1 sec\n");

            appl_mutex_unlock(
                p_mutex);
#endif

#if 0
            /* Wait for event */
            appl_mutex_lock(
                p_mutex);

            appl_printf(
                "wait for event...\n");

            while (!(o_test_thread_context.b_event_signaled))
            {
                appl_event_wait(
                    p_event,
                    p_mutex);
            }

            appl_printf(
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
                appl_printf(
                    "thread result = %p\n",
                    p_thread_result);
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

static
void
appl_test_socket(
    struct appl_context * const
        p_context)
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

            p_name_cur =
                a_name;

            e_status =
                appl_address_get_name(
                    p_address,
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
                    p_address,
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
            struct appl_property *
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
                e_status =
                    appl_socket_property_set_bind_address(
                        p_socket_descriptor,
                        p_address);

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
                        appl_object_destroy(
                            appl_socket_parent(
                                p_socket));
                    }

                }

                appl_object_destroy(
                    appl_property_parent(
                        p_socket_descriptor));
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
                    p_property,
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
                    p_property,
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
            appl_string_parent(
                p_home_value));
    }
    else
    {
        appl_printf(
            "appl_test_env: failed env get\n");
    }

} /* appl_test_env() */

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
            p_context);
    }

    if (1)
    {
        appl_test_socket(
            p_context);
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

    e_status =
        appl_status_ok;

    return
        e_status;

}
