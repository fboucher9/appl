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
        struct appl_property const * const
            p_property,
        struct appl_address * * const
            r_address)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_property);
    static_cast<void>(
        r_address);

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
        struct appl_property const * const
            p_socket_descriptor,
        struct appl_socket * * const
            r_socket)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_socket_descriptor);
    static_cast<void>(
        r_socket);

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
