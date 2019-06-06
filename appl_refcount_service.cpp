/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_refcount_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_refcount.h>

//
//
//
struct appl_object *
appl_refcount_service::s_parent(
    struct appl_refcount * const
        p_refcount)
{
    return
        p_refcount;

} // s_parent()

//
//
//
struct appl_object const *
appl_refcount_service::s_const_parent(
    struct appl_refcount const * const
        p_refcount)
{
    return
        p_refcount;

} // s_const_parent()

//
//
//
enum appl_status
appl_refcount_service::s_acquire(
    struct appl_refcount * const
        p_refcount)
{
    return
        p_refcount->v_acquire();

} // s_acquire()

//
//
//
enum appl_status
appl_refcount_service::s_release(
    struct appl_refcount * const
        p_refcount)
{
    return
        p_refcount->v_release();

} // s_release()

/* end-of-file: appl_refcount_service.cpp */
