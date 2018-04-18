/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_address_handle.h"

#include "appl_address_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_address_node.h"

/*

*/
enum appl_status
appl_address_create(
    struct appl_context * const
        p_context,
    struct appl_address_property const * const
        p_address_property,
    struct appl_address * * const
        r_address)
{
    return
        appl_address_service::s_create(
            p_context,
            p_address_property,
            r_address);

} /* appl_address_create() */

struct appl_object *
appl_address_parent(
    struct appl_address * const
        p_address)
{
    return
        p_address;

}

struct appl_object const *
appl_address_const_parent(
    struct appl_address const * const
        p_address)
{
    return
        p_address;

}

/*

*/
enum appl_status
appl_address_get_name(
    struct appl_address * const
        p_address,
    unsigned char * * const
        pp_name_cur,
    unsigned char * const
        p_name_max)
{
    return
        appl_address_service::s_get_name(
            p_address,
            pp_name_cur,
            p_name_max);

} /* appl_address_get_name() */

/*

*/
enum appl_status
appl_address_get_port(
    struct appl_address * const
        p_address,
    unsigned short int * const
        r_port)
{
    return
        appl_address_service::s_get_port(
            p_address,
            r_port);

} /* appl_address_get_port() */

/* end-of-file: appl_address_handle.cpp */
