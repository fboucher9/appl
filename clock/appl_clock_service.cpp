/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <clock/appl_clock_service.h>

#include <appl_object.h>

#include <clock/appl_clock.h>

#include <context/appl_context.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
appl_clock_service::s_read(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_time_freq,
    appl_ull_t * const
        p_time_count)
{
    enum appl_status
        e_status;

    if (
        p_context
        && i_time_freq
        && p_time_count
#if defined APPL_HAVE_COVERAGE
        && !appl_coverage_check()
#endif /* #if defined APPL_HAVE_COVERAGE */
        )
    {
        class appl_clock *
            p_clock;

        e_status =
            p_context->v_clock(
                &(
                    p_clock));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_clock->v_read(
                    i_time_freq,
                    p_time_count);
        }
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "clock service read invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_invalid_param;
    }

    return
        e_status;

} // s_read()

//
//
//
enum appl_status
appl_clock_service::s_delay(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_time_freq,
    appl_ull_t const
        i_time_count)
{
    enum appl_status
        e_status;

    if (
        p_context
        && i_time_freq
#if defined APPL_HAVE_COVERAGE
        && !appl_coverage_check()
#endif /* #if defined APPL_HAVE_COVERAGE */
        )
    {
        class appl_clock *
            p_clock;

        e_status =
            p_context->v_clock(
                &(
                    p_clock));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_clock->v_delay(
                    i_time_freq,
                    i_time_count);
        }
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "clock service delay invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_invalid_param;
    }

    return
        e_status;

} // s_delay()

/* end-of-file: appl_clock_service.cpp */
