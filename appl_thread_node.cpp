/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_thread_node.h"

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

//
//
//
enum appl_status
    appl_thread_node::wait_result(
        void * * const
            r_result)
{
    static_cast<void>(
        r_result);
    return
        appl_status_fail;
} // wait_result()

//
//
//
enum appl_status
    appl_thread_node::detach(void)
{
    return
        appl_status_fail;
} // detach()

//
//
//
appl_thread_node::appl_thread_node() :
    appl_object()
{
}

//
//
//
appl_thread_node::~appl_thread_node()
{
}

class appl_thread_node *
    appl_thread_node::convert_handle(
        struct appl_thread_handle * const
            p_thread_handle)
{
    return
        reinterpret_cast<class appl_thread_node *>(
            p_thread_handle);

} // convert_handle()

struct appl_thread_handle *
    appl_thread_node::get_handle(void)
{
    return
        reinterpret_cast<struct appl_thread_handle *>(
            this);

} // get_handle()

/* end-of-file: appl_thread_node.cpp */
