/* See LICENSE for license details */

/* Reverse include guard */
enum guard_appl_refcount_handle_h
{
    inc_appl_refcount_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_refcount;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

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

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_refcount_handle.h */
