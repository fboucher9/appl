/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_object_handle.h>

#include <appl_options_handle.h>

#include <appl_options_service.h>

/*

*/
enum appl_status
appl_options_count(
    struct appl_object const * const
        p_object,
    unsigned long int * const
        r_count)
{
    return
        appl_options_service::s_count(
            p_object,
            r_count);

} /* count() */

/*

*/
enum appl_status
appl_options_get(
    struct appl_object const * const
        p_object,
    unsigned long int const
        i_index,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max)
{
    return
        appl_options_service::s_get(
            p_object,
            i_index,
            r_buf_min,
            r_buf_max);

} /* get() */

/* end-of-file: appl_options_handle.cpp */
