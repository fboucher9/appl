/* See LICENSE for license details */

/*

*/

#if ( defined APPL_DEBUG ) && ( defined APPL_OS_LINUX )

#include <signal.h>

#include <unistd.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_debug.h"

#include "appl_debug_std.h"

#include "appl_buf.h"

//
//
//
enum appl_status
    appl_debug_std::create_instance(
        class appl_context * const
            p_context,
        class appl_debug * * const
            r_debug)
{
    return
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_debug_std),
            &(
                appl_debug_std::placement_new),
            r_debug);

} // create_instance()

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
void
    appl_debug_std::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_debug_std;

} // placement_new()

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
        struct appl_buf const * const
            p_buf)
{
    enum appl_status
        e_status;

    signed long int
        i_write_result;

    i_write_result =
        static_cast<signed long int>(
            write(
                STDERR_FILENO,
                p_buf->o_min.pc_uchar,
                static_cast<unsigned int>(
                    p_buf->o_max.pc_uchar
                    - p_buf->o_min.pc_uchar)));

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
