/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_log_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <log/appl_log.h>

#include <log/appl_log_impl.h>

#include <log/appl_log_std.h>

#include <appl_allocator_handle.h>

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
        appl_new(
            p_allocator,
            r_instance);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_log_std::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_log * const
            p_instance)
{
    return
        appl_delete(
            p_allocator,
            p_instance);

} // s_destroy()

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
appl_size_t
    appl_log_std::v_cleanup(void)
{
    return
        sizeof(class appl_log_std);

} // v_cleanup()

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
