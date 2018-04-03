/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_property_handle.h"

#include "appl_address_property.h"

/*

*/
enum appl_status
appl_address_property_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_property_handle * * const
        r_property_handle)
{
    return
        appl_property_create(
            p_context_handle,
            appl_address_property_id_max,
            reinterpret_cast<struct appl_property_handle * *>(
                r_property_handle));

} /* appl_address_property_create() */

/*

*/
enum appl_status
appl_address_property_set_name(
    struct appl_property_handle * const
        p_property_handle,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max)
{
    return
        appl_property_set_buf(
            p_property_handle,
            appl_address_property_id_name,
            p_name_min,
            p_name_max);

} /* appl_address_property_set_name() */

/*

*/
enum appl_status
appl_address_property_set_port(
    struct appl_property_handle * const
        p_property_handle,
    unsigned short int const
        i_port)
{
    return
        appl_property_set_ulong(
            p_property_handle,
            appl_address_property_id_port,
            static_cast<unsigned long int>(
                i_port));

} /* appl_address_property_set_port() */

/*

*/
enum appl_status
appl_address_property_get_name(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned char const * * const
        r_name_min,
    unsigned char const * * const
        r_name_max)
{
    return
        appl_property_get_buf(
            p_property_handle,
            appl_address_property_id_name,
            r_name_min,
            r_name_max);

} /* appl_address_property_get_name() */

/*

*/
enum appl_status
appl_address_property_get_port(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned short int * const
        r_port)
{
    enum appl_status
        e_status;

    unsigned long int
        u_value;


    e_status =
        appl_property_get_ulong(
            p_property_handle,
            appl_address_property_id_port,
            &(
                u_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_port) =
            static_cast<unsigned short int>(
                u_value);
    }

    return
        e_status;

} /* appl_address_property_get_port() */

/* end-of-file: appl_address_property.cpp */
