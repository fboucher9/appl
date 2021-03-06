/* See LICENSE for license details */

/*

Module: appl_address_service.cpp

Description:
    Services for handling of address handles.

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <socket/appl_address_property.h>

#include <socket/appl_address_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <socket/appl_socket_mgr.h>

#include <context/appl_context.h>

#include <socket/appl_address_node.h>

#include <property/appl_property_types.h>

#include <property/appl_property.h>

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
    struct appl_address_property const * const
        p_address_property,
    struct appl_address * * const
        r_address)
{
    enum appl_status
        e_status;

    // Use the C++ context object to query socket manager
    class appl_socket_mgr *
        p_socket_mgr;

    e_status =
        p_context->v_socket_mgr(
            &(
                p_socket_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_address *
            p_address_node;

        // Use socket manager to dispatch this request
        e_status =
            p_socket_mgr->v_create_address(
                p_address_property,
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
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_address_service::s_destroy(
    struct appl_address * const
        p_address)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_address->get_context();

    class appl_socket_mgr *
        p_socket_mgr;

    e_status =
        p_context->v_socket_mgr(
            &(
                p_socket_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_socket_mgr->v_destroy_address(
                p_address);
    }

    return
        e_status;

} // s_destroy()

//
//
//
struct appl_object *
appl_address_service::s_parent(
    struct appl_address * const
        p_address)
{
    return
        p_address;

} // s_parent()

//
//
//
struct appl_object const *
appl_address_service::s_const_parent(
    struct appl_address const * const
        p_address)
{
    return
        p_address;

} // s_const_parent()

//
//
//
enum appl_status
appl_address_service::s_get_name_len(
    struct appl_address const * const
        p_address,
    unsigned long int * const
        r_name_len)
{
    enum appl_status
        e_status;

    e_status =
        p_address->v_get_name_len(
            r_name_len);

    return
        e_status;

} // s_get_name_len()

//
//
//
enum appl_status
appl_address_service::s_get_name(
    struct appl_address const * const
        p_address,
    unsigned char * const
        p_name_min,
    unsigned char * const
        p_name_max,
    unsigned char * * const
        r_name_cur)
{
    enum appl_status
        e_status;

    e_status =
        p_address->v_get_name(
            p_name_min,
            p_name_max,
            r_name_cur);

    return
        e_status;

} // s_get_name()

//
//
//
enum appl_status
appl_address_service::s_get_port(
    struct appl_address const * const
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

//
//
//
enum appl_status
appl_address_service::s_get_family(
    struct appl_address const * const
        p_address,
    int * const
        r_family)
{
    enum appl_status
        e_status;

    e_status =
        p_address->v_get_family(
            r_family);

    return
        e_status;

} // s_get_family()

//
//
//
enum appl_status
appl_address_service::s_get_index(
    struct appl_address const * const
        p_address,
    unsigned int * const
        r_index)
{
    return
        p_address->v_get_index(
            r_index);

} // s_get_index()

//
//
//
enum appl_status
appl_address_service::s_resolve(
    struct appl_context * const
        p_context,
    struct appl_address_descriptor const * const
        p_address_descriptor,
    void (* p_callback)(
        void * const
            p_callback_context,
        struct appl_address_descriptor const * const
            p_address_descriptor),
    void * const
        p_callback_context)
{
    enum appl_status
        e_status;

    // Use the C++ context object to query socket manager
    class appl_socket_mgr *
        p_socket_mgr;

    e_status =
        p_context->v_socket_mgr(
            &(
                p_socket_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_socket_mgr->v_resolve(
                p_address_descriptor,
                p_callback,
                p_callback_context);
    }

    return
        e_status;

} // s_resolve()

/* end-of-file: appl_address_service.cpp */
