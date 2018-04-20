/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#if defined APPL_OS_WINDOWS

#include <pthread_time.h>

#else /* */

#include <time.h>

#endif /* */

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_event_node.h>

#include <appl_event_std_node.h>

#include <appl_mutex_node.h>

#include <appl_mutex_std_node.h>

#include <appl_unused.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_event_std_node::s_create(
        struct appl_context * const
            p_context,
        struct appl_event_descriptor const * const
            p_event_descriptor,
        struct appl_event * * const
            r_event_node)
{
    enum appl_status
        e_status;

    appl_unused(
        p_event_descriptor);

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_event_std_node),
            (&
                appl_event_std_node::s_new),
            (&
                appl_event_std_node::init),
            r_event_node);

    return
        e_status;

} // create_instance()

//
//
//
appl_event_std_node::appl_event_std_node() :
    appl_event(),
    m_pthread_event_storage(),
    m_pthread_event_initialized()
{
}

//
//
//
appl_event_std_node::~appl_event_std_node()
{
}

//
//
//
void
    appl_event_std_node::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_event_std_node;

} // s_new()

//
//
//
enum appl_status
    appl_event_std_node::init(void)
{
    enum appl_status
        e_status;

    int
        i_pthread_result;

    i_pthread_result =
        pthread_cond_init(
            &(
                m_pthread_event_storage),
            NULL);

    if (
        0
        == i_pthread_result)
    {
        m_pthread_event_initialized =
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
    appl_event_std_node::v_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        m_pthread_event_initialized)
    {
        pthread_cond_destroy(
            &(
                m_pthread_event_storage));

        m_pthread_event_initialized =
            false;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

//
//
//
enum appl_status
    appl_event_std_node::v_signal(void)
{
    enum appl_status
        e_status;

    int
        i_pthread_result;

    i_pthread_result =
        pthread_cond_signal(
            &(
                m_pthread_event_storage));

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

} // v_signal()

//
//
//
enum appl_status
    appl_event_std_node::v_wait(
        struct appl_mutex * const
            p_mutex_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    class appl_mutex_std_node *
        p_mutex_std_node;

    p_mutex_std_node =
        static_cast<class appl_mutex_std_node *>(
            p_mutex_node);

    int
        i_clock_result;

    struct timespec
        o_now;

    i_clock_result =
        clock_gettime(
            CLOCK_REALTIME,
            &(
                o_now));

    if (
        0
        == i_clock_result)
    {
        appl_ull_t
            i_abstime;

        i_abstime =
            static_cast<appl_ull_t>(
                (
                 static_cast<appl_ull_t>(
                     o_now.tv_sec)
                 * 1000000000ul)
                + static_cast<appl_ull_t>(
                    o_now.tv_nsec)
                + (
                    (
                        static_cast<appl_ull_t>(
                            i_wait_count)
                        * 1000000000ul)
                    / i_wait_freq));

        /* Default timeout ... */
        struct timespec
            o_abstime;

        o_abstime.tv_sec =
            static_cast<time_t>(
                i_abstime / 1000000000ul);

        o_abstime.tv_nsec =
            static_cast<signed long int>(
                i_abstime % 1000000000ul);

        int
            i_pthread_result;

        i_pthread_result =
            pthread_cond_timedwait(
                &(
                    m_pthread_event_storage),
                &(
                    p_mutex_std_node->m_pthread_mutex_storage),
                &(
                    o_abstime));

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
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_wait()

/* end-of-file: appl_event_std_node.cpp */
