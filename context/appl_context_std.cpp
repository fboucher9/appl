/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include <appl_status.h>

#include <appl_predefines.h>

#include <context/appl_context_handle.h>

#include <buf/appl_buf.h>

#include <buf/appl_buf0.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <context/appl_context.h>

#include <allocator/appl_allocator.h>

#include <allocator/appl_allocator_std.h>

#include <heap/appl_heap.h>

#include <heap/appl_heap_std.h>

#include <context/appl_context_std.h>

#include <allocator/appl_allocator_handle.h>

#if defined APPL_DEBUG

#include <list/appl_list.h>

#include <mutex/appl_mutex_impl.h>

#include <heap/appl_heap_dbg.h>

#include <debug/appl_debug_impl.h>

#endif /* #if defined APPL_DEBUG */

#if defined APPL_DEBUG

#include <debug/appl_debug.h>

#if defined APPL_OS_LINUX

#include <debug/appl_debug_std.h>

#elif defined APPL_OS_WINDOWS

#include <debug/appl_debug_w32.h>

#endif /* #if defined APPL_OS_Xx */

#endif /* #if defined APPL_DEBUG */

#include <thread/appl_thread_mgr.h>

#include <thread/appl_thread_std_mgr.h>

#include <file/appl_file_mgr.h>

#include <file/appl_file_std_mgr.h>

#include <mutex/appl_mutex_mgr.h>

#include <mutex/appl_mutex_std_mgr.h>

#include <list/appl_node.h>

#include <socket/appl_poll_mgr.h>

#include <clock/appl_clock.h>

#if defined APPL_OS_LINUX

#include <clock/appl_clock_std.h>

#elif defined APPL_OS_WINDOWS

#include <clock/appl_clock_w32.h>

#endif /* #if defined APPL_OS_Xx */

#include <event/appl_event_mgr.h>

#include <event/appl_event_std_mgr.h>

#include <socket/appl_socket_mgr.h>

#if defined APPL_OS_LINUX

#include <socket/appl_socket_std_mgr.h>

#elif defined APPL_OS_WINDOWS

#include <socket/appl_socket_w32_mgr.h>

#endif /* #if defined APPL_OS_Xx */

#include <socket/appl_netdevice_mgr.h>

#if defined APPL_OS_LINUX

#include <socket/appl_netdevice_std.h>

#elif defined APPL_OS_WINDOWS

#include <socket/appl_netdevice_w32.h>

#endif /* #if defined APPL_OS_Xx */

#include <env/appl_env.h>

#if defined APPL_OS_LINUX

#include <env/appl_env_std.h>

#elif defined APPL_OS_WINDOWS

#include <env/appl_env_w32.h>

#endif /* #if defined APPL_OS_Xx */

#include <random/appl_random_mgr.h>

#if defined APPL_OS_LINUX

#include <random/appl_random_std_mgr.h>

#elif defined APPL_OS_WINDOWS

#include <random/appl_random_w32_mgr.h>

#endif

#include <log/appl_log_handle.h>

#include <log/appl_log.h>

#include <log/appl_log_impl.h>

#include <log/appl_log_std.h>

#include <pool/appl_pool_mgr.h>

#include <thread/appl_thread_cache.h>

#include <timer/appl_timer_mgr.h>

#include <timer/appl_timer_std_mgr.h>

#if defined APPL_HAVE_XLIB

#include <X11/Xlib.h>

#include <xlib/appl_xlib.h>

#include <xlib/appl_xlib_intf.h>

#include <xlib/appl_xlib_std.h>

#endif /* #if defined APPL_HAVE_XLIB */

#include <backtrace/appl_backtrace.h>

#include <backtrace/appl_backtrace_std.h>

#include <socket/appl_download_mgr.h>

#include <dir/appl_dir_mgr.h>

#if defined APPL_OS_LINUX

#include <dir/appl_dir_std_mgr.h>

#elif defined APPL_OS_WINDOWS

#include <dir/appl_dir_w32_mgr.h>

#endif /* #if defined APPL_OS_Xx */

#include <unique/appl_unique_mgr.h>

#include <unique/appl_unique_std_mgr.h>

#include <thread/appl_once.h>

