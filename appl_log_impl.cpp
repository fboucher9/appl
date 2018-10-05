/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#if defined APPL_OS_LINUX

#include <syslog.h>

#endif /* #if defined APPL_OS_LINUX */

#include <appl_log_handle.h>

#include <appl_log_impl.h>

#include <appl_unused.h>

//
//
//
appl_log_impl::appl_log_impl()
{
}

//
//
//
appl_log_impl::~appl_log_impl()
{
}

//
//
//
enum appl_status
    appl_log_impl::f_print(
        struct appl_context * const
            p_context,
        enum appl_log_level const
            e_level,
        unsigned char const * const
            p_message_min,
        unsigned char const * const
            p_message_max)
{
    enum appl_status
        e_status;

    appl_unused(
        p_context,
        e_level,
        p_message_min,
        p_message_max);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // f_print()

/* end-of-file: appl_log_impl.cpp */
