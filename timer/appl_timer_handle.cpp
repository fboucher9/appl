/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_timer_handle.h>

#include <timer/appl_timer_service.h>

/*

*/
enum appl_status
appl_timer_create(
    struct appl_context * const
        p_context,
    struct appl_timer * * const
        r_timer)
{
    return
        appl_timer_service::s_create(
            p_context,
            r_timer);

} /* _create() */

/*

*/
enum appl_status
appl_timer_destroy(
    struct appl_timer * const
        p_timer)
{
    return
        appl_timer_service::s_destroy(
            p_timer);

} /* _destroy() */

/*

*/
struct appl_object *
appl_timer_parent(
    struct appl_timer * const
        p_timer)
{
    return
        appl_timer_service::s_parent(
            p_timer);

} /* _parent() */

/*

*/
enum appl_status
appl_timer_schedule(
    struct appl_timer * const
        p_timer,
    struct appl_timer_descriptor const * const
        p_timer_descriptor)
{
    return
        appl_timer_service::s_schedule(
            p_timer,
            p_timer_descriptor);

} /* _schedule() */

/* end-of-file: appl_timer_handle.cpp */
