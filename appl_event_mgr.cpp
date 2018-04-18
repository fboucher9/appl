/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_event_mgr.h"

#include "appl_unused.h"

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

    appl_unused(
        p_context);
    appl_unused(
        p_event_descriptor);
    appl_unused(
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
