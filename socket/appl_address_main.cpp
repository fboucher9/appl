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

#include <appl_buf.h>

#include <appl_address_family.h>

#include <appl_convert.h>

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

    if (
        p_address_descriptor->i_flags
        & APPL_ADDRESS_FLAG_NAME)
    {
        appl_print0(
            "name=[");

        appl_print(
            p_address_descriptor->p_name_min,
            p_address_descriptor->p_name_max);

        appl_print0(
            "]\n");
    }

    if (
        p_address_descriptor->i_flags
        & APPL_ADDRESS_FLAG_PORT)
    {
        appl_print0(
            "port=[");

        appl_print_lu(
            p_address_descriptor->i_port);

        appl_print0(
            "]\n");
    }

    if (
        p_address_descriptor->i_flags
        & APPL_ADDRESS_FLAG_FAMILY)
    {
        appl_print0(
            "family=[");

        appl_print_ld(
            p_address_descriptor->e_family);

        appl_print0(
            "]\n");
    }

    if (
        p_address_descriptor->i_flags
        & APPL_ADDRESS_FLAG_INDEX)
    {
        appl_print0(
            "index=[");

        appl_print_lu(
            p_address_descriptor->i_index);

        appl_print0(
            "]\n");
    }
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

    struct appl_address_descriptor
        o_address_descriptor;

    // resolve address and create an address object
    // p_options[i_shift + 0] = test-address
    // p_options[i_shift + 1] = host
    // p_options[i_shift + 2] = port

    o_address_descriptor.i_flags =
        0u;

    {
        unsigned long int
            i_iterator;

        i_iterator =
            i_shift + 1ul;

        unsigned char const *
            p_option_min;

        unsigned char const *
            p_option_max;

        bool
            b_more_options;

        b_more_options =
            true;

        while (
            b_more_options)
        {
            if (
                appl_status_ok
                == appl_options_get(
                    p_options,
                    i_iterator,
                    &(
                        p_option_min),
                    &(
                        p_option_max)))
            {
                i_iterator ++;

                static unsigned char const s_ref_inet[] =
                {
                    '-',
                    '4'
                };

                static unsigned char const s_ref_inet6[] =
                {
                    '-',
                    '6'
                };

                static unsigned char const s_ref_port[] =
                {
                    '-',
                    'p'
                };

                if (
                    0
                    == appl_buf_compare(
                        p_option_min,
                        p_option_max,
                        s_ref_inet,
                        s_ref_inet + sizeof(s_ref_inet)))
                {
                    o_address_descriptor.i_flags |=
                        APPL_ADDRESS_FLAG_FAMILY;

                    o_address_descriptor.e_family =
                        appl_address_family_inet;
                }
                else if (
                    0
                    == appl_buf_compare(
                        p_option_min,
                        p_option_max,
                        s_ref_inet6,
                        s_ref_inet6 + sizeof(s_ref_inet6)))
                {
                    o_address_descriptor.i_flags |=
                        APPL_ADDRESS_FLAG_FAMILY;

                    o_address_descriptor.e_family =
                        appl_address_family_inet6;
                }
                else if (
                    0
                    == appl_buf_compare(
                        p_option_min,
                        p_option_max,
                        s_ref_port,
                        s_ref_port + sizeof(s_ref_port)))
                {
                    if (
                        appl_status_ok
                        == appl_options_get(
                            p_options,
                            i_iterator,
                            &(
                                p_option_min),
                            &(
                                p_option_max)))
                    {
                        i_iterator ++;

                        signed long int
                            i_value;

                        i_value =
                            0l;

                        appl_buf_scan_number(
                            p_option_min,
                            p_option_max,
                            &(
                                i_value),
                            0);

                        if (
                            i_value)
                        {
                            o_address_descriptor.i_flags |=
                                APPL_ADDRESS_FLAG_PORT;

                            o_address_descriptor.i_port =
                                appl_convert::to_ushort(
                                    appl_convert::to_unsigned(
                                        i_value));
                        }
                    }
                    else
                    {
                        b_more_options =
                            false;
                    }
                }
                else
                {
                    o_address_descriptor.i_flags |=
                        APPL_ADDRESS_FLAG_NAME;

                    o_address_descriptor.p_name_min =
                        p_option_min;

                    o_address_descriptor.p_name_max =
                        p_option_max;
                }
            }
            else
            {
                b_more_options =
                    false;
            }
        }
    }

    e_status =
        appl_address_resolve(
            p_context,
            &(
                o_address_descriptor),
            &(
                test_address_resolve_callback),
            0);

    return
        e_status;

} // appl_address_main()

/* end-of-file: appl_address_main.cpp */
