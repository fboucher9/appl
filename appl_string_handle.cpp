/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_string_handle.h"

#include "appl_string_service.h"

/*

*/
enum appl_status
appl_string_create(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned long int const
        i_alloc_len,
    struct appl_string_handle * * const
        r_string_handle)
{
    return
        appl_string_service::s_create(
            p_object_handle,
            i_alloc_len,
            r_string_handle);

} /* create() */

enum appl_status
appl_string_create_ref_buffer(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    struct appl_string_handle * * const
        r_string_handle)
{
    return
        appl_string_service::s_create_ref(
            p_object_handle,
            p_buf_min,
            p_buf_max,
            r_string_handle);

} /* create_ref_buffer() */

enum appl_status
appl_string_create_ref_buffer_n(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_count,
    struct appl_string_handle * * const
        r_string_handle)
{
    unsigned char const * const
        p_buf_end =
        ((p_buf_min + i_count) < p_buf_max)
        ? p_buf_min + i_count
        : p_buf_max;

    return
        appl_string_service::s_create_ref(
            p_object_handle,
            p_buf_min,
            p_buf_end,
            r_string_handle);

} /* create_ref_buffer_n() */

/*

*/
enum appl_status
appl_string_create_ref_object(
    struct appl_string_handle const * const
        p_ref_string_handle,
    struct appl_string_handle * * const
        r_string_handle)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
            p_ref_string_handle,
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
                &(
                    p_ref_string_handle->o_object_handle),
                p_buf_min,
                p_buf_max,
                r_string_handle);
    }

    return
        e_status;

} /* create_ref_object() */

/*

*/
enum appl_status
appl_string_create_ref_object_n(
    struct appl_string_handle const * const
        p_ref_string_handle,
    unsigned long int const
        i_count,
    struct appl_string_handle * * const
        r_string_handle)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
            p_ref_string_handle,
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
                &(
                    p_ref_string_handle->o_object_handle),
                p_buf_min,
                p_buf_max,
                i_count,
                r_string_handle);
    }

    return
        e_status;

} /* create_ref_object_n() */

enum appl_status
appl_string_create_dup_buffer(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    struct appl_string_handle * * const
        r_string_handle)
{
    return
        appl_string_create_dup_buffer_n(
            p_object_handle,
            p_buf_min,
            p_buf_max,
            static_cast<unsigned long int>(
                p_buf_max
                - p_buf_min),
            r_string_handle);

} /* create_dup_buffer() */

enum appl_status
appl_string_create_dup_buffer_n(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_count,
    struct appl_string_handle * * const
        r_string_handle)
{
    enum appl_status
        e_status;

    struct appl_string_handle *
        p_string_handle;

    e_status =
        appl_string_service::s_create(
            p_object_handle,
            i_count,
            &(
                p_string_handle));

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
                p_string_handle,
                p_buf_min,
                p_buf_end);

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_string_handle) =
                p_string_handle;
        }
        else
        {
            appl_object_destroy(
                &(
                    p_string_handle->o_object_handle));
        }
    }

    return
        e_status;

} /* create_dup_buffer_n() */

enum appl_status
appl_string_create_dup_object(
    struct appl_string_handle const * const
        p_ref_string_handle,
    struct appl_string_handle * * const
        r_string_handle)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
            p_ref_string_handle,
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
                &(
                    p_ref_string_handle->o_object_handle),
                p_buf_min,
                p_buf_max,
                r_string_handle);
    }

    return
        e_status;

} /* create_dup_object() */

enum appl_status
appl_string_create_dup_object_n(
    struct appl_string_handle const * const
        p_ref_string_handle,
    unsigned long int const
        i_count,
    struct appl_string_handle * * const
        r_string_handle)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
            p_ref_string_handle,
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
                &(
                    p_ref_string_handle->o_object_handle),
                p_buf_min,
                p_buf_max,
                i_count,
                r_string_handle);
    }

    return
        e_status;

} /* create_dup_object_n() */

/*

*/
enum appl_status
appl_string_read(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max)
{
    return
        appl_string_service::s_read(
            p_string_handle,
            r_buf_min,
            r_buf_max);

} /* read() */

/*

*/
enum appl_status
appl_string_write_char(
    struct appl_string_handle * const
        p_string_handle,
    unsigned char const
        i_value)
{
    return
        appl_string_service::s_write(
            p_string_handle,
            &(
                i_value),
            &(
                i_value) + 1);

} /* write_char() */

/*

*/
enum appl_status
appl_string_write_buffer(
    struct appl_string_handle * const
        p_string_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        appl_string_service::s_write(
            p_string_handle,
            p_buf_min,
            p_buf_max);

} /* write_buffer() */

/*

*/
enum appl_status
appl_string_write_buffer_n(
    struct appl_string_handle * const
        p_string_handle,
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
            p_string_handle,
            p_buf_min,
            p_buf_end);

} /* write_buffer_n() */

/*

*/
enum appl_status
appl_string_write_object(
    struct appl_string_handle * const
        p_string_handle,
    struct appl_string_handle const * const
        p_ref_string_handle)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    e_status =
        appl_string_service::s_read(
            p_ref_string_handle,
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
                p_string_handle,
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
    struct appl_string_handle * const
        p_string_handle,
    struct appl_string_handle const * const
        p_ref_string_handle,
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
            p_ref_string_handle,
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
                p_string_handle,
                p_buf_min,
                p_buf_max,
                i_count);
    }

    return
        e_status;

} /* write_object_n() */

/* end-of-file: appl_string_handle.cpp */
