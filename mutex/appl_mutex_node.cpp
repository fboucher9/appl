/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <mutex/appl_mutex_node.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_mutex::v_lock(void)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "mutex lock not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_lock()

//
//
//
enum appl_status
    appl_mutex::v_unlock(void)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "mutex unlock not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_unlock()

//
//
//
enum appl_status
    appl_mutex::v_sync(
        enum appl_status (*
            p_sync_callback)(
            void * const
                p_sync_context),
        void * const
            p_sync_context)
{
    enum appl_status
        e_status;

    appl_unused(
        p_sync_callback,
        p_sync_context);

#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "mutex sync not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_sync()

//
//
//
appl_mutex::appl_mutex() :
    appl_object()
{
}

//
//
//
appl_mutex::~appl_mutex()
{
}

/* end-of-file: appl_mutex_node.cpp */
