/* See LICENSE for license details */

/*

*/

#include <signal.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_debug.h"

#include "appl_debug_std.h"

//
//
//
enum appl_status
    appl_debug_std::create_instance(
        class appl_context * const
            p_context,
        class appl_debug * * const
            r_debug)
{
    return
        appl_object::create_instance(
            p_context,
            static_cast<unsigned long int>(
                sizeof(
                    class appl_debug_std)),
            &(
                appl_debug_std::placement_new),
            0,
            reinterpret_cast<class appl_object * *>(
                r_debug));

} // create_instance()

//
//
//
appl_debug_std::appl_debug_std() :
    appl_debug()
{
}

//
//
//
appl_debug_std::~appl_debug_std()
{
}

//
//
//
void
    appl_debug_std::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_debug_std;

} // placement_new()

//
//
//
enum appl_status
    appl_debug_std::break_to_debugger(void)
{
    raise(SIGINT);

    return
        appl_status_ok;

} // break_to_debugger()

/* end-of-file: appl_debug_std.cpp */
