/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_address_handle.h"

#include "appl_address_service.h"

/*

*/
enum appl_status
appl_address_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_address_descriptor const * const
        p_address_descriptor,
    struct appl_address_handle * * const
        r_address_handle)
{
    return
        appl_address_service::s_create(
            p_context_handle,
            p_address_descriptor,
            r_address_handle);

} /* appl_address_create() */

/*

*/
enum appl_status
appl_address_get_name(
    struct appl_address_handle * const
        p_address_handle,
    struct appl_buf * const
        p_name_buf)
{
    return
        appl_address_service::s_get_name(
            p_address_handle,
            p_name_buf);

} /* appl_address_get_name() */

/*

*/
enum appl_status
appl_address_get_port(
    struct appl_address_handle * const
        p_address_handle,
    unsigned short int * const
        r_port)
{
    return
        appl_address_service::s_get_port(
            p_address_handle,
            r_port);

} /* appl_address_get_port() */

/* end-of-file: appl_address_handle.cpp */
