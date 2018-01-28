/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object.h"

#include "appl_heap.h"

//
//
//
enum appl_status
    appl_heap::alloc_memory(
        struct appl_buf * const
            p_buf,
        unsigned long int const
            i_buf_len)
{
    static_cast<void>(
        p_buf);
    static_cast<void>(
        i_buf_len);

    return
        appl_status_not_implemented;

} // alloc_memory()

//
//
//
enum appl_status
    appl_heap::free_memory(
        struct appl_buf * const
            p_buf)
{
    static_cast<void>(
        p_buf);

    return
        appl_status_not_implemented;

} // free_memory()

//
//
//
enum appl_status
    appl_heap::realloc_memory(
        struct appl_buf * const
            p_buf,
        unsigned long int const
            i_buf_len)
{
    static_cast<void>(
        p_buf);
    static_cast<void>(
        i_buf_len);

    return
        appl_status_not_implemented;

} // realloc_memory()

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
