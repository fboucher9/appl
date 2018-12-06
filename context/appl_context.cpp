/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <appl_unused.h>

//
//
//
appl_context::appl_context()
    : appl_object()
    // public
    , m_allocator()
    , m_heap()
    , m_backtrace()
    , m_thread_mgr()
    // protected
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
struct appl_context *
appl_context::from_object_handle(
    struct appl_object const * const
        p_object)
{
    return
        p_object->get_context();

} // from_object_handle()

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

    return
        appl_status_not_implemented;

} // v_timer_mgr()

//
//
//
enum appl_status
    appl_context::v_xlib(
        struct appl_xlib * * const
            r_xlib) const
{
    appl_unused(
        r_xlib);

    return
        appl_status_not_implemented;

} // v_xlib()

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

    return
        appl_status_not_implemented;

}

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

    return
        appl_status_not_implemented;

}
#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_context.cpp */
