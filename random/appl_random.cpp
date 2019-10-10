/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <random/appl_random.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
appl_random::v_pick(
    unsigned long int const
        i_value_max,
    unsigned long int * const
        r_value)
{
    appl_unused(
        i_value_max,
        r_value);

    return
        appl_status_not_implemented;

} // v_pick()

//
//
//
appl_random::appl_random(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_random::~appl_random()
{
}

/* end-of-file: appl_random.cpp */
