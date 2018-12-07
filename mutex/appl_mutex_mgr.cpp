/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <mutex/appl_mutex_mgr.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_mutex_mgr::v_create_node(
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex * * const
            r_mutex)
{
    enum appl_status
        e_status;

    appl_unused(
        p_mutex_descriptor,
        r_mutex);

#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "mutex mgr create node not implement\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_node()

//
//
//
enum appl_status
    appl_mutex_mgr::v_destroy_node(
        struct appl_mutex * const
            p_mutex)
{
    enum appl_status
        e_status;

    appl_unused(
        p_mutex);

#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "mutex mgr destroy node not implement\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_destroy_node()

//
//
//
appl_mutex_mgr::appl_mutex_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_mutex_mgr::~appl_mutex_mgr()
{
}

/* end-of-file: appl_mutex_mgr.cpp */
