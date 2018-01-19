/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object.h"

//
//
//
enum appl_status
    appl_object::destroy(
        class appl_client * const
            p_client)
{
    static_cast<void>(
        p_client);

    delete
        this;

    return
        appl_status_ok;

} // destroy()

//
//
//
appl_object::appl_object()
{
}

//
//
//
appl_object::~appl_object()
{
}

/* end-of-file: appl_object.cpp */
