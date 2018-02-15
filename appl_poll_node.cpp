/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_list.h"

#include "appl_node.h"

#include "appl_poll_descriptor.h"

#include "appl_poll_node.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_poll_node::create_instance(
        class appl_context * const
            p_context,
        class appl_poll_mgr * const
            p_poll_mgr,
        struct appl_poll_descriptor const * const
            p_poll_descriptor,
        class appl_poll_node * * const
            r_poll_node)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_context);
    static_cast<void>(
        p_poll_mgr);
    static_cast<void>(
        p_poll_descriptor);
    static_cast<void>(
        r_poll_node);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // create_instance()

//
//
//
enum appl_status
    appl_poll_node::dispatch_event(
        unsigned int const
            i_poll_flags)
{
    enum appl_status
        e_status;

    static_cast<void>(
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
    appl_poll_node::is_busy(void) const
{
    return
        m_busy;

} // is_busy()

//
//
//
bool
    appl_poll_node::is_avail(void) const
{
    return
        m_avail;

} // is_avail()

//
//
//
appl_poll_node::appl_poll_node() :
    appl_node(),
    m_poll_mgr(),
    m_descriptor(),
    m_fd(),
    m_busy(),
    m_avail()
{
}

//
//
//
appl_poll_node::~appl_poll_node()
{
}

/* end-of-file: appl_poll_node.cpp */
