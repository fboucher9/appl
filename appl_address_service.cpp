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
//      p_context
//          Opaque context handle.
//
//      p_property
//          Pointer to opaque appl_property structure.
//
//      r_address
//          Output pointer to opaque address handle.
//
//  Returns:
//      ok on success, fail otherwise.
//
enum appl_status
appl_address_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_property const * const
        p_property,
    struct appl_address * * const
        r_address)
{
    enum appl_status
        e_status;

    // Use the C++ context object to query socket manager
    class appl_socket_mgr * const
        p_socket_mgr =
        p_context->m_socket_mgr;

    struct appl_address *
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
            r_address) =
            p_address_node;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_address_service::s_get_name(
    struct appl_address * const
        p_address,
    unsigned char * * const
        pp_name_cur,
    unsigned char * const
        p_name_max)
{
    enum appl_status
        e_status;

    e_status =
        p_address->v_get_name(
            pp_name_cur,
            p_name_max);

    return
        e_status;

} // s_get_name()

//
//
//
enum appl_status
appl_address_service::s_get_port(
    struct appl_address * const
        p_address,
    unsigned short int * const
        r_port)
{
    enum appl_status
        e_status;

    e_status =
        p_address->v_get_port(
            r_port);

    return
        e_status;

} // s_get_port()

/* end-of-file: appl_address_service.cpp */
