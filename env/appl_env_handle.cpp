/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_env_handle.h>

#include <env/appl_env_service.h>

#include <appl_string_handle.h>

/*

*/
enum appl_status
appl_env_acquire(
    struct appl_context * const
        p_context,
    struct appl_env * * const
        r_instance)
{
    return
        appl_env_service::s_acquire(
            p_context,
            r_instance);

} /* acquire() */

/*

*/
struct appl_object *
appl_env_parent(
    struct appl_env * const
        p_env)
{
    return
        appl_env_service::s_parent(
            p_env);

} /* parent() */

/*

*/
struct appl_object const *
appl_env_const_parent(
    struct appl_env const * const
        p_env)
{
    return
        appl_env_service::s_const_parent(
            p_env);

} /* const_parent() */

/*

*/
enum appl_status
appl_env_get(
    struct appl_env const * const
        p_env,
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
            p_env,
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
    struct appl_env * const
        p_env,
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
            p_env,
            p_name_min,
            p_name_max,
            p_value_min,
            p_value_max);

    return
        e_status;

} /* set() */

/* end-of-file: appl_env_handle.cpp */
