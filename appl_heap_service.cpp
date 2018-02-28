/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_heap_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_heap.h"

//
//
//
enum appl_status
    appl_heap_service::s_alloc(
        struct appl_context_handle * const
            p_context_handle,
        struct appl_buf * const
            p_buf,
        unsigned long int const
            i_length)
{
    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_heap * const
        p_heap =
        p_context->m_heap;

    enum appl_status const
        e_status =
        p_heap->v_alloc(
            p_buf,
            i_length);

    return
        e_status;

} // s_alloc()

enum appl_status
    appl_heap_service::s_free(
        struct appl_context_handle * const
            p_context_handle,
        struct appl_buf * const
            p_buf)
{
    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_heap * const
        p_heap =
        p_context->m_heap;

    enum appl_status const
        e_status =
        p_heap->v_free(
            p_buf);

    return
        e_status;

} // s_free()

enum appl_status
    appl_heap_service::s_realloc(
        struct appl_context_handle * const
            p_context_handle,
        struct appl_buf * const
            p_buf,
        unsigned long int const
            i_length)
{
    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_heap * const
        p_heap =
        p_context->m_heap;

    enum appl_status const
        e_status =
        p_heap->v_realloc(
            p_buf,
            i_length);

    return
        e_status;

} // s_realloc()

/* end-of-file: appl_heap_service.cpp */
