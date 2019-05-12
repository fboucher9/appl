/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <random/appl_random_main.h>

#include <appl_random_handle.h>

#include <appl_options_handle.h>

#include <appl_test.h>

#include <appl_unused.h>

#include <appl_buf.h>

#include <appl_convert.h>

//
//
//
enum appl_status
    appl_random_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    appl_unused(
        p_context,
        p_options,
        i_shift);

    appl_print0(
        "appl_random_main...\n");

    // [0] test_random
    // [1] type
    // [2] seed

    unsigned char const *
        p_arg_min;

    unsigned char const *
        p_arg_max;

    if (
        appl_status_ok
        == appl_options_get(
            p_options,
            i_shift + 1ul,
            &(
                p_arg_min),
            &(
                p_arg_max)))
    {
        struct appl_random *
            p_random;

        struct appl_random_descriptor
            o_random_descriptor;

        o_random_descriptor.i_seed =
            0u;

        if (
            'p' == *(p_arg_min))
        {
            o_random_descriptor.e_type =
                appl_random_type_pseudo;
        }
        else
        {
            o_random_descriptor.e_type =
                appl_random_type_crypto;
        }

        if (
            appl_status_ok
            == appl_options_get(
                p_options,
                i_shift + 2ul,
                &(
                    p_arg_min),
                &(
                    p_arg_max)))
        {
            signed long int
                i_number;

            appl_buf_scan_number(
                p_arg_min,
                p_arg_max,
                &(
                    i_number),
                0);

            o_random_descriptor.i_seed =
                appl_convert::to_unsigned(
                    i_number);
        }

        e_status =
            appl_random_create(
                p_context,
                &(
                    o_random_descriptor),
                &(
                    p_random));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned long int
                i_value;

            e_status =
                appl_random_pick(
                    p_random,
                    0ul,
                    &(
                        i_value));

            if (
                appl_status_ok
                == e_status)
            {
                appl_print_08lx(
                    i_value);

                appl_print0(
                    "\n");
            }

            appl_random_destroy(
                p_random);
        }
    }

    return
        e_status;

} // appl_random_main()

/* end-of-file: appl_random_main.cpp */
