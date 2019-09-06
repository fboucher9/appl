/* See LICENSE for license details */

/*

*/

#include <callstack/appl_callstack_service.h>

#include <appl_types.h>

#include <appl_status.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#include <appl_str.h>

#include <appl_unused.h>

#include <appl_convert.h>

static unsigned long int __thread g_frame = 0ul;

static unsigned char __thread g_stack[4096u];

union appl_callstack_ptr
{
    struct appl_callstack_frame *
        p_frame;

    unsigned char *
        p_uchar;

}; /* union appl_callstack_ptr */

//
//
//
static
struct appl_callstack_frame *
get_frame_handle(void)
{
    union appl_callstack_ptr
        o_callstack_ptr;

    o_callstack_ptr.p_uchar =
        g_stack + g_frame;

    return
        o_callstack_ptr.p_frame;

}

//
//
//
static
void
set_frame_ptr(
    unsigned char const * const
        p_copy_result)
{
    if (
        (
            p_copy_result >= g_stack)
        && (
            p_copy_result <= g_stack + sizeof(g_stack)))
    {
        g_frame =
            p_copy_result
            - g_stack;
    }
}

//
//
//
static
void
set_frame_handle(
    struct appl_callstack_frame * const
        p_frame)
{
    union appl_callstack_ptr
        o_callstack_ptr;

    o_callstack_ptr.p_frame =
        p_frame;

    set_frame_ptr(
        o_callstack_ptr.p_uchar);
}

//
//
//
static
void
write_frame_char(
    unsigned char const
        c_data)
{
    if (g_frame < sizeof(g_stack))
    {
        g_stack[g_frame] = c_data;
        g_frame ++;
    }
}

//
//
//
static
void
write_frame_buffer(
    unsigned char const * const
        p_buffer_min,
    unsigned char const * const
        p_buffer_max)
{
    unsigned char * const
        p_copy_result =
        appl_str_copy(
            g_stack + g_frame,
            g_stack + sizeof(g_stack),
            p_buffer_min,
            p_buffer_max);

    set_frame_ptr(
        p_copy_result);
}

//
//
//
static
void
    write_frame_buffer0(
        char const * const
            p_buffer0)
{
    union appl_buf_ptr
        o_buffer0_ptr;

    o_buffer0_ptr.pc_char =
        p_buffer0;

    unsigned long int const
        i_buffer0_len =
        appl_buf0_len(
            o_buffer0_ptr.pc_uchar);

    write_frame_buffer(
        o_buffer0_ptr.pc_uchar,
        o_buffer0_ptr.pc_uchar + i_buffer0_len);
}

//
//
//
static
void
    write_frame_number(
        signed long int const
            i_value,
        int const
            i_flags,
        unsigned int const
            i_width)
{
    unsigned char const *
        p_print_result =
        appl_buf_print_number(
            g_stack + g_frame,
            g_stack + sizeof(g_stack),
            i_value,
            i_flags,
            i_width);

    set_frame_ptr(
        p_print_result);
}

//
//
//
struct appl_callstack_frame *
    appl_callstack_service::s_enter(
        struct appl_context * const
            p_context,
        char const * const
            p_buffer0)
{
    struct appl_callstack_frame * const
        p_frame =
        get_frame_handle();

    appl_unused(
        p_context);

    if (g_frame)
    {
        write_frame_char('\n');
    }

    write_frame_buffer0(
        p_buffer0);

    return
        p_frame;

} // s_enter()

//
//
//
void
    appl_callstack_service::s_print0(
        struct appl_context * const
            p_context,
        char const * const
            p_buffer0)
{
    appl_unused(
        p_context);

    write_frame_char(' ');

    write_frame_buffer0(p_buffer0);

} // s_print0()

//
//
//
void
    appl_callstack_service::s_print_buffer(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_buffer_min,
        unsigned char const * const
            p_buffer_max)
{
    appl_unused(
        p_context);

    write_frame_char(' ');

    write_frame_buffer(p_buffer_min, p_buffer_max);

} // s_print_buffer()

//
//
//
void
    appl_callstack_service::s_print_signed(
        struct appl_context * const
            p_context,
        signed long int const
            i_number)
{
    appl_unused(
        p_context);

    write_frame_char(' ');

    write_frame_number(i_number, 0, 0u);

} // s_print_signed()

//
//
//
void
    appl_callstack_service::s_print_unsigned(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_number)
{
    appl_unused(
        p_context);

    write_frame_char(' ');

    write_frame_number(
        appl_convert::to_signed(
            i_number),
        appl_buf_print_flag_unsigned,
        0u);

} // s_print_unsigned()

//
//
//
void
    appl_callstack_service::s_print_hexadecimal(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_number)
{
    appl_unused(
        p_context);

    write_frame_char(' ');

    write_frame_number(
        appl_convert::to_signed(
            i_number),
        appl_buf_print_flag_unsigned
        | appl_buf_print_flag_hex
        | appl_buf_print_flag_zero,
        8u);

} // s_print_hexadecimal()

//
//
//
void
    appl_callstack_service::s_leave(
        struct appl_context * const
            p_context,
        struct appl_callstack_frame * const
            p_frame)
{
    appl_unused(
        p_context);

    set_frame_handle(
        p_frame);

} // s_leave()

//
//
//
unsigned long int
    appl_callstack_service::s_get_report_length(
        struct appl_context * const
            p_context)
{
    appl_unused(
        p_context);

    return
        g_frame;

} // s_get_report_length()

//
//
//
unsigned char *
    appl_callstack_service::s_read_report(
        struct appl_context * const
            p_context,
        unsigned char * const
            p_report_min,
        unsigned char * const
            p_report_max)
{
    appl_unused(
        p_context);

    unsigned char * const
        p_copy_result =
        appl_str_copy(
            p_report_min,
            p_report_max,
            g_stack,
            g_stack + g_frame);

    return
        p_copy_result;

} // s_read_report()

/* end-of-file: appl_callstack_service.cpp */
