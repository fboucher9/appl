/* See LICENSE for license details */

/*

*/

#include <callstack/appl_callstack_test.h>

#include <callstack/appl_callstack_handle.h>

#include <appl_test.h>

//
//
//
void
appl_callstack_test_1(
    struct appl_context * const
        p_context)
{
    struct appl_callstack_frame *
        p_frame1;

    p_frame1 =
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

    struct appl_callstack_frame *
        p_frame2;

    p_frame2 =
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

    unsigned long int const
        i_length =
        appl_callstack_get_report_length(
            p_context);

    if (
        i_length)
    {
        static unsigned char g_report[1024u];

        unsigned char * const
            p_report_end =
            appl_callstack_read_report(
                p_context,
                g_report,
                g_report + sizeof(g_report));

        appl_print0(
            "callstack report [");

        appl_print(
            g_report,
            p_report_end);

        appl_print0(
            "]\n");

    }

    appl_callstack_leave(
        p_context,
        p_frame2);

    appl_callstack_leave(
        p_context,
        p_frame1);

} // appl_callstack_test_1()

/* end-of-file: appl_callstack_test.cpp */