#include <misc/appl_convert.h>

#include <misc/appl_unused.h>

#if defined APPL_HAVE_COVERAGE
#include <coverage/appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

extern
enum appl_status
    appl_library_mgr_create(
        struct appl_allocator * const
            p_allocator,
        class appl_library_mgr * * const
            r_library_mgr);

extern
enum appl_status
    appl_library_mgr_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_library_mgr * const
            p_library_mgr);

//
//
//
class appl_context_default : public appl_context
{
    friend class appl_context_std;

    public:

        appl_context_default();

        virtual
        ~appl_context_default();

        void
            f_init(void);

    protected:

    private:

        class appl_allocator_std
            m_allocator_std;

        // --

        struct appl_allocator *
            m_allocator;

#define PADDING (APPL_SIZEOF_PTR)
#include <misc/appl_padding.h>

        // --

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        struct appl_allocator *
            v_allocator(void) const;

        appl_context_default(
            class appl_context_default const & r);

        class appl_context_default &
            operator =(
                class appl_context_default const & r);

}; // class appl_context_default

appl_context_default::appl_context_default() :
    appl_context(this),
    m_allocator_std(this),
    m_allocator()
{
}

appl_context_default::~appl_context_default()
{
}

void
appl_context_default::f_init(void)
{
    m_allocator_std.f_init();

    m_allocator =
        &(
            m_allocator_std);
}

appl_size_t
appl_context_default::v_cleanup(void)
{
    return
        0;

}

struct appl_allocator *
    appl_context_default::v_allocator(void) const
{
    return
        m_allocator;

}

static unsigned char g_context_default_placement[sizeof(class appl_context_default)];

static class appl_context_default * g_context_default = 0;

//
//
//
enum appl_status
    appl_context_std::init_heap(void)
{
    enum appl_status
        e_status;

    e_status =
        m_heap_std.f_init();

    if (
        appl_status_ok
        == e_status)
    {
#if defined APPL_DEBUG
        e_status =
            appl_heap_dbg::s_create(
                &(
                    m_heap_std),
                &(
                    m_heap_dbg));

        if (
            appl_status_ok
            == e_status)
#endif /* #if defined APPL_DEBUG */
        {
            m_allocator =
#if defined APPL_DEBUG
                m_heap_dbg
#else /* #if defined APPL_DEBUG */
                &(
                    m_heap_std)
#endif /* #if defined APPL_DEBUG */
                ;

            b_init_allocator =
                true;

#if defined APPL_DEBUG
            if (
                appl_status_ok != e_status)
            {
                appl_heap_dbg::s_destroy(
                    &(
                        m_heap_std),
                    m_heap_dbg);
            }
#endif /* #if defined APPL_DEBUG */
        }

        if (
            appl_status_ok != e_status)
        {
            m_heap_std.v_cleanup();
        }
    }

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
        b_init_allocator)
    {
#if defined APPL_DEBUG
        appl_heap_dbg::s_destroy(
            &(
                m_heap_std),
            m_heap_dbg);

        m_heap_dbg =
            0;
#endif /* #if defined APPL_DEBUG */

        m_heap_std.v_cleanup();

        m_allocator =
            0;

        b_init_allocator =
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
            m_allocator,
            &(
                m_debug));

