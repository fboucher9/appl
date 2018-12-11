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

#include <clock/appl_clock_impl.h>

#include <appl_allocator_handle.h>

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
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
#if defined APPL_HAVE_COVERAGE
    if (appl_coverage_check())
    {
        appl_clock::v_cleanup();
    }
#endif /* #if defined APPL_HAVE_COVERAGE */

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

#if defined APPL_HAVE_COVERAGE
    if (appl_coverage_check())
    {
        appl_clock::v_read(
            i_time_freq,
            p_time_count);
    }
#endif /* #if defined APPL_HAVE_COVERAGE */

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

#if defined APPL_HAVE_COVERAGE
    if (appl_coverage_check())
    {
        appl_clock::v_delay(
            i_time_freq,
            i_time_count);
    }
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_clock_impl::s_delay(
            i_time_freq,
            i_time_count);

    return
        e_status;

} // v_delay()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_clock_std.cpp */
