/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_options_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_options.h>

#include <appl_context.h>

#include <appl_list.h>

#include <appl_options_std.h>

//
//
//
enum appl_status
appl_options_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_options * * const
        r_instance)
{
    return
        appl_options_std::s_create(
            p_context->m_allocator,
            r_instance);

} // s_create()

//
//
//
struct appl_object *
appl_options_service::s_parent(
    struct appl_options * const
        p_options)
{
    return
        p_options;

} // s_parent()

//
//
//
struct appl_object const *
appl_options_service::s_const_parent(
    struct appl_options const * const
        p_options)
{
    return
        p_options;

} // s_const_parent()

//
//
//
enum appl_status
appl_options_service::s_count(
    struct appl_options const * const
        p_options,
    unsigned long int * const
        r_count)
{
    enum appl_status
        e_status;

    e_status =
        p_options->v_count(
            r_count);

    return
        e_status;

} // s_count()

//
//
//
enum appl_status
appl_options_service::s_get(
    struct appl_options const * const
        p_options,
    unsigned long int const
        i_index,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max)
{
    enum appl_status
        e_status;

    e_status =
        p_options->v_get(
            i_index,
            r_buf_min,
            r_buf_max);

    return
        e_status;

} // s_get()

//
//
//
enum appl_status
appl_options_service::s_write(
    struct appl_options * const
        p_options,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        p_options->v_write(
            p_buf_min,
            p_buf_max);

} // s_write()

//
//
//
enum appl_status
appl_options_service::s_append_argument(
    struct appl_options * const
        p_options,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        p_options->v_append_argument(
            p_buf_min,
            p_buf_max);

} // s_append_argument()

/* end-of-file: appl_options_service.cpp */
