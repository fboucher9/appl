/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_MUTEX_HANDLE_H)
#error include appl_mutex_handle.h once
#endif /* #if defined(INC_APPL_MUTEX_HANDLE_H) */

#define INC_APPL_MUTEX_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_HANDLE_H
#error include appl_object_handle.h before
#endif /* #if ! defined INC_APPL_OBJECT_HANDLE_H */

/* mutex */
struct appl_mutex_handle;

struct appl_mutex_descriptor
{
    void *
        p_dummy;

}; /* struct appl_mutex_descriptor */

struct appl_mutex_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_mutex_handle */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_mutex_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex_handle * * const
        r_mutex_handle);

enum appl_status
appl_mutex_lock(
    struct appl_mutex_handle * const
        p_mutex_handle);

enum appl_status
appl_mutex_unlock(
    struct appl_mutex_handle * const
        p_mutex_handle);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_mutex_handle.h */
