/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <clock/appl_clock_main.h>

#include <appl_options_handle.h>

#include <appl_types.h>

#include <appl_clock_handle.h>

#include <appl_convert.h>

#include <appl_unused.h>

#include <appl_buf.h>

#include <appl_test.h>

//
//
//
enum appl_status
    appl_clock_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    unsigned long int
        i_time_freq;

    appl_ull_t
        i_time_prev;

    bool
        b_time_prev;

    /* test_clock f[freq] r d[count] */
    /* read commands from cmdline or from files */

    i_time_freq =
        1000000ul;

    i_time_prev =
        0ul;

    b_time_prev =
        false;

    bool
        b_more_options;

    b_more_options =
        true;

    unsigned long int
        i_options_index;

    i_options_index =
        i_shift + 1ul;

    while (
        b_more_options)
    {
        unsigned char const *
            p_option_min;

        unsigned char const *
            p_option_max;

        if (
            appl_status_ok
            == appl_options_get(
                p_options,
                i_options_index,
                &(
                    p_option_min),
                &(
                    p_option_max)))
        {
            if (
                p_option_max != p_option_min)
            {
                if ('f' == *p_option_min)
                {
                    signed long int
                        i_decimal_value;

                    i_decimal_value =
                        0;

                    appl_buf_scan_number(
                        p_option_min + 1u,
                        p_option_max,
                        &(
                            i_decimal_value),
                        appl_buf_scan_flag_unsigned);

                    if (
                        i_decimal_value)
                    {
                        i_time_freq =
                            appl_convert::to_unsigned(
                                i_decimal_value);
                    }
                }
                else if ('r' == *p_option_min)
                {
                    appl_ull_t
                        i_time_count;

                    if (
                        appl_status_ok
                        == appl_clock_read(
                            p_context,
                            i_time_freq,
                            &(
                                i_time_count)))
                    {
                        appl_print_08lx(
                            appl_convert::to_ulong(
                                i_time_count >> 32u));

                        appl_print_08lx(
                            appl_convert::to_ulong(
                                i_time_count >> 0u));

                        if (
                            b_time_prev)
                        {
                            appl_print0(" ");
                            appl_print_number(
                                appl_convert::to_long(
                                    i_time_count - i_time_prev),
                                appl_buf_print_flag_plus,
                                0u);
                        }

                        appl_print0("\n");

                        i_time_prev =
                            i_time_count;

                        b_time_prev =
                            true;
                    }
                    else
                    {
                    }
                }
                else if ('d' == *p_option_min)
                {
                    signed long int
                        i_decimal_value;

                    i_decimal_value =
                        0;

                    appl_buf_scan_number(
                        p_option_min + 1u,
                        p_option_max,
                        &(
                            i_decimal_value),
                        appl_buf_scan_flag_unsigned);

                    if (
                        i_decimal_value)
                    {
                        appl_ull_t
                            i_time_count;

                        i_time_count =
                            appl_convert::to_unsigned(
                                i_decimal_value);

                        appl_clock_delay(
                            p_context,
                            i_time_freq,
                            i_time_count);
                    }
                }
                else
                {
                }
            }

            i_options_index ++;
        }
        else
        {
            b_more_options =
                false;
        }
    }


    e_status =
        appl_status_ok;

    return
        e_status;

} // appl_clock_main()

/* end-of-file: appl_clock_main.cpp */
