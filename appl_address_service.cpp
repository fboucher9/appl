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

#include "appl_address_node.h"

#include "appl_property_types.h"

#include "appl_property.h"

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
//      p_property_handle
//          Pointer to opaque appl_property_handle structure.
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
    struct appl_property_handle const * const
        p_property_handle,
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

    // Convert opaque property handle to C++ property object
    class appl_property const * const
        p_property =
        appl_property::convert_const_handle(
            p_property_handle);

    // Use the C++ context object to query socket manager
    class appl_socket_mgr * const
        p_socket_mgr =
        p_context->m_socket_mgr;

    class appl_address_node *
        p_address_node;

    // Use socket manager to dispatch this request
    e_status =
        p_socket_mgr->v_create_address(
            p_property,
            &(
                p_address_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_address_handle) =
            p_address_node->get_handle();
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_address_service::s_get_name(
    struct appl_address_handle * const
        p_address_handle,
    struct appl_buf * const
        p_name_buf)
{
    enum appl_status
        e_status;

    class appl_address_node * const
        p_address_node =
        appl_address_node::convert_handle(
            p_address_handle);

    e_status =
        p_address_node->v_get_name(
            p_name_buf);

    return
        e_status;

} // s_get_name()

//
//
//
enum appl_status
appl_address_service::s_get_port(
    struct appl_address_handle * const
        p_address_handle,
    unsigned short int * const
        r_port)
{
    enum appl_status
        e_status;

    class appl_address_node * const
        p_address_node =
        appl_address_node::convert_handle(
            p_address_handle);

    e_status =
        p_address_node->v_get_port(
            r_port);

    return
        e_status;

} // s_get_port()

/* end-of-file: appl_address_service.cpp */
