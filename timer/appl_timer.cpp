/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <timer/appl_timer.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_timer::v_schedule(
        struct appl_timer_descriptor const * const
            p_timer_descriptor)
{
    appl_unused(
        p_timer_descriptor);

    return
        appl_status_not_implemented;

} // v_schedule()

//
//
//
appl_timer::appl_timer(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_timer::~appl_timer()
{
}

/* end-of-file: appl_timer.cpp */
