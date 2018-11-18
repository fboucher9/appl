/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_log_handle.h>

#include <log/appl_log_service.h>

/*

*/
enum appl_status
    appl_log_print(
        struct appl_context * const
            p_context,
        enum appl_log_level const
            e_level,
        unsigned char const * const
            p_message_min,
        unsigned char const * const
            p_message_max)
{
    return
        appl_log_service::s_print(
            p_context,
            e_level,
            p_message_min,
            p_message_max);

} /* appl_log_print() */

/* end-of-file: appl_log_handle.cpp */
