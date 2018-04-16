/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_event_node.h"

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

    static_cast<void>(
        p_mutex);
    static_cast<void>(
        i_wait_freq);
    static_cast<void>(
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
