/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <env/appl_env_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <env/appl_env.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
appl_env_service::s_get(
    struct appl_context * const
        p_context,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    struct appl_string * * const
        r_string)
{
    enum appl_status
        e_status;

    struct appl_env *
        p_env;

    e_status =
        p_context->v_env(
            &(
                p_env));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_env->v_get(
                p_name_min,
                p_name_max,
                r_string);
    }

    return
        e_status;

} // s_get()

//
//
//
enum appl_status
appl_env_service::s_query(
    struct appl_context * const
        p_context,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    void (* p_query_callback)(
        void * const
            p_query_context,
        unsigned char const * const
            p_value_min,
        unsigned char const * const
            p_value_max),
    void * const
        p_query_context)
{
    enum appl_status
        e_status;

    struct appl_env *
        p_env;

    e_status =
        p_context->v_env(
            &(
                p_env));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_env->v_query(
                p_name_min,
                p_name_max,
                p_query_callback,
                p_query_context);
    }

    return
        e_status;

} // s_query()

//
//
//
enum appl_status
appl_env_service::s_set(
    struct appl_context * const
        p_context,
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

    struct appl_env *
        p_env;

    e_status =
        p_context->v_env(
            &(
                p_env));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_env->v_set(
                p_name_min,
                p_name_max,
                p_value_min,
                p_value_max);
    }

    return
        e_status;

} // s_set()

/* end-of-file: appl_env_service.cpp */
