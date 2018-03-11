/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_socket_mgr.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_socket_mgr::v_create_address(
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
    appl_socket_mgr::v_create_socket(
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

//
//
//
appl_socket_mgr::appl_socket_mgr() :
    appl_object()
{
}

//
//
//
appl_socket_mgr::~appl_socket_mgr()
{
}

/* end-of-file: appl_socket_mgr.cpp */
