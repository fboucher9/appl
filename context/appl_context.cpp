/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

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
    , m_mutex_mgr()
    , m_file_mgr()
    , m_poll_mgr()
    , m_clock()
    , m_env()
    , m_library_mgr()
    , m_random_mgr()
    , m_thread_cache_mgr()
    // protected
    , m_log()
    , m_pool_mgr()
    , m_timer_mgr()
    , m_xlib()
    , m_event_mgr()
    , m_socket_mgr()
#if defined APPL_DEBUG
    , m_debug()
#endif /* #if defined APPL_DEBUG */
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

enum appl_status
    appl_context::v_random_mgr(
        class appl_random_mgr * * const
            r_random_mgr) const
{
    *(r_random_mgr) =
        m_random_mgr;

    return
        appl_status_ok;
}

enum appl_status
    appl_context::v_thread_cache_mgr(
        class appl_thread_cache_mgr * * const
            r_thread_cache_mgr) const
{
    *(r_thread_cache_mgr) =
        m_thread_cache_mgr;

    return
        appl_status_ok;
}

enum appl_status
    appl_context::v_log(
        struct appl_log * * const
            r_log) const
{
    *(r_log) =
        m_log;

    return
        appl_status_ok;

}

enum appl_status
    appl_context::v_pool_mgr(
        class appl_pool_mgr * * const
            r_pool_mgr) const
{
    *(r_pool_mgr) =
        m_pool_mgr;

    return
        appl_status_ok;

}

//
//
//
enum appl_status
    appl_context::v_timer_mgr(
        class appl_timer_mgr * * const
            r_timer_mgr) const
{
    *(r_timer_mgr) =
        m_timer_mgr;

    return
        appl_status_ok;

} // v_timer_mgr()

//
//
//
enum appl_status
    appl_context::v_xlib(
        struct appl_xlib * * const
            r_xlib) const
{
    *(r_xlib) =
        m_xlib;

    return
        appl_status_ok;

} // v_xlib()

enum appl_status
    appl_context::v_socket_mgr(
        class appl_socket_mgr * * const
            r_socket_mgr) const
{
    *(r_socket_mgr) =
        m_socket_mgr;

    return
        appl_status_ok;
}

enum appl_status
    appl_context::v_event_mgr(
        class appl_event_mgr * * const
            r_event_mgr) const
{
    *(r_event_mgr) =
        m_event_mgr;

    return
        appl_status_ok;

}

#if defined APPL_DEBUG
enum appl_status
    appl_context::v_debug(
        class appl_debug * * const
            r_debug) const
{
    *(r_debug) =
        m_debug;

    return
        appl_status_ok;

}
#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_context.cpp */
