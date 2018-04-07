/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include <pthread.h>

#endif /* #if defined APPL_DEBUG */

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_context_handle.h"

#include "appl_buf.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_context_std.h"

#include "appl_heap.h"

#include "appl_heap_std.h"

#if defined APPL_DEBUG

#include "appl_list.h"

#include "appl_heap_dbg.h"

#endif /* #if defined APPL_DEBUG */

#if defined APPL_DEBUG

#include "appl_debug.h"

#if defined APPL_OS_LINUX

#include "appl_debug_std.h"

#elif defined APPL_OS_WINDOWS

#include "appl_debug_w32.h"

#endif /* #if defined APPL_OS_Xx */

#endif /* #if defined APPL_DEBUG */

#include "appl_options.h"

#include "appl_options_std.h"

#include "appl_thread_mgr.h"

#if defined APPL_OS_LINUX

#include "appl_thread_std_mgr.h"

#elif defined APPL_OS_WINDOWS

#include "appl_thread_w32_mgr.h"

#endif

#include "appl_file_mgr.h"

#include "appl_file_std_mgr.h"

#include "appl_mutex_mgr.h"

#include "appl_mutex_std_mgr.h"

#include "appl_node.h"

#include "appl_poll_mgr.h"

#include "appl_clock.h"

#if defined APPL_OS_LINUX

#include "appl_clock_std.h"

#elif defined APPL_OS_WINDOWS

#include "appl_clock_w32.h"

#endif /* #if defined APPL_OS_Xx */

#include "appl_event_mgr.h"

#include "appl_event_std_mgr.h"

#include "appl_socket_mgr.h"

#include "appl_socket_std_mgr.h"

struct appl_context_init_descriptor
{
    struct appl_context_descriptor const *
        p_context_descriptor;

    class appl_heap *
        p_heap;

}; /* struct appl_context_init_descriptor */

//
//
//
enum appl_status
    appl_context_std::init_heap(
        class appl_heap * const
            p_heap)
{
    enum appl_status
        e_status;

    m_heap =
        p_heap;

    b_init_heap =
        true;

    e_status =
        appl_status_ok;

    return
        e_status;

} // init_heap()

//
//
//
void
    appl_context_std::cleanup_heap(void)
{
    if (
        b_init_heap)
    {
        m_heap =
            0;

        b_init_heap =
            false;
    }

} // cleanup_heap()

//
//
//
#if defined APPL_DEBUG
enum appl_status
appl_context_std::init_debug(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    e_status =
        appl_debug_std::create_instance(
            m_context,
            &(
                m_debug));

#elif defined APPL_OS_WINDOWS

    e_status =
        appl_debug_w32::create_instance(
            m_context,
            &(
                m_debug));

#else /* #if defined APPL_OS_Xx */

    e_status =
        appl_status_fail;

#endif /* #if defined APPL_OS_Xx */

    if (
        appl_status_ok
        == e_status)
    {
        b_init_debug =
            true;
    }

    return
        e_status;

} // init_debug()
#endif /* #if defined APPL_DEBUG */

//
//
//
#if defined APPL_DEBUG
void
appl_context_std::cleanup_debug(void)
{
    if (b_init_debug)
    {
        m_debug->destroy();

        m_debug =
            0;

        b_init_debug =
            false;
    }

} // cleanup_debug()
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
appl_context_std::init_options(
    struct appl_context_descriptor const * const
        p_context_descriptor)
{
    enum appl_status
        e_status;

    struct appl_options_std_descriptor
        o_options_std_descriptor;

    o_options_std_descriptor.p_arg_min =
        p_context_descriptor->p_arg_min;

    o_options_std_descriptor.p_arg_max =
        p_context_descriptor->p_arg_max;

    e_status =
        appl_options_std::create_instance(
            m_context,
            &(
                o_options_std_descriptor),
            &(
                m_options));

    if (
        appl_status_ok
        == e_status)
    {
        b_init_options =
            true;
    }

    return
        e_status;

} // init_options()

//
//
//
void
appl_context_std::cleanup_options(void)
{
    if (b_init_options)
    {
        m_options->destroy();

        m_options =
            0;

        b_init_options =
            false;
    }

} // cleanup_options()

//
//
//
enum appl_status
appl_context_std::init_thread_mgr(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    e_status =
        appl_thread_std_mgr::create_instance(
            m_context,
            &(
                m_thread_mgr));

#elif defined APPL_OS_WINDOWS

    e_status =
        appl_thread_w32_mgr::create_instance(
            m_context,
            &(
                m_thread_mgr));

#else /* #if defined APPL_OS_Xx */

    e_status =
        appl_status_fail;

#endif /* #if defined APPL_OS_Xx */

    if (
        appl_status_ok
        == e_status)
    {
        b_init_thread_mgr =
            true;
    }

    return
        e_status;

} // init_thread_mgr()

