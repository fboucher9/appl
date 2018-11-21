/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_log_handle.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <log/appl_log.h>

#include <log/appl_log_impl.h>

#include <log/appl_log_std.h>

#include <appl_unused.h>

#include <allocator/appl_allocator.h>

//
//
//
enum appl_status
    appl_log_std::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_log_std * * const
            r_instance)
{
    enum appl_status
        e_status;

    e_status =
        p_allocator->alloc_object(
            r_instance);

    return
        e_status;

} // s_create()

//
//
//
appl_log_std::appl_log_std() :
    appl_log(),
    m_log_impl()
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

    e_status =
        m_log_impl.f_print(
            m_context,
            e_level,
            p_message_min,
            p_message_max);

    return
        e_status;

} // v_print()

/* end-of-file: appl_log_std.cpp */