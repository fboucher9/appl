/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <mutex/appl_mutex_node.h>

#include <appl_unused.h>

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
enum appl_status
    appl_mutex::v_sync(
        enum appl_status (*
            p_sync_callback)(
            void * const
                p_sync_context),
        void * const
            p_sync_context)
{
    enum appl_status
        e_status;

    appl_unused(
        p_sync_callback,
        p_sync_context);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_sync()

//
//
//
appl_mutex::appl_mutex() :
    appl_object()
{
}

//
//
//
appl_mutex::~appl_mutex()
{
}

/* end-of-file: appl_mutex_node.cpp */