//
//
//
void
appl_context_std::cleanup_thread_mgr(void)
{
    if (b_init_thread_mgr)
    {
        m_thread_mgr->destroy();

        m_thread_mgr =
            0;

        b_init_thread_mgr =
            false;
    }

} // cleanup_thread_mgr()

//
//
//
enum appl_status
    appl_context_std::init_mutex_mgr(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_std_mgr::create_instance(
            m_context,
            &(
                m_mutex_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        b_init_mutex_mgr =
            true;
    }

    return
        e_status;

}

//
//
//
void
    appl_context_std::cleanup_mutex_mgr(void)
{
    if (b_init_mutex_mgr)
    {
        m_mutex_mgr->destroy();

        m_mutex_mgr =
            0;

        b_init_mutex_mgr =
            false;
    }
}

//
//
//
enum appl_status
    appl_context_std::init_file_mgr(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_file_std_mgr::create_instance(
            m_context,
            &(
                m_file_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        b_init_file_mgr =
            true;
    }

    return
        e_status;
}

//
//
//
void
    appl_context_std::cleanup_file_mgr(void)
{
    if (
        b_init_file_mgr)
    {
        m_file_mgr->destroy();

        m_file_mgr =
            0;

        b_init_file_mgr =
            false;
    }
}

//
//
//
enum appl_status
    appl_context_std::init_poll_mgr(void)
{
    enum appl_status
        e_status;

#if 0
    e_status =
        appl_poll_mgr::create_instance(
            m_context,
            &(
                m_poll_mgr));
#else
    e_status =
        appl_status_not_implemented;
#endif

    return
        e_status;

}

//
//
//
void
    appl_context_std::cleanup_poll_mgr(void)
{
    if (
        b_init_poll_mgr)
    {
        m_poll_mgr->destroy();

        m_poll_mgr =
            0;

        b_init_poll_mgr =
            false;
    }
}

//
//
//
enum appl_status
    appl_context_std::init_clock(void)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    e_status =
        appl_clock_std::create_instance(
            m_context,
            &(
                m_clock));

#elif defined APPL_OS_WINDOWS

    e_status =
        appl_clock_w32::create_instance(
            m_context,
            &(
                m_clock));

#else

    e_status =
        appl_status_not_implemented;

#endif

    if (
        appl_status_ok
        == e_status)
    {
        b_init_clock =
            true;
    }

    return
        e_status;

} // init_clock()

//
//
//
void
    appl_context_std::cleanup_clock(void)
{
    if (
        b_init_clock)
    {
        m_clock->destroy();

        m_clock =
            0;

        b_init_clock =
            false;
    }

} // cleanup_clock()

//
//
//
enum appl_status
    appl_context_std::init_event_mgr(void)
{
    enum appl_status
        e_status;

    if (
        !b_init_event_mgr)
    {
        e_status =
            appl_event_std_mgr::s_create(
                m_context,
                &(
                    m_event_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            b_init_event_mgr =
                true;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // init_event_mgr()

//
//
//
void
    appl_context_std::cleanup_event_mgr(void)
{
    if (
        b_init_event_mgr)
    {
        m_event_mgr->destroy();

        m_event_mgr =
            0;

        b_init_event_mgr =
            false;
    }
} // cleanup_event_mgr()

//
//
//
enum appl_status
    appl_context_std::init_socket_mgr(void)
{
    enum appl_status
        e_status;

    if (
        !b_init_socket_mgr)
    {
        e_status =
            appl_socket_std_mgr::s_create(
                m_context,
                &(
                    m_socket_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            b_init_socket_mgr =
                true;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // init_socket_mgr()

//
//
//
void
    appl_context_std::cleanup_socket_mgr(void)
{
    if (
        b_init_socket_mgr)
    {
        m_socket_mgr->destroy();

        m_socket_mgr =
            0;

        b_init_socket_mgr =
            false;
    }

} // cleanup_socket_mgr()

//
//
//
enum appl_status
    appl_context_std::create_instance(
        struct appl_context_descriptor const * const
            p_context_descriptor,
        class appl_context * * const
            r_context)
{
    enum appl_status
        e_status;

    class appl_heap *
        p_heap;

    e_status =
        appl_heap_std::create_instance(
            &(
                p_heap));

    if (
        appl_status_ok
        == e_status)
    {
#if defined APPL_DEBUG
        e_status =
            appl_heap_dbg::create_instance(
                p_heap,
                &(
                    p_heap));
#endif /* #if defined APPL_DEBUG */

        if (
            appl_status_ok
            == e_status)
        {
            struct appl_context_init_descriptor
                o_init_descriptor;

            o_init_descriptor.p_context_descriptor =
                p_context_descriptor;

            o_init_descriptor.p_heap =
                p_heap;

            void *
                p_placement;

            e_status =
                p_heap->v_alloc(
                    static_cast<unsigned long int>(
                        sizeof(
                            class appl_context_std)),
                    &(
                        p_placement));

            if (
                appl_status_ok == e_status)
            {
                e_status =
                    appl_object::s_init(
                        static_cast<class appl_context *>(
                            0),
                        p_placement,
                        &(
                            appl_context_std::placement_new),
                        &(
                            o_init_descriptor),
                        r_context);

                if (
                    appl_status_ok != e_status)
                {
                    p_heap->v_free(
                        p_placement);
                }
            }
        }

        if (
            appl_status_ok != e_status)
        {
            p_heap->destroy();
        }
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_context_std::appl_context_std() :
    appl_context(),
    b_init_heap(),
    b_init_debug(),
    b_init_options(),
    b_init_thread_mgr(),
    b_init_mutex_mgr(),
    b_init_file_mgr(),
    b_init_poll_mgr(),
    b_init_clock(),
    b_init_event_mgr(),
    b_init_socket_mgr()
{
}

//
//
//
appl_context_std::~appl_context_std()
{
}

void
    appl_context_std::placement_new(
        void * const
            p_placement)
{
    new (
        p_placement)
        class appl_context_std;

} // placement_new()

//
//
//
enum appl_status
    appl_context_std::init(
        void const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    m_context =
        this;

    struct appl_context_init_descriptor const * const
        p_context_init_descriptor =
        static_cast<struct appl_context_init_descriptor const *>(
            p_descriptor);

    e_status =
        init_heap(
            p_context_init_descriptor->p_heap);

    if (
        appl_status_ok
        == e_status)
    {
#if defined APPL_DEBUG
        e_status =
            init_debug();
#endif /* #if defined APPL_DEBUG */

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                init_options(
                    p_context_init_descriptor->p_context_descriptor);

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    init_thread_mgr();

                if (
                    appl_status_ok
                    == e_status)
                {
                    e_status =
                        init_file_mgr();

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        e_status =
                            init_mutex_mgr();

                        if (
                            appl_status_ok
                            == e_status)
                        {
                            e_status =
                                init_clock();

                            if (
                                appl_status_ok
                                == e_status)
                            {
                                e_status =
                                    init_event_mgr();

                                if (
                                    appl_status_ok
                                    == e_status)
                                {
                                    e_status =
                                        init_socket_mgr();

                                    if (
                                        appl_status_ok
                                        == e_status)
                                    {
                                        if (
                                            appl_status_ok != e_status)
                                        {
                                            cleanup_socket_mgr();
                                        }
                                    }

                                    if (
                                        appl_status_ok != e_status)
                                    {
                                        cleanup_event_mgr();
                                    }
                                }

                                if (
                                    appl_status_ok != e_status)
                                {
                                    cleanup_clock();
                                }
                            }

                            if (
                                appl_status_ok != e_status)
                            {
                                cleanup_mutex_mgr();
                            }
                        }

                        if (
                            appl_status_ok != e_status)
                        {
                            cleanup_file_mgr();
                        }
                    }

                    if (
                        appl_status_ok != e_status)
                    {
                        cleanup_thread_mgr();
                    }
                }

                if (
                    appl_status_ok != e_status)
                {
                    cleanup_options();
                }
            }

#if defined APPL_DEBUG
            if (
                appl_status_ok != e_status)
            {
                cleanup_debug();
            }
#endif /* #if defined APPL_DEBUG */
        }

        if (
            appl_status_ok != e_status)
        {
            cleanup_heap();
        }
    }

    return
        e_status;

} // init()

//
//
//
enum appl_status
    appl_context_std::cleanup(void)
{
    enum appl_status
        e_status;

    // destroy objects

    cleanup_socket_mgr();

    cleanup_event_mgr();

    cleanup_clock();

    cleanup_mutex_mgr();

    cleanup_file_mgr();

    cleanup_thread_mgr();

    cleanup_options();

#if defined APPL_DEBUG
    cleanup_debug();
#endif /* #if defined APPL_DEBUG */

    cleanup_heap();

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
appl_context_std::destroy(void)
{
    enum appl_status
        e_status;

    class appl_heap *
        p_heap;

    p_heap =
        m_heap;

    cleanup();

    void *
        p_placement;

    p_placement =
        static_cast<void *>(
            this);

    delete
        this;

    p_heap->v_free(
        p_placement);

    p_heap->destroy();

    e_status =
        appl_status_ok;

    return
        e_status;

} // destroy()

/* end-of-file: appl_context_std.cpp */
