/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <event/appl_event_node.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_event::v_signal(void)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "event signal not implemented\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_signal()

//
//
//
enum appl_status
    appl_event::v_wait(
        struct appl_mutex * const
            p_mutex,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    appl_unused(
        p_mutex,
        i_wait_freq,
        i_wait_count);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "event wait not implemented\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_wait()

//
//
//
appl_event::appl_event(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_event::~appl_event()
{
}

/* end-of-file: appl_event_node.cpp */
