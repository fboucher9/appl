/* See LICENSE for license details */

/*

*/

#include <socket/appl_netdevice_test.h>

#include <appl_status.h>

#include <appl_netdevice_handle.h>

#include <appl_unused.h>

//
//
//
static
void
enumerate_netdevice_cb(
    void * const
        p_callback_context,
    struct appl_netdevice_descriptor const * const
        p_netdevice_descriptor)
{
    appl_unused(
        p_callback_context,
        p_netdevice_descriptor);

} // enumerate_netdevice_cb()

//
//
//
void
    appl_netdevice_test_1(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    struct appl_netdevice_descriptor
        o_netdevice_filter;

    o_netdevice_filter.i_flags =
        0u;

    e_status =
        appl_netdevice_enumerate(
            p_context,
            &(
                o_netdevice_filter),
            &(
                enumerate_netdevice_cb),
            0);

} // appl_netdevice_test_1()

/* end-of-file: appl_netdevice_test.cpp */
