/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_heap.h"

#include "appl_unused.h"

//
//
//
enum appl_status
    appl_heap::v_alloc(
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    appl_unused(
        i_buf_len);
    appl_unused(
        r_buf);

    return
        appl_status_not_implemented;

} // v_alloc()

//
//
//
enum appl_status
    appl_heap::v_free(
        void * const
            p_buf)
{
    appl_unused(
        p_buf);

    return
        appl_status_not_implemented;

} // v_free()

//
//
//
enum appl_status
    appl_heap::v_realloc(
        void * const
            p_old_buf,
        appl_size_t const
            i_buf_len,
        void * * const
            r_new_buf)
{
    appl_unused(
        p_old_buf);
    appl_unused(
        i_buf_len);
    appl_unused(
        r_new_buf);

    return
        appl_status_not_implemented;

} // v_realloc()

//
//
//
appl_heap::appl_heap() :
    appl_object()
{
}

//
//
//
appl_heap::~appl_heap()
{
}

/* end-of-file: appl_heap.cpp */
