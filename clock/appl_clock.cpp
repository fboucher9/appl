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

    e_status =
        appl_raise_not_implemented();

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

    e_status =
        appl_raise_not_implemented();

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