#elif defined APPL_OS_WINDOWS

    e_status =
        appl_debug_w32::s_create(
            m_allocator,
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
#if defined APPL_OS_LINUX

        appl_debug_std::s_destroy(
            m_allocator,
            m_debug);

#else /* #if defined APPL_OS_Xx */

        appl_debug_w32::s_destroy(
            m_allocator,
            m_debug);

#endif /* #if defined APPL_OS_Xx */

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
appl_context_std::init_thread_mgr(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_std_mgr::s_create(
            m_allocator,
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
        appl_thread_std_mgr::s_destroy(
            m_allocator,
            m_thread_mgr);

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
            m_allocator,
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
        appl_mutex_std_mgr::s_destroy(
            m_allocator,
            m_mutex_mgr);

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
            m_allocator,
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
        appl_file_std_mgr::s_destroy(
            m_allocator,
            m_file_mgr);

        m_file_mgr =
            0;

        b_init_file_mgr =
            false;
    }
}

//
//
//
#if 0
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
#endif

//
//
//
#if 0
void
    appl_context_std::cleanup_poll_mgr(void)
{
    if (
        b_init_poll_mgr)
    {
#if 0
        appl_poll_mgr::s_destroy(
            m_allocator,
            m_poll_mgr);
#endif

        m_poll_mgr =
            0;

        b_init_poll_mgr =
            false;
    }
}
#endif

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
#if defined APPL_OS_LINUX

        appl_clock_std::s_destroy(
            m_allocator,
            m_clock);

#elif defined APPL_OS_WINDOWS

        appl_clock_w32::s_destroy(
            m_allocator,
            m_clock);

#else /* #if defined APPL_OS_Xx */

#endif /* #if defined APPL_OS_Xx */

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

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_event_mgr,
        "event mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

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
        appl_event_std_mgr::s_destroy(
            m_allocator,
            m_event_mgr);

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

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_socket_mgr,
        "socket mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

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
#if defined APPL_OS_LINUX
        appl_socket_std_mgr::s_destroy(
            m_allocator,
            m_socket_mgr);
#elif defined APPL_OS_WINDOWS
        appl_socket_w32_mgr::s_destroy(
            m_allocator,
            m_socket_mgr);
#else /* #if defined APPL_OS_Xx */
#endif /* #if defined APPL_OS_Xx */

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

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_env,
        "env already initialized\n");
#endif /* #if defined APPL_DEBUG */

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
#if defined APPL_OS_LINUX
        appl_env_std::s_destroy(
            m_allocator,
            m_env);
#elif defined APPL_OS_WINDOWS
        appl_env_w32::s_destroy(
            m_allocator,
            m_env);
#else /* #if defined APPL_OS_Xx */
#endif /* #if defined APPL_OS_Xx */

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

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_library_mgr,
        "library mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

    {
        e_status =
            appl_library_mgr_create(
                m_allocator,
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
            m_allocator,
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

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_random_mgr,
        "random mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

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
#if defined APPL_OS_LINUX
        appl_random_std_mgr::s_destroy(
            m_allocator,
            m_random_mgr);
#elif defined APPL_OS_WINDOWS
        appl_random_w32_mgr::s_destroy(
            m_allocator,
            m_random_mgr);
#else /* #if defined APPL_OS_LINUX */
#endif /* #if defined APPL_OS_LINUX */

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

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_log,
        "log already initialized\n");
#endif /* #if defined APPL_DEBUG */

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
        appl_log_std::s_destroy(
            m_allocator,
            m_log);

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

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_pool_mgr,
        "pool mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

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
        appl_pool_mgr::s_destroy(
            m_allocator,
            m_pool_mgr);

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

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_thread_cache_mgr,
        "thread cache mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

    {
        e_status =
            appl_thread_cache_mgr_create(
                m_allocator,
                &(
                    m_thread_cache_mgr));

        b_init_thread_cache_mgr =
            true;
    }

    return
        e_status;

} // init_thread_cache_mgr()

extern
enum appl_status
appl_thread_cache_mgr_destroy(
    struct appl_allocator * const
        p_allocator,
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
            m_allocator,
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

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_timer_mgr,
        "timer mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

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
        appl_delete(
            m_allocator,
            m_timer_mgr);

        m_timer_mgr =
            0;

        b_init_timer_mgr =
            false;
    }

} // cleanup_timer_mgr()

//
//
//
#if defined APPL_HAVE_XLIB
enum appl_status
    appl_context_std::init_xlib(void)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_xlib,
        "xlib already initialized\n");
#endif /* #if defined APPL_DEBUG */

    {
        e_status =
            appl_xlib_std::s_create(
                m_allocator,
                &(
                    m_xlib));

        if (
            appl_status_ok
            == e_status)
        {
            b_init_xlib =
                true;
        }
    }

    return
        e_status;

} // init_xlib()
#endif /* #if defined APPL_HAVE_XLIB */

