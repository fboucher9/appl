/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <socket/appl_address_property.h>

#include <socket/appl_address_handle.h>

#include <socket/appl_address_service.h>

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

/*

*/
enum appl_status
appl_address_destroy(
    struct appl_address * const
        p_address)
{
    return
        appl_address_service::s_destroy(
            p_address);

} /* _destroy() */

struct appl_object *
appl_address_parent(
    struct appl_address * const
        p_address)
{
    return
        appl_address_service::s_parent(
            p_address);

}

struct appl_object const *
appl_address_const_parent(
    struct appl_address const * const
        p_address)
{
    return
        appl_address_service::s_const_parent(
            p_address);

}

/*

*/
enum appl_status
appl_address_get_name_len(
    struct appl_address const * const
        p_address,
    unsigned long int * const
        r_name_len)
{
    return
        appl_address_service::s_get_name_len(
            p_address,
            r_name_len);

} /* appl_address_get_name_len() */

/*

*/
enum appl_status
appl_address_get_name(
    struct appl_address const * const
        p_address,
    unsigned char * const
        p_name_min,
    unsigned char * const
        p_name_max,
    unsigned char * * const
        r_name_cur)
{
    return
        appl_address_service::s_get_name(
            p_address,
            p_name_min,
            p_name_max,
            r_name_cur);

} /* appl_address_get_name() */

/*

*/
enum appl_status
appl_address_get_port(
    struct appl_address const * const
        p_address,
    unsigned short int * const
        r_port)
{
    return
        appl_address_service::s_get_port(
            p_address,
            r_port);

} /* appl_address_get_port() */

/*

*/
enum appl_status
appl_address_get_family(
    struct appl_address const * const
        p_address,
    int * const
        r_family)
{
    return
        appl_address_service::s_get_family(
            p_address,
            r_family);

} /* appl_address_get_family() */

/*

*/
enum appl_status
appl_address_get_index(
    struct appl_address const * const
        p_address,
    unsigned int * const
        r_index)
{
    return
        appl_address_service::s_get_index(
            p_address,
            r_index);

} /* appl_address_get_index() */

/*

*/
enum appl_status
appl_address_resolve(
    struct appl_context * const
        p_context,
    struct appl_address_descriptor const * const
        p_address_descriptor,
    void (* p_callback)(
        void * const
            p_callback_context,
        struct appl_address_descriptor const * const
            p_address_descriptor),
    void * const
        p_callback_context)
{
    return
        appl_address_service::s_resolve(
            p_context,
            p_address_descriptor,
            p_callback,
            p_callback_context);

} /* appl_address_resolve() */

/* end-of-file: appl_address_handle.cpp */
