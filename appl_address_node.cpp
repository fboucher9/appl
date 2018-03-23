/* See LICENSE for license details */

/*

Module: appl_address_node.cpp

Description:
    Base interface for address objects.

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_address_node.h"

//
//
//
class appl_address_node *
appl_address_node::convert_handle(
    struct appl_address_handle * const
        p_address_handle)
{
    return
        reinterpret_cast<class appl_address_node *>(
            p_address_handle);

} // convert_handle()

//
//
//
struct appl_address_handle *
appl_address_node::get_handle(void)
{
    return
        reinterpret_cast<struct appl_address_handle *>(
            this);

} // get_handle()

//
//
//
enum appl_status
    appl_address_node::v_get_name(
        struct appl_buf * const
            p_name_buf)
{
    static_cast<void>(
        p_name_buf);
    return
        appl_status_not_implemented;
} // v_get_name()

//
//
//
enum appl_status
    appl_address_node::v_get_port(
        unsigned short int * const
            r_port)
{
    static_cast<void>(
        r_port);
    return
        appl_status_not_implemented;
} // v_get_port()

//
//  Function: appl_address_node()
//
//  Description:
//      Initialize to default values.
//
appl_address_node::appl_address_node() :
    appl_object()
{
}

//
//  Function: ~appl_address_node()
//
//  Description:
//      Deinitialize all members.
//
appl_address_node::~appl_address_node()
{
}

/* end-of-file: appl_address_node.cpp */
