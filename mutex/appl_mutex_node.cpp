/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <mutex/appl_mutex_node.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_mutex::v_lock(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_raise_not_implemented();

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
        appl_raise_not_implemented();

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
        appl_raise_not_implemented();

    return
        e_status;

} // v_sync()

//
//
//
appl_mutex::appl_mutex(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_mutex::~appl_mutex()
{
}

/* end-of-file: appl_mutex_node.cpp */
