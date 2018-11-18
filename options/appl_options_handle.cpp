/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_options_handle.h>

#include <options/appl_options_service.h>

/*

*/
enum appl_status
appl_options_create(
    struct appl_context * const
        p_context,
    struct appl_options * * const
        r_instance)
{
    return
        appl_options_service::s_create(
            p_context,
            r_instance);

} /* create() */

/*

*/
struct appl_object *
appl_options_parent(
    struct appl_options * const
        p_options)
{
    return
        appl_options_service::s_parent(
            p_options);

} /* parent() */

/*

*/
struct appl_object const *
appl_options_const_parent(
    struct appl_options const * const
        p_options)
{
    return
        appl_options_service::s_const_parent(
            p_options);

} /* const_parent() */

/*

*/
enum appl_status
appl_options_count(
    struct appl_options const * const
        p_options,
    unsigned long int * const
        r_count)
{
    return
        appl_options_service::s_count(
            p_options,
            r_count);

} /* count() */

/*

*/
enum appl_status
appl_options_get(
    struct appl_options const * const
        p_options,
    unsigned long int const
        i_index,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max)
{
    return
        appl_options_service::s_get(
            p_options,
            i_index,
            r_buf_min,
            r_buf_max);

} /* get() */

/*

*/
enum appl_status
appl_options_write(
    struct appl_options * const
        p_options,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        p_count,
    char * const
        p_ready)
{
    return
        appl_options_service::s_write(
            p_options,
            p_buf_min,
            p_buf_max,
            p_count,
            p_ready);

} /* write() */

/*

*/
enum appl_status
appl_options_append_argument(
    struct appl_options * const
        p_options,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        appl_options_service::s_append_argument(
            p_options,
            p_buf_min,
            p_buf_max);

} /* append_argument() */

/* end-of-file: appl_options_handle.cpp */
