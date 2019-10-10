/* See LICENSE for license details */

/*

*/

#include <appl_predefines.h>

#include <callstack/appl_callstack_handle.h>

#include <callstack/appl_callstack_service.h>

//
//
//
void
    appl_callstack_enter(
        struct appl_context * const
            p_context,
        char const * const
            p_buffer0)
{
    appl_callstack_service::s_enter(
        p_context,
        p_buffer0);

} // appl_callstack_enter()

//
//
//
void
    appl_callstack_print0(
        struct appl_context * const
            p_context,
        char const * const
            p_buffer0)
{
    appl_callstack_service::s_print0(
        p_context,
        p_buffer0);

} // appl_callstack_print0()

//
//
//
void
    appl_callstack_print_buffer(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_buffer_min,
        unsigned char const * const
            p_buffer_max)
{
    appl_callstack_service::s_print_buffer(
        p_context,
        p_buffer_min,
        p_buffer_max);

} // appl_callstack_print_buffer()

//
//
//
void
    appl_callstack_print_signed(
        struct appl_context * const
            p_context,
        signed long int const
            i_number)
{
    appl_callstack_service::s_print_signed(
        p_context,
        i_number);

} // appl_callstack_print_signed()

//
//
//
void
    appl_callstack_print_unsigned(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_number)
{
    appl_callstack_service::s_print_unsigned(
        p_context,
        i_number);

} // appl_callstack_print_unsigned()

//
//
//
void
    appl_callstack_print_hexadecimal(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_number)
{
    appl_callstack_service::s_print_hexadecimal(
        p_context,
        i_number);

} // appl_callstack_print_hexadecimal()

//
//
//
void
    appl_callstack_leave(
        struct appl_context * const
            p_context)
{
    appl_callstack_service::s_leave(
        p_context);

} // appl_callstack_leave()

//
//
//
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
            p_callback_data)
{
    appl_callstack_service::s_report(
        p_context,
        p_callback,
        p_callback_data);

} // appl_callstack_report()

/* end-of-file: appl_callstack_handle.cpp */
