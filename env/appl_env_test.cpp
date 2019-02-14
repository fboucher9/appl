/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <env/appl_env.h>

#include <env/appl_env_test.h>

#include <appl_env_handle.h>

#include <appl_string_handle.h>

#include <appl_buf.h>

#include <appl_unused.h>

#include <appl_heap_handle.h>

#include <stdio.h>

//
//
//
static
void
appl_env_test_query_cb(
    void * const
        p_query_context,
    unsigned char const * const
        p_value_min,
    unsigned char const * const
        p_value_max)
{
    appl_unused(
        p_query_context);
    printf("value=[%.*s]\n",
        static_cast<int>(appl_buf_len(
                p_value_min,
                p_value_max)),
        reinterpret_cast<char const *>(p_value_min));

} // appl_env_test_query_cb()

//
//
//
void
appl_env_test_1(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_string *
        p_string;

    static unsigned char const a_name[] =
    {
        'H', 'O', 'M', 'E'
    };

    e_status =
        appl_env_get(
            p_context,
            a_name,
            a_name + sizeof(a_name),
            &(
                p_string));

    if (
        appl_status_ok
        == e_status)
    {
        appl_string_destroy(
            p_string);
    }

    e_status =
        appl_env_query(
            p_context,
            a_name,
            a_name + sizeof(a_name),
            &(
                appl_env_test_query_cb),
            0);

    static unsigned char const a_homer[] =
    {
        'h',
        'o',
        'm',
        'e',
        'r'
    };

    e_status =
        appl_env_get(
            p_context,
            a_homer,
            a_homer + sizeof(a_homer),
            &(
                p_string));

    if (
        appl_status_ok
        == e_status)
    {
        appl_string_destroy(
            p_string);
    }

    e_status =
        appl_env_query(
            p_context,
            a_homer,
            a_homer + sizeof(a_homer),
            &(
                appl_env_test_query_cb),
            0);

    static unsigned char const a_test[] =
    {
        'T', 'E', 'S', 'T'
    };

    static unsigned char const a_value[] =
    {
        '1', '2', '3'
    };

    e_status =
        appl_env_set(
            p_context,
            a_test,
            a_test + sizeof(a_test),
            a_value,
            a_value + sizeof(a_value));

    static unsigned char const a_bad_name[] =
    {
        '='
    };

    e_status =
        appl_env_set(
            p_context,
            a_bad_name,
            a_bad_name + sizeof(a_bad_name),
            a_value,
            a_value + sizeof(a_value));

    {
        struct appl_env *
            p_env;

        e_status =
            appl_new(
                p_context,
                &(
                    p_env));

        if (
            appl_status_ok
            == e_status)
        {
            p_env->v_get(
                0,
                0,
                0);

            p_env->v_query(
                0,
                0,
                &(
                    appl_env_test_query_cb),
                0);

            p_env->v_set(
                0,
                0,
                0,
                0);

            appl_delete(
                p_context,
                p_env);
        }

    }

} // appl_env_test_1()

/* end-of-file: appl_env_test.cpp */
