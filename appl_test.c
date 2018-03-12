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
        p_context_handle,
        1000ul,
        &(
            i_time_before));

    e_status =
        appl_clock_delay(
            p_context_handle,
            1000ul,
            i_msec_count);

    appl_clock_read(
        p_context_handle,
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
    struct appl_buf
        o_buf;

    enum appl_status
        e_status;

    e_status =
        appl_heap_alloc(
            p_context_handle,
            &(
                o_buf),
            123u);

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

    o_file_descriptor.o_name.o_min.p_void =
        (void *)(
            0);

    o_file_descriptor.o_name.o_max.p_void =
        (void *)(
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

        struct appl_buf
            o_msg;

        o_msg.o_min.pc_uchar =
            g_msg;

        o_msg.o_max.pc_uchar =
            g_msg + sizeof(g_msg);

        e_status =
            appl_file_write(
                p_file_handle,
                &(
                    o_msg));

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

    struct appl_buf
        o_buf;

    o_buf.o_min.p_uchar = s_msg;
    o_buf.o_max.p_uchar = s_msg + sizeof s_msg;

    appl_buf_print_number(
        &(
            o_buf),
        i_value,
        i_flags);

    appl_printf("msg = [%.*s]\n",
        (int)(o_buf.o_min.p_uchar - s_msg),
        s_msg);
}

static void appl_test_options(
    struct appl_options_descriptor const * const
        p_options_descriptor)
{
    struct appl_buf *
        p_buf_it;

    unsigned int
        argi;

    p_buf_it =
        p_options_descriptor->p_buf_min;

    argi = 0;

    while (
        p_buf_it < p_options_descriptor->p_buf_max)
    {
        appl_printf(
            "[%3u] [%.*s]\n",
            argi,
            (int)(
                p_buf_it->o_max.pc_uchar
                - p_buf_it->o_min.pc_uchar),
            (char const *)(
                p_buf_it->o_min.pc_uchar));

        argi ++;

        p_buf_it ++;
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

    struct appl_thread_descriptor
        o_thread_descriptor;

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

    o_thread_descriptor.p_entry =
        &(
            appl_test_thread_entry);

    o_thread_descriptor.p_context =
        &(
            o_test_thread_context);

    e_status =
        appl_thread_create(
            p_context_handle,
            &(
                o_thread_descriptor),
            &(
                p_thread_handle));

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

        /* Use interrupt to stop the sleep */
        o_test_thread_context.b_kill =
            1;

        e_status =
            appl_thread_interrupt(
                p_thread_handle);

        e_status =
            appl_thread_wait_result(
                p_thread_handle,
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

        appl_object_destroy(
            &(
                p_thread_handle->o_object_handle));
    }

    appl_object_destroy(
        &(
            p_event_handle->o_object_handle));

    appl_object_destroy(
        &(
            p_mutex_handle->o_object_handle));

}

enum appl_status
appl_main(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_options_descriptor const * const
        p_options_descriptor,
    int * const
        p_exit_code)
{
    enum appl_status
        e_status;

    /* Print the argument list */
    {
        appl_test_options(
            p_options_descriptor);
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

            struct appl_buf
                o_msg;

            o_msg.o_min.pc_uchar = g_msg;
            o_msg.o_max.pc_uchar = g_msg + sizeof(g_msg);

            appl_debug_print(
                p_context_handle,
                &(o_msg));

            appl_debug_break(
                p_context_handle);
        }
    }
#endif /* #if defined APPL_DEBUG */

    if (1)
    {
        /* test read */
        if (1)
        {
            static unsigned char g_data[] =
            {
                1,
                2,
                3,
                4,
                5
            };

            struct appl_buf
                o_buf;

            unsigned char
                c_value;

            o_buf.o_min.pc_uchar =
                g_data;

            o_buf.o_max.pc_uchar =
                g_data + sizeof(g_data);

            while (
                appl_status_ok
                == appl_buf_read(
                    &(
                        o_buf),
                    &(
                        c_value)))
            {
                appl_printf(
                    "%u\n",
                    (unsigned int)(
                        c_value));
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

    *(
        p_exit_code) =
        0;

    e_status =
        appl_status_ok;

    return
        e_status;

}
