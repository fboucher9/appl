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
        class appl_client * const
            p_client,
        void * * const
            r_result)
{
    static_cast<void>(
        p_client);
    static_cast<void>(
        r_result);
    return
        appl_status_fail;
} // wait_result()

//
//
//
enum appl_status
    appl_thread_node::detach(
        class appl_client * const
            p_client)
{
    static_cast<void>(
        p_client);
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

/* end-of-file: appl_thread_node.cpp */
