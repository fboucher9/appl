/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <allocator/appl_allocator_placement.h>

#include <appl_unused.h>

//
//
//
appl_allocator_placement::appl_allocator_placement(
    void * const
        p_placement) :
    m_placement(
        p_placement)
{
}

//
//
//
appl_allocator_placement::~appl_allocator_placement()
{
}

//
//
//
enum appl_status
    appl_allocator_placement::v_alloc(
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    appl_unused(
        i_buf_len);

    *(
        r_buf) =
        m_placement;

    return
        appl_status_ok;

} // v_alloc()

//
//
//
enum appl_status
    appl_allocator_placement::v_free(
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    appl_unused(
        i_buf_len,
        p_buf);

    return
        appl_status_ok;

} // v_free()

/* end-of-file: appl_allocator_placement.cpp */
