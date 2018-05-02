/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_REFCOUNT_HANDLE_H
#error include appl_refcount_handle.h once
#endif /* #if defined INC_APPL_REFCOUNT_HANDLE_H */

#define INC_APPL_REFCOUNT_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before appl_refcount_handle.h
#endif /* #if ! defined INC_APPL_STATUS_H */

struct appl_refcount;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_refcount_add(
    struct appl_refcount * const
        p_refcount);

struct appl_object *
appl_refcount_parent(
    struct appl_refcount * const
        p_refcount);

struct appl_object const *
appl_refcount_const_parent(
    struct appl_refcount const * const
        p_refcount);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_refcount_handle.h */
