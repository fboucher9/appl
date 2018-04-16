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
enum appl_status
    appl_address::v_get_name(
        unsigned char * * const
            pp_name_cur,
        unsigned char * const
            p_name_max) const
{
    static_cast<void>(
        pp_name_cur);
    static_cast<void>(
        p_name_max);
    return
        appl_status_not_implemented;
} // v_get_name()

//
//
//
enum appl_status
    appl_address::v_get_port(
        unsigned short int * const
            r_port) const
{
    static_cast<void>(
        r_port);
    return
        appl_status_not_implemented;
} // v_get_port()

//
//  Function: appl_address()
//
//  Description:
//      Initialize to default values.
//
appl_address::appl_address() :
    appl_object()
{
}

//
//  Function: ~appl_address()
//
//  Description:
//      Deinitialize all members.
//
appl_address::~appl_address()
{
}

/* end-of-file: appl_address_node.cpp */
