/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_refcount_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_refcount.h>

/*

*/
enum appl_status
appl_refcount_add(
    struct appl_refcount * const
        p_refcount)
{
    return
        p_refcount->v_add();

} /* add() */

/*

*/
struct appl_object *
appl_refcount_parent(
    struct appl_refcount * const
        p_refcount)
{
    return
        p_refcount;

} /* parent() */

/*

*/
struct appl_object const *
appl_refcount_const_parent(
    struct appl_refcount const * const
        p_refcount)
{
    return
        p_refcount;

} /* const_parent() */

/* end-of-file: appl_refcount_handle.cpp */
