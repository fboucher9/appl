/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_heap_handle.h"

#include "appl_heap_service.h"

#include "appl_object_handle.h"

/*

*/
enum appl_status
appl_heap_alloc(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned long int const
        i_length,
    void * * const
        r_buf)
{
    enum appl_status
        e_status;

    struct appl_context_handle *
        p_context_handle;

    p_context_handle =
        appl_object_get_context_handle(
            p_object_handle);

    e_status =
        appl_heap_service::s_alloc(
            p_context_handle,
            i_length,
            r_buf);

    return
        e_status;

} /* appl_heap_alloc() */

/*

*/
enum appl_status
appl_heap_free(
    struct appl_object_handle const * const
        p_object_handle,
    void * const
        p_buf)
{
    enum appl_status
        e_status;

    struct appl_context_handle *
        p_context_handle;

    p_context_handle =
        appl_object_get_context_handle(
            p_object_handle);

    e_status =
        appl_heap_service::s_free(
            p_context_handle,
            p_buf);

    return
        e_status;

} /* appl_heap_free() */

/*

*/
enum appl_status
appl_heap_realloc(
    struct appl_object_handle const * const
        p_object_handle,
    void * const
        p_old_buf,
    unsigned long int const
        i_length,
    void * * const
        r_new_buf)
{
    enum appl_status
        e_status;

    struct appl_context_handle *
        p_context_handle;

    p_context_handle =
        appl_object_get_context_handle(
            p_object_handle);

    e_status =
        appl_heap_service::s_realloc(
            p_context_handle,
            p_old_buf,
            i_length,
            r_new_buf);

    return
        e_status;

} /* appl_heap_realloc() */

/* end-of-file: appl_heap_handle.cpp */
