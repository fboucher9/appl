/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_env_handle.h>

#include <appl_env_service.h>

#include <appl_string_handle.h>

/*

*/
enum appl_status
appl_env_get(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    struct appl_string * * const
        r_string)
{
    enum appl_status
        e_status;

    e_status =
        appl_env_service::s_get(
            p_object,
            p_name_min,
            p_name_max,
            r_string);

    return
        e_status;

} /* get() */

/*

*/
enum appl_status
appl_env_set(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    unsigned char const * const
        p_value_min,
    unsigned char const * const
        p_value_max)
{
    enum appl_status
        e_status;

    e_status =
        appl_env_service::s_set(
            p_object,
            p_name_min,
            p_name_max,
            p_value_min,
            p_value_max);

    return
        e_status;

} /* set() */

/* end-of-file: appl_env_handle.cpp */
