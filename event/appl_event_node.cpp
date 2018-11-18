/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <event/appl_event_node.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_event::v_signal(void)
{
    enum appl_status
        e_status;

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

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_wait()

//
//
//
appl_event::appl_event() :
    appl_object()
{
}

//
//
//
appl_event::~appl_event()
{
}

/* end-of-file: appl_event_node.cpp */
