/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <backtrace/appl_backtrace_service.h>

#include <object/appl_object.h>

#include <backtrace/appl_backtrace.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
    appl_backtrace_service::s_capture(
        struct appl_context * const
            p_context,
        void const * * const
            p_buffer,
        appl_size_t const
            i_count_max,
        appl_size_t * const
            r_count)
{
    enum appl_status
        e_status;

    class appl_backtrace *
        p_backtrace;

    e_status =
        p_context->v_backtrace(
            &(
                p_backtrace));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_backtrace->v_capture(
                p_buffer,
                i_count_max,
                r_count);
    }

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
        void const * const * const
            p_buffer,
        appl_size_t const
            i_count)
{
    enum appl_status
        e_status;

    class appl_backtrace *
        p_backtrace;

    e_status =
        p_context->v_backtrace(
            &(
                p_backtrace));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_backtrace->v_report(
                p_buffer,
                i_count);
    }

    return
        e_status;

} // s_report()

//
//
//
enum appl_status
    appl_backtrace_service::s_ouch(
        struct appl_context * const
            p_context,
        char const * const
            p_header0)
{
    enum appl_status
        e_status;

    class appl_backtrace *
        p_backtrace;

    e_status =
        p_context->v_backtrace(
            &(
                p_backtrace));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_backtrace->v_ouch(
                p_header0);
    }

    return
        e_status;

} // s_ouch()

/* end-of-file: appl_backtrace_service.cpp */
