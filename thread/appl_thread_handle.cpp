/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_thread_handle.h>

#include <thread/appl_thread_service.h>

/*

*/
enum appl_status
appl_thread_create(
    struct appl_context * const
        p_context,
    struct appl_thread_property const * const
        p_thread_property,
    struct appl_thread_descriptor const * const
        p_thread_descriptor,
    struct appl_thread * * const
        r_thread)
{
    return
        appl_thread_service::s_create(
            p_context,
            p_thread_property,
            p_thread_descriptor,
            r_thread);

} /* appl_thread_create() */

/*

*/
enum appl_status
appl_thread_destroy(
    struct appl_thread * const
        p_thread)
{
    return
        appl_thread_service::s_destroy(
            p_thread);

} /* appl_thread_destroy() */

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
appl_thread_interrupt(
    struct appl_thread * const
        p_thread)
{
    return
        appl_thread_service::s_interrupt(
            p_thread);

} /* appl_thread_interrupt() */

/* end-of-file: appl_thread_handle.cpp */
