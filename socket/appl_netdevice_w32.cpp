/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <socket/appl_netdevice_handle.h>

#if defined APPL_OS_WINDOWS

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_netdevice_mgr.h>

#include <socket/appl_netdevice_w32.h>

#include <appl_unused.h>

//
//
//
appl_netdevice_w32::appl_netdevice_w32(
    struct appl_context * const
        p_context) :
    appl_netdevice_mgr(
        p_context)
{
}

//
//
//
appl_netdevice_w32::~appl_netdevice_w32()
{
}

//
//
//
enum appl_status
    appl_netdevice_w32::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_netdevice_w32::v_cleanup(void)
{
    return
        sizeof(class appl_netdevice_w32);

} // v_cleanup()

//
//
//
enum appl_status
    appl_netdevice_w32::v_enumerate(
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

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_netdevice_w32.cpp */
