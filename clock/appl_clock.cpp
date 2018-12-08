/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <clock/appl_clock.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_clock::v_read(
        unsigned long int const
            i_time_freq,
        appl_ull_t * const
            p_time_count)
{
    enum appl_status
        e_status;

    appl_unused(
        i_time_freq,
        p_time_count);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "clock read not implemented\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_read()

//
//
//
enum appl_status
    appl_clock::v_delay(
        unsigned long int const
            i_time_freq,
        appl_ull_t const
            i_time_count)
{
    enum appl_status
        e_status;

    appl_unused(
        i_time_freq,
        i_time_count);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "clock delay not implemented\n");
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_delay()

//
//
//
appl_clock::appl_clock(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_clock::~appl_clock()
{
}

/* end-of-file: appl_clock.cpp */
