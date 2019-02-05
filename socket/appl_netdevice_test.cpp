/* See LICENSE for license details */

/*

*/

#include <socket/appl_netdevice_test.h>

#include <appl_status.h>

#include <appl_netdevice_handle.h>

#include <appl_unused.h>

#include <appl_buf.h>

#include <appl_convert.h>

#include <stdio.h>

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

    printf("netdevice callback {...\n");

    printf(" - flags = %u\n",
        p_netdevice_descriptor->i_flags);

    if (
        APPL_NETDEVICE_FLAGS_NAME
        & p_netdevice_descriptor->i_flags)
    {
        printf(" - name [%.*s]\n",
            appl_convert::to_int(
                appl_buf_len(
                    p_netdevice_descriptor->p_name_min,
                    p_netdevice_descriptor->p_name_max)),
            appl_convert::to_char_ptr(
                p_netdevice_descriptor->p_name_min));
    }

    if (
        APPL_NETDEVICE_FLAGS_ADDRESS
        & p_netdevice_descriptor->i_flags)
    {
        printf(
            " - addr [%.*s]\n",
            appl_convert::to_int(
                appl_buf_len(
                    p_netdevice_descriptor->p_address_min,
                    p_netdevice_descriptor->p_address_max)),
            appl_convert::to_char_ptr(
                p_netdevice_descriptor->p_address_min));
    }

    if (
        APPL_NETDEVICE_FLAGS_FAMILY
        & p_netdevice_descriptor->i_flags)
    {
        printf(
            " - family [%d]\n",
            p_netdevice_descriptor->e_family);
    }

    if (
        APPL_NETDEVICE_FLAGS_INDEX
        & p_netdevice_descriptor->i_flags)
    {
        printf(
            " - index [%u]\n",
            p_netdevice_descriptor->i_index);
    }

    if (
        APPL_NETDEVICE_FLAGS_TYPE
        & p_netdevice_descriptor->i_flags)
    {
        printf(
            " - type [%d]\n",
            p_netdevice_descriptor->e_type);
    }

    printf("...}\n");
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

    if (
        appl_status_ok
        == e_status)
    {
    }
    else
    {
    }

} // appl_netdevice_test_1()

/* end-of-file: appl_netdevice_test.cpp */
