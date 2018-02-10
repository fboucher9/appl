/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_file_descriptor.h"

#include "appl_object_handle.h"

#include "appl_file_handle.h"

enum appl_status
appl_file_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_file_descriptor const * const
        p_file_descriptor,
    struct appl_file_handle * * const
        r_file_handle)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_context_handle);
    static_cast<void>(
        p_file_descriptor);
    static_cast<void>(
        r_file_handle);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_file_create() */

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
    enum appl_status
        e_status;

    static_cast<void>(
        p_file_handle);
    static_cast<void>(
        p_buffer);
    static_cast<void>(
        i_buffer_max_length);
    static_cast<void>(
        p_actual_length);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_file_read() */

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
    enum appl_status
        e_status;

    static_cast<void>(
        p_file_handle);
    static_cast<void>(
        p_buffer);
    static_cast<void>(
        i_buffer_max_length);
    static_cast<void>(
        p_actual_length);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* appl_file_write() */

/* end-of-file: appl_file_handle.cpp */
