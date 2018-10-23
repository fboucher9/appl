/* See LICENSE for license details */

/*

*/

#if ( defined APPL_DEBUG ) && ( defined APPL_OS_WINDOWS )

#include <windows.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_debug.h>

#include <appl_debug_w32.h>

#include <appl_buf.h>

#include <appl_heap.h>

//
//
//
enum appl_status
    appl_debug_w32::s_create(
        struct appl_heap * const
            p_heap,
        class appl_debug * * const
            r_debug)
{
    enum appl_status
        e_status;

    class appl_debug_w32 *
        p_debug_w32;

    e_status =
        p_heap->alloc_object(
            &(
                p_debug_w32));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_debug) =
            p_debug_w32;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_debug_w32::appl_debug_w32() :
    appl_debug()
{
}

//
//
//
appl_debug_w32::~appl_debug_w32()
{
}

//
//
//
enum appl_status
    appl_debug_w32::v_break(void)
{
    DebugBreak();

    return
        appl_status_ok;

} // v_break()

//
//
//
enum appl_status
    appl_debug_w32::v_print(
        unsigned char const * const
            p_msg_min,
        unsigned char const * const
            p_msg_max)
{
    enum appl_status
        e_status;

    HANDLE
        h_stderr_file;

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
                p_msg_min,
                appl_buf_len(
                    p_msg_min,
                    p_msg_max),
                &(
                    dwBytesWritten),
                NULL);

        if (
            b_write_file_result)
        {
            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_print()

#endif /* #if ( defined APPL_DEBUG ) && ( defined APPL_OS_WINDOWS ) */

/* end-of-file: appl_debug_std.cpp */
