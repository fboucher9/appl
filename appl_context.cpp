/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

//
//
//
appl_context::appl_context()
    : appl_object()
    , m_allocator()
    , m_heap()
    , m_thread_mgr()
    , m_mutex_mgr()
    , m_file_mgr()
    , m_poll_mgr()
    , m_clock()
    , m_event_mgr()
    , m_socket_mgr()
    , m_env()
    , m_library_mgr()
    , m_random_mgr()
    , m_thread_cache_mgr()
    , m_log()
    , m_pool_mgr()
    , m_timer_mgr()
    , m_xlib()
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

/* end-of-file: appl_context.cpp */
