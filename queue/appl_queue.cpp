/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_queue_handle.h>

#include <list/appl_list.h>

#include <appl_object.h>

#include <queue/appl_queue.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
    appl_queue::v_push(
        struct appl_list * const
            p_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    appl_unused(
        p_node,
        i_wait_freq,
        i_wait_count);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_push()

//
//
//
enum appl_status
    appl_queue::v_pop(
        struct appl_list * * const
            r_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count)
{
    enum appl_status
        e_status;

    appl_unused(
        r_node,
        i_wait_freq,
        i_wait_count);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_pop()

//
//
//
enum appl_status
    appl_queue::v_interrupt(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_interrupt()

//
//
//
appl_queue::appl_queue(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_queue::~appl_queue()
{
}

/* end-of-file: appl_queue.cpp */
