/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_allocator_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_allocator.h>

//
//
//
struct appl_object *
    appl_allocator_service::s_parent(
        struct appl_allocator * const
            p_allocator)
{
    return
        p_allocator;

} // s_parent()

//
//
//
enum appl_status
    appl_allocator_service::s_alloc(
        struct appl_allocator * const
            p_allocator,
        unsigned long int const
            i_buf_len,
        void * * const
            r_buf)
{
    return
        p_allocator->v_alloc(
            i_buf_len,
            r_buf);

} // s_alloc()

//
//
//
enum appl_status
    appl_allocator_service::s_free(
        struct appl_allocator * const
            p_allocator,
        unsigned long int const
            i_buf_len,
        void * const
            p_buf)
{
    return
        p_allocator->v_free(
            i_buf_len,
            p_buf);

} // s_free()

/* end-of-file: appl_allocator_service.cpp */
