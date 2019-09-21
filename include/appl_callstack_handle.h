/* See LICENSE for license details */

/*

Module: appl_callstack_handle.h

Description:

    Store information about callstack, for use with logs.  This module may
    be used in release build without any debug symbol information.

Notes:

    Sample callstack usage:

        void appl_demo_function(
            unsigned long int const
                i_value)
        {
            appl_callstack_enter("demo function");

            appl_callstack_print_unsigned(i_value);

            appl_callstack_report();

            appl_callstack_leave();
        }

    Sample report output:

        function1 param1 1234 0xfeed
        function2
        function3 true

*/

/* Reverse include guard */
enum guard_appl_callstack_h
{
    inc_appl_callstack_h = 1
        /* Header file dependencies */

}; /* enum guard_appl_callstack_h */

#include <appl_extern_c_begin.h>

void
    appl_callstack_enter(
        struct appl_context * const
            p_context,
        char const * const
            p_buffer0);

void
    appl_callstack_print0(
        struct appl_context * const
            p_context,
        char const * const
            p_buffer0);

void
    appl_callstack_print_buffer(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_buffer_min,
        unsigned char const * const
            p_buffer_max);

void
    appl_callstack_print_signed(
        struct appl_context * const
            p_context,
        signed long int const
            i_number);

void
    appl_callstack_print_unsigned(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_number);

void
    appl_callstack_print_hexadecimal(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_number);

void
    appl_callstack_leave(
        struct appl_context * const
            p_context);

void
    appl_callstack_report(
        struct appl_context * const
            p_context,
        void (* p_callback)(
            void * const
                p_callback_data,
            unsigned char const * const
                p_report_min,
            unsigned char const * const
                p_report_max),
        void * const
            p_callback_data);

#include <appl_extern_c_end.h>

/* end-of-file: appl_callstack_handle.h */
