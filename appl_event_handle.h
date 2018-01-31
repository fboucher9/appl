/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_EVENT_HANDLE_H)
#error include appl_event_handle.h once
#endif /* #if defined(INC_APPL_EVENT_HANDLE_H) */

#define INC_APPL_EVENT_HANDLE_H

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
        p_context,
    struct appl_event_descriptor const * const
        p_event_descriptor,
    struct appl_event_handle * * const
        p_event);

enum appl_status
appl_event_signal(
    struct appl_event_handle * const
        p_event);

enum appl_status
appl_event_wait(
    struct appl_event_handle * const
        p_event,
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_event_handle.h */
