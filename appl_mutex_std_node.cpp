/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_mutex_node.h"

#include "appl_mutex_std_node.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_mutex_std_node::create_instance(
        class appl_context * const
            p_context,
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        class appl_mutex_node * * const
            r_mutex_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::create_instance(
            p_context,
            sizeof(
                class appl_mutex_std_node),
            &(
                appl_mutex_std_node::placement_new),
            static_cast<void const *>(
                p_mutex_descriptor),
            reinterpret_cast<class appl_object * *>(
                r_mutex_node));

    return
        e_status;

} // create_instance()

//
//
//
appl_mutex_std_node::appl_mutex_std_node() :
    appl_mutex_node(),
    m_pthread_mutex_storage(),
    m_pthread_mutex_initialized()
{
}

//
//
//
appl_mutex_std_node::~appl_mutex_std_node()
{
}

//
//
//
void
    appl_mutex_std_node::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_mutex_std_node;

} // placement_new()

//
//
//
enum appl_status
    appl_mutex_std_node::init(
        void const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    int
        i_pthread_result;

    static_cast<void>(
        p_descriptor);

    i_pthread_result =
        pthread_mutex_init(
            &(
                m_pthread_mutex_storage),
            NULL);

    if (
        0
        == i_pthread_result)
    {
        m_pthread_mutex_initialized =
            true;

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

} // init()

//
//
//
enum appl_status
    appl_mutex_std_node::cleanup(void)
{
    enum appl_status
        e_status;

    if (
        m_pthread_mutex_initialized)
    {
        pthread_mutex_destroy(
            &(
                m_pthread_mutex_storage));

        m_pthread_mutex_initialized =
            false;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
    appl_mutex_std_node::v_lock(void)
{
    enum appl_status
        e_status;

    int
        i_pthread_result;

    i_pthread_result =
        pthread_mutex_lock(
            &(
                m_pthread_mutex_storage));

    if (
        0
        == i_pthread_result)
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

} // v_lock()

//
//
//
enum appl_status
    appl_mutex_std_node::v_unlock(void)
{
    enum appl_status
        e_status;

    int
        i_pthread_result;

    i_pthread_result =
        pthread_mutex_unlock(
            &(
                m_pthread_mutex_storage));

    if (
        0
        == i_pthread_result)
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

} // v_unlock()

/* end-of-file: appl_mutex_std_node.cpp */
