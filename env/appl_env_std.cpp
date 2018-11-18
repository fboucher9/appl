/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <string.h>

#include <stdlib.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <env/appl_env.h>

#include <env/appl_env_std.h>

#include <appl_context.h>

#include <appl_allocator.h>

#include <heap/appl_heap.h>

#include <appl_object_handle.h>

#include <appl_string_handle.h>

#include <appl_convert.h>

#include <appl_buf.h>

//
//
//
enum appl_status
appl_env_std::s_create(
    struct appl_allocator * const
        p_allocator,
    class appl_env * * const
        r_env)
{
    enum appl_status
        e_status;

    class appl_env_std *
        p_env_std;

    e_status =
        p_allocator->alloc_object(
            &(
                p_env_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_env) =
            p_env_std;
    }

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
        struct appl_string * * const
            r_string)
{
    enum appl_status
        e_status;

    struct appl_heap *
        p_heap;

    p_heap =
        m_context->m_heap;

    unsigned long int const
        i_name_len =
        appl_buf_len(
            p_name_min,
            p_name_max);

    char *
        p_name0;

    e_status =
        p_heap->alloc_structure_array(
            i_name_len + 1ul,
            &(
                p_name0));

    if (
        appl_status_ok
        == e_status)
    {
        memcpy(
            p_name0,
            p_name_min,
            i_name_len);

        p_name0[i_name_len] =
            0;

        char const * const
            p_value0 =
            getenv(
                p_name0);

        if (
            p_value0)
        {
            appl_size_t const
                i_value_len =
                strlen(
                    p_value0);

            struct appl_string *
                p_string;

            e_status =
                appl_string_create_dup_buffer(
                    m_context,
                    appl_convert::to_uchar_ptr(
                        p_value0),
                    appl_convert::to_uchar_ptr(
                        p_value0 + i_value_len),
                    &(
                        p_string));

            if (
                appl_status_ok
                == e_status)
            {
                *(
                    r_string) =
                    p_string;

                if (
                    appl_status_ok
                    != e_status)
                {
                    appl_object_destroy(
                        appl_string_parent(
                            p_string));
                }
            }
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        p_heap->v_free(
            i_name_len + 1ul,
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

    struct appl_heap * const
        p_heap =
        m_context->m_heap;

    unsigned long int const
        i_name_len =
        appl_buf_len(
            p_name_min,
            p_name_max);

    char *
        p_name0;

    e_status =
        p_heap->alloc_structure_array(
            i_name_len + 1,
            &(
                p_name0));

    if (
        appl_status_ok
        == e_status)
    {
        memcpy(
            p_name0,
            p_name_min,
            i_name_len);

        p_name0[i_name_len] =
            0;

        unsigned long int const
            i_value_len =
            appl_buf_len(
                p_value_min,
                p_value_max);

        char *
            p_value0;

        e_status =
            p_heap->alloc_structure_array(
                i_value_len + 1,
                &(
                    p_value0));

        if (
            appl_status_ok
            == e_status)
        {
            memcpy(
                p_value0,
                p_value_min,
                i_value_len);

            p_value0[i_value_len] =
                0;

            int const
                i_setenv_result =
                setenv(
                    p_name0,
                    p_value0,
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
                i_value_len + 1,
                p_value0);
        }

        p_heap->v_free(
            i_name_len + 1,
            p_name0);
    }

    return
        e_status;

} // v_set()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_env_std.cpp */
