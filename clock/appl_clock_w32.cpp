/* See LICENSE for license details */

/*

*/

#include <misc/appl_unused.h>

#include <appl_types.h>

#include <appl_status.h>

#include <appl_predefines.h>

#include <object/appl_object.h>

#include <clock/appl_clock.h>

#include <clock/appl_clock_w32.h>

#include <misc/appl_convert.h>

#include <allocator/appl_allocator_handle.h>

#include <misc/appl_windows.h>

//
//
//
enum appl_status
    appl_clock_w32::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_clock * * const
            r_clock)
{
    enum appl_status
        e_status;

    class appl_clock_w32 *
        p_clock_w32;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_clock_w32));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_clock) =
            p_clock_w32;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_clock_w32::s_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_clock * const
            p_clock)
{
    return
        appl_delete(
            p_allocator,
            p_clock);

} // s_destroy()

//
//
//
appl_clock_w32::appl_clock_w32(
    struct appl_context * const
        p_context) :
    appl_clock(
        p_context)
{
}

//
//
//
appl_clock_w32::~appl_clock_w32()
{
}

//
//
//
enum appl_status
    appl_clock_w32::f_init(void)
{
    enum appl_status
        e_status;

    if (
        appl_windows_time_begin_period(
            1u))
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_clock_w32::v_cleanup(void)
{
    if (
        appl_windows_time_end_period(
            1u))
    {
    }
    else
    {
    }

    return
        sizeof(class appl_clock_w32);

} // v_cleanup()

//
//
//
static
unsigned long int
appl_math_muldiv(
    appl_ull_t const
        i_value,
    unsigned long int const
        i_mul,
    unsigned long int const
        i_div)
{
    return
        appl_convert::to_ulong(
            (
                i_value
                * i_mul)
            / i_div);

} // appl_math_muldiv()

//
//
//
enum appl_status
appl_clock_w32::v_read(
    unsigned long int const
        i_time_freq,
    appl_ull_t * const
        p_time_count)
{
    enum appl_status
        e_status;

    appl_ull_t
        i_freq;

    if (
        appl_windows_query_performance_frequency(
            &(
                i_freq)))
    {
        appl_ull_t
            i_counter;

        if (
            appl_windows_query_performance_counter(
                &(
                    i_counter)))
        {
            unsigned long int
                i_time_count;

            appl_ull_t
                ll_time_count;

            ll_time_count =
                ((i_counter * i_time_freq) / i_freq);

            i_time_count =
                appl_convert::to_ulong(
                    ll_time_count);

            *(
                p_time_count) =
                i_time_count;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_read()

//
//
//
enum appl_status
appl_clock_w32::v_delay(
    unsigned long int const
        i_time_freq,
    appl_ull_t const
        i_time_count)
{
    enum appl_status
        e_status;

    unsigned long int
        i_time_msec;

    if (
        i_time_freq)
    {
        i_time_msec =
            appl_math_muldiv(
                i_time_count,
                1000ul,
                i_time_freq);

        appl_windows_sleep_ex(
            appl_convert::to_uint(
                i_time_msec),
            1);

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_delay()

/* end-of-file: appl_clock_w32.cpp */
