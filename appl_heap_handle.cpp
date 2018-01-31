/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_heap_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_heap.h"

/*

*/
enum appl_status
appl_heap_alloc(
    struct appl_context_handle * const
        p_context,
    struct appl_buf * const
        p_buf,
    unsigned long int const
        i_length)
{
    static_cast<void>(
        p_context);
    static_cast<void>(
        p_buf);
    static_cast<void>(
        i_length);
    return
        appl_status_not_implemented;
} /* appl_heap_alloc() */

/*

*/
enum appl_status
appl_heap_free(
    struct appl_context_handle * const
        p_context,
    struct appl_buf * const
        p_buf)
{
    static_cast<void>(
        p_context);
    static_cast<void>(
        p_buf);
    return
        appl_status_not_implemented;
} /* appl_heap_free() */

/*

*/
enum appl_status
appl_heap_realloc(
    struct appl_context_handle * const
        p_context,
    struct appl_buf * const
        p_buf,
    unsigned long int const
        i_length)
{
    static_cast<void>(
        p_context);
    static_cast<void>(
        p_buf);
    static_cast<void>(
        i_length);
    return
        appl_status_not_implemented;
} /* appl_heap_realloc() */

/* end-of-file: appl_heap_handle.cpp */
