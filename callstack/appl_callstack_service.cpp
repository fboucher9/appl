/* See LICENSE for license details */

/*

*/

#include <appl_predefines.h>

#include <callstack/appl_callstack_service.h>

#include <appl_types.h>

#include <appl_status.h>

#include <buf/appl_buf.h>

#include <buf/appl_buf0.h>

#include <buf/appl_str.h>

#include <misc/appl_unused.h>

#include <misc/appl_convert.h>

#include <clock/appl_clock_handle.h>

#define APPL_CALLSTACK_FRAMES (64u)

#define APPL_CALLSTACK_TEXT_SIZE (4096u)

static unsigned long int __thread g_callstack_index = 0ul;

static unsigned long int __thread g_callstack_stack[APPL_CALLSTACK_FRAMES];

static unsigned long int __thread g_callstack_level = 0ul;

static unsigned char __thread g_callstack_text[APPL_CALLSTACK_TEXT_SIZE];

//
//
//
static
void
push_frame_index(void)
{
    if (
        g_callstack_level
        < appl_convert::to_ulong(sizeof(g_callstack_stack)))
    {
        g_callstack_stack[g_callstack_level] =
            g_callstack_index;
    }

    g_callstack_level ++;
}

//
//
//
static
void
pop_frame_index(void)
{
    if (
        g_callstack_level)
    {
        g_callstack_level --;

        if (
            g_callstack_level
            < appl_convert::to_ulong(sizeof(g_callstack_stack)))
        {
            g_callstack_index = g_callstack_stack[g_callstack_level];
        }
    }
}

//
//
//
static
void
set_text_ptr(
    unsigned char const * const
        p_copy_result)
{
    if (
        (
            p_copy_result >= g_callstack_text)
        && (
            p_copy_result <= g_callstack_text + sizeof(g_callstack_text)))
    {
        g_callstack_index =
            appl_convert::to_ulong(
                appl_convert::to_unsigned(
                    p_copy_result
                    - g_callstack_text));
    }
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
    if (g_callstack_index < sizeof(g_callstack_text))
    {
        g_callstack_text[g_callstack_index] = c_data;
        g_callstack_index ++;
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
            g_callstack_text + g_callstack_index,
            g_callstack_text + sizeof(g_callstack_text),
            p_buffer_min,
            p_buffer_max);

    set_text_ptr(
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
            g_callstack_text + g_callstack_index,
            g_callstack_text + sizeof(g_callstack_text),
            i_value,
            i_flags,
            i_width);

    set_text_ptr(
        p_print_result);
}

//
//
//
void
    appl_callstack_service::s_enter(
        struct appl_context * const
            p_context,
        char const * const
            p_buffer0)
{
    push_frame_index();

    appl_unused(
        p_context);

    if (g_callstack_index)
    {
        write_frame_char('\n');
    }

    appl_ull_t
        i_clock_value;

    if (
        appl_status_ok
        == appl_clock_read(
            p_context,
            1000ul,
            &(i_clock_value)))
    {
        write_frame_number(
            appl_convert::to_signed(
                appl_convert::to_ulong(
                    i_clock_value / 1000ul)),
            appl_buf_print_flag_unsigned,
            0);

        write_frame_char('.');

        write_frame_number(
            appl_convert::to_signed(
                appl_convert::to_ulong(
                    i_clock_value % 1000ul)),
            appl_buf_print_flag_unsigned
            | appl_buf_print_flag_zero,
            3);

        write_frame_char(':');
    }

    write_frame_buffer0(
        p_buffer0);

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
            p_context)
{
    appl_unused(
        p_context);

    pop_frame_index();

} // s_leave()

//
//
//
void
    appl_callstack_service::s_report(
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
    appl_unused(
        p_context);

    (*p_callback)(
        p_callback_data,
        g_callstack_text,
        g_callstack_text + g_callstack_index);

} // s_report()

/* end-of-file: appl_callstack_service.cpp */
