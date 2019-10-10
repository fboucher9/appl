/* See LICENSE for license details */

/* Reverse include guard */
enum guard_appl_refcount_handle_h
{
    inc_appl_refcount_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

#include <misc/appl_extern_c_begin.h>

struct appl_object *
appl_refcount_parent(
    struct appl_refcount * const
        p_refcount);

struct appl_object const *
appl_refcount_const_parent(
    struct appl_refcount const * const
        p_refcount);

enum appl_status
appl_refcount_acquire(
    struct appl_refcount * const
        p_refcount);

enum appl_status
appl_refcount_release(
    struct appl_refcount * const
        p_refcount);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_refcount_handle.h */
