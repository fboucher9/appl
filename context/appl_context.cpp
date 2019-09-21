/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
appl_context::appl_context(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_context::~appl_context()
{
}

//
//
//
enum appl_status
    appl_context::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_context::v_cleanup(void)
{
    return
        sizeof(struct appl_context);

} // v_cleanup()

//
//
//
struct appl_allocator *
    appl_context::v_allocator(void) const
{
#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_allocator not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        0;

} // v_allocator()

//
//
//
enum appl_status
    appl_context::v_backtrace(
        class appl_backtrace * * const
            r_backtrace) const
{
    appl_unused(
        r_backtrace);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_backtrace not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_backtrace()

//
//
//
enum appl_status
    appl_context::v_thread_mgr(
        class appl_thread_mgr * * const
            r_thread_mgr) const
{
    appl_unused(
        r_thread_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_thread_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_thread_mgr()

//
//
//
enum appl_status
    appl_context::v_mutex_mgr(
        class appl_mutex_mgr * * const
            r_mutex_mgr) const
{
    appl_unused(
        r_mutex_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_mutex_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

}

//
//
//
enum appl_status
    appl_context::v_file_mgr(
        class appl_file_mgr * * const
            r_file_mgr) const
{
    appl_unused(
        r_file_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_file_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

}

//
//
//
enum appl_status
    appl_context::v_poll_mgr(
        class appl_poll_mgr * * const
            r_poll_mgr) const
{
    appl_unused(
        r_poll_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_poll_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

}

//
//
//
enum appl_status
    appl_context::v_clock(
        class appl_clock * * const
            r_clock) const
{
    appl_unused(
        r_clock);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_clock not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

}

//
//
//
enum appl_status
    appl_context::v_env(
        struct appl_env * * const
            r_env) const
{
    appl_unused(
        r_env);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_env not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_env()

//
//
//
enum appl_status
    appl_context::v_library_mgr(
        class appl_library_mgr * * const
            r_library_mgr)
{
    appl_unused(
        r_library_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_library_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_library_mgr()

//
//
//
enum appl_status
    appl_context::v_random_mgr(
        class appl_random_mgr * * const
            r_random_mgr) const
{
    appl_unused(
        r_random_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_random_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;
}

//
//
//
enum appl_status
    appl_context::v_thread_cache_mgr(
        class appl_thread_cache_mgr * * const
            r_thread_cache_mgr) const
{
    appl_unused(
        r_thread_cache_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_thread_cache_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;
}

//
//
//
enum appl_status
    appl_context::v_log(
        struct appl_log * * const
            r_log) const
{
    appl_unused(
        r_log);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_log not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

}

//
//
//
enum appl_status
    appl_context::v_pool_mgr(
        class appl_pool_mgr * * const
            r_pool_mgr) const
{
    appl_unused(
        r_pool_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_pool_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

}

//
//
//
enum appl_status
    appl_context::v_timer_mgr(
        class appl_timer_mgr * * const
            r_timer_mgr) const
{
    appl_unused(
        r_timer_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_timer_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_timer_mgr()

//
//
//
#if defined APPL_HAVE_XLIB
enum appl_status
    appl_context::v_xlib(
        struct appl_xlib * * const
            r_xlib) const
{
    appl_unused(
        r_xlib);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_xlib not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_xlib()
#endif /* #if defined APPL_HAVE_XLIB */

//
//
//
enum appl_status
    appl_context::v_socket_mgr(
        class appl_socket_mgr * * const
            r_socket_mgr) const
{
    appl_unused(
        r_socket_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_socket_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;
}

//
//
//
enum appl_status
    appl_context::v_event_mgr(
        class appl_event_mgr * * const
            r_event_mgr) const
{
    appl_unused(
        r_event_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_event_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

}

//
//
//
enum appl_status
    appl_context::v_netdevice_mgr(
        class appl_netdevice_mgr * * const
            r_netdevice_mgr) const
{
    appl_unused(
        r_netdevice_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_netdevice_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_netdevice_mgr()

//
//
//
enum appl_status
    appl_context::v_download_mgr(
        class appl_download_mgr * * const
            r_download_mgr) const
{
    appl_unused(
        r_download_mgr);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "v_download_mgr not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_download_mgr()

//
//
//
#if defined APPL_DEBUG
enum appl_status
    appl_context::v_debug(
        class appl_debug * * const
            r_debug) const
{
    appl_unused(
        r_debug);

    appl_debug_impl::s_print0(
        "v_debug not implemented\n");

    return
        appl_status_not_implemented;

}
#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_context.cpp */
