/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_file_descriptor.h"

#include "appl_object_handle.h"

#include "appl_file_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_file_mgr.h"

#include "appl_file_node.h"

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
    enum appl_status
        e_status;

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_file_mgr * const
        p_file_mgr =
        p_context->m_file_mgr;

    e_status =
        p_file_mgr->v_create_node(
            p_file_descriptor,
            reinterpret_cast<struct appl_file_node * *>(
                r_file_handle));

    return
        e_status;

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
    enum appl_status
        e_status;

    class appl_file_node * const
        p_file_node =
        appl_file_node::convert_handle(
            p_file_handle);

    e_status =
        p_file_node->v_read(
            p_buffer,
            i_buffer_max_length,
            p_actual_length);

    return
        e_status;

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
    enum appl_status
        e_status;

    class appl_file_node * const
        p_file_node =
        appl_file_node::convert_handle(
            p_file_handle);

    e_status =
        p_file_node->v_write(
            p_buffer,
            i_buffer_max_length,
            p_actual_length);

    return
        e_status;

} /* appl_file_write() */

/* end-of-file: appl_file_handle.cpp */
