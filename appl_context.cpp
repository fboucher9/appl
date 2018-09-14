/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_object_handle.h>

//
//
//
appl_context::appl_context() :
    appl_object(),
    m_heap(),
    m_options(),
    m_thread_mgr(),
    m_mutex_mgr(),
    m_file_mgr(),
    m_poll_mgr(),
    m_clock(),
    m_event_mgr(),
    m_socket_mgr(),
    m_env(),
    m_library_mgr(),
    m_random_mgr(),
    m_thread_cache_mgr()
#if defined APPL_DEBUG
    ,
    m_debug()
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
        appl_object_get_context(
            p_object);

} // from_object_handle()

/* end-of-file: appl_context.cpp */
