/* See LICENSE for license details */

/*

*/

#include <callstack/appl_callstack_test.h>

#include <appl_callstack_handle.h>

#include <appl_test.h>

#include <appl_unused.h>

static
void
test_callstack_report_cb(
    void * const
        p_callback_data,
    unsigned char const * const
        p_report_min,
    unsigned char const * const
        p_report_max)
{
    appl_unused(
        p_callback_data);

    appl_print(
        p_report_min,
        p_report_max);

} // test_callstack_report_cb()

//
//
//
void
appl_callstack_test_1(
    struct appl_context * const
        p_context)
{
    appl_callstack_enter(
        p_context,
        "test.level1");

    appl_callstack_print0(
        p_context,
        "arg.level1");

    appl_callstack_print_signed(
        p_context,
        -123);

    appl_callstack_print_unsigned(
        p_context,
        456);

    appl_callstack_enter(
        p_context,
        "test.level2");

    static unsigned char sc_buffer[] =
    {
        'a',
        'b',
        'c'
    };

    appl_callstack_print_buffer(
        p_context,
        sc_buffer,
        sc_buffer + sizeof(sc_buffer));

    appl_callstack_print_hexadecimal(
        p_context,
        0xdeadbeeful);

    appl_print0(
        "vvv callstack report vvv\n");

    appl_callstack_report(
        p_context,
        & test_callstack_report_cb,
        0);

    appl_print0(
        "\n^^^ callstack report ^^^\n");

    appl_callstack_leave(
        p_context);

    appl_callstack_leave(
        p_context);

} // appl_callstack_test_1()

/* end-of-file: appl_callstack_test.cpp */
