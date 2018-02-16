/* See LICENSE for license details */

/* Include unistd.h for usleep() function */
#define _BSD_SOURCE
#include <unistd.h>

#include <stdio.h>

#include "appl.h"

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

    e_status =
        appl_clock_delay(
            p_context_handle,
            1000ul,
            i_msec_count);

    if (
        appl_status_not_implemented
        == e_status)
    {
        printf("fallback sleep\n");

        usleep(
            (useconds_t)(
                i_msec_count * 1000ul));
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

    printf(
        "hello world!\n");

    appl_test_sleep_msec(
        p_test_thread_context->p_context_handle,
        100ul);

    appl_mutex_lock(
        p_test_thread_context->p_mutex_handle);

    printf(
        "thread wait 2 sec...\n");

    appl_test_sleep_msec(
        p_test_thread_context->p_context_handle,
        2000ul);

    printf(
        "... thread wait 2 sec\n");

    appl_mutex_unlock(
        p_test_thread_context->p_mutex_handle);

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

    printf("msg = [%.*s]\n",
        (int)(o_buf.o_min.p_uchar - s_msg),
        s_msg);
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
            printf(
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

    /* Test memory leak */
    {
        appl_test_memory_leak(
            p_context_handle);
    }

    /* Test thread */
    {
        struct appl_thread_handle *
            p_thread_handle;

        struct appl_mutex_handle *
            p_mutex_handle;

        struct appl_thread_descriptor
            o_thread_descriptor;

        struct appl_mutex_descriptor
            o_mutex_descriptor;

        struct appl_test_thread_context
            o_test_thread_context;

        appl_mutex_create(
            p_context_handle,
            &(
                o_mutex_descriptor),
            &(
                p_mutex_handle));

        o_test_thread_context.p_context_handle =
            p_context_handle;

        o_test_thread_context.p_mutex_handle =
            p_mutex_handle;

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
                500ul);

            appl_mutex_lock(
                p_mutex_handle);

            printf(
                "main sleep 2 sec ...\n");

            appl_test_sleep_msec(
                p_context_handle,
                2000ul);

            printf(
                "... main sleep 2 sec\n");

            appl_mutex_unlock(
                p_mutex_handle);

            e_status =
                appl_thread_wait_result(
                    p_thread_handle,
                    &(
                        p_thread_result));

            if (
                appl_status_ok
                == e_status)
            {
                printf(
                    "thread result = %p\n",
                    p_thread_result);
            }

            appl_object_destroy(
                &(
                    p_thread_handle->o_object_handle));

            appl_object_destroy(
                &(
                    p_mutex_handle->o_object_handle));
        }
    }

    if (0)
    {
        appl_debug_break(
            p_context_handle);
    }

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
                printf(
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
