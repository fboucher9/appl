/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_env_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_env.h"

#include "appl_context.h"

#include "appl_object_handle.h"

//
//
//
enum appl_status
appl_env_service::s_get(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    struct appl_string_handle * * const
        r_string_handle)
{
    enum appl_status
        e_status;

    struct appl_context_handle * const
        p_context_handle =
        appl_object_get_context_handle(
            p_object_handle);

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_env * const
        p_env =
        p_context->m_env;

    e_status =
        p_env->v_get(
            p_name_min,
            p_name_max,
            r_string_handle);

    return
        e_status;

} // s_get()

//
//
//
enum appl_status
appl_env_service::s_set(
    struct appl_object_handle const * const
        p_object_handle,
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

    struct appl_context_handle * const
        p_context_handle =
        appl_object_get_context_handle(
            p_object_handle);

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_env * const
        p_env =
        p_context->m_env;

    e_status =
        p_env->v_set(
            p_name_min,
            p_name_max,
            p_value_min,
            p_value_max);

    return
        e_status;

} // s_set()

/* end-of-file: appl_env_service.cpp */
