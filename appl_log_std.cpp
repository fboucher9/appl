/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_log_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_log.h>

#include <appl_log_std.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_log_std::s_create(
        struct appl_context * const
            p_context,
        class appl_log_std * * const
            r_instance)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_log_std::s_new),
            r_instance);

    return
        e_status;

} // s_create()

//
//
//
appl_log_std::appl_log_std()
{
}

//
//
//
appl_log_std::~appl_log_std()
{
}

//
//
//
void
    appl_log_std::s_new(
        void * const
            p_placement)
{
    new (
        p_placement)
        class appl_log_std;

} // s_new()

//
//
//
enum appl_status
    appl_log_std::v_print(
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
        appl_status_not_implemented;

    return
        e_status;

} // v_print()

/* end-of-file: appl_log_std.cpp */
