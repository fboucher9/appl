/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_file_handle.h>

#include <file/appl_file_service.h>

/*

*/
enum appl_status
appl_file_create(
    struct appl_context * const
        p_context,
    struct appl_file_descriptor const * const
        p_file_descriptor,
    struct appl_file * * const
        r_file)
{
    return
        appl_file_service::s_create(
            p_context,
            p_file_descriptor,
            r_file);

} /* appl_file_create() */

struct appl_object *
appl_file_parent(
    struct appl_file * const
        p_file)
{
    return
        appl_file_service::s_parent(
            p_file);

}

struct appl_object const *
appl_file_const_parent(
    struct appl_file const * const
        p_file)
{
    return
        appl_file_service::s_const_parent(
            p_file);

}

/*

*/
enum appl_status
appl_file_read(
    struct appl_file * const
        p_file,
    unsigned char * const
        p_buf_cur,
    unsigned char * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    return
        appl_file_service::s_read(
            p_file,
            p_buf_cur,
            p_buf_max,
            r_count);

} /* appl_file_read() */

/*

*/
enum appl_status
appl_file_write(
    struct appl_file * const
        p_file,
    unsigned char const * const
        p_buf_cur,
    unsigned char const * const
        p_buf_max,
    unsigned long int * const
        r_count)
{
    return
        appl_file_service::s_write(
            p_file,
            p_buf_cur,
            p_buf_max,
            r_count);

} /* appl_file_write() */

/* end-of-file: appl_file_handle.cpp */
