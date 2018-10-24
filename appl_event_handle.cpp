/* See LICENSE for license details */

/*

Module: appl_event_handle.cpp

Description:

    Public C-style interface for event object.  Event object is used for
    multi-threaded applications, with concept equivalent to pthread_cond.

*/

#include <appl_status.h>

#include <appl_event_handle.h>

#include <appl_event_service.h>

/*

Function: appl_event_create()

Description:

    Public C-style interface to create an event object.  This function returns
    an opaque C-style handle that may be used with other appl_event_handle
    functions.

Parameters:

    p_context
        Pointer to appl_context structure.

    p_event_descriptor
        Pointer to appl_event_descriptor structure.

    r_event
        Output of appl_event handle.

Returns:

    See appl_status enumeration.

Comments:

    None.

*/
enum appl_status
appl_event_create(
    struct appl_context * const
        p_context,
    struct appl_event_descriptor const * const
        p_event_descriptor,
    struct appl_event * * const
        r_event)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_service::s_create(
            p_context,
            p_event_descriptor,
            r_event);

    return
        e_status;

} /* appl_event_create() */

/*

Function: appl_event_parent()

Description:

    Public C-style interface to return parent object handle associated with
    given event handle.

Parameters:

    p_event
        Pointer to appl_event handle.

Returns:

    Pointer to parent object handle.

Comments:

    -   Application must call this to obtain an object handle required to
        call appl_object_destroy().

*/
struct appl_object *
appl_event_parent(
    struct appl_event * const
        p_event)
{
    return
        appl_event_service::s_parent(
            p_event);

} /* parent() */

/*

Function: appl_event_const_parent()

Description:

    Public C-style interface to obtain a constant object handle given a
    constant event handle.

Parameters:

    p_event
        Pointer to constant event handle.

Returns:

    Pointer to constant object handle.

Comments:

    -   This function is required when application is using contant handles.

*/
struct appl_object const *
appl_event_const_parent(
    struct appl_event const * const
        p_event)
{
    return
        appl_event_service::s_const_parent(
            p_event);

} /* const_parent() */

/*

Function: appl_event_signal

Description:

    Public C-style interface to signal an event object.

Parameters:

    p_event
        Pointer to event handle.

Returns:

    appl_status

Comments:

    None.

*/
enum appl_status
appl_event_signal(
    struct appl_event * const
        p_event)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_service::s_signal(
            p_event);

    return
        e_status;

} /* appl_event_signal() */

/*

Function: appl_event_wait()

Description:

    Public C-style interface to wait for an event object to be signaled.

Parameters:

    p_event
        Pointer to event handle

    p_mutex
        Pointer to mutex handle

    i_wait_freq
        Frequency of wait

    i_wait_count
        Counter for wait

Returns:

    appl_status

Comments:

    -   Mutex must be allocated by appl_mutex_create.

    -   If timeout occurs, status will return failure.

*/
enum appl_status
appl_event_wait(
    struct appl_event * const
        p_event,
    struct appl_mutex * const
        p_mutex,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_service::s_wait(
            p_event,
            p_mutex,
            i_wait_freq,
            i_wait_count);

    return
        e_status;

} /* appl_event_wait() */

/* end-of-file: appl_event_handle.cpp */
