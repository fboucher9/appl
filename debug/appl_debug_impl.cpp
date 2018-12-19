/* See LICENSE for license details */

/*

Module: appl_debug_impl.cpp

Description:

    OS-specific debugging functions to be used from implementation of
    appl_debug or from other appl modules.

*/

#if defined APPL_DEBUG

#include <debug/appl_debug_impl.h>

#include <appl_buf.h>

#include <appl_status.h>

#include <appl_buf0.h>

#include <appl_unused.h>

#include <appl_convert.h>

#if defined APPL_OS_LINUX
#include <signal.h>
#include <unistd.h>
#else /* #if defined APPL_OS_LINUX */
#include <windows.h>
#endif /* #if defined APPL_OS_LINUX */

//
//
//
void
    appl_debug_impl::s_break(void)
{
#if defined APPL_OS_LINUX
    raise(SIGINT);
#else /* #if defined APPL_OS_LINUX */
    DebugBreak();
#endif /* #if defined APPL_OS_LINUX */

} // s_break()

//
//
//
void
    appl_debug_impl::s_print(
        unsigned char const * const
            p_message_min,
        unsigned char const * const
            p_message_max)
{
#if defined APPL_OS_LINUX
    signed long int
        i_write_result;

    i_write_result =
        write(
            STDERR_FILENO,
            p_message_min,
            appl_buf_len(
                p_message_min,
                p_message_max));

    appl_unused(
        i_write_result);

#else /* #if defined APPL_OS_LINUX */
    HANDLE const
        h_stderr_file =
        GetStdHandle(
            STD_ERROR_HANDLE);

    if (
        INVALID_HANDLE_VALUE
        != h_stderr_file)
    {
        BOOL
            b_write_file_result;

        DWORD
            dwBytesWritten;

        b_write_file_result =
            WriteFile(
                h_stderr_file,
                p_message_min,
                appl_buf_len(
                    p_message_min,
                    p_message_max),
                &(
                    dwBytesWritten),
                NULL);

        appl_unused(
            b_write_file_result);
    }

#endif /* #if defined APPL_OS_LINUX */

} // s_print()

//
//
//
void
    appl_debug_impl::s_print0(
        char const * const
            p_message0)
{
    unsigned char const * const
        pc_uchar =
        appl_convert::to_uchar_ptr(
            p_message0);

    appl_debug_impl::s_print(
        pc_uchar,
        pc_uchar + appl_buf0_len(
            pc_uchar));

} // s_print0()

//
//
//
void
    appl_debug_impl::s_validate(
        bool const
            b_condition,
        char const * const
            p_message0)
{
    if (
        b_condition)
    {
    }
    else
    {
        appl_debug_impl::s_print0(
            p_message0);
    }
} // s_validate()

#else /* #if defined APPL_DEBUG */

typedef void appl_dummy;

#endif /* #if defined APPL_DEBUG */
