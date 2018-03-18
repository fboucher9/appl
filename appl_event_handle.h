/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_HANDLE_H
#error include appl_event_handle.h once
#endif /* #if defined INC_APPL_EVENT_HANDLE_H */

#define INC_APPL_EVENT_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_HANDLE_H
#error include appl_object_handle.h before
#endif /* #if ! defined INC_APPL_OBJECT_HANDLE_H */

struct appl_mutex_handle;

struct appl_event_handle;

struct appl_event_descriptor
{
    void *
        p_dummy;

}; /* struct appl_event_descriptor */

struct appl_event_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_event_handle */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_event_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_event_descriptor const * const
        p_event_descriptor,
    struct appl_event_handle * * const
        r_event_handle);

enum appl_status
appl_event_signal(
    struct appl_event_handle * const
        p_event_handle);

enum appl_status
appl_event_wait(
    struct appl_event_handle * const
        p_event_handle,
    struct appl_mutex_handle * const
        p_mutex_handle,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_event_handle.h */
