/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_mutex_node.h"

//
//
//
enum appl_status
    appl_mutex_node::v_lock(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_lock()

//
//
//
enum appl_status
    appl_mutex_node::v_unlock(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_unlock()

//
//
//
class appl_mutex_node *
appl_mutex_node::convert_handle(
    struct appl_mutex_handle * const
        p_mutex_handle)
{
    return
        reinterpret_cast<class appl_mutex_node *>(
            p_mutex_handle);

} // convert_handle()

//
//
//
appl_mutex_node::appl_mutex_node()
{
}

//
//
//
appl_mutex_node::~appl_mutex_node()
{
}

