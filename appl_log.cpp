/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_log_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_log.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_log::v_print(
        enum appl_log_level const
            e_level,
        unsigned char const * const
            p_message_min,
        unsigned char const * const
            p_message_max)
{
    enum appl_status
        e_status;

    appl_unused(
        e_level,
        p_message_min,
        p_message_max);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_print()

//
//
//
appl_log::appl_log() :
    appl_heap_object()
{
}

//
//
//
appl_log::~appl_log()
{
}

/* end-of-file: appl_log.cpp */
