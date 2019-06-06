/* See LICENSE for license details */

#include <appl_status.h>

#include <appl_refcount_handle.h>

#include <appl_refcount_service.h>

//
//
//
struct appl_object *
appl_refcount_parent(
    struct appl_refcount * const
        p_refcount)
{
    return
        appl_refcount_service::s_parent(
            p_refcount);

} /* appl_refcount_parent() */

//
//
//
struct appl_object const *
appl_refcount_const_parent(
    struct appl_refcount const * const
        p_refcount)
{
    return
        appl_refcount_service::s_const_parent(
            p_refcount);

} /* appl_refcount_const_parent() */

//
//
//
enum appl_status
appl_refcount_acquire(
    struct appl_refcount * const
        p_refcount)
{
    return
        appl_refcount_service::s_acquire(
            p_refcount);

} /* appl_refcount_acquire() */

//
//
//
enum appl_status
appl_refcount_release(
    struct appl_refcount * const
        p_refcount)
{
    return
        appl_refcount_service::s_release(
            p_refcount);

} /* appl_refcount_release() */

/* end-of-file: appl_refcount_handle.cpp */
