/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#if defined APPL_OS_LINUX

#include <signal.h>

#endif /* #if defined APPL_OS_LINUX */

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

    class appl_thread_std_node *
        p_thread_std_node;

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_thread_std_node),
            &(
                appl_thread_std_node::placement_new),
            p_thread_descriptor,
            &(
                p_thread_std_node));

    if (
        appl_status_ok
        == e_status)
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

#if defined APPL_OS_LINUX

/*

*/
static
void
dummy_urgent_signal_handler(
    int
        i_unused)
{
    static_cast<void>(
        i_unused);
} /* dummy_urgent_signal_handler() */

#endif /* #if defined APPL_OS_LINUX */

//
//
//
enum appl_status
    appl_thread_std_node::interrupt(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    // setup SIGURG handler
    struct sigaction
        o_new_action;

    struct sigaction
        o_old_action;

    o_new_action.sa_handler =
        &(
            dummy_urgent_signal_handler);

    sigemptyset(
        &(
            o_new_action.sa_mask));

    o_new_action.sa_flags = 0;

    int
        i_sigaction_result;

    i_sigaction_result =
        sigaction(
            SIGURG,
            &(
                o_new_action),
            &(
                o_old_action));

    if (
        0
        == i_sigaction_result)
    {
        int
            i_external_result;

        i_external_result =
            pthread_kill(
                p_external_thread_handle,
                SIGURG);

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
    }
    else
    {
        e_status =
            appl_status_fail;
    }

#elif defined APPL_OS_WINDOWS

    e_status =
        appl_status_not_implemented;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // interrupt()

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
