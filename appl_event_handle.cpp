/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_event_handle.h"

#include "appl_event_service.h"

/*

*/
enum appl_status
appl_event_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_event_descriptor const * const
        p_event_descriptor,
    struct appl_event_handle * * const
        r_event_handle)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_service::s_create(
            p_context_handle,
            p_event_descriptor,
            r_event_handle);

    return
        e_status;

} /* appl_event_create() */

/*

*/
enum appl_status
appl_event_signal(
    struct appl_event_handle * const
        p_event_handle)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_service::s_signal(
            p_event_handle);

    return
        e_status;

} /* appl_event_signal() */

/*

*/
enum appl_status
appl_event_wait(
    struct appl_event_handle * const
        p_event_handle,
    struct appl_mutex_handle * const
        p_mutex_handle,
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_service::s_wait(
            p_event_handle,
            p_mutex_handle,
            i_time_freq,
            i_time_count);

    return
        e_status;

} /* appl_event_wait() */

/* end-of-file: appl_event_handle.cpp */
