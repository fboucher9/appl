/* See LICENSE for license details */

/*

Module: appl_refcount.h

Description:

    Public C-style interface for ref counted objects.  All objects that
    have a reference counter may export this interface.

*/

/* Reverse include guard */
enum guard_appl_refcount_handle_h
{
    inc_appl_refcount_handle_h =
        /* Header file dependency */
        inc_appl_status_h
};

struct appl_refcount;

#include <misc/appl_extern_c_begin.h>

/* increment reference counter */
enum appl_status
appl_refcount_add(
    struct appl_refcount * const
        p_refcount);

/* get pointer to parent object */
struct appl_object *
appl_refcount_parent(
    struct appl_refcount * const
        p_refcount);

/* get pointer to parent object */
struct appl_object const *
appl_refcount_const_parent(
    struct appl_refcount const * const
        p_refcount);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_refcount_handle.h */
