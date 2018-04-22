/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#if defined APPL_OS_LINUX

#include <signal.h>

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS

#include <pthread_time.h>

#endif /* #if defined APPL_OS_WINDOWS */

#include <appl_status.h>

#include <appl_types.h>

#include <appl_buf.h>

#include <appl_object.h>

#include <appl_thread_descriptor.h>

#include <appl_object_handle.h>

#include <appl_property_handle.h>

#include <appl_thread_property.h>

#include <appl_thread_node.h>

#include <appl_thread_std_node.h>

#if defined APPL_DEBUG

#include <appl_debug.h>

#include <appl_context.h>

#endif /* #if defined APPL_DEBUG */

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_thread_std_node::create_instance(
        struct appl_context * const
            p_context,
        struct appl_thread_property const * const
            p_thread_property,
        struct appl_thread * * const
            r_thread)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::s_create
        < appl_thread_std_node, appl_thread_property, appl_thread >
        (
            p_context,
            (&
                appl_thread_std_node::placement_new),
            (&
                appl_thread_std_node::init),
            p_thread_property,
            r_thread);

    return
        e_status;

} // create_instance()

//
//
//
appl_thread_std_node::appl_thread_std_node() :
    appl_thread(),
    m_descriptor(),
    m_lock(),
    m_event(),
    m_thread(),
    m_thread_result(),
    m_running(false)
{
}

//
//
//
appl_thread_std_node::~appl_thread_std_node()
{
}

#if defined APPL_DEBUG
void
appl_thread_std_node::oops(
    unsigned char const * const
        p_msg_min,
    unsigned char const * const
        p_msg_max,
    int const
        i_status_code)
{
    unsigned char
        s_msg[128u];

    m_context->m_debug->v_print(
        s_msg,
        appl_buf_write(
            appl_buf_write(
                appl_buf_print_number(
                    appl_buf_write(
                        appl_buf_write(
                            appl_buf_copy(
                                s_msg,
                                s_msg + sizeof s_msg,
                                p_msg_min,
                                p_msg_max),
                            s_msg + sizeof s_msg,
                            ' '),
                        s_msg + sizeof s_msg,
                        '('),
                    s_msg + sizeof s_msg,
                    static_cast<signed long int>(
                        i_status_code),
                    0,
                    0),
                s_msg + sizeof s_msg,
                ')'),
            s_msg + sizeof s_msg,
            '\n'));

} // oops()
#endif /* #if defined APPL_DEBUG */

//
//
//
void
    appl_thread_std_node::thread_handler(void)
{
    void *
        p_thread_result;

    int
        i_detach_result;

    i_detach_result =
        pthread_detach(
            m_thread);

    if (
        0
        == i_detach_result)
    {
        p_thread_result =
            (*(m_descriptor.p_entry))(
                m_descriptor.p_context);

        int
            i_lock_result;

        i_lock_result =
            pthread_mutex_lock(
                &(
                    m_lock));

        if (
            0
            == i_lock_result)
        {
            m_running =
                false;

            m_thread_result =
                p_thread_result;

            int
                i_signal_result;

            i_signal_result =
                pthread_cond_signal(
                    &(
                        m_event));

            appl_unused(
                i_signal_result);

            int
                i_unlock_result;

            i_unlock_result =
                pthread_mutex_unlock(
                    &(
                        m_lock));

            appl_unused(
                i_unlock_result);
        }
        else
        {
#if defined APPL_DEBUG
            static unsigned char const s_msg[] =
            {
                'p',
                't',
                'h',
                'r',
                'e',
                'a',
                'd',
                '_',
                'm',
                'u',
                't',
                'e',
                'x',
                '_',
                'l',
                'o',
                'c',
                'k'
            };

            oops(
                s_msg,
                s_msg + sizeof s_msg,
                i_detach_result);
#endif /* #if defined APPL_DEBUG */

            m_running =
                false;

            m_thread_result =
                p_thread_result;

            pthread_cond_signal(
                &(
                    m_event));
        }
    }
    else
    {
#if defined APPL_DEBUG
        static unsigned char const s_msg[] =
        {
            'p',
            't',
            'h',
            'r',
            'e',
            'a',
            'd',
            '_',
            'd',
            'e',
            't',
            'a',
            'c',
            'h'
        };

        oops(
            s_msg,
            s_msg + sizeof s_msg,
            i_detach_result);
#endif /* #if defined APPL_DEBUG */
    }

} // thread_handler()

