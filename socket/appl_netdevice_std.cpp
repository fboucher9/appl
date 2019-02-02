/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_netdevice_handle.h>

#if defined APPL_OS_LINUX

#include <socket/appl_netdevice_std.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_netdevice_std::s_enumerate(
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
    appl_unused(
        p_context,
        p_netdevice_filter,
        p_callback,
        p_callback_context);

    return
        appl_raise_not_implemented();

} // s_enumerate()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_netdevice_std.h */
