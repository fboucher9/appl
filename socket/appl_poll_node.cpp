/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <appl_list.h>

#include <appl_node.h>

#include <appl_poll_descriptor.h>

#include <socket/appl_poll_node.h>

#include <appl_unused.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_poll::create_instance(
        struct appl_context * const
            p_context,
        class appl_poll_mgr * const
            p_poll_mgr,
        struct appl_poll_descriptor const * const
            p_poll_descriptor,
        struct appl_poll * * const
            r_poll)
{
    enum appl_status
        e_status;

    appl_unused(
        p_context,
        p_poll_mgr,
        p_poll_descriptor,
        r_poll);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // create_instance()

//
//
//
enum appl_status
    appl_poll::dispatch_event(
        unsigned int const
            i_poll_flags)
{
    enum appl_status
        e_status;

    appl_unused(
        i_poll_flags);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // dispatch_event()

//
//
//
bool
    appl_poll::is_busy(void) const
{
    return
        m_busy;

} // is_busy()

//
//
//
bool
    appl_poll::is_avail(void) const
{
    return
        m_avail;

} // is_avail()

//
//
//
appl_poll::appl_poll() :
    appl_node(),
    m_descriptor(),
    m_poll_mgr(),
    m_fd(),
    m_busy(),
    m_avail()
{
}

//
//
//
appl_poll::~appl_poll()
{
}

/* end-of-file: appl_poll_node.cpp */
