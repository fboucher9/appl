/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_thread_handle.h>

#include <thread/appl_thread_service.h>

#include <appl_types.h>

#include <appl_thread_descriptor.h>

/*

*/
void
appl_thread_descriptor_init(
    struct appl_thread_descriptor * const
        p_thread_descriptor)
{
    p_thread_descriptor->b_callback =
        0;

    p_thread_descriptor->b_name =
        0;

    p_thread_descriptor->b_stack =
        0;

    p_thread_descriptor->b_scheduling =
        0;

} /* appl_thread_descriptor_init() */

/*

*/
enum appl_status
appl_thread_create(
    struct appl_context * const
        p_context,
    struct appl_thread_descriptor const * const
        p_thread_descriptor,
    struct appl_thread * * const
        r_thread)
{
    return
        appl_thread_service::s_create(
            p_context,
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
