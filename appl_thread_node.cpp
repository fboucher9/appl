/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_pool_object.h>

#include <appl_thread_node.h>

#include <appl_unused.h>

/* Assert compiler */
#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

//
//
//
enum appl_status
    appl_thread::v_start(
        struct appl_thread_descriptor const * const
            p_thread_descriptor)
{
    appl_unused(
        p_thread_descriptor);
    return
        appl_status_fail;
} // v_start()

//
//
//
enum appl_status
    appl_thread::v_interrupt(void)
{
    return
        appl_status_fail;
} // v_interrupt()

//
//
//
appl_thread::appl_thread() :
    appl_pool_object()
{
}

//
//
//
appl_thread::~appl_thread()
{
}

/* end-of-file: appl_thread_node.cpp */
