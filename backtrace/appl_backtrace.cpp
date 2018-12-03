/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <backtrace/appl_backtrace.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_backtrace::v_capture(
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
    appl_backtrace::v_report(
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

//
//
//
appl_backtrace::appl_backtrace() :
    appl_object()
{
}

//
//
//
appl_backtrace::~appl_backtrace()
{
}

/* end-of-file: appl_backtrace.cpp */
