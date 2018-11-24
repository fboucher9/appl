/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <appl_unused.h>

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
        appl_status_not_implemented;

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
        appl_status_not_implemented;

} // v_free()

//
//
//
appl_allocator::appl_allocator() :
    appl_object()
{
}

//
//
//
appl_allocator::~appl_allocator()
{
}

/* end-of-file: appl_allocator.cpp */
