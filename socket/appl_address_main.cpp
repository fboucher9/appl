/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <socket/appl_address_main.h>

#include <appl_address_handle.h>

#include <appl_types.h>

#include <appl_address_descriptor.h>

#include <appl_test.h>

#include <appl_unused.h>

#include <appl_options_handle.h>

static
void
    test_address_resolve_callback(
        void * const
            p_callback_context,
        struct appl_address_descriptor const * const
            p_address_descriptor)
{
    appl_unused(
        p_callback_context);

    appl_print0(
        "resolve callback:\n");

    appl_print0(
        "name=[");

    appl_print(
        p_address_descriptor->p_name_min,
        p_address_descriptor->p_name_max);

    appl_print0(
        "]\n");

    appl_print0(
        "port=[");

    appl_print_lu(
        p_address_descriptor->i_port);

    appl_print0(
        "]\n");
}

//
//
//
enum appl_status
    appl_address_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    // resolve address and create an address object
    // p_options[i_shift + 0] = test-address
    // p_options[i_shift + 1] = host
    // p_options[i_shift + 2] = port

    unsigned char const *
        p_host_min;

    unsigned char const *
        p_host_max;

    e_status =
        appl_options_get(
            p_options,
            i_shift + 1ul,
            &(
                p_host_min),
            &(
                p_host_max));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_address_descriptor
            o_address_descriptor;

        o_address_descriptor.i_flags =
            APPL_ADDRESS_FLAG_NAME
            | APPL_ADDRESS_FLAG_PORT;

        o_address_descriptor.p_name_min =
            p_host_min;

        o_address_descriptor.p_name_max =
            p_host_max;

        o_address_descriptor.i_port =
            1234u;

        e_status =
            appl_address_resolve(
                p_context,
                &(
                    o_address_descriptor),
                &(
                    test_address_resolve_callback),
                0);
    }

    return
        e_status;

} // appl_address_main()

/* end-of-file: appl_address_main.cpp */
