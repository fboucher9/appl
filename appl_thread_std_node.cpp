/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#if defined APPL_OS_LINUX

#include <signal.h>

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS

#include <windows.h>

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

#include <appl_mutex_impl.h>

#include <appl_event_impl.h>

#include <appl_thread_std_node.h>

#if defined APPL_DEBUG

#include <appl_debug.h>

#include <appl_context.h>

#endif /* #if defined APPL_DEBUG */

#include <appl_unused.h>

#include <appl_convert.h>

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

    class appl_thread_std_node *
        p_thread_std_node;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_thread_std_node::placement_new),
            (&
                appl_thread_std_node::init),
            p_thread_property,
            &(
                p_thread_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_thread) =
            p_thread_std_node;
    }

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
    m_running(false),
    m_detached(false),
    m_kill(false),
    m_start(false)
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
                    i_status_code,
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
    int const
        i_detach_result =
        pthread_detach(
            m_thread);

    if (
        0
        == i_detach_result)
    {
        enum appl_status const
            e_lock_status =
            m_lock.lock();

        if (
            appl_status_ok
            == e_lock_status)
        {
            // wait for start event
            while (
                !(
                    m_kill))
            {
                if (
                    m_start)
                {
                    struct appl_thread_descriptor const
                        o_descriptor =
                        m_descriptor;

                    m_event.signal();

                    enum appl_status const
                        e_unlock_status =
                        m_lock.unlock();

                    if (
                        appl_status_ok
                        == e_unlock_status)
                    {
                        (*(o_descriptor.p_entry))(
                            o_descriptor.p_context);

                        enum appl_status const
                            e_lock_status2 =
                            m_lock.lock();

                        if (
                            appl_status_ok
                            == e_lock_status2)
                        {
                            m_start =
                                false;

                            m_event.signal();
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
                            'm',
                            'u',
                            't',
                            'e',
                            'x',
                            '_',
                            'u',
                            'n',
                            'l',
                            'o',
                            'c',
                            'k'
                        };

                        oops(
                            s_msg,
                            s_msg + sizeof s_msg,
                            e_unlock_status);
#endif /* #if defined APPL_DEBUG */
                    }
                }
                else
                {
                    // wait for start event
                    m_event.wait(
                        &(
                            m_lock),
                        1,
                        1);
                }
            }

            m_running =
                false;

            m_event.signal();

            enum appl_status const
                e_unlock_status =
                m_lock.unlock();

            appl_unused(
                e_unlock_status);
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
                e_lock_status);
#endif /* #if defined APPL_DEBUG */
        }

        m_running =
            false;

        if (
            m_detached)
        {
            m_detached =
                false;

            /* Kill ourselves */
            destroy();
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

union appl_thread_std_node_thread_context_ptr
{
    void *
        p_thread_context;

    class appl_thread_std_node *
        p_thread_std_node;

}; // appl_thread_std_node_thread_context_ptr

//
//
//
void *
    appl_thread_std_node::thread_entry(
        void *
            p_thread_context)
{
    union appl_thread_std_node_thread_context_ptr
        o_thread_context_ptr;

    o_thread_context_ptr.p_thread_context =
        p_thread_context;

    class appl_thread_std_node * const
        p_thread_std_node =
        o_thread_context_ptr.p_thread_std_node;

    p_thread_std_node->thread_handler();

    return
        0;

} // thread_entry()

//
//
//
enum appl_status
appl_thread_std_node::v_start(
    void (* const p_callback)(
        void * const
            p_context),
    void * const
        p_context)
{
    enum appl_status
        e_status;

    e_status =
        m_lock.lock();

    if (
        appl_status_ok
        == e_status)
    {
        m_descriptor.p_entry =
            p_callback;

        m_descriptor.p_context =
            p_context;

        if (
            !(
                m_running))
        {
            e_status =
                appl_status_fail;
        }
        else
        {
            m_start =
                true;

            enum appl_status const
                e_signal_result =
                m_event.signal();

            appl_unused(
                e_signal_result);

            enum appl_status const
                e_wait_result =
                m_event.wait(
                    &(
                        m_lock),
                    1,
                    1);

            appl_unused(
                e_wait_result);

            e_status =
                appl_status_ok;
        }

        enum appl_status const
            e_unlock_result =
            m_lock.unlock();

        appl_unused(
            e_unlock_result);
    }

    return
        e_status;

} // v_start()

//
//
//
enum appl_status
    appl_thread_std_node::v_detach(void)
{
    enum appl_status
        e_status;

    e_status =
        m_lock.lock();

    if (
        appl_status_ok
        == e_status)
    {
        m_detached =
            true;

        m_lock.unlock();
    }

    return
        e_status;

} // v_detach()

//
//
//
enum appl_status
    appl_thread_std_node::v_stop(
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    /* if m_detached then there's a risk of segfault */
#if defined APPL_DEBUG
    {
        if (m_detached)
        {
            static unsigned char const s_msg[] =
            {
                'v',
                '_',
                's',
                't',
                'o',
                'p'
            };

            oops(
                s_msg,
                s_msg + sizeof s_msg,
                0);
        }
    }
#endif /* #if defined APPL_DEBUG */

    enum appl_status const
        e_lock_result =
        m_lock.lock();

    if (
        appl_status_ok
        == e_lock_result)
    {
        if (
            m_start)
        {
            enum appl_status const
                e_wait_result =
                m_event.wait(
                    &(
                        m_lock),
                    i_wait_freq,
                    i_wait_count);

            appl_unused(
                e_wait_result);

            e_status =
                appl_status_ok;
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
                    m_start))
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

        enum appl_status const
            e_unlock_result =
            m_lock.unlock();

        appl_unused(
            e_unlock_result);
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

    unsigned char
        b_detach_state;

    if (
        appl_status_ok
        == appl_thread_property_get_detach_state(
            p_thread_property,
            &(
                b_detach_state)))
    {
        if (
            b_detach_state)
        {
            m_detached =
                true;
        }
    }

    e_status =
        m_lock.init();

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            m_event.init();

        if (
            appl_status_ok
            == e_status)
        {
            int
                i_create_result;

            union appl_thread_std_node_thread_context_ptr
                o_thread_context_ptr;

            o_thread_context_ptr.p_thread_std_node =
                this;

            i_create_result =
                pthread_create(
                    &(
                        m_thread),
                    NULL,
                    &(
                        appl_thread_std_node::thread_entry),
                    o_thread_context_ptr.p_thread_context);

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

            if (
                appl_status_ok
                != e_status)
            {
                m_event.cleanup();
            }
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
            m_lock.cleanup();
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

    // kill the thread
    enum appl_status const
        e_lock_result =
        m_lock.lock();

    if (
        appl_status_ok
        == e_lock_result)
    {
        while (
            m_running)
        {
            m_kill =
                true;

            m_event.signal();

            m_event.wait(
                &(
                    m_lock),
                1,
                1);
        }

        enum appl_status const
            e_unlock_result =
            m_lock.unlock();

        appl_unused(
            e_unlock_result);
    }

    if (
        m_running || m_detached)
    {
        e_status =
            appl_status_fail;
    }
    else
    {
        m_event.cleanup();

        m_lock.cleanup();

        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // v_cleanup()

/* end-of-file: appl_thread_std_node.cpp */
