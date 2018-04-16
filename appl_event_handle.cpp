/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_event_handle.h"

#include "appl_event_service.h"

/*

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
