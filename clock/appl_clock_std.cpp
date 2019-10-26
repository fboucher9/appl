/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <time.h>

#include <unistd.h>

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <clock/appl_clock.h>

#include <clock/appl_clock_std.h>

#include <clock/appl_clock_impl.h>

#include <clock/appl_clock_details.h>

#include <allocator/appl_allocator_handle.h>

#include <misc/appl_unused.h>

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
enum appl_status
appl_clock_std::v_read(
    unsigned long int const
        i_time_freq,
    appl_ull_t * const
        p_time_count)
{
    enum appl_status
        e_status;

    e_status =
        appl_clock_impl::s_read(
            i_time_freq,
            p_time_count);

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

    e_status =
        appl_clock_impl::s_delay(
            i_time_freq,
            i_time_count);

    return
        e_status;

} // v_delay()

//
//
//
enum appl_status
    appl_clock_std::v_convert(
        unsigned long int const
            i_time_freq,
        appl_ull_t const
            i_time_count,
        struct appl_clock_details * const
            r_clock_details)
{
    enum appl_status
        e_status;

    appl_unused(
        i_time_freq,
        i_time_count);

    r_clock_details->i_fraction =
        0ul;

    r_clock_details->i_year =
        2019ul;

    r_clock_details->i_month =
        1u;

    r_clock_details->i_day =
        1u;

    r_clock_details->i_hour =
        12u;

    r_clock_details->i_minute =
        30u;

    r_clock_details->i_second =
        0u;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_convert()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_clock_std.cpp */
