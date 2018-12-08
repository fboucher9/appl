/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <backtrace/appl_backtrace_impl.h>

#if defined APPL_OS_LINUX
#include <execinfo.h>
#endif /* #if defined APPL_OS_LINUX */

#include <stdio.h>

#include <appl_unused.h>

#include <appl_convert.h>

#include <appl_buf.h>

//
//
//
enum appl_status
    appl_backtrace_impl::s_capture(
        void const * * const
            p_buffer,
        appl_size_t const
            i_count_max,
        appl_size_t * const
            r_count)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    union appl_backtrace_ptr
    {
        void const * *
            ppcv;

        void * *
            ppv;

    } o_backtrace_ptr;

    o_backtrace_ptr.ppcv =
        p_buffer;

    *(r_count) =
        appl_convert::to_unsigned(
            backtrace(
                o_backtrace_ptr.ppv,
                appl_convert::to_int(
                    appl_convert::to_signed(
                        i_count_max))));

    e_status =
        appl_status_ok;

#else /* #if defined APPL_OS_Xx */

    appl_unused(
        p_buffer,
        i_count_max,
        r_count);

    e_status =
        appl_status_not_implemented;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // s_capture()

//
//
//
enum appl_status
    appl_backtrace_impl::s_report(
        void const * const * const
            p_buffer,
        appl_size_t const
            i_count)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    union appl_backtrace_ptr
    {
        void const * const *
            pcpcv;

        void * const *
            pcpv;

    } o_backtrace_ptr;

    o_backtrace_ptr.pcpcv =
        p_buffer;

    backtrace_symbols_fd(
        o_backtrace_ptr.pcpv,
        appl_convert::to_int(
            appl_convert::to_signed(
                i_count)),
        2);

    e_status =
        appl_status_ok;

#else /* #if defined APPL_OS_Xx */

    appl_unused(
        p_buffer,
        i_count);

    e_status =
        appl_status_not_implemented;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // s_report()

//
//
//
void
appl_backtrace_impl::s_ouch(
    unsigned char const * const
        p_header_min,
    unsigned char const * const
        p_header_max)
{
    void const *
        a_stack[8u];

    appl_size_t
        i_count;

    fwrite(
        p_header_min,
        1,
        appl_buf_len(
            p_header_min,
            p_header_max),
        stderr);

    if (
        appl_status_ok
        == appl_backtrace_impl::s_capture(
            a_stack,
            8u,
            &(
                i_count)))
    {
        appl_backtrace_impl::s_report(
            a_stack,
            i_count);
    }
} // s_ouch()

/* end-of-file: appl_backtrace_impl.cpp */
