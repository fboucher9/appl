/* See LICENSE for license details */

#include <stdio.h>

#include "appl.h"

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

static
void *
appl_test_thread_entry(
    void * const
        p_context)
{
    (void)(
        p_context);

    printf(
        "hello world!\n");

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

        unsigned long int
            i_actual_len;

        e_status =
            appl_file_write(
                p_file_handle,
                g_msg,
                sizeof(
                    g_msg),
                &(
                    i_actual_len));

        appl_object_destroy(
            &(
                p_file_handle->o_object_handle));
    }

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

        struct appl_thread_descriptor
            o_thread_descriptor;

        o_thread_descriptor.p_entry =
            &(
                appl_test_thread_entry);

        o_thread_descriptor.p_context =
            p_context_handle;

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
