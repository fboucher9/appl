/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_file_handle.h"

#include "appl_file_service.h"

/*

*/
enum appl_status
appl_file_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_file_descriptor const * const
        p_file_descriptor,
    struct appl_file_handle * * const
        r_file_handle)
{
    return
        appl_file_service::s_create(
            p_context_handle,
            p_file_descriptor,
            r_file_handle);

} /* appl_file_create() */

/*

*/
enum appl_status
appl_file_read(
    struct appl_file_handle * const
        p_file_handle,
    unsigned char * const
        p_buf_cur,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    return
        appl_file_service::s_read(
            p_file_handle,
            p_buf_cur,
            p_buf_max,
            r_count);

} /* appl_file_read() */

/*

*/
enum appl_status
appl_file_write(
    struct appl_file_handle * const
        p_file_handle,
    unsigned char const * const
        p_buf_cur,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    return
        appl_file_service::s_write(
            p_file_handle,
            p_buf_cur,
            p_buf_max,
            r_count);

} /* appl_file_write() */

/* end-of-file: appl_file_handle.cpp */
