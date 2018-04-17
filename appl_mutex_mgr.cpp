/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_mutex_mgr.h"

//
//
//
enum appl_status
    appl_mutex_mgr::v_create(
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex * * const
            r_mutex)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_mutex_descriptor);
    static_cast<void>(
        r_mutex);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create()

//
//
//
appl_mutex_mgr::appl_mutex_mgr() :
    appl_object()
{
}

//
//
//
appl_mutex_mgr::~appl_mutex_mgr()
{
}

/* end-of-file: appl_mutex_mgr.cpp */
