/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <clock/appl_clock.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_handle.h>
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
enum appl_status
    appl_clock::v_convert(
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
        i_time_count,
        r_clock_details);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_convert()

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
