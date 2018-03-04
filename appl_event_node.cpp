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
class appl_event_node *
    appl_event_node::convert_handle(
        struct appl_event_handle * const
            p_event_handle)
{
    return
        reinterpret_cast<class appl_event_node *>(
            p_event_handle);

} // convert_handle()

//
//
//
enum appl_status
    appl_event_node::v_signal(void)
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
    appl_event_node::v_wait(
        class appl_mutex_node * const
            p_mutex_node)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_mutex_node);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_wait()

//
//
//
appl_event_node::appl_event_node() :
    appl_object()
{
}

//
//
//
appl_event_node::~appl_event_node()
{
}

/* end-of-file: appl_event_node.cpp */
