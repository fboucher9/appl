/* See LICENSE for license details */

/*

*/

#if ( defined APPL_DEBUG ) && ( defined APPL_OS_WINDOWS )

#include <windows.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_debug.h>

#include <appl_debug_w32.h>

//
//
//
enum appl_status
    appl_debug_w32::create_instance(
        struct appl_context * const
            p_context,
        class appl_debug * * const
            r_debug)
{
    return
        appl_object::s_create
        < appl_debug_w32, appl_debug >
        (
            p_context,
            (&
                appl_debug_w32::placement_new),
            r_debug);

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
void
    appl_debug_w32::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_debug_w32;

} // placement_new()

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
                static_cast<DWORD>(
                    p_msg_max
                    - p_msg_min),
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
