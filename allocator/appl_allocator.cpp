/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG

#include <debug/appl_debug_impl.h>

#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_allocator::v_alloc(
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    appl_unused(
        i_buf_len,
        r_buf);

    return
        appl_raise_not_implemented();

} // v_alloc()

//
//
//
enum appl_status
    appl_allocator::v_free(
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    appl_unused(
        i_buf_len,
        p_buf);

    return
        appl_raise_not_implemented();

} // v_free()

//
//
//
appl_allocator::appl_allocator(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_allocator::~appl_allocator()
{
}

/* end-of-file: appl_allocator.cpp */
