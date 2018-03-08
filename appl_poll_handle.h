/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POLL_HANDLE_H
#error include appl_poll_handle.h once
#endif /* #if defined INC_APPL_POLL_HANDLE_H */

#define INC_APPL_POLL_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_HANDLE_H
#error include appl_object_handle.h before
#endif /* #if ! defined INC_APPL_OBJECT_HANDLE_H */

struct appl_poll_descriptor;

struct appl_poll_handle;

struct appl_poll_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_poll_handle */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_poll_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_poll_descriptor const * const
        p_poll_descriptor,
    struct appl_poll_handle * * const
        r_poll_handle);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_poll_handle.h */
