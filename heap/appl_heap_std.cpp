/* See LICENSE for license details */

/*

*/

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <appl_status.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <appl_allocator_handle.h>

#include <heap/appl_heap.h>

#include <appl_list.h>

#include <heap/appl_heap_std.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

//
//
//
enum appl_status
    appl_heap_std::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_heap * * const
            r_heap)
{
    enum appl_status
        e_status;

    class appl_heap_std *
        p_heap_std;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_heap_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_heap) =
            p_heap_std;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_heap_std::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_heap * const
            p_heap)
{
    return
        appl_delete(
            p_allocator,
            p_heap);

} // s_destroy()

//
//
//
appl_heap_std::appl_heap_std(
    struct appl_context * const
        p_context) :
    appl_heap(
        p_context)
{
}

//
//
//
appl_heap_std::~appl_heap_std()
{
}

//
//
//
enum appl_status
    appl_heap_std::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
appl_heap_std::v_cleanup(void)
{
    return
        sizeof(class appl_heap_std);

} // v_cleanup()

//
//
//
enum appl_status
    appl_heap_std::v_alloc(
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    void *
        p_allocation;

#if defined APPL_HAVE_COVERAGE
    if (appl_coverage_check())
    {
        p_allocation =
            0;
    }
    else
#endif /* #if defined APPL_HAVE_COVERAGE */
    {
        p_allocation =
            malloc(
                i_buf_len);
    }

    if (
        p_allocation)
    {
        *(
            r_buf) =
            p_allocation;

        e_status =
            appl_status_ok;
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "appl_heap_std v_alloc: out of memory\n");
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
    appl_heap_std::v_free(
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    appl_unused(
        i_buf_len);

    {
        free(
            p_buf);

        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // v_free()

/* end-of-file: appl_heap_std.cpp */
