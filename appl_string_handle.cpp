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
            0,
            0,
            0,
            i_alloc_len,
            r_string);

} /* create() */

enum appl_status
appl_string_create_ref_buffer(
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
        appl_string_service::s_create(
            p_object,
            p_buf_min,
            p_buf_max,
            p_buf_min,
            0,
            r_string);

} /* create_ref_buffer() */

enum appl_status
appl_string_create_ref_buffer_n(
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
    unsigned char const * const
        p_buf_end =
        ((p_buf_min + i_count) < p_buf_max)
        ? p_buf_min + i_count
        : p_buf_max;

    return
        appl_string_service::s_create(
            p_object,
            p_buf_min,
            p_buf_end,
            p_buf_min,
            0,
            r_string);

} /* create_ref_buffer_n() */

/*

*/
enum appl_status
appl_string_create_ref_object(
    struct appl_string const * const
        p_ref_string,
    struct appl_string * * const
        r_string)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
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
            appl_string_create_ref_buffer(
                p_ref_string,
                p_buf_min,
                p_buf_max,
                r_string);
    }

    return
        e_status;

} /* create_ref_object() */

/*

*/
enum appl_status
appl_string_create_ref_object_n(
    struct appl_string const * const
        p_ref_string,
    unsigned long int const
        i_count,
    struct appl_string * * const
        r_string)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
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
            appl_string_create_ref_buffer_n(
                p_ref_string,
                p_buf_min,
                p_buf_max,
                i_count,
                r_string);
    }

    return
        e_status;

} /* create_ref_object_n() */

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
            0,
            0,
            0,
            i_count,
            &(
                p_string));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char const * const
            p_buf_end =
            ((p_buf_min + i_count) < p_buf_max)
            ? p_buf_min + i_count
            : p_buf_max;

        e_status =
            appl_string_service::s_write(
                p_string,
                p_buf_min,
                p_buf_end);

        if (
            appl_status_ok
            == e_status)
        {
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

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
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

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
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

/*

*/
enum appl_status
appl_string_create_extern(
    struct appl_object const * const
        p_object,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    struct appl_string * * const
        r_string)
{
    enum appl_status
        e_status;

    e_status =
        appl_string_service::s_create(
            p_object,
            p_buf_min,
            p_buf_min,
            p_buf_max,
            0,
            r_string);

    return
        e_status;

} /* create_extern() */

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
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
            p_string,
            &(
                p_buf_min),
            &(
                p_buf_max));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_length) =
            appl_buf_len(
                p_buf_min,
                p_buf_max);
    }

    return
        e_status;

} /* length() */

/*

*/
enum appl_status
appl_string_read(
    struct appl_string const * const
        p_string,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max)
{
    return
        appl_string_service::s_read(
            p_string,
            r_buf_min,
            r_buf_max);

} /* read() */

/*

*/
enum appl_status
appl_string_write_char(
    struct appl_string * const
        p_string,
    unsigned char const
        i_value)
{
    return
        appl_string_service::s_write(
            p_string,
            &(
                i_value),
            &(
                i_value) + 1);

} /* write_char() */

/*

*/
enum appl_status
appl_string_write_buffer(
    struct appl_string * const
        p_string,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        appl_string_service::s_write(
            p_string,
            p_buf_min,
            p_buf_max);

} /* write_buffer() */

/*

*/
enum appl_status
appl_string_write_buffer_n(
    struct appl_string * const
        p_string,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_count)
{
    unsigned char const * const
        p_buf_end =
        ((p_buf_min + i_count) < p_buf_max)
        ? p_buf_min + i_count
        : p_buf_max;

    return
        appl_string_service::s_write(
            p_string,
            p_buf_min,
            p_buf_end);

} /* write_buffer_n() */

/*

*/
enum appl_status
appl_string_write_object(
    struct appl_string * const
        p_string,
    struct appl_string const * const
        p_ref_string)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
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
            appl_string_write_buffer(
                p_string,
                p_buf_min,
                p_buf_max);
    }

    return
        e_status;

} /* write_object() */

/*

*/
enum appl_status
appl_string_write_object_n(
    struct appl_string * const
        p_string,
    struct appl_string const * const
        p_ref_string,
    unsigned long int const
        i_count)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
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
            appl_string_write_buffer_n(
                p_string,
                p_buf_min,
                p_buf_max,
                i_count);
    }

    return
        e_status;

} /* write_object_n() */

/* end-of-file: appl_string_handle.cpp */
