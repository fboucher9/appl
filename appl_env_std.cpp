/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <string.h>

#include <stdlib.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_env.h"

#include "appl_env_std.h"

#include "appl_context.h"

#include "appl_heap.h"

#include "appl_object_handle.h"

#include "appl_context_handle.h"

#include "appl_string_handle.h"

#include "appl_buf.h"

//
//
//
enum appl_status
appl_env_std::s_create(
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
                class appl_env_std),
            &(
                appl_env_std::s_new),
            r_env);

    return
        e_status;

} // s_create()

//
//
//
appl_env_std::appl_env_std() :
    appl_env()
{
}

//
//
//
appl_env_std::~appl_env_std()
{
}

//
//
//
enum appl_status
    appl_env_std::v_get(
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

    appl_size_t const
        i_name_len =
        (
            p_name_max
            - p_name_min);

    union appl_ptr
        o_name_allocation;

    e_status =
        p_heap->v_alloc(
            i_name_len + 1,
            &(
                o_name_allocation.p_void));

    if (
        appl_status_ok
        == e_status)
    {
        memcpy(
            o_name_allocation.p_void,
            p_name_min,
            i_name_len);

        o_name_allocation.p_uchar[i_name_len] =
            0;

        union appl_ptr
            o_std_result;

        o_std_result.pc_char =
            getenv(
                o_name_allocation.p_char);

        if (
            o_std_result.pc_char)
        {
            appl_size_t
                i_value_len;

            i_value_len =
                strlen(
                    o_std_result.pc_char);

            struct appl_string_handle *
                p_string_handle;

            e_status =
                appl_string_create_dup_buffer(
                    &(
                        m_context->get_handle()->o_object_handle),
                    o_std_result.pc_uchar,
                    o_std_result.pc_uchar + i_value_len,
                    &(
                        p_string_handle));

            if (
                appl_status_ok
                == e_status)
            {
                *(
                    r_string_handle) =
                    p_string_handle;

#if 0
                if (
                    appl_status_ok
                    != e_status)
                {
                    appl_object_destroy(
                        &(
                            p_string_handle->o_object_handle));
                }
#endif
            }
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        p_heap->v_free(
            o_name_allocation.p_void);
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
    appl_env_std::v_set(
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

    class appl_heap * const
        p_heap =
        m_context->m_heap;

    appl_size_t const
        i_name_len =
        (
            p_name_max
            - p_name_min);

    union appl_ptr
        o_name_allocation;

    e_status =
        p_heap->v_alloc(
            i_name_len + 1,
            &(
                o_name_allocation.p_void));

    if (
        appl_status_ok
        == e_status)
    {
        memcpy(
            o_name_allocation.p_void,
            p_name_min,
            i_name_len);

        o_name_allocation.p_uchar[i_name_len] =
            0;

        appl_size_t const
            i_value_len =
            (
                p_value_max
                - p_value_min);

        union appl_ptr
            o_value_allocation;

        e_status =
            p_heap->v_alloc(
                i_value_len + 1,
                &(
                    o_value_allocation.p_void));

        if (
            appl_status_ok
            == e_status)
        {
            memcpy(
                o_value_allocation.p_void,
                p_value_min,
                i_value_len);

            o_value_allocation.p_uchar[i_value_len] =
                0;

            int
                i_setenv_result;

            i_setenv_result =
                setenv(
                    o_name_allocation.p_char,
                    o_value_allocation.p_char,
                    1);

            if (
                0 == i_setenv_result)
            {
                e_status =
                    appl_status_ok;
            }
            else
            {
                e_status =
                    appl_status_fail;
            }

            p_heap->v_free(
                o_value_allocation.p_void);
        }

        p_heap->v_free(
            o_name_allocation.p_void);
    }

    return
        e_status;

} // v_set()

//
//
//
void
appl_env_std::s_new(
    void * const
        p_placement)
{
    new (p_placement)
        class appl_env_std;

} // s_new()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_env_std.cpp */
