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
    struct appl_object_handle * const
        p_object_handle,
    unsigned long int const
        i_alloc_len,
    struct appl_string_handle * * const
        r_string_handle)
{
    return
        appl_string_service::s_create(
            p_object_handle,
            (unsigned char const *)(
                0),
            (unsigned char const *)(
                0),
            i_alloc_len,
            r_string_handle);

} /* create() */

/*

*/
enum appl_status
appl_string_create_const(
    struct appl_object_handle * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    struct appl_string_handle * * const
        r_string_handle)
{
    return
        appl_string_service::s_create(
            p_object_handle,
            p_buf_min,
            p_buf_max,
            0ul,
            r_string_handle);

} /* create_const() */

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
appl_string_write(
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

} /* write() */

/* end-of-file: appl_string_handle.cpp */
