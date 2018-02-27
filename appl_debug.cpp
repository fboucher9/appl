/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_debug.h"

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
        struct appl_buf const * const
            p_buf)
{
    static_cast<void>(
        p_buf);

    return
        appl_status_not_implemented;

} // v_print()

//
//
//
appl_debug::appl_debug() :
    appl_object()
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
