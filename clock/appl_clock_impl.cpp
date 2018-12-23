/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <clock/appl_clock_impl.h>

#include <appl_unused.h>

#include <appl_convert.h>

#if defined APPL_OS_LINUX

#include <time.h>

#include <unistd.h>

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

#include <appl_validate.h>

//
//
//
#if defined APPL_OS_LINUX
static
appl_ull_t
appl_math_muldiv(
    appl_ull_t const
        i_value,
    unsigned long int const
        i_mul,
    unsigned long int const
        i_div)
{
    appl_ull_t const
        ll_value =
        i_value;

    return
        appl_convert::to_ulong(
            (
                ll_value
                * i_mul)
            / i_div);

} // appl_math_muldiv()
#endif /* #if defined APPL_OS_LINUX */

//
//
//
enum appl_status
    appl_clock_impl::s_read(
        unsigned long int const
            i_time_freq,
        appl_ull_t * const
            p_time_count)
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != i_time_freq)
            && (0 != p_time_count));

    if (
        appl_status_ok
        == e_status)
    {
#if defined APPL_HAVE_COVERAGE
        {
            bool
                b_coverage;

            if (
                1000ul
                <= i_time_freq)
            {
                b_coverage =
                    true;
            }
            else if (
                1000000ul
                <= i_time_freq)
            {
                b_coverage =
                    true;
            }
            else if (
                1000000000ul
                <= i_time_freq)
            {
                b_coverage =
                    true;
            }
            else
            {
                b_coverage =
                    true;
            }

            appl_unused(
                b_coverage);
        }
#endif /* #if defined APPL_HAVE_COVERAGE */

#if defined APPL_OS_LINUX

        int
            i_clock_result;

        struct timespec
            o_clock_value;

        i_clock_result =
#if defined APPL_HAVE_COVERAGE
            appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
            clock_gettime(
                CLOCK_MONOTONIC,
                &(
                    o_clock_value));

        if (
            0 == i_clock_result)
        {
            appl_ull_t
                i_time_count;

            unsigned long int const
                i_clock_sec =
                appl_convert::to_unsigned(
                    o_clock_value.tv_sec);

            unsigned long int const
                i_clock_nsec =
                appl_convert::to_unsigned(
                    o_clock_value.tv_nsec);

            i_time_count =
                (
                    appl_math_muldiv(
                        i_clock_sec,
                        i_time_freq,
                        1ul)
                    + appl_math_muldiv(
                        i_clock_nsec,
                        i_time_freq,
                        1000000000ul));

            *(
                p_time_count) =
                i_time_count;

            e_status =
                appl_status_ok;
        }
        else
        {
#if defined APPL_DEBUG
            appl_debug_impl::s_print0(
                "clock_gettime error\n");
#endif /* #if defined APPL_DEBUG */

            e_status =
                appl_status_fail;
        }

#else /* #if defined APPL_OS_Xx */

        appl_unused(
            i_time_freq,
            p_time_count);

        e_status =
            appl_raise_not_implemented();

#endif /* #if defined APPL_OS_Xx */
    }

    return
        e_status;

} // s_read()

//
//
//
enum appl_status
    appl_clock_impl::s_delay(
        unsigned long int const
            i_time_freq,
        appl_ull_t const
            i_time_count)
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != i_time_freq));

    if (
        appl_status_ok
        == e_status)
    {
#if defined APPL_HAVE_COVERAGE
        {
            bool
                b_coverage;

            if (
                1000ul
                <= i_time_freq)
            {
                b_coverage =
                    true;
            }
            else if (
                1000000ul
                <= i_time_freq)
            {
                b_coverage =
                    true;
            }
            else if (
                1000000000ul
                <= i_time_freq)
            {
                b_coverage =
                    true;
            }
            else
            {
                b_coverage =
                    true;
            }

            appl_unused(
                b_coverage);
        }
#endif /* #if defined APPL_HAVE_COVERAGE */

#if defined APPL_OS_LINUX

        appl_ull_t const
            ul_time_usec =
            appl_math_muldiv(
                i_time_count,
                1000000ul,
                i_time_freq);

        unsigned int const
            ui_time_usec =
            appl_convert::to_uint(
                ul_time_usec);

        int const
            i_usleep_result =
#if defined APPL_HAVE_COVERAGE
            appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
            usleep(
                ui_time_usec);

        if (
            0
            == i_usleep_result)
        {
            e_status =
                appl_status_ok;
        }
        else
        {
#if defined APPL_DEBUG
            appl_debug_impl::s_print0(
                "usleep error\n");
#endif /* #if defined APPL_DEBUG */

            e_status =
                appl_status_fail;
        }

#else /* #if defined APPL_OS_Xx */

        appl_unused(
            i_time_freq,
            i_time_count);

        e_status =
            appl_raise_not_implemented();

#endif /* #if defined APPL_OS_Xx */
    }

    return
        e_status;

} // s_delay()

/* end-of-file: appl_clock_impl.cpp */
