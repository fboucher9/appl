/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_allocator_handle.h>

#include <allocator/appl_allocator_service.h>

#include <appl_object.h>

#if defined APPL_DEBUG

#include <debug/appl_debug_impl.h>

#endif /* #if defined APPL_DEBUG */

/*

*/
struct appl_object *
    appl_allocator_parent(
        struct appl_allocator * const
            p_allocator)
{
#if defined APPL_DEBUG
    if (!p_allocator)
    {
        appl_debug_impl::s_print0(
            "appl_allocator_parent invalid param\n");
    }
#endif /* #if defined APPL_DEBUG */

    return
        appl_allocator_service::s_parent(
            p_allocator);

} /* parent() */

/*

*/
enum appl_status
    appl_allocator_alloc(
        struct appl_allocator * const
            p_allocator,
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    if (
        p_allocator
        && i_buf_len
        && r_buf)
    {
        e_status =
            appl_allocator_service::s_alloc(
                p_allocator,
                i_buf_len,
                r_buf);
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "appl_allocator_alloc invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* alloc() */

/*

*/
enum appl_status
    appl_allocator_free(
        struct appl_allocator * const
            p_allocator,
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    if (
        p_allocator
        && i_buf_len
        && p_buf)
    {
        e_status =
            appl_allocator_service::s_free(
                p_allocator,
                i_buf_len,
                p_buf);
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "appl_allocator_free invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* free() */

//
//
//
enum appl_status
    appl_delete(
        struct appl_allocator * const
            p_allocator,
        struct appl_object * const
            p_object)
{
    enum appl_status
        e_status;

    if (
        p_object)
    {
        void * const
            p_placement =
            p_object;

        appl_size_t const
            i_placement_length =
            p_object->v_cleanup();

        if (
            i_placement_length)
        {
            delete
                p_object;

            // Ignore failure of free()
            e_status =
                appl_allocator_free(
                    p_allocator,
                    i_placement_length,
                    p_placement);

#if defined APPL_HAVE_COVERAGE
            if (
                appl_status_ok
                != e_status)
            {
                e_status =
                    appl_allocator_free(
                        p_allocator,
                        i_placement_length,
                        p_placement);
            }
#endif /* #if defined APPL_HAVE_COVERAGE */

            e_status =
                appl_status_ok;
        }
        else
        {
#if defined APPL_DEBUG
            appl_debug_impl::s_print0(
                "v_cleanup returned 0\n");
#endif /* #if defined APPL_DEBUG */

            e_status =
                appl_status_fail;
        }
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "appl_delete invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // appl_delete()

/* end-of-file: appl_allocator_handle.cpp */
