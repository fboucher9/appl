/* See LICENSE for license details */

/*

*/

#if ( defined APPL_DEBUG ) && ( defined APPL_OS_LINUX )

#include <signal.h>

#include <unistd.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <debug/appl_debug.h>

#include <debug/appl_debug_std.h>

#include <appl_buf.h>

#include <appl_allocator.h>

//
//
//
enum appl_status
    appl_debug_std::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_debug * * const
            r_debug)
{
    enum appl_status
        e_status;

    class appl_debug_std *
        p_debug_std;

    e_status =
        p_allocator->alloc_object(
            &(
                p_debug_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_debug) =
            p_debug_std;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_debug_std::appl_debug_std() :
    appl_debug()
{
}

//
//
//
appl_debug_std::~appl_debug_std()
{
}

//
//
//
enum appl_status
    appl_debug_std::v_break(void)
{
    raise(SIGINT);

    return
        appl_status_ok;

} // v_break()

//
//
//
enum appl_status
    appl_debug_std::v_print(
        unsigned char const * const
            p_msg_min,
        unsigned char const * const
            p_msg_max)
{
    enum appl_status
        e_status;

    signed long int
        i_write_result;

    i_write_result =
        write(
            STDERR_FILENO,
            p_msg_min,
            appl_buf_len(
                p_msg_min,
                p_msg_max));

    if (
        i_write_result > 0)
    {
        e_status =
            appl_status_ok;

    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_print()

#endif /* #if ( defined APPL_DEBUG ) && ( defined APPL_OS_LINUX ) */

/* end-of-file: appl_debug_std.cpp */
