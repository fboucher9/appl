/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

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
        void (* const p_callback)(
            void * const
                p_context),
        void * const
            p_context)
{
    appl_unused(
        p_callback,
        p_context);
    return
        appl_status_fail;
} // v_start()

//
//
//
enum appl_status
    appl_thread::v_detach(void)
{
    return
        appl_status_not_implemented;
} // v_detach()

//
//
//
enum appl_status
    appl_thread::v_stop(
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    appl_unused(
        i_wait_freq,
        i_wait_count);
    return
        appl_status_fail;
} // wait_result()

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
    appl_object()
{
}

//
//
//
appl_thread::~appl_thread()
{
}

/* end-of-file: appl_thread_node.cpp */
