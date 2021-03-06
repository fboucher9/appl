/* See LICENSE for license details */

/*

Module: appl_address_node.cpp

Description:
    Base interface for address objects.

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <socket/appl_address_node.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
    appl_address::v_get_name_len(
        unsigned long int * const
            r_name_len) const
{
    appl_unused(
        r_name_len);
    return
        appl_raise_not_implemented();
} // v_get_name_len()

//
//
//
enum appl_status
    appl_address::v_get_name(
        unsigned char * const
            p_name_min,
        unsigned char * const
            p_name_max,
        unsigned char * * const
            r_name_cur) const
{
    appl_unused(
        p_name_min,
        p_name_max,
        r_name_cur);
    return
        appl_raise_not_implemented();
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
        appl_raise_not_implemented();
} // v_get_port()

//
//
//
enum appl_status
    appl_address::v_get_family(
        int * const
            r_family) const
{
    appl_unused(
        r_family);
    return
        appl_raise_not_implemented();
} // v_get_family()

//
//
//
enum appl_status
    appl_address::v_get_index(
        unsigned int * const
            r_index) const
{
    appl_unused(
        r_index);
    return
        appl_raise_not_implemented();
} // v_get_index()

//
//  Function: appl_address()
//
//  Description:
//      Initialize to default values.
//
appl_address::appl_address(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
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
