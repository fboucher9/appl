/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <allocator/appl_allocator_std.h>

#include <appl_unused.h>

#include <stdlib.h>

//
//
//
appl_allocator_std::appl_allocator_std() :
    appl_allocator()
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

    free(
        p_buf);

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_free()

/* end-of-file: appl_allocator_std.cpp */
