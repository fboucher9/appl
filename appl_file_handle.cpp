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
        appl_file_service::create_node(
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
        p_buffer,
    unsigned long int const
        i_buffer_max_length,
    unsigned long int * const
        p_actual_length)
{
    return
        appl_file_service::read_buffer(
            p_file_handle,
            p_buffer,
            i_buffer_max_length,
            p_actual_length);

} /* appl_file_read() */

/*

*/
enum appl_status
appl_file_write(
    struct appl_file_handle * const
        p_file_handle,
    unsigned char const * const
        p_buffer,
    unsigned long int const
        i_buffer_max_length,
    unsigned long int * const
        p_actual_length)
{
    return
        appl_file_service::write_buffer(
            p_file_handle,
            p_buffer,
            i_buffer_max_length,
            p_actual_length);

} /* appl_file_write() */

/* end-of-file: appl_file_handle.cpp */
