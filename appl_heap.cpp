/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_heap.h"

//
//
//
enum appl_status
    appl_heap::v_alloc(
        struct appl_buf * const
            p_buf,
        appl_size_t const
            i_buf_len)
{
    static_cast<void>(
        p_buf);
    static_cast<void>(
        i_buf_len);

    return
        appl_status_not_implemented;

} // v_alloc()

//
//
//
enum appl_status
    appl_heap::v_free(
        struct appl_buf * const
            p_buf)
{
    static_cast<void>(
        p_buf);

    return
        appl_status_not_implemented;

} // v_free()

//
//
//
enum appl_status
    appl_heap::v_realloc(
        struct appl_buf * const
            p_buf,
        appl_size_t const
            i_buf_len)
{
    static_cast<void>(
        p_buf);
    static_cast<void>(
        i_buf_len);

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
