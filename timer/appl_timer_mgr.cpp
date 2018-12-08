/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <timer/appl_timer_mgr.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_timer_mgr::v_create_node(
        struct appl_timer * * const
            r_timer)
{
    appl_unused(
        r_timer);

#if defined APPL_DEBUG
    {
        static char const s_msg[] =
            "timer mgr create node not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_create_node()

//
//
//
enum appl_status
    appl_timer_mgr::v_destroy_node(
        struct appl_timer * const
            p_timer)
{
    appl_unused(
        p_timer);

#if defined APPL_DEBUG
    {
        static char const s_msg[] =
            "timer mgr destroy node not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_destroy_node()

//
//
//
appl_timer_mgr::appl_timer_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_timer_mgr::~appl_timer_mgr()
{
}

/* end-of-file: appl_timer_mgr.cpp */
