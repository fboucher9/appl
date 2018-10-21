/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_file_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_pool_object.h>

#include <appl_context.h>

#include <appl_file_mgr.h>

#include <appl_file_node.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_file_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_file_descriptor const * const
            p_file_descriptor,
        struct appl_file * * const
            r_file)
{
    enum appl_status
        e_status;

    class appl_file_mgr * const
        p_file_mgr =
        p_context->m_file_mgr;

    e_status =
        p_file_mgr->v_create_node(
            p_file_descriptor,
            r_file);

    return
        e_status;

} // create_node()

//
//
//
enum appl_status
    appl_file_service::s_read(
        struct appl_file * const
            p_file,
        unsigned char * const
            p_buf_cur,
        unsigned char * const
            p_buf_max,
        unsigned long int * const
            r_count)
{
    enum appl_status
        e_status;

    e_status =
        p_file->v_read(
            p_buf_cur,
            p_buf_max,
            r_count);

    return
        e_status;

} // read_buffer()

//
//
//
enum appl_status
    appl_file_service::s_write(
        struct appl_file * const
            p_file,
        unsigned char const * const
            p_buf_cur,
        unsigned char const * const
            p_buf_max,
        unsigned long int * const
            r_count)
{
    enum appl_status
        e_status;

    e_status =
        p_file->v_write(
            p_buf_cur,
            p_buf_max,
            r_count);

    return
        e_status;

} // write_buffer()

/* end-of-file: appl_file_service.cpp */
