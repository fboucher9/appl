/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <socket/appl_netdevice_main.h>

#include <appl_netdevice_handle.h>

#include <appl_unused.h>

#include <appl_test.h>

//
//
//
static
void
appl_netdevice_main_cb(
    void * const
        p_callback_context,
    struct appl_netdevice_descriptor const * const
        p_netdevice_descriptor)
{
    appl_unused(
        p_callback_context);

    appl_print0("netdevice callback {...\n");

    appl_print0(" - flags = ");
    appl_print_lu(
        p_netdevice_descriptor->i_flags);
    appl_print0("\n");

    if (
        APPL_NETDEVICE_FLAGS_NAME
        & p_netdevice_descriptor->i_flags)
    {
        appl_print0(
            " - name [");
        appl_print(
            p_netdevice_descriptor->p_name_min,
            p_netdevice_descriptor->p_name_max);
        appl_print0(
            "]\n");
    }

    if (
        APPL_NETDEVICE_FLAGS_ADDRESS
        & p_netdevice_descriptor->i_flags)
    {
        appl_print0(
            " - addr [");
        appl_print(
            p_netdevice_descriptor->p_address_min,
            p_netdevice_descriptor->p_address_max);
        appl_print0(
            "]\n");
    }

    if (
        APPL_NETDEVICE_FLAGS_FAMILY
        & p_netdevice_descriptor->i_flags)
    {
        appl_print0(
            " - family [");
        appl_print_ld(
            p_netdevice_descriptor->e_family);
        appl_print0(
            "]\n");
    }

    if (
        APPL_NETDEVICE_FLAGS_INDEX
        & p_netdevice_descriptor->i_flags)
    {
        appl_print0(
            " - index [");
        appl_print_lu(
            p_netdevice_descriptor->i_index);
        appl_print0(
            "]\n");
    }

    if (
        APPL_NETDEVICE_FLAGS_TYPE
        & p_netdevice_descriptor->i_flags)
    {
        appl_print0(
            " - type [");
        appl_print_ld(
            p_netdevice_descriptor->e_type);
        appl_print0(
            "]\n");
    }

    appl_print0("...}\n");

} // enumerate_netdevice_cb()

//
//
//
enum appl_status
appl_netdevice_main(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_options,
    unsigned long int const
        i_shift)
{
    enum appl_status
        e_status;

    struct appl_netdevice_descriptor
        o_netdevice_filter;

    appl_unused(
        p_options,
        i_shift);

    o_netdevice_filter.i_flags =
        0ul;

    e_status =
        appl_netdevice_enumerate(
            p_context,
            &(
                o_netdevice_filter),
            &(
                appl_netdevice_main_cb),
            0);

    return
        e_status;

} // appl_netdevice_main()

/* end-of-file: appl_netdevice_main.cpp */
