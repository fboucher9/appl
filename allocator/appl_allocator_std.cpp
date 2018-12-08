/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <allocator/appl_allocator_std.h>

#include <appl_unused.h>

#if defined APPL_DEBUG

#include <debug/appl_debug_impl.h>

#endif /* #if defined APPL_DEBUG */

#include <stdlib.h>

//
//
//
appl_allocator_std::appl_allocator_std(
    struct appl_context * const
        p_context) :
    appl_allocator(
        p_context)
{
}

//
//
//
appl_allocator_std::~appl_allocator_std()
{
}

//
//
//
appl_size_t
    appl_allocator_std::v_cleanup(void)
{
    return
        sizeof(class appl_allocator_std);

} // v_cleanup()

//
//
//
enum appl_status
    appl_allocator_std::v_alloc(
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    void *
        p_buf;

#if defined APPL_DEBUG
    if (
        !i_buf_len
        || !r_buf)
    {
        appl_debug_impl::s_print0(
            "v_alloc invalid param\n");
        appl_debug_impl::s_break();
    }
#endif /* #if defined APPL_DEBUG */

    p_buf =
        malloc(
            i_buf_len);

    if (
        p_buf)
    {
        *(
            r_buf) =
            p_buf;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "out of memory\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_alloc()

//
//
//
enum appl_status
    appl_allocator_std::v_free(
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    appl_unused(
        i_buf_len);

#if defined APPL_DEBUG
    if (
        !i_buf_len
        || !p_buf)
    {
        appl_debug_impl::s_print0(
            "v_free invalid param\n");
        appl_debug_impl::s_break();
    }
#endif /* #if defined APPL_DEBUG */

    free(
        p_buf);

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_free()

/* end-of-file: appl_allocator_std.cpp */
