/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_object_handle.h>

#include <appl_property_handle.h>

#include <appl_property_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_property_types.h>

#include <appl_property.h>

#include <appl_context.h>

/*

*/
enum appl_status
appl_property_create(
    struct appl_context * const
        p_context,
    unsigned int const
        i_count,
    struct appl_property * * const
        r_property)
{
    return
        appl_property_service::s_create(
            p_context->m_heap,
            i_count,
            r_property);

} /* appl_property_create() */

struct appl_object *
appl_property_parent(
    struct appl_property * const
        p_property)
{
    return
        p_property;

} /* parent() */

struct appl_object const *
appl_property_const_parent(
    struct appl_property const * const
        p_property)
{
    return
        p_property;

} /* const_parent() */

/*

*/
enum appl_status
appl_property_set_ptr(
    struct appl_property * const
        p_property,
    unsigned int const
        i_id,
    void const * const
        p_value)
{
    return
        appl_property_service::s_set_ptr(
            p_property,
            i_id,
            p_value);

} /* appl_property_set_ptr() */

/*

*/
enum appl_status
appl_property_set_ulong(
    struct appl_property * const
        p_property,
    unsigned int const
        i_id,
    unsigned long int const
        u_value)
{
    return
        appl_property_service::s_set_ulong(
            p_property,
            i_id,
            u_value);

} /* appl_property_set_ulong() */

/*

*/
enum appl_status
appl_property_set_long(
    struct appl_property * const
        p_property,
    unsigned int const
        i_id,
    signed long int const
        i_value)
{
    return
        appl_property_service::s_set_long(
            p_property,
            i_id,
            i_value);

} /* appl_property_set_long() */

/*

*/
enum appl_status
appl_property_get_ptr(
    struct appl_property const * const
        p_property,
    unsigned int const
        i_id,
    void * * const
        r_value)
{
    return
        appl_property_service::s_get_ptr(
            p_property,
            i_id,
            r_value);

} /* appl_property_get_ptr() */

/*

*/
enum appl_status
appl_property_get_ulong(
    struct appl_property const * const
        p_property,
    unsigned int const
        i_id,
    unsigned long int * const
        r_value)
{
    return
        appl_property_service::s_get_ulong(
            p_property,
            i_id,
            r_value);

} /* appl_property_get_ulong() */

/*

*/
enum appl_status
appl_property_get_long(
    struct appl_property const * const
        p_property,
    unsigned int const
        i_id,
    signed long int * const
        r_value)
{
    return
        appl_property_service::s_get_long(
            p_property,
            i_id,
            r_value);

} /* appl_property_get_long() */

/* end-of-file: appl_property_handle.cpp */
