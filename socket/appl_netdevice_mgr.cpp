/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_netdevice_mgr.h>

#include <appl_netdevice_handle.h>

#include <appl_unused.h>

//
//
//
appl_netdevice_mgr::appl_netdevice_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_netdevice_mgr::~appl_netdevice_mgr()
{
}

//
//
//
enum appl_status
    appl_netdevice_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_netdevice_mgr::v_cleanup(void)
{
    return
        sizeof(class appl_netdevice_mgr);

} // v_cleanup

//
//
//
enum appl_status
    appl_netdevice_mgr::v_enumerate(
        struct appl_netdevice_descriptor const * const
            p_netdevice_filter,
        void (* p_callback)(
            void * const
                p_callback_context,
            struct appl_netdevice_descriptor const * const
                p_netdevice_descriptor),
        void * p_callback_context)
{
    appl_unused(
        p_netdevice_filter,
        p_callback,
        p_callback_context);

    return
        appl_raise_not_implemented();

} // v_enumerate()

/* end-of-file: appl_netdevice_mgr.cpp */
