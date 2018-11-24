/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <heap/appl_heap_service.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <allocator/appl_allocator.h>

#include <heap/appl_heap.h>

static
struct appl_heap *
get_heap_from_object(
    struct appl_context const * const
        p_context)
{
    return
        p_context->m_heap;

} // get_heap_from_object()

//
//
//
enum appl_status
    appl_heap_service::s_alloc(
        struct appl_context const * const
            p_context,
        appl_size_t const
            i_length,
        void * * const
            r_buf)
{
    struct appl_heap * const
        p_heap =
        get_heap_from_object(
            p_context);

    enum appl_status const
        e_status =
        p_heap->v_alloc(
            i_length,
            r_buf);

    return
        e_status;

} // s_alloc()

enum appl_status
    appl_heap_service::s_free(
        struct appl_context const * const
            p_context,
        appl_size_t const
            i_length,
        void * const
            p_buf)
{
    struct appl_heap * const
        p_heap =
        get_heap_from_object(
            p_context);

    enum appl_status const
        e_status =
        p_heap->v_free(
            i_length,
            p_buf);

    return
        e_status;

} // s_free()

/* end-of-file: appl_heap_service.cpp */
