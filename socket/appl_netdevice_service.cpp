/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_netdevice_handle.h>

#include <socket/appl_netdevice_service.h>

#if defined APPL_OS_LINUX

#include <socket/appl_netdevice_std.h>

#else /* #if defined APPL_OS_LINUX */

#include <socket/appl_netdevice_w32.h>

#endif /* #if defined APPL_OS_LINUX */

//
//
//
enum appl_status
    appl_netdevice_service::s_enumerate(
        struct appl_context * const
            p_context,
        struct appl_netdevice_descriptor const * const
            p_netdevice_filter,
        void (* p_callback)(
            void * const
                p_callback_context,
            struct appl_netdevice_descriptor const * const
                p_netdevice_descriptor),
        void * p_callback_context)
{
    return
#if defined APPL_OS_LINUX
        appl_netdevice_std
#else /* #if defined APPL_OS_LINUX */
        appl_netdevice_w32
#endif /* #if defined APPL_OS_LINUX */
        ::s_enumerate(
            p_context,
            p_netdevice_filter,
            p_callback,
            p_callback_context);

} // s_enumerate()

/* end-of-file: appl_netdevice_service.cpp */
