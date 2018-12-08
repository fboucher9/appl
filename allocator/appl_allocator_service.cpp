/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <allocator/appl_allocator_service.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#if defined APPL_DEBUG

#include <debug/appl_debug_impl.h>

#endif /* #if defined APPL_DEBUG */

//
//
//
struct appl_object *
    appl_allocator_service::s_parent(
        struct appl_allocator * const
            p_allocator)
{
#if defined APPL_DEBUG
    if (!p_allocator)
    {
        appl_debug_impl::s_print0(
            "appl_allocator_service::s_parent invalid param\n");
    }
#endif /* #if defined APPL_DEBUG */

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
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
#if defined APPL_DEBUG
    if (!p_allocator
        || !i_buf_len
        || !r_buf)
    {
        appl_debug_impl::s_print0(
            "appl_allocator_service::s_alloc invalid param\n");
    }
#endif /* #if defined APPL_DEBUG */

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
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
#if defined APPL_DEBUG
    if (
        !p_allocator
        || !i_buf_len
        || !p_buf)
    {
        appl_debug_impl::s_print0(
            "appl_allocator_service::s_free invalid param\n");
    }
#endif /* #if defined APPL_DEBUG */

    return
        p_allocator->v_free(
            i_buf_len,
            p_buf);

} // s_free()

/* end-of-file: appl_allocator_service.cpp */
