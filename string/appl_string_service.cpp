/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <string/appl_string_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_buf.h>

#include <string/appl_string.h>

#include <appl_context.h>

#include <allocator/appl_allocator.h>

//
//
//
enum appl_status
appl_string_service::s_create(
    struct appl_object const * const
        p_object,
    unsigned long int const
        i_alloc_len,
    struct appl_string * * const
        r_string)
{
    struct appl_context * const
        p_context =
        p_object->get_context();

    return
        appl_string::s_create(
            p_context->m_allocator,
            i_alloc_len,
            r_string);

} // s_create()

//
//
//
struct appl_object *
appl_string_service::s_parent(
    struct appl_string * const
        p_string)
{
    return
        p_string;

} // s_parent()

//
//
//
struct appl_object const *
appl_string_service::s_const_parent(
    struct appl_string const * const
        p_string)
{
    return
        p_string;

} // s_const_parent()

//
//
//
enum appl_status
appl_string_service::s_length(
    struct appl_string const * const
        p_string,
    unsigned long int * const
        r_length)
{
    return
        p_string->v_length(
            r_length);

} // s_length()

//
//
//
enum appl_status
appl_string_service::s_get(
    struct appl_string const * const
        p_string,
    unsigned char * * const
        r_buf_min,
    unsigned char * * const
        r_buf_max)
{
    return
        p_string->v_get(
            r_buf_min,
            r_buf_max);

} // s_get()

/* end-of-file: appl_string_service.cpp */
