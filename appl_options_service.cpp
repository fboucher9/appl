/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_options_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_options.h>

#include <appl_context.h>

//
//
//
static
class appl_options *
get_options_from_object(
    struct appl_object const * const
        p_object)
{
    struct appl_context * const
        p_context =
        p_object->get_context();

    return
        p_context->m_options;

} // get_options_from_object

//
//
//
enum appl_status
appl_options_service::s_count(
    struct appl_object const * const
        p_object,
    unsigned long int * const
        r_count)
{
    enum appl_status
        e_status;

    class appl_options * const
        p_options =
        get_options_from_object(
            p_object);

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
    struct appl_object const * const
        p_object,
    unsigned long int const
        i_index,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max)
{
    enum appl_status
        e_status;

    class appl_options * const
        p_options =
        get_options_from_object(
            p_object);

    e_status =
        p_options->v_get(
            i_index,
            r_buf_min,
            r_buf_max);

    return
        e_status;

} // s_get()

/* end-of-file: appl_options_service.cpp */
