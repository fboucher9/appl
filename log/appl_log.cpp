/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <log/appl_log_handle.h>

#include <appl_object.h>

#include <log/appl_log.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_log::v_register(
        appl_log_callback * const
            p_callback,
        void * const
            p_callback_context,
        struct appl_log_client * * const
            r_client)
{
    enum appl_status
        e_status;

    appl_unused(
        p_callback,
        p_callback_context,
        r_client);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_register()

//
//
//
enum appl_status
    appl_log::v_unregister(
        struct appl_log_client * const
            p_client)
{
    enum appl_status
        e_status;

    appl_unused(
        p_client);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_unregister()

//
//
//
enum appl_status
    appl_log::v_print(
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
        e_level,
        p_message_min,
        p_message_max);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_print()

//
//
//
appl_log::appl_log(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_log::~appl_log()
{
}

/* end-of-file: appl_log.cpp */
