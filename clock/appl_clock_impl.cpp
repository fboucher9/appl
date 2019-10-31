/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <clock/appl_clock_impl.h>

#include <misc/appl_unused.h>

#include <misc/appl_convert.h>

#include <clock/appl_clock_std_defs.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

#if defined APPL_HAVE_COVERAGE
#include <coverage/appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

#include <coverage/appl_validate.h>

#include <misc/appl_os.h>

//
//
//
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
        (
            ll_value
            * i_mul)
        / i_div;

} // appl_math_muldiv()

//
//
//
enum appl_clock_epoch
{
    appl_clock_epoch_mono = 1,

    appl_clock_epoch_real = 2

};

static
enum appl_status
read_at_epoch(
    enum appl_clock_epoch const
        e_epoch,
    struct timespec * const
        r_value)
{
    int const
        i_clock_result =
#if defined APPL_HAVE_COVERAGE
        appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
        clock_gettime(
            (
                appl_clock_epoch_real
                == e_epoch)
            ? CLOCK_REALTIME
            : CLOCK_MONOTONIC,
            r_value);

    enum appl_status const
        e_status =
        (
            0 == i_clock_result)
        ? appl_status_ok
        : appl_raise_fail();

    return
        e_status;

}

//
//
//
static
appl_ull_t
    from_timespec_to_count(
        struct timespec const &
            o_clock_value,
        unsigned long int const
            i_time_freq)
{
    appl_ull_t
        i_time_count;

    unsigned long int const
        i_clock_sec =
        appl_convert::to_ulong(
            appl_convert::to_unsigned(
                o_clock_value.tv_sec));

    unsigned long int const
        i_clock_nsec =
        appl_convert::to_ulong(
            appl_convert::to_unsigned(
                o_clock_value.tv_nsec));

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

    return
        i_time_count;

} // from_timespec_to_count()

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
                1000000000ul
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
                1000ul
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

        if (
            appl_os_linux
            == appl_os_get())
        {
            struct timespec
                o_clock_value;

            e_status =
                read_at_epoch(
                    appl_clock_epoch_mono,
                    &(
                        o_clock_value));

            if (
                appl_status_ok
                == e_status)
            {
                appl_ull_t const
                    i_time_count =
                    from_timespec_to_count(
                        o_clock_value,
                        i_time_freq);

                *(
                    p_time_count) =
                    i_time_count;
            }
        }
        else
        {
            appl_unused(
                i_time_freq,
                p_time_count);

            e_status =
                appl_raise_not_implemented();
        }
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
                1000000000ul
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
                1000ul
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

        if (
            appl_os_linux
            == appl_os_get())
        {
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
        }
        else
        {
            appl_unused(
                i_time_freq,
                i_time_count);

            e_status =
                appl_raise_not_implemented();
        }
    }

    return
        e_status;

} // s_delay()

//
//
//
enum appl_status
    appl_clock_impl::s_calibrate(
        unsigned long int const
            i_time_freq,
        appl_ull_t * const
            p_time_count)
{
    enum appl_status
        e_status;

    if (
        appl_os_linux
        == appl_os_get())
    {
        struct timespec
            o_clock_mono_value;

        e_status =
            read_at_epoch(
                appl_clock_epoch_mono,
                &(
                    o_clock_mono_value));

        if (
            appl_status_ok
            == e_status)
        {
            struct timespec
                o_clock_real_value;

            e_status =
                read_at_epoch(
                    appl_clock_epoch_real,
                    &(
                        o_clock_real_value));

            if (
                appl_status_ok
                == e_status)
            {
                appl_ull_t const
                    i_time_mono_count =
                    from_timespec_to_count(
                        o_clock_mono_value,
                        i_time_freq);

                appl_ull_t const
                    i_time_real_count =
                    from_timespec_to_count(
                        o_clock_real_value,
                        i_time_freq);

                *(
                    p_time_count) =
                    i_time_real_count
                    - i_time_mono_count;
            }
        }
    }
    else
    {
        appl_unused(
            i_time_freq,
            p_time_count);

        e_status =
            appl_raise_not_implemented();
    }

    return
        e_status;

} // s_calibrate()

/* end-of-file: appl_clock_impl.cpp */
