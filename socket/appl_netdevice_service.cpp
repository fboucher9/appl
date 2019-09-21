/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_netdevice_handle.h>

#include <socket/appl_netdevice_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_netdevice_mgr.h>

#include <context/appl_context.h>

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
    enum appl_status
        e_status;

    class appl_netdevice_mgr *
        p_netdevice_mgr;

    e_status =
        p_context->v_netdevice_mgr(
            &(
                p_netdevice_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_netdevice_mgr->v_enumerate(
                p_netdevice_filter,
                p_callback,
                p_callback_context);
    }

    return
        e_status;

} // s_enumerate()

/* end-of-file: appl_netdevice_service.cpp */
