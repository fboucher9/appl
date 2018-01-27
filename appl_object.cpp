/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object.h"

//
//
//
enum appl_status
    appl_object::destroy(void)
{
    delete
        this;

    return
        appl_status_ok;

} // destroy()

//
//
//
appl_object::appl_object() :
    m_client()
{
}

//
//
//
appl_object::~appl_object()
{
}

/* end-of-file: appl_object.cpp */
