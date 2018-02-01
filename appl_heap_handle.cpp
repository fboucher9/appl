/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_heap_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_heap.h"

/*

*/
enum appl_status
appl_heap_alloc(
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
        p_heap->alloc_memory(
            p_buf,
            i_length);

    return
        e_status;

} /* appl_heap_alloc() */

/*

*/
enum appl_status
appl_heap_free(
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
        p_heap->free_memory(
            p_buf);

    return
        e_status;

} /* appl_heap_free() */

/*

*/
enum appl_status
appl_heap_realloc(
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
        p_heap->realloc_memory(
            p_buf,
            i_length);

    return
        e_status;

} /* appl_heap_realloc() */

/* end-of-file: appl_heap_handle.cpp */
