/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <clock/appl_clock_handle.h>

#include <clock/appl_clock_service.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

/*

*/
enum appl_status
appl_clock_read(
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
        && p_time_count)
    {
        e_status =
            appl_clock_service::s_read(
                p_context,
                i_time_freq,
                p_time_count);
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "clock read invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* appl_clock_read() */

/*

*/
enum appl_status
appl_clock_delay(
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
        && i_time_freq)
    {
        e_status =
            appl_clock_service::s_delay(
                p_context,
                i_time_freq,
                i_time_count);
    }
    else
    {
#if defined APPL_DEBUG
        appl_debug_impl::s_print0(
            "clock delay invalid param\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* appl_clock_delay() */

/* end-of-file: appl_clock_handle.cpp */
