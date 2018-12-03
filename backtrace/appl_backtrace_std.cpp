/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <backtrace/appl_backtrace.h>

#include <backtrace/appl_backtrace_std.h>

#include <allocator/appl_allocator.h>

#include <appl_unused.h>

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
        p_allocator->alloc_object(
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
        p_instance->v_destroy(
            p_allocator);

    return
        e_status;

}

//
//
//
appl_backtrace_std::appl_backtrace_std() :
    appl_backtrace()
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
        void * const
            p_buffer,
        appl_size_t const
            i_buffer_length)
{
    appl_unused(
        p_buffer,
        i_buffer_length);

    return
        appl_status_not_implemented;

} // v_capture()

//
//
//
enum appl_status
    appl_backtrace_std::v_report(
        void const * const
            p_buffer,
        appl_size_t const
            i_buffer_length)
{
    appl_unused(
        p_buffer,
        i_buffer_length);

    return
        appl_status_not_implemented;

} // v_report()

/* end-of-file: appl_backtrace_std.cpp */
