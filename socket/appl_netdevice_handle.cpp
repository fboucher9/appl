/* See LICENSE for license details */

#include <appl_status.h>

#include <appl_netdevice_handle.h>

#include <socket/appl_netdevice_service.h>

/*

*/
enum appl_status
    appl_netdevice_enumerate(
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
        appl_netdevice_service::s_enumerate(
            p_context,
            p_netdevice_filter,
            p_callback,
            p_callback_context);

} /* appl_netdevice_enumerate() */

/* end-of-file: appl_netdevice_handle.cpp */
