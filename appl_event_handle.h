/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_HANDLE_H
#error include appl_event_handle.h once
#endif /* #if defined INC_APPL_EVENT_HANDLE_H */

#define INC_APPL_EVENT_HANDLE_H

struct appl_object;

struct appl_mutex;

struct appl_event;

struct appl_event_descriptor
{
    void *
        p_dummy;

}; /* struct appl_event_descriptor */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_event_create(
    struct appl_context * const
        p_context,
    struct appl_event_descriptor const * const
        p_event_descriptor,
    struct appl_event * * const
        r_event);

struct appl_object *
appl_event_parent(
    struct appl_event * const
        p_event);

struct appl_object const *
appl_event_const_parent(
    struct appl_event const * const
        p_event);

enum appl_status
appl_event_signal(
    struct appl_event * const
        p_event);

enum appl_status
appl_event_wait(
    struct appl_event * const
        p_event,
    struct appl_mutex * const
        p_mutex,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_event_handle.h */
