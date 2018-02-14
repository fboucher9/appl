/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_thread_node.h"

#include "appl_thread_std_node.h"

#include "appl_thread_descriptor.h"

//
//
//
enum appl_status
    appl_thread_std_node::create_instance(
        class appl_context * const
            p_context,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        class appl_thread_node * * const
            r_thread_node)
{
    enum appl_status
        e_status;

    class appl_object *
        p_object;

    e_status =
        appl_object::create_instance(
            p_context,
            sizeof(
                class appl_thread_std_node),
            &(
                appl_thread_std_node::placement_new),
            static_cast<void const *>(
                p_thread_descriptor),
            &(
                p_object));

    if (
        appl_status_ok
        == e_status)
    {
        class appl_thread_std_node *
            p_thread_std_node;

        p_thread_std_node =
            reinterpret_cast<class appl_thread_std_node *>(
                p_object);

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
            p_thread_std_node->destroy();

            e_status =
                appl_status_fail;
        }
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
        void * * const
            r_result)
{
    enum appl_status
        e_status;

    void *
        p_result;

    int
        i_external_result;

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
    appl_thread_std_node::detach(void)
{
    enum appl_status
        e_status;

    int
        i_external_result;

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

//
//
//
void
    appl_thread_std_node::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_thread_std_node;

} // placement_new()

/* end-of-file: appl_thread_std_node.cpp */
