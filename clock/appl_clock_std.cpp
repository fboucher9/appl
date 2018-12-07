/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <time.h>

#include <unistd.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <clock/appl_clock.h>

#include <clock/appl_clock_std.h>

#include <appl_convert.h>

#include <appl_allocator_handle.h>

//
//
//
enum appl_status
    appl_clock_std::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_clock * * const
            r_clock)
{
    enum appl_status
        e_status;

    class appl_clock_std *
        p_clock_std;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_clock_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_clock) =
            p_clock_std;
    }

    return
        e_status;

} // create_instance()

//
//
//
enum appl_status
    appl_clock_std::s_destroy(
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
appl_clock_std::appl_clock_std(
    struct appl_context * const
        p_context) :
    appl_clock(
        p_context)
{
}

//
//
//
appl_clock_std::~appl_clock_std()
{
}

//
//
//
appl_size_t
appl_clock_std::v_cleanup(void)
{
    return
        sizeof(class appl_clock_std);

} // v_cleanup()

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
        appl_convert::to_ulong(
            (
                ll_value
                * i_mul)
            / i_div);

} // appl_math_muldiv()

//
//
//
enum appl_status
appl_clock_std::v_read(
    unsigned long int const
        i_time_freq,
    appl_ull_t * const
        p_time_count)
{
    enum appl_status
        e_status;

    int
        i_clock_result;

    struct timespec
        o_clock_value;

    i_clock_result =
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
appl_clock_std::v_delay(
    unsigned long int const
        i_time_freq,
    appl_ull_t const
        i_time_count)
{
    enum appl_status
        e_status;

    if (
        i_time_freq)
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

        usleep(
            ui_time_usec);

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

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_clock_std.cpp */
