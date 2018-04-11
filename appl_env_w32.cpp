/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_env.h"

#include "appl_env_w32.h"

#include "appl_context.h"

#include "appl_heap.h"

#include "appl_object_handle.h"

#include "appl_context_handle.h"

#include "appl_string_handle.h"

//
//
//
enum appl_status
appl_env_w32::s_create(
    class appl_context * const
        p_context,
    class appl_env * * const
        r_env)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_env_w32),
            &(
                appl_env_w32::s_new),
            r_env);

    return
        e_status;

} // s_create()

//
//
//
appl_env_w32::appl_env_w32() :
    appl_env()
{
}

//
//
//
appl_env_w32::~appl_env_w32()
{
}

//
//
//
enum appl_status
    appl_env_w32::v_get(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        struct appl_string_handle * * const
            r_string_handle)
{
    enum appl_status
        e_status;

    class appl_heap *
        p_heap;

    p_heap =
        m_context->m_heap;

    char *
        p_name_allocation;

    e_status =
        p_heap->v_alloc(
            (
             p_name_max
             - p_name_min)
            + 1,
            reinterpret_cast<void * *>(
                &(
                    p_name_allocation)));

    if (
        appl_status_ok
        == e_status)
    {
        memcpy(
            p_name_allocation,
            p_name_min,
            p_name_max
            - p_name_min);

        p_name_allocation[p_name_max - p_name_min] =
            static_cast<unsigned char>(
                0u);

        DWORD
            dwResult;

        dwResult =
            GetEnvironmentVariableA(
                p_name_allocation,
                NULL,
                0);

        if (
            dwResult)
        {
            char *
                p_value_allocation;

            e_status =
                p_heap->v_alloc(
                    static_cast<appl_size_t>(
                        dwResult),
                    reinterpret_cast<void * *>(
                        &(
                            p_value_allocation)));

            if (
                appl_status_ok
                == e_status)
            {
                DWORD
                    dwResult2;

                dwResult2 =
                    GetEnvironmentVariableA(
                        p_name_allocation,
                        p_value_allocation,
                        dwResult);

                if (
                    dwResult2)
                {
                    struct appl_string_handle *
                        p_string_handle;

                    e_status =
                        appl_string_create_dup_buffer(
                            &(
                                m_context->get_handle()->o_object_handle),
                            reinterpret_cast<unsigned char const *>(
                                p_value_allocation),
                            reinterpret_cast<unsigned char const *>(
                                p_value_allocation + dwResult2),
                            &(
                                p_string_handle));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        *(
                            r_string_handle) =
                            p_string_handle;
                    }

                    if (
                        appl_status_ok
                        != e_status)
                    {
                        appl_object_destroy(
                            &(
                                p_string_handle->o_object_handle));
                    }
                }

                p_heap->v_free(
                    static_cast<void *>(
                        p_value_allocation));
            }
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        p_heap->v_free(
            static_cast<void *>(
                p_name_allocation));
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_get()

//
//
//
enum appl_status
    appl_env_w32::v_set(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        unsigned char const * const
            p_value_min,
        unsigned char const * const
            p_value_max)
{
    static_cast<void>(
        p_name_min);
    static_cast<void>(
        p_name_max);
    static_cast<void>(
        p_value_min);
    static_cast<void>(
        p_value_max);

    return
        appl_status_not_implemented;

} // v_set()

//
//
//
void
appl_env_w32::s_new(
    void * const
        p_placement)
{
    new (p_placement)
        class appl_env_w32;

} // s_new()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_env_w32.cpp */
