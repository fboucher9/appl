/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_socket_mgr.h"

#include "appl_socket_std_mgr.h"

//
//
//
enum appl_status
    appl_socket_std_mgr::s_create(
        class appl_context * const
            p_context,
        class appl_socket_mgr * * const
            r_socket_mgr)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_socket_std_mgr),
            &(
                appl_socket_std_mgr::s_new),
            r_socket_mgr);

    return
        e_status;

} // s_create()

//
//
//
appl_socket_std_mgr::appl_socket_std_mgr() :
    appl_socket_mgr()
{
}

//
//
//
appl_socket_std_mgr::~appl_socket_std_mgr()
{
}

//
//
//
void
    appl_socket_std_mgr::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_socket_std_mgr;

} // s_new()

//
//
//
enum appl_status
    appl_socket_std_mgr::v_create_address(
        struct appl_address_descriptor const * const
            p_address_descriptor,
        class appl_address_node * * const
            r_address_node)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_address_descriptor);
    static_cast<void>(
        r_address_node);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_address()

//
//
//
enum appl_status
    appl_socket_std_mgr::v_create_socket(
        struct appl_socket_descriptor const * const
            p_socket_descriptor,
        class appl_socket_node * * const
            r_socket_node)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_socket_descriptor);
    static_cast<void>(
        r_socket_node);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_socket()

/* end-of-file: appl_socket_std_mgr.cpp */
