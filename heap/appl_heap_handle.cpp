/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_heap_handle.h>

#include <heap/appl_heap_service.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

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

    if (
        p_context
        && i_length
        && r_buf)
    {
        e_status =
            appl_heap_service::s_alloc(
                p_context,
                i_length,
                r_buf);
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "appl_heap_alloc: invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
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

    if (
        p_context
        && i_length
        && p_buf)
    {
        e_status =
            appl_heap_service::s_free(
                p_context,
                i_length,
                p_buf);
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "appl_heap_free: invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* appl_heap_free() */

/* end-of-file: appl_heap_handle.cpp */
