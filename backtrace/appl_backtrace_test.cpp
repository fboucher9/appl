/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_backtrace_handle.h>

#include <backtrace/appl_backtrace.h>

#include <backtrace/appl_backtrace_test.h>

#include <appl_allocator_handle.h>

#include <appl_context_handle.h>

//
//
//
void
appl_backtrace_test_1(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    {
        class appl_backtrace *
            p_backtrace;

        e_status =
            appl_new(
                p_allocator,
                &(
                    p_backtrace));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_backtrace->v_capture(0, 0, 0);

            e_status =
                p_backtrace->v_report(0, 0);

            e_status =
                p_backtrace->v_ouch("ouch!\n");

            appl_delete(
                p_allocator,
                p_backtrace);
        }
    }

    appl_size_t
        i_count;

    void const *
        a_stack[8u];

    e_status =
        appl_backtrace_capture(
            p_context,
            a_stack,
            sizeof(a_stack) / sizeof(a_stack[0u]),
            &(
                i_count));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_backtrace_report(
                p_context,
                a_stack,
                i_count);
    }

    e_status =
        appl_backtrace_ouch(
            p_context,
            "ouch!\n");

} // appl_backtrace_test_1()

/* end-of-file: appl_backtrace_test.cpp */
