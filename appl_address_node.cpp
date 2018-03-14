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