//
//
//
void *
    appl_thread_std_node::thread_entry(
        void *
            p_thread_context)
{
    class appl_thread_std_node * const
        p_thread_std_node =
        static_cast<class appl_thread_std_node *>(
            p_thread_context);

    p_thread_std_node->thread_handler();

    return
        static_cast<void *>(
            0);

} // thread_entry()

//
//
//
enum appl_status
appl_thread_std_node::v_start(void)
{
    enum appl_status
        e_status;

    int
        i_lock_result;

    i_lock_result =
        pthread_mutex_lock(
            &(
                m_lock));

    if (
        0
        == i_lock_result)
    {
        if (
            !(
                m_running))
        {
            int
                i_create_result;

            i_create_result =
                pthread_create(
                    &(
                        m_thread),
                    NULL,
                    &(
                        appl_thread_std_node::thread_entry),
                    static_cast<void *>(
                        this));

            if (
                0
                == i_create_result)
            {
                m_running =
                    true;

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

        int
            i_unlock_result;

        i_unlock_result =
            pthread_mutex_unlock(
                &(
                    m_lock));

        appl_unused(
            i_unlock_result);
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_start()

//
//
//
enum appl_status
    appl_thread_std_node::v_stop(
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count,
        void * * const
            r_result)
{
    enum appl_status
        e_status;

    int
        i_lock_result;

    i_lock_result =
        pthread_mutex_lock(
            &(
                m_lock));

    if (
        0
        == i_lock_result)
    {
        if (
            m_running)
        {
            struct timespec
                o_now;

            int
                i_clock_result;

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
                    i_wait_result;

                i_wait_result =
                    pthread_cond_timedwait(
                        &(
                            m_event),
                        &(
                            m_lock),
                        &(
                            o_abstime));

                if (
                    0
                    == i_wait_result)
                {
                }
                else
                {
                }

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
                appl_status_ok;
        }

        if (
            appl_status_ok
            == e_status)
        {
            if (
                !(
                    m_running))
            {
                *(
                    r_result) =
                    m_thread_result;

                e_status =
                    appl_status_ok;
            }
            else
            {
                e_status =
                    appl_status_fail;
            }
        }

        int
            i_unlock_result;

        i_unlock_result =
            pthread_mutex_unlock(
                &(
                    m_lock));

        appl_unused(
            i_unlock_result);
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // wait_result()

#if defined APPL_OS_LINUX

/*

*/
static
void
dummy_urgent_signal_handler(
    int
        i_unused)
{
    appl_unused(
        i_unused);
} /* dummy_urgent_signal_handler() */

#endif /* #if defined APPL_OS_LINUX */

//
//
//
enum appl_status
    appl_thread_std_node::v_interrupt(void)
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
                m_thread,
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

} // v_interrupt()

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

//
//
//
enum appl_status
    appl_thread_std_node::init(
        struct appl_thread_property const * const
            p_thread_property)
{
    enum appl_status
        e_status;

    appl_thread_property_get_callback(
        p_thread_property,
        &(
            m_descriptor.p_entry));

    appl_thread_property_get_context(
        p_thread_property,
        &(
            m_descriptor.p_context));

    int
        i_mutex_result;

    i_mutex_result =
        pthread_mutex_init(
            &(
                m_lock),
            NULL);

    if (
        0
        == i_mutex_result)
    {
        int
            i_cond_result;

        i_cond_result =
            pthread_cond_init(
                &(
                    m_event),
                NULL);

        if (
            0
            == i_cond_result)
        {
            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        if (
            appl_status_ok
            != e_status)
        {
            pthread_mutex_destroy(
                &(
                    m_lock));
        }
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
    appl_thread_std_node::v_cleanup(void)
{
    enum appl_status
        e_status;

    pthread_cond_destroy(
        &(
            m_event));

    pthread_mutex_destroy(
        &(
            m_lock));

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

/* end-of-file: appl_thread_std_node.cpp */
