/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include "appl_status.h"

#include "appl_object.h"

#include "appl_thread_node.h"

#include "appl_thread_std_node.h"

#include "appl_thread_descriptor.h"

//
//
//
enum appl_status
    appl_thread_std_node::create_instance(
        class appl_client * const
            p_client,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        class appl_thread_node * * const
            r_thread_node)
{
    enum appl_status
        e_status;

    class appl_thread_std_node *
        p_thread_std_node;

    static_cast<void>(
        p_client);

    p_thread_std_node =
        new
            class appl_thread_std_node;

    if (
        p_thread_std_node)
    {
        int
            i_external_result;

        i_external_result =
            pthread_create(
                &(
                    p_thread_std_node->p_external_thread_handle),
                NULL,
                p_thread_descriptor->p_entry,
                p_thread_descriptor->p_context);

        if (
            0
            == i_external_result)
        {
            *(
                r_thread_node) =
                p_thread_std_node;

            e_status =
                appl_status_ok;
        }
        else
        {
            delete
                p_thread_std_node;

            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_thread_std_node::appl_thread_std_node() :
    appl_thread_node(),
    p_external_thread_handle()
{
}

//
//
//
appl_thread_std_node::~appl_thread_std_node()
{
}

enum appl_status
    appl_thread_std_node::wait_result(
        class appl_client * const
            p_client,
        void * * const
            r_result)
{
    enum appl_status
        e_status;

    void *
        p_result;

    int
        i_external_result;

    static_cast<void>(
        p_client);

    i_external_result =
        pthread_join(
            p_external_thread_handle,
            &(
                p_result));

    if (
        0
        == i_external_result)
    {
        *(
            r_result) =
            p_result;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // wait_result()

//
//
//
enum appl_status
    appl_thread_std_node::detach(
        class appl_client * const
            p_client)
{
    enum appl_status
        e_status;

    int
        i_external_result;

    static_cast<void>(
        p_client);

    i_external_result =
        pthread_detach(
            p_external_thread_handle);

    if (
        0
        == i_external_result)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // detach()

/* end-of-file: appl_thread_std_node.cpp */
