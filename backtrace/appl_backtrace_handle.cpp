/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_backtrace_handle.h>

#include <backtrace/appl_backtrace_service.h>

/*

*/
enum appl_status
    appl_backtrace_capture(
        struct appl_context * const
            p_context,
        void * const
            p_buffer,
        appl_size_t const
            i_buffer_length)
{
    return
        appl_backtrace_service::s_capture(
            p_context,
            p_buffer,
            i_buffer_length);

} /* appl_backtrace_capture() */

/*

*/
enum appl_status
    appl_backtrace_report(
        struct appl_context * const
            p_context,
        void const * const
            p_buffer,
        appl_size_t const
            i_buffer_length)
{
    return
        appl_backtrace_service::s_report(
            p_context,
            p_buffer,
            i_buffer_length);

} /* appl_backtrace_report() */

/* end-of-file: appl_backtrace_handle.cpp */
