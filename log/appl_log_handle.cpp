/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_log_handle.h>

#include <log/appl_log_service.h>

//
//
//
enum appl_status
    appl_log_register(
        struct appl_context * const
            p_context,
        void (* const p_callback)(
            void * const
                p_callback_context,
            struct appl_log_record const * const
                p_log_record),
        void * const
            p_callback_context,
        struct appl_log_client * * const
            r_client)
{
    return
        appl_log_service::s_register(
            p_context,
            p_callback,
            p_callback_context,
            r_client);

} // appl_log_register()

//
//
//
enum appl_status
    appl_log_unregister(
        struct appl_context * const
            p_context,
        struct appl_log_client * const
            p_client)
{
    return
        appl_log_service::s_unregister(
            p_context,
            p_client);

} // appl_log_unregister()

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

//
//
//
enum appl_status
    appl_log_enter(
        struct appl_context * const
            p_context,
        char const * const
            p_function0)
{
    return
        appl_log_service::s_enter(
            p_context,
            p_function0);

} // appl_log_enter()

//
//
//
enum appl_status
    appl_log_leave(
        struct appl_context * const
            p_context)
{
    return
        appl_log_service::s_leave(
            p_context);

} // appl_log_leave()

/* end-of-file: appl_log_handle.cpp */
