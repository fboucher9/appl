/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <backtrace/appl_backtrace_impl.h>

#if defined APPL_OS_LINUX
#include <execinfo.h>
#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS
#include <windows.h>
#endif /* #if defined APPL_OS_WINDOWS */

#include <stdio.h>

#include <appl_unused.h>

#include <appl_convert.h>

#include <appl_buf.h>

#include <appl_buf0.h>

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

    union appl_backtrace_ptr
    {
        void const * *
            ppcv;

        void * *
            ppv;

    } o_backtrace_ptr;

    o_backtrace_ptr.ppcv =
        p_buffer;

#if defined APPL_OS_LINUX

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

    USHORT
        i_result;

    i_result =
        RtlCaptureStackBackTrace(
            0,
            static_cast<DWORD>(
                i_count_max),
            o_backtrace_ptr.ppv,
            NULL);

    *(r_count) =
        i_result;

    e_status =
        appl_status_ok;

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

    appl_size_t
        i_index;

    i_index =
        0u;

    while (
        i_index < i_count)
    {
        void const * const
            p_symbol =
            p_buffer[i_index];

        printf(
            " -- %p\n",
            p_symbol);

        i_index ++;
    }

    e_status =
        appl_status_ok;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // s_report()

//
//
//
enum appl_status
appl_backtrace_impl::s_ouch(
    char const * const
        p_header0)
{
    enum appl_status
        e_status;

    unsigned char const * const
        pc_uchar =
        appl_convert::to_uchar_ptr(
            p_header0);

    void const *
        a_stack[8u];

    appl_size_t
        i_count;

    fwrite(
        pc_uchar,
        1,
        appl_buf0_len(
            pc_uchar),
        stderr);

    e_status =
        appl_backtrace_impl::s_capture(
            a_stack,
            8u,
            &(
                i_count));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_backtrace_impl::s_report(
                a_stack,
                i_count);
    }

    return
        e_status;

} // s_ouch()

/* end-of-file: appl_backtrace_impl.cpp */
