/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <backtrace/appl_backtrace_service.h>

#include <appl_object.h>

#include <backtrace/appl_backtrace.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
    appl_backtrace_service::s_capture(
        struct appl_context * const
            p_context,
        void * const
            p_buffer,
        appl_size_t const
            i_buffer_length)
{
    enum appl_status
        e_status;

    class appl_backtrace * const
        p_backtrace =
        p_context->m_backtrace;

    e_status =
        p_backtrace->v_capture(
            p_buffer,
            i_buffer_length);

    return
        e_status;

} // s_capture()

//
//
//
enum appl_status
    appl_backtrace_service::s_report(
        struct appl_context * const
            p_context,
        void const * const
            p_buffer,
        appl_size_t const
            i_buffer_length)
{
    enum appl_status
        e_status;

    class appl_backtrace * const
        p_backtrace =
        p_context->m_backtrace;

    e_status =
        p_backtrace->v_report(
            p_buffer,
            i_buffer_length);

    return
        e_status;

} // s_report()

/* end-of-file: appl_backtrace_service.cpp */
