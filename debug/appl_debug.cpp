/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <debug/appl_debug.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
    appl_debug::v_break(void)
{
    return
        appl_status_not_implemented;

} // v_break()

//
//
//
enum appl_status
    appl_debug::v_print(
        unsigned char const * const
            p_msg_min,
        unsigned char const * const
            p_msg_max)
{
    appl_unused(
        p_msg_min,
        p_msg_max);

    return
        appl_status_not_implemented;

} // v_print()

//
//
//
appl_debug::appl_debug(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_debug::~appl_debug()
{
}

#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_debug.cpp */
