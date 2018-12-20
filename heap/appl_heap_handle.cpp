/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_heap_handle.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

#include <heap/appl_heap_service.h>

#include <appl_validate.h>

/*

*/
enum appl_status
appl_heap_alloc(
    struct appl_context const * const
        p_context,
    appl_size_t const
        i_length,
    void * * const
        r_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != p_context)
            && (0 != i_length)
            && (0 != r_buf));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_heap_service::s_alloc(
                p_context,
                i_length,
                r_buf);
    }

    return
        e_status;

} /* appl_heap_alloc() */

/*

*/
enum appl_status
appl_heap_free(
    struct appl_context const * const
        p_context,
    appl_size_t const
        i_length,
    void * const
        p_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != p_context)
            && (0 != i_length)
            && (0 != p_buf));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_heap_service::s_free(
                p_context,
                i_length,
                p_buf);
    }

    return
        e_status;

} /* appl_heap_free() */

//
//
//
enum appl_status
    appl_delete(
        struct appl_context * const
            p_context,
        struct appl_object * const
            p_object)
{
    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_delete(
            p_allocator,
            p_object);

} // appl_delete()

/* end-of-file: appl_heap_handle.cpp */
