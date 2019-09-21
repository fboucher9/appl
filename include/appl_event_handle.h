/* See LICENSE for license details */

/*

Module: appl_event_handle.h

Description:

    Public C-style interface for event object.  Event object is used for
    multi-threaded applications, with concept equivalent to pthread_cond.

*/

/* Reverse include guard */
enum guard_appl_event_handle_h
{
    inc_appl_event_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/*

Structure: appl_event_descriptor

Description:

    Descriptor used for creation of event handle.

*/
struct appl_event_descriptor
{
    void *
        p_dummy;

}; /* struct appl_event_descriptor */

#include <appl_extern_c_begin.h>

/* Create an event */
enum appl_status
appl_event_create(
    struct appl_context * const
        p_context,
    struct appl_event_descriptor const * const
        p_event_descriptor,
    struct appl_event * * const
        r_event);

enum appl_status
appl_event_destroy(
    struct appl_event * const
        p_event);

/* Obtain pointer to parent object handle */
struct appl_object *
appl_event_parent(
    struct appl_event * const
        p_event);

/* Obtain constant pointer to parent object handle */
struct appl_object const *
appl_event_const_parent(
    struct appl_event const * const
        p_event);

/* Signal event */
enum appl_status
appl_event_signal(
    struct appl_event * const
        p_event);

/* Wait for event to be signaled */
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

#include <appl_extern_c_end.h>

/* end-of-file: appl_event_handle.h */
