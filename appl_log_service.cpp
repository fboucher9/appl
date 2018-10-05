/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_log_handle.h>

#include <appl_log_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_log.h>

//
//
//
enum appl_status
    appl_log_service::s_print(
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

    // Dispatch to appl_log object
    struct appl_log * const
        p_log =
        p_context->m_log;

    e_status =
        p_log->v_print(
            e_level,
            p_message_min,
            p_message_max);

    return
        e_status;

} // s_print()

/* end-of-file: appl_log_service.cpp */