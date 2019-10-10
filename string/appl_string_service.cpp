/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <string/appl_string_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <buf/appl_buf.h>

#include <string/appl_string.h>

#include <context/appl_context_handle.h>

//
//
//
enum appl_status
appl_string_service::s_create(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_alloc_len,
    struct appl_string * * const
        r_string)
{
    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_string::s_create(
            p_allocator,
            i_alloc_len,
            r_string);

} // s_create()

//
//
//
enum appl_status
appl_string_service::s_destroy(
    struct appl_string * const
        p_string)
{
    struct appl_context * const
        p_context =
        p_string->get_context();

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_string::s_destroy(
            p_allocator,
            p_string);

} // s_destroy()

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
