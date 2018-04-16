/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_event_mgr.h"

//
//
//
enum appl_status
    appl_event_mgr::v_create(
        struct appl_context * const
            p_context,
        struct appl_event_descriptor const * const
            p_event_descriptor,
        struct appl_event * * const
            r_event)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_context);
    static_cast<void>(
        p_event_descriptor);
    static_cast<void>(
        r_event);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create()

//
//
//
appl_event_mgr::appl_event_mgr() :
    appl_object()
{
}

//
//
//
appl_event_mgr::~appl_event_mgr()
{
}

/* end-of-file: appl_event_mgr.cpp */
