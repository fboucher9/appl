/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_thread_handle.h"

#include "appl_thread_service.h"

/*

*/
enum appl_status
appl_thread_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_thread_handle * * const
        r_thread_handle)
{
    return
        appl_thread_service::s_create(
            p_context_handle,
            p_property_handle,
            r_thread_handle);

} /* appl_thread_create() */

/*

*/
enum appl_status
appl_thread_start(
    struct appl_thread_handle * const
        p_thread_handle)
{
    return
        appl_thread_service::s_start(
            p_thread_handle);

} /* appl_thread_start() */

/*

*/
enum appl_status
appl_thread_stop(
    struct appl_thread_handle * const
        p_thread_handle,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count,
    void * * const
        r_thread_result)
{
    return
        appl_thread_service::s_stop(
            p_thread_handle,
            i_wait_freq,
            i_wait_count,
            r_thread_result);

} /* appl_thread_stop() */

/*

*/
enum appl_status
appl_thread_interrupt(
    struct appl_thread_handle * const
        p_thread_handle)
{
    return
        appl_thread_service::s_interrupt(
            p_thread_handle);

} /* appl_thread_interrupt() */

/* end-of-file: appl_thread_handle.cpp */
