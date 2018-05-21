/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_HANDLE_H)
#error include appl_thread_handle.h once
#endif /* #if defined(INC_APPL_THREAD_HANDLE_H) */

#define INC_APPL_THREAD_HANDLE_H

struct appl_object;

struct appl_thread;

struct appl_thread_property;

struct appl_object;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_thread_create(
    struct appl_object const * const
        p_object,
    struct appl_thread_property const * const
        p_thread_property,
    struct appl_thread * * const
        r_thread);

struct appl_object *
appl_thread_parent(
    struct appl_thread * const
        p_thread);

struct appl_object const *
appl_thread_const_parent(
    struct appl_thread const * const
        p_thread);

enum appl_status
appl_thread_start(
    struct appl_thread * const
        p_thread);

enum appl_status
appl_thread_detach(
    struct appl_thread * const
        p_thread);

enum appl_status
appl_thread_stop(
    struct appl_thread * const
        p_thread,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count,
    void * * const
        r_thread_result);

enum appl_status
appl_thread_interrupt(
    struct appl_thread * const
        p_thread);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_thread_handle.h */
