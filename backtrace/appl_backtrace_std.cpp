/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <backtrace/appl_backtrace.h>

#include <backtrace/appl_backtrace_std.h>

#include <backtrace/appl_backtrace_impl.h>

#include <allocator/appl_allocator_handle.h>

//
//
//
enum appl_status
    appl_backtrace_std::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_backtrace * * const
            r_instance)
{
    enum appl_status
        e_status;

    class appl_backtrace_std *
        p_backtrace_std;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_backtrace_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_instance) =
            p_backtrace_std;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_backtrace_std::s_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_backtrace * const
            p_instance)
{
    enum appl_status
        e_status;

    e_status =
        appl_delete(
            p_allocator,
            p_instance);

    return
        e_status;

}

//
//
//
appl_backtrace_std::appl_backtrace_std(
    struct appl_context * const
        p_context) :
    appl_backtrace(
        p_context)
{
}

//
//
//
appl_backtrace_std::~appl_backtrace_std()
{
}

//
//
//
enum appl_status
    appl_backtrace_std::f_init(void)
{
    return
        appl_status_ok;
} // f_init()

//
//
//
appl_size_t
    appl_backtrace_std::v_cleanup(void)
{
    return
        sizeof(class appl_backtrace_std);
} // v_cleanup()

//
//
//
enum appl_status
    appl_backtrace_std::v_capture(
        void const * * const
            p_buffer,
        appl_size_t const
            i_count_max,
        appl_size_t * const
            r_count)
{
    return
        appl_backtrace_impl::s_capture(
            p_buffer,
            i_count_max,
            r_count);

} // v_capture()

//
//
//
enum appl_status
    appl_backtrace_std::v_report(
        void const * const * const
            p_buffer,
        appl_size_t const
            i_count)
{
    return
        appl_backtrace_impl::s_report(
            p_buffer,
            i_count);

} // v_report()

//
//
//
enum appl_status
    appl_backtrace_std::v_ouch(
        char const * const
            p_header0)
{
    return
        appl_backtrace_impl::s_ouch(
            p_header0);

} // v_ouch()

/* end-of-file: appl_backtrace_std.cpp */