//
//
//
#if defined APPL_HAVE_XLIB
void
    appl_context_std::cleanup_xlib(void)
{
    if (
        b_init_xlib)
    {
        appl_delete(
            m_allocator,
            m_xlib);

        m_xlib =
            0;

        b_init_xlib =
            false;
    }
} // cleanup_xlib()
#endif /* #if defined APPL_HAVE_XLIB */

//
//
//
enum appl_status
    appl_context_std::init_backtrace(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_backtrace_std::s_create(
            m_allocator,
            &(
                m_backtrace));

    if (
        appl_status_ok
        == e_status)
    {
        b_init_backtrace =
            true;
    }

    return
        e_status;

} // init_backtrace()

//
//
//
void
    appl_context_std::cleanup_backtrace(void)
{
    if (
        b_init_backtrace)
    {
        appl_backtrace_std::s_destroy(
            m_allocator,
            m_backtrace);

        m_backtrace =
            0;

        b_init_backtrace =
            false;
    }
} // cleanup_backtrace()

//
//
//
enum appl_status
    appl_context_std::init_netdevice_mgr(void)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_netdevice_mgr,
        "netdevice already initialized\n");
#endif /* #if defined APPL_DEBUG */

#if defined APPL_OS_LINUX
    {
        class appl_netdevice_std *
            p_netdevice_std;

        e_status =
            appl_new(
                m_allocator,
                &(
                    p_netdevice_std));

        if (
            appl_status_ok
            == e_status)
        {
            m_netdevice_mgr =
                p_netdevice_std;

            b_init_netdevice_mgr =
                true;
        }
    }
#elif defined APPL_OS_WINDOWS
    {
        class appl_netdevice_w32 *
            p_netdevice_w32;

        e_status =
            appl_new(
                m_allocator,
                &(
                    p_netdevice_w32));

        if (
            appl_status_ok
            == e_status)
        {
            m_netdevice_mgr =
                p_netdevice_w32;

            b_init_netdevice_mgr =
                true;
        }
    }
#else /* #if defined APPL_OS_Xx */
    e_status =
        appl_status_fail;
#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // init_netdevice_mgr()

//
//
//
void
    appl_context_std::cleanup_netdevice_mgr(void)
{
    if (
        b_init_netdevice_mgr)
    {
        appl_delete(
            m_allocator,
            m_netdevice_mgr);

        b_init_netdevice_mgr =
            false;
    }
} // cleanup_netdevice_mgr()

//
//
//
enum appl_status
    appl_context_std::init_download_mgr(void)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_download_mgr,
        "download_mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_new(
            m_allocator,
            &(
                m_download_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        b_init_download_mgr =
            true;
    }

    return
        e_status;

} // init_download_mgr()

//
//
//
void
    appl_context_std::cleanup_download_mgr(void)
{
    if (
        b_init_download_mgr)
    {
        appl_delete(
            m_allocator,
            m_download_mgr);

        b_init_download_mgr =
            false;
    }
} // cleanup_download_mgr()

//
//
//
enum appl_status
    appl_context_std::init_dir_mgr(void)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_dir_mgr,
        "dir_mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

