/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include <pthread.h>

#if defined APPL_OS_WINDOWS

#include <windows.h>

#endif /* #if defined APPL_OS_WINDOWS */

#endif /* #if defined APPL_DEBUG */

#include <appl_status.h>

#include <appl_context_handle.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_context_std.h>

#include <appl_allocator.h>

#include <appl_heap.h>

#include <appl_heap_std.h>

#if defined APPL_DEBUG

#include <appl_list.h>

#include <appl_mutex_impl.h>

#include <appl_heap_dbg.h>

#endif /* #if defined APPL_DEBUG */

#if defined APPL_DEBUG

#include <appl_debug.h>

#if defined APPL_OS_LINUX

#include <appl_debug_std.h>

#elif defined APPL_OS_WINDOWS

#include <appl_debug_w32.h>

#endif /* #if defined APPL_OS_Xx */

#endif /* #if defined APPL_DEBUG */

#include <appl_options.h>

#include <appl_options_std.h>

#include <appl_thread_mgr.h>

#include <appl_thread_std_mgr.h>

#include <appl_file_mgr.h>

#include <appl_file_std_mgr.h>

#include <appl_mutex_mgr.h>

#include <appl_mutex_std_mgr.h>

#include <appl_node.h>

#include <appl_poll_mgr.h>

#include <appl_clock.h>

#if defined APPL_OS_LINUX

#include <appl_clock_std.h>

#elif defined APPL_OS_WINDOWS

#include <appl_clock_w32.h>

#endif /* #if defined APPL_OS_Xx */

#include <appl_event_mgr.h>

#include <appl_event_std_mgr.h>

#include <appl_socket_mgr.h>

#if defined APPL_OS_LINUX

#include <appl_socket_std_mgr.h>

#elif defined APPL_OS_WINDOWS

#include <appl_socket_w32_mgr.h>

#endif /* #if defined APPL_OS_Xx */

#include <appl_env.h>

#if defined APPL_OS_LINUX

#include <appl_env_std.h>

#elif defined APPL_OS_WINDOWS

#include <appl_env_w32.h>

#endif /* #if defined APPL_OS_Xx */

#include <appl_random_mgr.h>

#if defined APPL_OS_LINUX

#include <appl_random_std_mgr.h>

#elif defined APPL_OS_WINDOWS

#include <appl_random_w32_mgr.h>

#endif

#include <appl_log_handle.h>

#include <appl_log.h>

#include <appl_log_impl.h>

#include <appl_log_std.h>

#include <appl_pool_mgr.h>

#include <appl_thread_cache.h>

#include <appl_timer_mgr.h>

#include <appl_timer_std_mgr.h>

#include <appl_convert.h>

extern
enum appl_status
    appl_library_mgr_create(
        struct appl_context * const
            p_context,
        class appl_library_mgr * * const
            r_library_mgr);

extern
enum appl_status
    appl_library_mgr_destroy(
        class appl_library_mgr * const
            p_library_mgr);

struct appl_context_init_descriptor
{
    struct appl_context_descriptor const *
        p_context_descriptor;

    struct appl_heap *
        p_heap;

}; /* struct appl_context_init_descriptor */

