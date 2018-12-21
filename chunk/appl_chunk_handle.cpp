/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_chunk_handle.h>

#include <chunk/appl_chunk_service.h>

/*

*/
enum appl_status
appl_chunk_create(
    struct appl_context * const
        p_context,
    struct appl_chunk * * const
        r_chunk)
{
    return
        appl_chunk_service::s_create(
            p_context,
            r_chunk);

} /* appl_chunk_create() */

/*

*/
enum appl_status
appl_chunk_destroy(
    struct appl_chunk * const
        p_chunk)
{
    return
        appl_chunk_service::s_destroy(
            p_chunk);

} /* appl_chunk_destroy() */

/*

*/
enum appl_status
appl_chunk_write(
    struct appl_chunk * const
        p_chunk,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        appl_chunk_service::s_write(
            p_chunk,
            p_buf_min,
            p_buf_max);

} /* appl_chunk_write() */

/*

*/
enum appl_status
appl_chunk_length(
    struct appl_chunk const * const
        p_chunk,
    unsigned long int * const
        r_length)
{
    return
        appl_chunk_service::s_length(
            p_chunk,
            r_length);

} /* appl_chunk_length() */

/*

*/
enum appl_status
appl_chunk_read(
    struct appl_chunk const * const
        p_chunk,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max)
{
    return
        appl_chunk_service::s_read(
            p_chunk,
            p_buf_min,
            p_buf_max);

} /* appl_chunk_read() */

/*

*/
enum appl_status
appl_chunk_reset(
    struct appl_chunk * const
        p_chunk)
{
    return
        appl_chunk_service::s_reset(
            p_chunk);

} /* appl_chunk_reset() */

/* end-of-file: appl_chunk_handle.cpp */
