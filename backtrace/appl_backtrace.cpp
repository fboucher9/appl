/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <backtrace/appl_backtrace.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
    appl_backtrace::v_capture(
        void const * * const
            p_buffer,
        appl_size_t const
            i_count_max,
        appl_size_t * const
            r_count)
{
    appl_unused(
        p_buffer,
        i_count_max,
        r_count);

    return
        appl_raise_not_implemented();

} // v_capture()

//
//
//
enum appl_status
    appl_backtrace::v_report(
        void const * const * const
            p_buffer,
        appl_size_t const
            i_count)
{
    appl_unused(
        p_buffer,
        i_count);

    return
        appl_raise_not_implemented();

} // v_report()

//
//
//
enum appl_status
    appl_backtrace::v_ouch(
        char const * const
            p_header0)
{
    appl_unused(
        p_header0);

    return
        appl_raise_not_implemented();

} // v_ouch()

//
//
//
appl_backtrace::appl_backtrace(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_backtrace::~appl_backtrace()
{
}

/* end-of-file: appl_backtrace.cpp */
