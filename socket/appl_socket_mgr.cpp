/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <socket/appl_socket_mgr.h>

#include <appl_unused.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_socket_mgr::v_create_address(
        struct appl_address_property const * const
            p_property,
        struct appl_address * * const
            r_address)
{
    enum appl_status
        e_status;

    appl_unused(
        p_property,
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
        struct appl_socket_property const * const
            p_socket_descriptor,
        struct appl_socket * * const
            r_socket)
{
    enum appl_status
        e_status;

    appl_unused(
        p_socket_descriptor,
        r_socket);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_socket()

//
//
//
enum appl_status
    appl_socket_mgr::v_poll(
        struct appl_poll_descriptor const * const
            p_poll_descriptor_min,
        struct appl_poll_descriptor const * const
            p_poll_descriptor_max,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    appl_unused(
        p_poll_descriptor_min,
        p_poll_descriptor_max,
        i_wait_freq,
        i_wait_count);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_poll()

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
