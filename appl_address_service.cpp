/* See LICENSE for license details */

/*

Module: appl_address_service.cpp

Description:
    Services for handling of address handles.

*/

#include "appl_status.h"

#include "appl_address_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_socket_mgr.h"

#include "appl_context.h"

//
//  Function: s_create
//
//  Description:
//      Create an instance of an address node using information provided by the
//      address descriptor.
//
//  Parameters:
//      p_context_handle
//          Opaque context handle.
//
//      p_address_descriptor
//          Pointer to transparent appl_address_descriptor structure.
//
//      r_address_handle
//          Output pointer to opaque address handle.
//
//  Returns:
//      ok on success, fail otherwise.
//
enum appl_status
appl_address_service::s_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_address_descriptor const * const
        p_address_descriptor,
    struct appl_address_handle * * const
        r_address_handle)
{
    enum appl_status
        e_status;

    // Convert opaque context handle to C++ context object
    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    // Use the C++ context object to query socket manager
    class appl_socket_mgr * const
        p_socket_mgr =
        p_context->m_socket_mgr;

    // Use socket manager to dispatch this request
    e_status =
        p_socket_mgr->v_create_address(
            p_address_descriptor,
            reinterpret_cast<class appl_address_node * *>(
                r_address_handle));

    return
        e_status;

} // s_create()

/* end-of-file: appl_address_service.cpp */
