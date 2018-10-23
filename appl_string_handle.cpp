/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_object_handle.h>

#include <appl_string_handle.h>

#include <appl_string_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_string.h>

#include <appl_buf.h>

#include <appl_context.h>

/*

*/
enum appl_status
appl_string_create(
    struct appl_object const * const
        p_object,
    unsigned long int const
        i_alloc_len,
    struct appl_string * * const
        r_string)
{
    return
        appl_string_service::s_create(
            p_object,
            i_alloc_len,
            r_string);

} /* create() */

enum appl_status
appl_string_create_dup_buffer(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    struct appl_string * * const
        r_string)
{
    return
        appl_string_create_dup_buffer_n(
            p_object,
            p_buf_min,
            p_buf_max,
            appl_buf_len(
                p_buf_min,
                p_buf_max),
            r_string);

} /* create_dup_buffer() */

enum appl_status
appl_string_create_dup_buffer_n(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_count,
    struct appl_string * * const
        r_string)
{
    enum appl_status
        e_status;

    struct appl_string *
        p_string;

    e_status =
        appl_string_service::s_create(
            p_object,
            i_count,
            &(
                p_string));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char *
            p_new_min;

        unsigned char *
            p_new_max;

        e_status =
            appl_string_service::s_get(
                p_string,
                &(
                    p_new_min),
                &(
                    p_new_max));

        if (
            appl_status_ok
            == e_status)
        {
            /* copy... */
            appl_buf_copy(
                p_new_min,
                p_new_max,
                p_buf_min,
                p_buf_max);

            *(
                r_string) =
                p_string;
        }
        else
        {
            appl_object_destroy(
                p_string);
        }
    }

    return
        e_status;

} /* create_dup_buffer_n() */

enum appl_status
appl_string_create_dup_object(
    struct appl_string const * const
        p_ref_string,
    struct appl_string * * const
        r_string)
{
    enum appl_status
        e_status;

    unsigned char *
        p_buf_min;

    unsigned char *
        p_buf_max;

    e_status =
        appl_string_service::s_get(
            p_ref_string,
            &(
                p_buf_min),
            &(
                p_buf_max));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_string_create_dup_buffer(
                p_ref_string,
                p_buf_min,
                p_buf_max,
                r_string);
    }

    return
        e_status;

} /* create_dup_object() */

enum appl_status
appl_string_create_dup_object_n(
    struct appl_string const * const
        p_ref_string,
    unsigned long int const
        i_count,
    struct appl_string * * const
        r_string)
{
    enum appl_status
        e_status;

    unsigned char *
        p_buf_min;

    unsigned char *
        p_buf_max;

    e_status =
        appl_string_service::s_get(
            p_ref_string,
            &(
                p_buf_min),
            &(
                p_buf_max));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_string_create_dup_buffer_n(
                p_ref_string,
                p_buf_min,
                p_buf_max,
                i_count,
                r_string);
    }

    return
        e_status;

} /* create_dup_object_n() */

struct appl_object *
appl_string_parent(
    struct appl_string * const
        p_string)
{
    return
        p_string;

}

struct appl_object const *
appl_string_const_parent(
    struct appl_string const * const
        p_string)
{
    return
        p_string;

}

/*

*/
enum appl_status
appl_string_length(
    struct appl_string const * const
        p_string,
    unsigned long int * const
        r_length)
{
    return
        appl_string_service::s_length(
            p_string,
            r_length);

} /* length() */

/*

*/
enum appl_status
appl_string_get(
    struct appl_string const * const
        p_string,
    unsigned char * * const
        r_buf_min,
    unsigned char * * const
        r_buf_max)
{
    return
        appl_string_service::s_get(
            p_string,
            r_buf_min,
            r_buf_max);

} /* read() */

/* end-of-file: appl_string_handle.cpp */
