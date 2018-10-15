/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_thread_handle.h>

#include <appl_thread_service.h>

/*

*/
enum appl_status
appl_thread_create(
    struct appl_object const * const
        p_object,
    struct appl_thread_property const * const
        p_thread_property,
    struct appl_thread * * const
        r_thread)
{
    return
        appl_thread_service::s_create(
            p_object,
            p_thread_property,
            r_thread);

} /* appl_thread_create() */

struct appl_object *
appl_thread_parent(
    struct appl_thread * const
        p_thread)
{
    return
        appl_thread_service::s_convert(
            p_thread);

} /* parent() */

struct appl_object const *
appl_thread_const_parent(
    struct appl_thread const * const
        p_thread)
{
    return
        appl_thread_service::s_convert(
            p_thread);

} /* const_parent() */

/*

*/
enum appl_status
appl_thread_start(
    struct appl_thread * const
        p_thread,
    struct appl_thread_descriptor const * const
        p_thread_descriptor)
{
    return
        appl_thread_service::s_start(
            p_thread,
            p_thread_descriptor);

} /* appl_thread_start() */

/*

*/
enum appl_status
appl_thread_interrupt(
    struct appl_thread * const
        p_thread)
{
    return
        appl_thread_service::s_interrupt(
            p_thread);

} /* appl_thread_interrupt() */

/* end-of-file: appl_thread_handle.cpp */
