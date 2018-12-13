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

#include <appl_allocator_handle.h>

#include <appl_object_handle.h>

#include <appl_string_handle.h>

#include <appl_context_handle.h>

#include <appl_convert.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#include <appl_validate.h>

//
//
//
enum appl_status
appl_env_std::s_create(
    struct appl_allocator * const
        p_allocator,
    struct appl_env * * const
        r_env)
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != p_allocator)
            && (0 != r_env));

    if (
        appl_status_ok
        == e_status)
    {
        class appl_env_std *
            p_env_std;

        e_status =
            appl_new(
                p_allocator,
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
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_env_std::s_destroy(
    struct appl_allocator * const
        p_allocator,
    struct appl_env * const
        p_env)
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != p_allocator)
            && (0 != p_env));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_delete(
                p_allocator,
                p_env);
    }

    return
        e_status;

} // s_destroy()

//
//
//
appl_env_std::appl_env_std(
    struct appl_context * const
        p_context) :
    appl_env(
        p_context)
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
    appl_env_std::f_init(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

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
            r_string) const
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != p_name_min)
            && (0 != p_name_max)
            && (0 != r_string));

    if (
        appl_status_ok
        == e_status)
    {
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
            char const * const
                p_value0 =
                getenv(
                    appl_convert::to_char_ptr(
                        p_name0));

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
                        appl_context_parent(
                            m_context),
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

#if 0
                    if (
                        appl_status_ok
                        != e_status)
                    {
                        appl_string_destroy(
                            p_string);
                    }
#endif
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
    }

    return
        e_status;

} // v_get()

//
//
//
enum appl_status
    appl_env_std::v_query(
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
            p_query_context) const
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != p_name_min)
            && (0 != p_name_max)
            && (0 != p_query_callback));

    if (
        appl_status_ok
        == e_status)
    {
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
            char const * const
                p_value0 =
                getenv(
                    appl_convert::to_char_ptr(
                        p_name0));

            if (
                p_value0)
            {
                appl_size_t const
                    i_value_len =
                    strlen(
                        p_value0);

                (*p_query_callback)(
                    p_query_context,
                    appl_convert::to_uchar_ptr(
                        p_value0),
                    appl_convert::to_uchar_ptr(
                        p_value0 + i_value_len));

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
                p_name0);
        }
    }

    return
        e_status;

} // v_query()

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

    e_status =
        appl_validate(
            (0 != p_name_min)
            && (0 != p_name_max)
            && (0 != p_value_min)
            && (0 != p_value_max));

    if (
        appl_status_ok
        == e_status)
    {
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
                int const
                    i_setenv_result =
                    setenv(
                        appl_convert::to_char_ptr(
                            p_name0),
                        appl_convert::to_char_ptr(
                            p_value0),
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

                appl_buf0_destroy(
                    m_context,
                    p_value0);
            }

            appl_buf0_destroy(
                m_context,
                p_name0);
        }
    }

    return
        e_status;

} // v_set()

//
//
//
appl_size_t
appl_env_std::v_cleanup(void)
{
    return
        sizeof(class appl_env_std);

} // v_cleanup()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_env_std.cpp */
