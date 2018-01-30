/* See LICENSE for license details */

#include <stdio.h>

#include "appl.h"

#include "appl_object.h"

#include "appl_client.h"

#include "appl_thread_node.h"

#include "appl_thread_mgr.h"

#include "appl_thread_std_mgr.h"

#include "appl_thread_descriptor.h"

static
void *
appl_thread_test_cb(
    void * const
        p_context)
{
    static_cast<void>(
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

    class appl_client *
        p_client;

    class appl_thread_mgr *
        p_thread_mgr;

    static_cast<void>(
        p_options_descriptor);

    p_client =
        reinterpret_cast<class appl_client *>(
            p_context);

    e_status =
        appl_thread_std_mgr::create_instance(
            p_client,
            &(
                p_thread_mgr));
    if (
        appl_status_ok
        == e_status)
    {
        class appl_thread_node *
            p_thread_node;

        struct appl_thread_descriptor
            o_thread_descriptor;

        o_thread_descriptor.p_entry =
            &(
                appl_thread_test_cb);

        o_thread_descriptor.p_context =
            0;

        e_status =
            p_thread_mgr->create_node(
                p_client,
                &(
                    o_thread_descriptor),
                &(
                    p_thread_node));

        if (
            appl_status_ok
            == e_status)
        {
            void *
                p_result;

            e_status =
                p_thread_node->wait_result(
                    p_client,
                    &(
                        p_result));

            if (
                appl_status_ok
                == e_status)
            {
                printf(
                    "result = %p\n",
                        p_result);
            }

            p_thread_node->destroy();
        }

        p_thread_mgr->destroy();
    }

    *(p_exit_code) = 0;

    return e_status;
}

