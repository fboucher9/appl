/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_object_handle.h"

#include "appl_property_handle.h"

#include "appl_property_service.h"

/*

*/
enum appl_status
appl_property_create(
    struct appl_context_handle * const
        p_context_handle,
    unsigned int const
        i_count,
    struct appl_property_handle * * const
        r_property_handle)
{
    return
        appl_property_service::s_create(
            p_context_handle,
            i_count,
            r_property_handle);

} /* appl_property_create() */

/*

*/
enum appl_status
appl_property_set_ptr(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    void * const
        p_value)
{
    return
        appl_property_service::s_set_ptr(
            p_property_handle,
            i_id,
            p_value);

} /* appl_property_set_ptr() */

/*

*/
enum appl_status
appl_property_set_ulong(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int const
        u_value)
{
    return
        appl_property_service::s_set_ulong(
            p_property_handle,
            i_id,
            u_value);

} /* appl_property_set_ulong() */

/*

*/
enum appl_status
appl_property_set_long(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int const
        i_value)
{
    return
        appl_property_service::s_set_long(
            p_property_handle,
            i_id,
            i_value);

} /* appl_property_set_long() */

/*

*/
enum appl_status
appl_property_set_pfn(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    void * (* p_func)(
        void * const
            p_args))
{
    return
        appl_property_service::s_set_pfn(
            p_property_handle,
            i_id,
            p_func);

} /* appl_property_set_pfn() */

/*

*/
enum appl_status
appl_property_set_buf(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        appl_property_service::s_set_buf(
            p_property_handle,
            i_id,
            p_buf_min,
            p_buf_max);

} /* appl_property_set_buf() */

/*

*/
enum appl_status
appl_property_get_ptr(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned int const
        i_id,
    void * * const
        r_value)
{
    return
        appl_property_service::s_get_ptr(
            p_property_handle,
            i_id,
            r_value);

} /* appl_property_get_ptr() */

/*

*/
enum appl_status
appl_property_get_ulong(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned long int * const
        r_value)
{
    return
        appl_property_service::s_get_ulong(
            p_property_handle,
            i_id,
            r_value);

} /* appl_property_get_ulong() */

/*

*/
enum appl_status
appl_property_get_long(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned int const
        i_id,
    signed long int * const
        r_value)
{
    return
        appl_property_service::s_get_long(
            p_property_handle,
            i_id,
            r_value);

} /* appl_property_get_long() */

/*

*/
enum appl_status
appl_property_get_pfn(
    struct appl_property_handle const * const
        p_property_handle,
    unsigned int const
        i_id,
    void * (* * r_value)(
        void * const
            p_args))
{
    return
        appl_property_service::s_get_pfn(
            p_property_handle,
            i_id,
            r_value);

} /* appl_property_get_pfn() */

/*

*/
enum appl_status
appl_property_get_buf(
    struct appl_property_handle * const
        p_property_handle,
    unsigned int const
        i_id,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max)
{
    return
        appl_property_service::s_get_buf(
            p_property_handle,
            i_id,
            r_buf_min,
            r_buf_max);

} /* appl_property_get_buf() */

/* end-of-file: appl_property_handle.cpp */
