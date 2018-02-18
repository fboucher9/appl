/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_heap.h"

#include "appl_debug.h"

#include "appl_options.h"

#include "appl_thread_mgr.h"

//
//
//
appl_context::appl_context() :
    appl_object(),
    m_heap(),
    m_debug(),
    m_options(),
    m_thread_mgr(),
    m_mutex_mgr(),
    m_file_mgr(),
    m_poll_mgr(),
    m_clock(),
    m_event_mgr()
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
class appl_context *
appl_context::convert_handle(
    struct appl_context_handle * const
        p_context_handle)
{
    return
        reinterpret_cast<class appl_context *>(
            p_context_handle);

} // convert_handle()

//
//
//
struct appl_context_handle *
appl_context::get_handle(void)
{
    return
        reinterpret_cast<struct appl_context_handle *>(
            this);

} // get_handle()

/* end-of-file: appl_context.cpp */
