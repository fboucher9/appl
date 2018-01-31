/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_THREAD_HANDLE_H)
#error include appl_thread_handle.h once
#endif /* #if defined(INC_APPL_THREAD_HANDLE_H) */

#define INC_APPL_THREAD_HANDLE_H

struct appl_thread_handle;

struct appl_thread_descriptor;

struct appl_context_handle;

struct appl_thread_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_thread_handle */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_thread_create(
    struct appl_context_handle * const
        p_context,
    struct appl_thread_descriptor const * const
        p_thread_descriptor,
    struct appl_thread_handle * * const
        r_thread_handle);

enum appl_status
appl_thread_detach(
    struct appl_thread_handle * const
        p_thread_handle);

enum appl_status
appl_thread_wait_result(
    struct appl_thread_handle * const
        p_thread_handle,
    void * * const
        r_thread_result);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_thread_handle.h */
