/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <syslog.h>

#endif /* #if defined APPL_OS_LINUX */

#include <appl_status.h>

#include <appl_types.h>

#include <log/appl_log_handle.h>

#include <log/appl_log_impl.h>

#include <misc/appl_unused.h>

#include <misc/appl_convert.h>

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

#if defined APPL_OS_LINUX

    {
        appl_unused(
            p_context);

        appl_ptrdiff_t const
            l_message_len =
            p_message_max
            - p_message_min;

        int const
            i_message_len =
            appl_convert::to_int(
                l_message_len);

        int const
            i_syslog_priority =
            (appl_log_level_error == e_level)
            ? LOG_ERR
            : (appl_log_level_warning == e_level)
            ? LOG_WARNING
            : LOG_NOTICE;

        syslog(
            i_syslog_priority,
            "%.*s",
            i_message_len,
            p_message_min);

        e_status =
            appl_status_ok;
    }

#else /* #if defined APPL_OS_Xx */

    {
        appl_unused(
            p_context,
            e_level,
            p_message_min,
            p_message_max);

        e_status =
            appl_raise_not_implemented();
    }

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // f_print()

/* end-of-file: appl_log_impl.cpp */
