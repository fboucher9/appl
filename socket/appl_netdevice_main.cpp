/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <socket/appl_netdevice_main.h>

#include <appl_netdevice_handle.h>

#include <appl_options_handle.h>

#include <appl_address_family.h>

#include <appl_buf.h>

#include <appl_convert.h>

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

    if (
        APPL_NETDEVICE_FLAGS_FAMILY
        & p_netdevice_descriptor->i_flags)
    {
        if (
            appl_address_family_inet
            == p_netdevice_descriptor->e_family)
        {
            appl_print0(" -4");
        }
        else if (
            appl_address_family_inet6
            == p_netdevice_descriptor->e_family)
        {
            appl_print0(" -6");
        }
        else
        {
            appl_print0(
                " -f ");
            appl_print_ld(
                p_netdevice_descriptor->e_family);
        }
    }

    if (
        APPL_NETDEVICE_FLAGS_TYPE
        & p_netdevice_descriptor->i_flags)
    {
        if (
            appl_netdevice_type_normal
            == p_netdevice_descriptor->e_type)
        {
            appl_print0(
                " -e");
        }
        else if (
            appl_netdevice_type_loopback
            == p_netdevice_descriptor->e_type)
        {
            appl_print0(
                " -l");
        }
        else
        {
            appl_print0(
                " -t ");
            appl_print_ld(
                p_netdevice_descriptor->e_type);
        }
    }

    if (
        APPL_NETDEVICE_FLAGS_INDEX
        & p_netdevice_descriptor->i_flags)
    {
        appl_print0(
            " -i ");
        appl_print_lu(
            p_netdevice_descriptor->i_index);
    }

    if (
        APPL_NETDEVICE_FLAGS_NAME
        & p_netdevice_descriptor->i_flags)
    {
        appl_print0(
            " -n ");
        appl_print(
            p_netdevice_descriptor->p_name_min,
            p_netdevice_descriptor->p_name_max);
    }

    if (
        APPL_NETDEVICE_FLAGS_ADDRESS
        & p_netdevice_descriptor->i_flags)
    {
        appl_print0(
            " -a ");
        appl_print(
            p_netdevice_descriptor->p_address_min,
            p_netdevice_descriptor->p_address_max);
    }

    appl_print0("\n");

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

    unsigned long int
        i_options_iterator;

    i_options_iterator =
        i_shift + 1ul;

    bool
        b_more_options;

    b_more_options =
        true;

    while (
        b_more_options)
    {
        unsigned char const *
            p_arg_min;

        unsigned char const *
            p_arg_max;

        if (
            appl_status_ok
            == appl_options_get(
                p_options,
                i_options_iterator,
                &(
                    p_arg_min),
                &(
                    p_arg_max)))
        {
            i_options_iterator ++;

            static unsigned char const s_ref_name[] =
            {
                '-',
                'n'
            };

            static unsigned char const s_ref_addr[] =
            {
                '-',
                'a'
            };

            static unsigned char const s_ref_type[] =
            {
                '-',
                't'
            };

            static unsigned char const s_ref_type_normal[] =
            {
                '-',
                'e'
            };

            static unsigned char const s_ref_type_loopback[] =
            {
                '-',
                'l'
            };

            static unsigned char const s_ref_family[] =
            {
                '-',
                'f'
            };

            static unsigned char const s_ref_family_inet[] =
            {
                '-',
                '4'
            };

            static unsigned char const s_ref_family_inet6[] =
            {
                '-',
                '6'
            };

            static unsigned char const s_ref_index[] =
            {
                '-',
                'i'
            };

            if (
                0
                == appl_buf_compare(
                    p_arg_min,
                    p_arg_max,
                    s_ref_name,
                    s_ref_name + sizeof(s_ref_name)))
            {
                unsigned char const *
                    p_value_min;

                unsigned char const *
                    p_value_max;

                if (
                    appl_status_ok
                    == appl_options_get(
                        p_options,
                        i_options_iterator,
                        &(
                            p_value_min),
                        &(
                            p_value_max)))
                {
                    i_options_iterator ++;

                    o_netdevice_filter.p_name_min =
                        p_value_min;

                    o_netdevice_filter.p_name_max =
                        p_value_max;

                    o_netdevice_filter.i_flags |=
                        APPL_NETDEVICE_FLAGS_NAME;
                }
                else
                {
                    b_more_options =
                        false;
                }
            }
            else if (
                0
                == appl_buf_compare(
                    p_arg_min,
                    p_arg_max,
                    s_ref_addr,
                    s_ref_addr + sizeof(s_ref_addr)))
            {
                unsigned char const *
                    p_value_min;

                unsigned char const *
                    p_value_max;

                if (
                    appl_status_ok
                    == appl_options_get(
                        p_options,
                        i_options_iterator,
                        &(
                            p_value_min),
                        &(
                            p_value_max)))
                {
                    i_options_iterator ++;

                    o_netdevice_filter.i_flags |=
                        APPL_NETDEVICE_FLAGS_ADDRESS;

                    o_netdevice_filter.p_address_min =
                        p_value_min;

                    o_netdevice_filter.p_address_max =
                        p_value_max;
                }
                else
                {
                    b_more_options =
                        false;
                }
            }
            else if (
                0
                == appl_buf_compare(
                    p_arg_min,
                    p_arg_max,
                    s_ref_type_normal,
                    s_ref_type_normal + sizeof(s_ref_type_normal)))
            {
                o_netdevice_filter.i_flags |=
                    APPL_NETDEVICE_FLAGS_TYPE;

                o_netdevice_filter.e_type =
                    appl_netdevice_type_normal;
            }
            else if (
                0
                == appl_buf_compare(
                    p_arg_min,
                    p_arg_max,
                    s_ref_type_loopback,
                    s_ref_type_loopback + sizeof(s_ref_type_loopback)))
            {
                o_netdevice_filter.i_flags |=
                    APPL_NETDEVICE_FLAGS_TYPE;

                o_netdevice_filter.e_type =
                    appl_netdevice_type_loopback;
            }
            else if (
                0
                == appl_buf_compare(
                    p_arg_min,
                    p_arg_max,
                    s_ref_family_inet,
                    s_ref_family_inet + sizeof(s_ref_family_inet)))
            {
                o_netdevice_filter.i_flags |=
                    APPL_NETDEVICE_FLAGS_FAMILY;

                o_netdevice_filter.e_family =
                    appl_address_family_inet;
            }
            else if (
                0
                == appl_buf_compare(
                    p_arg_min,
                    p_arg_max,
                    s_ref_family_inet6,
                    s_ref_family_inet6 + sizeof(s_ref_family_inet6)))
            {
                o_netdevice_filter.i_flags |=
                    APPL_NETDEVICE_FLAGS_FAMILY;

                o_netdevice_filter.e_family =
                    appl_address_family_inet6;
            }
            else if (
                0
                == appl_buf_compare(
                    p_arg_min,
                    p_arg_max,
                    s_ref_type,
                    s_ref_type + sizeof(s_ref_type)))
            {
                unsigned char const *
                    p_value_min;

                unsigned char const *
                    p_value_max;

                if (
                    appl_status_ok
                    == appl_options_get(
                        p_options,
                        i_options_iterator,
                        &(
                            p_value_min),
                        &(
                            p_value_max)))
                {
                    i_options_iterator ++;

                    o_netdevice_filter.i_flags |=
                        APPL_NETDEVICE_FLAGS_TYPE;

                    signed long int
                        i_number;

                    appl_buf_scan_number(
                        p_value_min,
                        p_value_max,
                        &(
                            i_number),
                        0);

                    o_netdevice_filter.e_type =
                        appl_convert::to_int(
                            i_number);
                }
                else
                {
                    b_more_options =
                        false;
                }
            }
            else if (
                0
                == appl_buf_compare(
                    p_arg_min,
                    p_arg_max,
                    s_ref_family,
                    s_ref_family + sizeof(s_ref_family)))
            {
                unsigned char const *
                    p_value_min;

                unsigned char const *
                    p_value_max;

                if (
                    appl_status_ok
                    == appl_options_get(
                        p_options,
                        i_options_iterator,
                        &(
                            p_value_min),
                        &(
                            p_value_max)))
                {
                    i_options_iterator ++;

                    o_netdevice_filter.i_flags |=
                        APPL_NETDEVICE_FLAGS_FAMILY;

                    signed long int
                        i_number;

                    appl_buf_scan_number(
                        p_value_min,
                        p_value_max,
                        &(
                            i_number),
                        0);

                    o_netdevice_filter.e_family =
                        appl_convert::to_int(
                            i_number);
                }
                else
                {
                    b_more_options =
                        false;
                }
            }
            else if (
                0
                == appl_buf_compare(
                    p_arg_min,
                    p_arg_max,
                    s_ref_index,
                    s_ref_index + sizeof(s_ref_index)))
            {
                unsigned char const *
                    p_value_min;

                unsigned char const *
                    p_value_max;

                if (
                    appl_status_ok
                    == appl_options_get(
                        p_options,
                        i_options_iterator,
                        &(
                            p_value_min),
                        &(
                            p_value_max)))
                {
                    i_options_iterator ++;

                    o_netdevice_filter.i_flags |=
                        APPL_NETDEVICE_FLAGS_INDEX;

                    signed long int
                        i_number;

                    appl_buf_scan_number(
                        p_value_min,
                        p_value_max,
                        &(
                            i_number),
                        0);

                    o_netdevice_filter.i_index =
                        appl_convert::to_int(
                            i_number);
                }
                else
                {
                    b_more_options =
                        false;
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
            b_more_options =
                false;
        }
    }

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
