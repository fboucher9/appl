/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <clock/appl_clock_service.h>

#include <object/appl_object.h>

#include <clock/appl_clock.h>

#include <context/appl_context.h>

#include <coverage/appl_validate.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

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

    e_status =
        appl_validate(
            (0 != p_context)
            && (0 != i_time_freq)
            && (0 != p_time_count));

    if (
        appl_status_ok
        == e_status)
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

    e_status =
        appl_validate(
            (0 != p_context)
            && (0 != i_time_freq));

    if (
        appl_status_ok
        == e_status)
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

    return
        e_status;

} // s_delay()

//
//
//
enum appl_status
appl_clock_service::s_convert(
    struct appl_context const * const
        p_context,
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
            (0 != p_context)
            && (0 != i_time_freq));

    if (
        appl_status_ok
        == e_status)
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
                p_clock->v_convert(
                    i_time_freq,
                    i_time_count,
                    r_clock_details);
        }
    }

    return
        e_status;

} // s_convert()

/* end-of-file: appl_clock_service.cpp */
