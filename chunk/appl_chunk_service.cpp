/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <chunk/appl_chunk_service.h>

#include <appl_context_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <chunk/appl_chunk.h>

#include <list/appl_list.h>

#include <chunk/appl_chunk_std.h>

//
//
//
enum appl_status
appl_chunk_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_chunk * * const
        r_chunk)
{
    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_chunk_std::s_create(
            p_allocator,
            r_chunk);

} // s_create()

//
//
//
enum appl_status
appl_chunk_service::s_destroy(
    struct appl_chunk * const
        p_chunk)
{
    struct appl_context * const
        p_context =
        p_chunk->get_context();

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_chunk_std::s_destroy(
            p_allocator,
            p_chunk);

} // s_destroy()

//
//
//
enum appl_status
appl_chunk_service::s_write(
    struct appl_chunk * const
        p_chunk,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        p_chunk->v_write(
            p_buf_min,
            p_buf_max);

} // s_write()

//
//
//
enum appl_status
appl_chunk_service::s_length(
    struct appl_chunk const * const
        p_chunk,
    unsigned long int * const
        r_length)
{
    return
        p_chunk->v_length(
            r_length);

} // s_length()

//
//
//
enum appl_status
appl_chunk_service::s_read(
    struct appl_chunk const * const
        p_chunk,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max)
{
    return
        p_chunk->v_read(
            p_buf_min,
            p_buf_max);

} // s_read()

//
//
//
enum appl_status
appl_chunk_service::s_reset(
    struct appl_chunk * const
        p_chunk)
{
    return
        p_chunk->v_reset();

} // s_reset()

/* end-of-file: appl_chunk_service.cpp */
