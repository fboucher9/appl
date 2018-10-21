/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_refcount.h>

//
//
//
enum appl_status
    appl_refcount::v_add(void)
{
    return
        appl_status_not_implemented;

} // v_add()

//
//
//
appl_refcount::appl_refcount() :
    appl_heap_object()
{
}

//
//
//
appl_refcount::~appl_refcount()
{
}

/* end-of-file: appl_refcount.cpp */
