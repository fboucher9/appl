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

struct appl_poll;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_poll_create(
    struct appl_context * const
        p_context,
    struct appl_poll_descriptor const * const
        p_poll_descriptor,
    struct appl_poll * * const
        r_poll);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_poll_handle.h */
