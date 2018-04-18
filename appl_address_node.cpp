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

#include "appl_unused.h"

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
    appl_unused(
        pp_name_cur);
    appl_unused(
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
    appl_unused(
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
