/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_mutex_node.h>

//
//
//
enum appl_status
    appl_mutex::v_lock(void)
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
    appl_mutex::v_unlock(void)
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
appl_mutex::appl_mutex() :
    appl_heap_object()
{
}

//
//
//
appl_mutex::~appl_mutex()
{
}