#if defined APPL_OS_LINUX
    class appl_dir_std_mgr *
        p_dir_std_mgr;

    e_status =
        appl_new(
            m_allocator,
            &(
                p_dir_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        m_dir_mgr =
            p_dir_std_mgr;
    }
#elif defined APPL_OS_WINDOWS
    class appl_dir_w32_mgr *
        p_dir_w32_mgr;

    e_status =
        appl_new(
            m_allocator,
            &(
                p_dir_w32_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        m_dir_mgr =
            p_dir_w32_mgr;
    }
#else /* #if defined APPL_OS_LINUX */
    e_status =
        appl_raise_not_implemented();
#endif /* #if defined APPL_OS_LINUX */

    if (
        appl_status_ok
        == e_status)
    {
        b_init_dir_mgr =
            true;
    }

    return
        e_status;

} // init_dir_mgr()

//
//
//
void
    appl_context_std::cleanup_dir_mgr(void)
{
    if (
        b_init_dir_mgr)
    {
        appl_delete(
            m_allocator,
            m_dir_mgr);

        b_init_dir_mgr =
            false;
    }
} // cleanup_dir_mgr()

//
//
//
enum appl_status
    appl_context_std::init_unique_mgr(void)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_debug_impl::s_validate(
        !b_init_unique_mgr,
        "unique_mgr already initialized\n");
#endif /* #if defined APPL_DEBUG */

    class appl_unique_std_mgr *
        p_unique_std_mgr;

    e_status =
        appl_new(
            m_allocator,
            &(
                p_unique_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        m_unique_mgr =
            p_unique_std_mgr;
    }

    if (
        appl_status_ok
        == e_status)
    {
        b_init_unique_mgr =
            true;
    }

    return
        e_status;

} // init_unique_mgr()

//
//
//
void
    appl_context_std::cleanup_unique_mgr(void)
{
    if (
        b_init_unique_mgr)
    {
        appl_delete(
            m_allocator,
            m_unique_mgr);

        b_init_unique_mgr =
            false;
    }
} // cleanup_unique_mgr()


//
//
//
void
    appl_context_std::s_bootstrap(void)
{
    // Initialize global stuff here...
    g_context_default = new(g_context_default_placement) class appl_context_default;

    g_context_default->f_init();

} // s_bootstrap()

//
//
//
enum appl_status
    appl_context_std::s_create(
        struct appl_context * * const
            r_context)
{
    static
    struct appl_once
    g_bootstrap =
    {
        APPL_ONCE_INIT
    };

    enum appl_status
        e_status;

    appl_once_dispatch(
        &(
            g_bootstrap),
        &(
            appl_context_std::s_bootstrap));

    class appl_context_std *
        p_context_std;

    e_status =
        appl_new(
            g_context_default->m_allocator,
            &(
                p_context_std));

    if (
        appl_status_ok == e_status)
    {
        *(
            r_context) =
            p_context_std;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_context_std::s_destroy(
        struct appl_context * const
            p_context)
{
    return
        appl_delete(
            g_context_default->m_allocator,
            p_context);

} // s_destroy()

//
//
//
appl_context_std::appl_context_std(
    struct appl_context * const
        p_context) :
    appl_context(
        this)
    , m_heap_std(
        this)
    , m_allocator()
    , m_backtrace()
    , m_thread_mgr()
    , m_mutex_mgr()
    , m_file_mgr()
    , m_poll_mgr()
    , m_clock()
    , m_env()
    , m_library_mgr()
    , m_random_mgr()
    , m_thread_cache_mgr()
    , m_log()
    , m_pool_mgr()
    , m_timer_mgr()
#if defined APPL_HAVE_XLIB
    , m_xlib()
#endif /* #if defined APPL_HAVE_XLIB */
    , m_event_mgr()
    , m_socket_mgr()
    , m_netdevice_mgr()
    , m_download_mgr()
    , m_dir_mgr()
    , m_unique_mgr()
#if defined APPL_DEBUG
    , m_heap_dbg()
    , m_debug()
#endif /* #if defined APPL_DEBUG */
    , b_init_allocator()
#if defined APPL_DEBUG
    , b_init_debug()
#endif /* #if defined APPL_DEBUG */
    , b_init_thread_mgr()
    , b_init_mutex_mgr()
    , b_init_file_mgr()
    , b_init_poll_mgr()
    , b_init_clock()
    , b_init_event_mgr()
    , b_init_socket_mgr()
    , b_init_env()
    , b_init_library_mgr()
    , b_init_random_mgr()
    , b_init_log()
    , b_init_pool_mgr()
    , b_init_thread_cache_mgr()
    , b_init_timer_mgr()
#if defined APPL_HAVE_XLIB
    , b_init_xlib()
#endif /* #if defined APPL_HAVE_XLIB */
    , b_init_backtrace()
    , b_init_netdevice_mgr()
    , b_init_download_mgr()
    , b_init_dir_mgr()
    , b_init_unique_mgr()
{
    appl_unused(
        p_context);
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
    {   & appl_context_std::init_heap,
        & appl_context_std::cleanup_heap
    },
#if defined APPL_DEBUG
    {
        & appl_context_std::init_debug,
        & appl_context_std::cleanup_debug
    },
#endif /* #if defined APPL_DEBUG */
    {
        & appl_context_std::init_backtrace,
        & appl_context_std::cleanup_backtrace
    },
    {
        & appl_context_std::init_clock,
        & appl_context_std::cleanup_clock
    },
    {
        & appl_context_std::init_env,
        & appl_context_std::cleanup_env
    },
    {
        & appl_context_std::init_pool_mgr,
        & appl_context_std::cleanup_pool_mgr
    },
    {
        & appl_context_std::init_mutex_mgr,
        & appl_context_std::cleanup_mutex_mgr
    },
    {
        & appl_context_std::init_event_mgr,
        & appl_context_std::cleanup_event_mgr
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
        & appl_context_std::init_netdevice_mgr,
        & appl_context_std::cleanup_netdevice_mgr
    },
    {
        & appl_context_std::init_socket_mgr,
        & appl_context_std::cleanup_socket_mgr
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
    },
    {
        & appl_context_std::init_download_mgr,
        & appl_context_std::cleanup_download_mgr
    },
    {
        & appl_context_std::init_dir_mgr,
        & appl_context_std::cleanup_dir_mgr
    },
    {
        & appl_context_std::init_unique_mgr,
        & appl_context_std::cleanup_unique_mgr
    }
#if defined APPL_HAVE_XLIB
    , {
        & appl_context_std::init_xlib,
        & appl_context_std::cleanup_xlib
    }
#endif /* #if defined APPL_HAVE_XLIB */
};

//
//
//
enum appl_status
    appl_context_std::f_init(void)
{
    enum appl_status
        e_status;

    m_context =
        this;

    {
        unsigned int
            i_item_iterator;

        i_item_iterator =
            0;

        e_status =
            appl_status_ok;

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
#if defined APPL_DEBUG
                appl_debug_impl::s_print0(
                    "cleanup during failed init\n");
#endif /* #if defined APPL_DEBUG */

                while (i_item_iterator)
                {
                    i_item_iterator --;

                    p_item =
                        g_init_cleanup_items + i_item_iterator;

                    ((this)->*(p_item->p_cleanup))();
                }
            }
        }
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_context_std::v_cleanup(void)
{
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

    return
        sizeof(class appl_context_std);

} // v_cleanup()

//
//
//
struct appl_allocator *
    appl_context_std::v_allocator(void) const
{
#if defined APPL_DEBUG
    if (
        !b_init_allocator)
    {
        appl_debug_impl::s_print0(
            "allocator not initialized\n");
    }
#endif /* #if defined APPL_DEBUG */

    return
        m_allocator;

} // v_allocator()

//
//
//
enum appl_status
    appl_context_std::v_backtrace(
        class appl_backtrace * * const
            r_backtrace) const
{
    enum appl_status
        e_status;

    if (
        b_init_backtrace)
    {
        *(r_backtrace) =
            m_backtrace;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "backtrace not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_backtrace()

//
//
//
enum appl_status
    appl_context_std::v_thread_mgr(
        class appl_thread_mgr * * const
            r_thread_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_thread_mgr)
    {
        *(r_thread_mgr) =
            m_thread_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "thread_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_thread_mgr()

//
//
//
enum appl_status
    appl_context_std::v_mutex_mgr(
        class appl_mutex_mgr * * const
            r_mutex_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_mutex_mgr)
    {
        *(r_mutex_mgr) =
            m_mutex_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "mutex_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_mutex_mgr()

//
//
//
enum appl_status
    appl_context_std::v_file_mgr(
        class appl_file_mgr * * const
            r_file_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_file_mgr)
    {
        *(r_file_mgr) =
            m_file_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "file_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_file_mgr()

//
//
//
#if 0
enum appl_status
    appl_context_std::v_poll_mgr(
        class appl_poll_mgr * * const
            r_poll_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_poll_mgr)
    {
        *(r_poll_mgr) =
            m_poll_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "poll_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_poll_mgr()
#endif

//
//
//
enum appl_status
    appl_context_std::v_clock(
        class appl_clock * * const
            r_clock) const
{
    enum appl_status
        e_status;

    if (
        b_init_clock
#if defined APPL_HAVE_COVERAGE
        && !appl_coverage_check()
#endif /* #if defined APPL_HAVE_COVERAGE */
        )
    {
        *(r_clock) =
            m_clock;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "clock not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_clock()

//
//
//
enum appl_status
    appl_context_std::v_env(
        struct appl_env * * const
            r_env) const
{
    enum appl_status
        e_status;

    if (
        b_init_env)
    {
        *(r_env) =
            m_env;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "env not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_env()

//
//
//
enum appl_status
    appl_context_std::v_library_mgr(
        class appl_library_mgr * * const
            r_library_mgr)
{
    enum appl_status
        e_status;

    if (
        b_init_library_mgr)
    {
        *(r_library_mgr) =
            m_library_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "library_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_library_mgr()

//
//
//
enum appl_status
    appl_context_std::v_random_mgr(
        class appl_random_mgr * * const
            r_random_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_random_mgr)
    {
        *(r_random_mgr) =
            m_random_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "random_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

//
//
//
enum appl_status
    appl_context_std::v_thread_cache_mgr(
        class appl_thread_cache_mgr * * const
            r_thread_cache_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_thread_cache_mgr)
    {
        *(r_thread_cache_mgr) =
            m_thread_cache_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "thread_cache_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

//
//
//
enum appl_status
    appl_context_std::v_log(
        struct appl_log * * const
            r_log) const
{
    enum appl_status
        e_status;

    if (
        b_init_log)
    {
        *(r_log) =
            m_log;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "log not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

//
//
//
enum appl_status
    appl_context_std::v_pool_mgr(
        class appl_pool_mgr * * const
            r_pool_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_pool_mgr)
    {
        *(r_pool_mgr) =
            m_pool_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "pool_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

//
//
//
enum appl_status
    appl_context_std::v_timer_mgr(
        class appl_timer_mgr * * const
            r_timer_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_timer_mgr)
    {
        *(r_timer_mgr) =
            m_timer_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "timer_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_timer_mgr()

//
//
//
#if defined APPL_HAVE_XLIB
enum appl_status
    appl_context_std::v_xlib(
        struct appl_xlib * * const
            r_xlib) const
{
    enum appl_status
        e_status;

    if (
        b_init_xlib)
    {
        *(r_xlib) =
            m_xlib;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "xlib not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_xlib()
#endif /* #if defined APPL_HAVE_XLIB */

//
//
//
enum appl_status
    appl_context_std::v_socket_mgr(
        class appl_socket_mgr * * const
            r_socket_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_socket_mgr)
    {
        *(r_socket_mgr) =
            m_socket_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "socket_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

//
//
//
enum appl_status
    appl_context_std::v_event_mgr(
        class appl_event_mgr * * const
            r_event_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_event_mgr)
    {
        *(r_event_mgr) =
            m_event_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "event_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

//
//
//
enum appl_status
    appl_context_std::v_netdevice_mgr(
        class appl_netdevice_mgr * * const
            r_netdevice_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_netdevice_mgr)
    {
        *(
            r_netdevice_mgr) =
            m_netdevice_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "netdevice_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_netdevice_mgr()

//
//
//
enum appl_status
    appl_context_std::v_download_mgr(
        class appl_download_mgr * * const
            r_download_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_download_mgr)
    {
        *(
            r_download_mgr) =
            m_download_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "download_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_download_mgr()

//
//
//
enum appl_status
    appl_context_std::v_dir_mgr(
        class appl_dir_mgr * * const
            r_dir_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_dir_mgr)
    {
        *(
            r_dir_mgr) =
            m_dir_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "dir_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_dir_mgr()

//
//
//
enum appl_status
    appl_context_std::v_unique_mgr(
        class appl_unique_mgr * * const
            r_unique_mgr) const
{
    enum appl_status
        e_status;

    if (
        b_init_unique_mgr)
    {
        *(
            r_unique_mgr) =
            m_unique_mgr;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "unique_mgr not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_unique_mgr()

//
//
//
#if defined APPL_DEBUG
enum appl_status
    appl_context_std::v_debug(
        class appl_debug * * const
            r_debug) const
{
    enum appl_status
        e_status;

    if (
        b_init_debug)
    {
        *(r_debug) =
            m_debug;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "debug not initialized\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

}
#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_context_std.cpp */
