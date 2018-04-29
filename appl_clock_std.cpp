/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <time.h>

#include <unistd.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_clock.h>

#include <appl_clock_std.h>

//
//
//
enum appl_status
    appl_clock_std::create_instance(
        struct appl_context * const
            p_context,
        class appl_clock * * const
            r_clock)
{
    enum appl_status
        e_status;

    class appl_clock_std *
        p_clock_std;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_clock_std::placement_new),
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
appl_clock_std::appl_clock_std() :
    appl_clock()
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
void
    appl_clock_std::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_clock_std;

} // placement_new()

//
//
//
static
unsigned long int
appl_math_muldiv(
    unsigned long int const
        i_value,
    unsigned long int const
        i_mul,
    unsigned long int const
        i_div)
{
    return
        static_cast<unsigned long int>(
            (
                static_cast<appl_ull_t>(
                    i_value)
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
    unsigned long int * const
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
        unsigned long int
            i_time_count;

        i_time_count =
            (
                appl_math_muldiv(
                    static_cast<unsigned long int>(
                        o_clock_value.tv_sec),
                    i_time_freq,
                    1ul)
                + appl_math_muldiv(
                    static_cast<unsigned long int>(
                        o_clock_value.tv_nsec),
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
    unsigned long int const
        i_time_count)
{
    enum appl_status
        e_status;

    unsigned long int
        i_time_usec;

    if (
        i_time_freq)
    {
        i_time_usec =
            appl_math_muldiv(
                i_time_count,
                1000000ul,
                i_time_freq);

        usleep(
            static_cast<unsigned int>(
                i_time_usec));

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
