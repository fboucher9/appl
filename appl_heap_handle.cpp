/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_heap_handle.h"

#include "appl_heap_service.h"

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
    return
        appl_heap_service::s_alloc(
            p_context_handle,
            p_buf,
            i_length);

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
    return
        appl_heap_service::s_free(
            p_context_handle,
            p_buf);

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
    return
        appl_heap_service::s_realloc(
            p_context_handle,
            p_buf,
            i_length);

} /* appl_heap_realloc() */

/* end-of-file: appl_heap_handle.cpp */
