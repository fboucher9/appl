/* See LICENSE for license details */

/*

*/

#include <time.h>

#include <unistd.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_clock.h"

#include "appl_clock_std.h"

//
//
//
enum appl_status
    appl_clock_std::create_instance(
        class appl_context * const
            p_context,
        class appl_clock * * const
            r_clock)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_context);
    static_cast<void>(
        r_clock);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // create_instance()

//
//
//
appl_clock_std::appl_clock_std() :
    appl_clock()
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
void
    appl_clock_std::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_clock_std;

} // placement_new()

//
//
//
enum appl_status
appl_clock_std::v_read(
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
appl_clock_std::v_delay(
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

/* end-of-file: appl_clock_std.cpp */
