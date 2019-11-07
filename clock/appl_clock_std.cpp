/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <misc/appl_linux.h>

#include <object/appl_object.h>

#include <clock/appl_clock.h>

#include <clock/appl_clock_std.h>

#include <clock/appl_clock_impl.h>

#include <clock/appl_clock_details.h>

#include <allocator/appl_allocator_handle.h>

#include <misc/appl_unused.h>

#include <misc/appl_convert.h>

#include <coverage/appl_validate.h>

#if defined APPL_HAVE_COVERAGE
#include <coverage/appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

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
        p_context),
    m_offset()
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
enum appl_status
    appl_clock_std::f_init(void)
{
    enum appl_status
        e_status;

    e_status =
        f_calibrate();

    return
        e_status;

} // f_init()

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
    appl_clock_std::f_calibrate(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_clock_impl::s_calibrate(
            1000000ul,
            &(
                m_offset));

    return
        e_status;

} // f_calibrate()

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

    e_status =
        appl_validate(
            i_time_freq
            && r_clock_details);

    if (
        appl_status_ok
        == e_status)
    {
        appl_ull_t const
            i_time_usec =
            ((i_time_count * 1000000ul) / i_time_freq);

        appl_ull_t const
            i_time_now =
                (i_time_usec + m_offset) / 1000000ul;

        struct appl_linux_time_info
            o_local_time_info;

        int
            i_localtime_result;

        i_localtime_result =
#if defined APPL_HAVE_COVERAGE
            appl_coverage_check() ? -1 :
#endif /* #if defined APPL_HAVE_COVERAGE */
            appl_linux_localtime(
                i_time_now,
                &(
                    o_local_time_info));

        if (
            0
            == i_localtime_result)
        {
            r_clock_details->i_fraction =
                0ul;

            r_clock_details->i_year =
                appl_convert::to_unsigned(
                    o_local_time_info.i_year) + 1900ul;

            r_clock_details->i_month =
                appl_convert::to_uchar(
                    appl_convert::to_unsigned(
                        o_local_time_info.i_mon) + 1u);

            r_clock_details->i_day =
                appl_convert::to_uchar(
                    appl_convert::to_unsigned(
                        o_local_time_info.i_mday));

            r_clock_details->i_hour =
                appl_convert::to_uchar(
                    appl_convert::to_unsigned(
                        o_local_time_info.i_hour));

            r_clock_details->i_minute =
                appl_convert::to_uchar(
                    appl_convert::to_unsigned(
                        o_local_time_info.i_min));

            r_clock_details->i_second =
                appl_convert::to_uchar(
                    appl_convert::to_unsigned(
                        o_local_time_info.i_sec));

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_raise_fail();
        }
    }

    return
        e_status;

} // v_convert()

/* end-of-file: appl_clock_std.cpp */
