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
    struct appl_buf const * const
        p_ref_buf,
    unsigned long int const
        i_alloc_len,
    struct appl_string_handle * * const
        r_string_handle)
{
    return
        appl_string_service::s_create(
            p_object_handle,
            p_ref_buf,
            i_alloc_len,
            r_string_handle);

} /* create() */

/*

*/
enum appl_status
appl_string_length(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned long int * const
        r_buf_len)
{
    return
        appl_string_service::s_length(
            p_string_handle,
            r_buf_len);

} /* length() */

/*

*/
enum appl_status
appl_string_read(
    struct appl_string_handle const * const
        p_string_handle,
    struct appl_buf * const
        p_buf)
{
    return
        appl_string_service::s_read(
            p_string_handle,
            p_buf);

} /* read() */

/*

*/
enum appl_status
appl_string_write(
    struct appl_string_handle * const
        p_string_handle,
    struct appl_buf * const
        p_buf)
{
    return
        appl_string_service::s_write(
            p_string_handle,
            p_buf);

} /* write() */

/* end-of-file: appl_string_handle.cpp */