//
//
//
enum appl_status
    appl_context_std::init_heap(
        struct appl_heap * const
            p_heap)
{
    enum appl_status
        e_status;

    m_heap =
        p_heap;

    m_heap->set_context(
        this);

    m_allocator =
        m_heap;

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
        appl_debug_std::s_create(
            m_heap,
            &(
                m_debug));

#elif defined APPL_OS_WINDOWS

    e_status =
        appl_debug_w32::s_create(
            m_heap,
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
        m_debug->v_destroy();

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

    e_status =
        appl_options_std::s_create(
            m_heap,
            &(
                m_options));

    if (
        appl_status_ok
        == e_status)
    {
        // append some arguments
        unsigned char const * const *
            p_arg_it;

        p_arg_it =
            p_context_descriptor->p_arg_min;

        while (
            (
                appl_status_ok
                == e_status)
            && (
                p_arg_it
                != p_context_descriptor->p_arg_max))
        {
            unsigned char const * const
                p_arg =
                *(
                    p_arg_it);

            // find length of arg
            unsigned long int const
                i_arg_len =
                appl_buf0_len(
                    p_arg);

            e_status =
                m_options->v_append_argument(
                    p_arg,
                    p_arg + i_arg_len);

            if (
                appl_status_ok
                == e_status)
            {
                p_arg_it ++;
            }
        }

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
        m_options->v_destroy();

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

    e_status =
        appl_thread_std_mgr::s_create(
            m_heap,
            &(
                m_thread_mgr));

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
        m_thread_mgr->v_destroy();

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
        appl_mutex_std_mgr::s_create(
            m_heap,
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
        m_mutex_mgr->v_destroy();

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
        appl_file_std_mgr::s_create(
            m_heap,
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
        m_file_mgr->v_destroy();

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
        m_poll_mgr->v_destroy();

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
        appl_clock_std::s_create(
            m_allocator,
            &(
                m_clock));

#elif defined APPL_OS_WINDOWS

    e_status =
        appl_clock_w32::s_create(
            m_allocator,
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
        m_clock->v_destroy();

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
                m_allocator,
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
        m_event_mgr->v_destroy();

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
#if defined APPL_OS_LINUX

        e_status =
            appl_socket_std_mgr::s_create(
                m_allocator,
                &(
                    m_socket_mgr));

#elif defined APPL_OS_WINDOWS

        e_status =
            appl_socket_w32_mgr::s_create(
                m_allocator,
                &(
                    m_socket_mgr));

#else /* #if defined APPL_OS_Xx */

        e_status =
            appl_status_fail;

#endif /* #if defined APPL_OS_Xx */

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
        m_socket_mgr->v_destroy();

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
    appl_context_std::init_env(void)
{
    enum appl_status
        e_status;

    if (
        !b_init_env)
    {
#if defined APPL_OS_LINUX
        e_status =
            appl_env_std::s_create(
                m_allocator,
                &(
                    m_env));
#elif defined APPL_OS_WINDOWS
        e_status =
            appl_env_w32::s_create(
                m_allocator,
                &(
                    m_env));
#else /* #if defined APPL_OS_Xx */
        e_status =
            appl_status_fail;
#endif /* #if defined APPL_OS_Xx */

        if (
            appl_status_ok
            == e_status)
        {
            b_init_env =
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

} // init_env()

//
//
//
void
    appl_context_std::cleanup_env(void)
{
    if (
        b_init_env)
    {
        m_env->v_destroy();

        m_env =
            0;

        b_init_env =
            false;
    }
} // cleanup_env()

//
//
//
enum appl_status
    appl_context_std::init_library_mgr(void)
{
    enum appl_status
        e_status;

    if (
        !b_init_library_mgr)
    {
        e_status =
            appl_library_mgr_create(
                m_context,
                &(
                    m_library_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            b_init_library_mgr =
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

} // init_library_mgr()

//
//
//
void
    appl_context_std::cleanup_library_mgr(void)
{
    if (
        b_init_library_mgr)
    {
        appl_library_mgr_destroy(
            m_library_mgr);

        m_library_mgr =
            0;

        b_init_library_mgr =
            false;
    }
} // cleanup_library_mgr()

//
//
//
enum appl_status
    appl_context_std::init_random_mgr(void)
{
    enum appl_status
        e_status;

    if (
        !b_init_random_mgr)
    {
#if defined APPL_OS_LINUX
        e_status =
            appl_random_std_mgr::s_create(
                m_allocator,
                &(
                    m_random_mgr));
#elif defined APPL_OS_WINDOWS
        e_status =
            appl_random_w32_mgr::s_create(
                m_allocator,
                &(
                    m_random_mgr));
#else /* #if defined APPL_OS_LINUX */
        e_status =
            appl_status_not_implemented;
#endif /* #if defined APPL_OS_LINUX */

        if (
            appl_status_ok
            == e_status)
        {
            b_init_random_mgr =
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

} // init_random_mgr()

//
//
//
void
    appl_context_std::cleanup_random_mgr(void)
{
    if (
        b_init_random_mgr)
    {
        m_random_mgr->v_destroy();

        m_random_mgr =
            0;

        b_init_random_mgr =
            false;
    }
} // cleanup_random_mgr()

//
//
//
enum appl_status
    appl_context_std::init_log(void)
{
    enum appl_status
        e_status;

    if (
        !b_init_log)
    {
        class appl_log_std *
            p_log_std;

        e_status =
            appl_log_std::s_create(
                m_allocator,
                &(
                    p_log_std));

        if (
            appl_status_ok
            == e_status)
        {
            m_log =
                p_log_std;

            b_init_log =
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

} // init_log()

//
//
//
void
    appl_context_std::cleanup_log(void)
{
    if (
        b_init_log)
    {
        m_log->v_destroy();

        m_log =
            0;

        b_init_log =
            false;
    }
} // cleanup_log()

//
//
//
enum appl_status
    appl_context_std::init_pool_mgr(void)
{
    enum appl_status
        e_status;

    if (
        !b_init_pool_mgr)
    {
        e_status =
            appl_pool_mgr::s_create(
                m_allocator,
                &(
                    m_pool_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            b_init_pool_mgr =
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

} // init_pool_mgr()

//
//
//
void
    appl_context_std::cleanup_pool_mgr(void)
{
    if (
        b_init_pool_mgr)
    {
        m_pool_mgr->v_destroy();

        m_pool_mgr =
            0;

        b_init_pool_mgr =
            false;
    }
} // cleanup_pool_mgr()

extern
enum appl_status
appl_thread_cache_mgr_create(
    struct appl_allocator * const
        p_allocator,
    class appl_thread_cache_mgr * * const
        r_instance);

//
//
//
enum appl_status
    appl_context_std::init_thread_cache_mgr(void)
{
    enum appl_status
        e_status;

    if (
        !(
            b_init_thread_cache_mgr))
    {
        e_status =
            appl_thread_cache_mgr_create(
                m_allocator,
                &(
                    m_thread_cache_mgr));

        b_init_thread_cache_mgr =
            true;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // init_thread_cache_mgr()

extern
void
appl_thread_cache_mgr_destroy(
    class appl_thread_cache_mgr * const
        p_thread_cache_mgr);

//
//
//
void
    appl_context_std::cleanup_thread_cache_mgr(void)
{
    if (
        b_init_thread_cache_mgr)
    {
        appl_thread_cache_mgr_destroy(
            m_thread_cache_mgr);

        m_thread_cache_mgr =
            0;

        b_init_thread_cache_mgr =
            false;
    }
} // cleanup_thread_cache_mgr()

//
//
//
enum appl_status
    appl_context_std::init_timer_mgr(void)
{
    enum appl_status
        e_status;

    if (
        b_init_timer_mgr)
    {
        e_status =
            appl_status_fail;
    }
    else
    {
        e_status =
            appl_timer_std_mgr::s_create(
                m_allocator,
                &(
                    m_timer_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            b_init_timer_mgr =
                true;
        }
    }

    return
        e_status;

} // init_timer_mgr()

//
//
//
void
    appl_context_std::cleanup_timer_mgr(void)
{
    if (
        b_init_timer_mgr)
    {
        m_timer_mgr->v_destroy();

        m_timer_mgr =
            0;

        b_init_timer_mgr =
            false;
    }

} // cleanup_timer_mgr()

//
//
//
enum appl_status
    appl_context_std::create_instance(
        struct appl_context_descriptor const * const
            p_context_descriptor,
        struct appl_context * * const
            r_context)
{
    enum appl_status
        e_status;

    struct appl_heap *
        p_heap;

    e_status =
        appl_heap_std::s_create(
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

            class appl_context_std *
                p_context_std;

            e_status =
                p_heap->alloc_object(
                    &(
                        o_init_descriptor),
                    &(
                        p_context_std));

            if (
                appl_status_ok == e_status)
            {
                *(
                    r_context) =
                    p_context_std;
            }
        }

        if (
            appl_status_ok != e_status)
        {
            p_heap->v_destroy();
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
    b_init_socket_mgr(),
    b_init_env(),
    b_init_library_mgr(),
    b_init_random_mgr(),
    b_init_log(),
    b_init_pool_mgr(),
    b_init_thread_cache_mgr(),
    b_init_timer_mgr()
{
}

//
//
//
appl_context_std::~appl_context_std()
{
}

struct appl_context_std::init_cleanup_item
const
appl_context_std::g_init_cleanup_items[] =
{
    {
        & appl_context_std::init_pool_mgr,
        & appl_context_std::cleanup_pool_mgr
    },
    {
        & appl_context_std::init_thread_mgr,
        & appl_context_std::cleanup_thread_mgr
    },
    {
        & appl_context_std::init_file_mgr,
        & appl_context_std::cleanup_file_mgr
    },
    {
        & appl_context_std::init_mutex_mgr,
        & appl_context_std::cleanup_mutex_mgr
    },
    {
        & appl_context_std::init_clock,
        & appl_context_std::cleanup_clock
    },
    {
        & appl_context_std::init_event_mgr,
        & appl_context_std::cleanup_event_mgr
    },
    {
        & appl_context_std::init_socket_mgr,
        & appl_context_std::cleanup_socket_mgr
    },
    {
        & appl_context_std::init_env,
        & appl_context_std::cleanup_env
    },
    {
        & appl_context_std::init_library_mgr,
        & appl_context_std::cleanup_library_mgr
    },
    {
        & appl_context_std::init_random_mgr,
        & appl_context_std::cleanup_random_mgr
    },
    {
        & appl_context_std::init_log,
        & appl_context_std::cleanup_log
    },
    {
        & appl_context_std::init_thread_cache_mgr,
        & appl_context_std::cleanup_thread_cache_mgr
    },
    {
        & appl_context_std::init_timer_mgr,
        & appl_context_std::cleanup_timer_mgr
    }
};

//
//
//
enum appl_status
    appl_context_std::f_init(
        struct appl_context_init_descriptor const * const
            p_context_init_descriptor)
{
    enum appl_status
        e_status;

    m_context =
        this;

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
                unsigned int
                    i_item_iterator;

                i_item_iterator =
                    0;

                while (
                    (
                        appl_status_ok
                        == e_status)
                    && (
                        i_item_iterator
                        < sizeof(g_init_cleanup_items) / sizeof(g_init_cleanup_items[0u])))
                {
                    struct init_cleanup_item const *
                        p_item;

                    p_item =
                        g_init_cleanup_items + i_item_iterator;

                    e_status =
                        ((this)->*(p_item->p_init))();

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        i_item_iterator ++;
                    }
                    else
                    {
                        while (i_item_iterator)
                        {
                            i_item_iterator --;

                            p_item =
                                g_init_cleanup_items + i_item_iterator;

                            ((this)->*(p_item->p_cleanup))();
                        }
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

} // f_init()

//
//
//
enum appl_status
    appl_context_std::v_cleanup(void)
{
    enum appl_status
        e_status;

    struct appl_heap * const
        p_heap =
        m_heap;

    // destroy objects

    unsigned int
        i_item_iterator;

    i_item_iterator =
        sizeof(g_init_cleanup_items) / sizeof(g_init_cleanup_items[0u]);

    while (
        i_item_iterator)
    {
        i_item_iterator --;

        struct init_cleanup_item const *
            p_item;

        p_item =
            g_init_cleanup_items + i_item_iterator;

        ((this)->*(p_item->p_cleanup))();
    }

    cleanup_options();

#if defined APPL_DEBUG
    cleanup_debug();
#endif /* #if defined APPL_DEBUG */

    cleanup_heap();

    // manual delete
    void * const
        p_placement =
        this;

    appl_context::v_cleanup();

    p_heap->v_free(
        sizeof(
            *this),
        p_placement);

    p_heap->v_destroy();

    e_status =
        appl_status_fail;

    return
        e_status;

} // v_cleanup()

/* end-of-file: appl_context_std.cpp */
