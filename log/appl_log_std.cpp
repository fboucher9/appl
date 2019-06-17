/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_log_handle.h>

#include <appl_object.h>

#include <log/appl_log.h>

#include <log/appl_log_impl.h>

#include <log/appl_log_std.h>

#include <appl_allocator_handle.h>

static __thread char const * g_appl_stack_table[64u];

static unsigned int __thread g_appl_stack_index = 0u;

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
appl_log_std::appl_log_std(
    struct appl_context * const
        p_context) :
    appl_log(
        p_context),
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

//
//
//
enum appl_status
    appl_log_std::v_enter(
        char const * const
            p_function0)
{
#if defined APPL_DEBUG
    /* tracing code here.. */
#endif /* #if defined APPL_DEBUG */

    g_appl_stack_table[g_appl_stack_index ++] = p_function0;

    return
        appl_status_ok;

} // v_enter()

//
//
//
enum appl_status
    appl_log_std::v_leave(void)
{
#if defined APPL_DEBUG
    /* tracing code here... */
#endif /* #if defined APPL_DEBUG */

    g_appl_stack_index --;

    return
        appl_status_ok;

} // v_leave()

/* end-of-file: appl_log_std.cpp */
