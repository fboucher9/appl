/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <env/appl_env.h>

#include <env/appl_env_w32.h>

#include <appl_context.h>

#include <allocator/appl_allocator.h>

#include <heap/appl_heap.h>

#include <appl_object_handle.h>

#include <appl_string_handle.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#include <appl_convert.h>

//
//
//
enum appl_status
appl_env_w32::s_create(
    struct appl_allocator * const
        p_allocator,
    class appl_env * * const
        r_env)
{
    enum appl_status
        e_status;

    class appl_env_w32 *
        p_env_w32;

    e_status =
        p_allocator->alloc_object(
            &(
                p_env_w32));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_env) =
            p_env_w32;
    }

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
        struct appl_string * * const
            r_string)
{
    enum appl_status
        e_status;

    unsigned char *
        p_name0;

    e_status =
        appl_buf0_create(
            m_context,
            p_name_min,
            p_name_max,
            &(
                p_name0));

    if (
        appl_status_ok
        == e_status)
    {
        DWORD
            dwResult;

        dwResult =
            GetEnvironmentVariableA(
                appl_convert::to_char_ptr(
                    p_name0),
                NULL,
                0);

        if (
            dwResult)
        {
            class appl_heap *
                p_heap;

            p_heap =
                m_context->m_heap;

            unsigned char *
                p_value0;

            e_status =
                p_heap->alloc_structure_array(
                    dwResult + 1,
                    &(
                        p_value0));

            if (
                appl_status_ok
                == e_status)
            {
                DWORD
                    dwResult2;

                dwResult2 =
                    GetEnvironmentVariableA(
                        appl_convert::to_char_ptr(
                            p_name0),
                        appl_convert::to_char_ptr(
                            p_value0),
                        dwResult);

                if (
                    dwResult2)
                {
                    struct appl_string *
                        p_string;

                    e_status =
                        appl_string_create_dup_buffer(
                            m_context,
                            p_value0,
                            p_value0 + dwResult2,
                            &(
                                p_string));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        *(
                            r_string) =
                            p_string;
                    }

                    if (
                        appl_status_ok
                        != e_status)
                    {
                        appl_object_destroy(
                            appl_string_parent(
                                p_string));
                    }
                }

                p_heap->v_free(
                    dwResult + 1,
                    p_value0);
            }
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        appl_buf0_destroy(
            m_context,
            p_name0);
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
    enum appl_status
        e_status;

    unsigned char *
        p_name0;

    e_status =
        appl_buf0_create(
            m_context,
            p_name_min,
            p_name_max,
            &(
                p_name0));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char *
            p_value0;

        e_status =
            appl_buf0_create(
                m_context,
                p_value_min,
                p_value_max,
                &(
                    p_value0));

        if (
            appl_status_ok
            == e_status)
        {
            BOOL
                bResult;

            bResult =
                SetEnvironmentVariableA(
                    appl_convert::to_char_ptr(
                        p_name0),
                    appl_convert::to_char_ptr(
                        p_value0));

            if (
                bResult)
            {
                e_status =
                    appl_status_ok;
            }
            else
            {
                e_status =
                    appl_status_fail;
            }

            appl_buf0_destroy(
                m_context,
                p_value0);
        }

        appl_buf0_destroy(
            m_context,
            p_name0);
    }

    return
        e_status;

} // v_set()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_env_w32.cpp */
