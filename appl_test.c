/* See LICENSE for license details */

#include <stdio.h>

#include "appl.h"

static
void *
appl_thread_test_cb(
    void * const
        p_context)
{
    (void)(
        p_context);

    printf(
        "hello world!\n");

    return
        (void *)(0x1234);

} /* appl_thread_test_cb() */

enum appl_status
appl_main(
    struct appl_context_handle * const
        p_context,
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

    /* Test thread */
    {
        struct appl_thread_handle *
            p_thread_handle;

        struct appl_thread_descriptor
            o_thread_descriptor;

        o_thread_descriptor.p_entry =
            &(
                appl_thread_test_cb);

        o_thread_descriptor.p_context =
            p_context;

        e_status =
            appl_thread_create(
                p_context,
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

    *(
        p_exit_code) =
        0;

    e_status =
        appl_status_ok;

    return
        e_status;

}
