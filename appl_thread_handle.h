/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_HANDLE_H)
#error include appl_thread_handle.h once
#endif /* #if defined(INC_APPL_THREAD_HANDLE_H) */

#define INC_APPL_THREAD_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_HANDLE_H
#error include appl_object_handle.h before
#endif /* #if ! defined INC_APPL_OBJECT_HANDLE_H */

struct appl_thread_handle;

struct appl_property_handle;

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
        p_context_handle,
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_thread_handle * * const
        r_thread_handle);

enum appl_status
appl_thread_start(
    struct appl_thread_handle * const
        p_thread_handle);

enum appl_status
appl_thread_stop(
    struct appl_thread_handle * const
        p_thread_handle,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count,
    void * * const
        r_thread_result);

enum appl_status
appl_thread_interrupt(
    struct appl_thread_handle * const
        p_thread_handle);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_thread_handle.h */
