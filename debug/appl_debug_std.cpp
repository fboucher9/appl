/* See LICENSE for license details */

/*

*/

#if ( defined APPL_DEBUG ) && ( defined APPL_OS_LINUX )

#include <signal.h>

#include <unistd.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <debug/appl_debug.h>

#include <debug/appl_debug_std.h>

#include <appl_allocator_handle.h>

#include <debug/appl_debug_impl.h>

//
//
//
enum appl_status
    appl_debug_std::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_debug * * const
            r_debug)
{
    enum appl_status
        e_status;

    class appl_debug_std *
        p_debug_std;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_debug_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_debug) =
            p_debug_std;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_debug_std::s_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_debug * const
            p_debug)
{
    return
        appl_delete(
            p_allocator,
            p_debug);

} // s_destroy()

//
//
//
appl_debug_std::appl_debug_std(
    struct appl_context * const
        p_context) :
    appl_debug(
        p_context)
{
}

//
//
//
appl_debug_std::~appl_debug_std()
{
}

//
//
//
enum appl_status
    appl_debug_std::v_break(void)
{
    enum appl_status
        e_status;

    appl_debug_impl::s_break();

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_break()

//
//
//
enum appl_status
    appl_debug_std::v_print(
        unsigned char const * const
            p_msg_min,
        unsigned char const * const
            p_msg_max)
{
    enum appl_status
        e_status;

    appl_debug_impl::s_print(
        p_msg_min,
        p_msg_max);

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_print()

//
//
//
appl_size_t
    appl_debug_std::v_cleanup(void)
{
    return
        sizeof(class appl_debug_std);

} // v_cleanup()

#endif /* #if ( defined APPL_DEBUG ) && ( defined APPL_OS_LINUX ) */

/* end-of-file: appl_debug_std.cpp */
