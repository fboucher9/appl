/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_clock.h"

//
//
//
enum appl_status
    appl_clock::v_read(
        unsigned long int const
            i_time_freq,
        unsigned long int * const
            p_time_count)
{
    enum appl_status
        e_status;

    static_cast<void>(
        i_time_freq);
    static_cast<void>(
        p_time_count);

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
        unsigned long int const
            i_time_count)
{
    enum appl_status
        e_status;

    static_cast<void>(
        i_time_freq);
    static_cast<void>(
        i_time_count);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_delay()

//
//
//
appl_clock::appl_clock() : appl_object()
{
}

//
//
//
appl_clock::~appl_clock()
{
}

/* end-of-file: appl_clock.cpp */
