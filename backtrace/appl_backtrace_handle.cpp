/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_backtrace_handle.h>

#include <backtrace/appl_backtrace_service.h>

/*

*/
enum appl_status
    appl_backtrace_capture(
        struct appl_context * const
            p_context,
        void const * * const
            p_buffer,
        appl_size_t const
            i_count_max,
        appl_size_t * const
            r_count)
{
    return
        appl_backtrace_service::s_capture(
            p_context,
            p_buffer,
            i_count_max,
            r_count);

} /* appl_backtrace_capture() */

/*

*/
enum appl_status
    appl_backtrace_report(
        struct appl_context * const
            p_context,
        void const * const * const
            p_buffer,
        appl_size_t const
            i_count)
{
    return
        appl_backtrace_service::s_report(
            p_context,
            p_buffer,
            i_count);

} /* appl_backtrace_report() */

/*

*/
enum appl_status
    appl_backtrace_ouch(
        struct appl_context * const
            p_context,
        char const * const
            p_header0)
{
    return
        appl_backtrace_service::s_ouch(
            p_context,
            p_header0);

} /* appl_backtrace_ouch() */

/* end-of-file: appl_backtrace_handle.cpp */
