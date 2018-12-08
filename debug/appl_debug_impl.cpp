/* See LICENSE for license details */

/*

Module: appl_debug_impl.cpp

Description:

    OS-specific debugging functions to be used from implementation of
    appl_debug or from other appl modules.

*/

#if defined APPL_DEBUG

#include <debug/appl_debug_impl.h>

#include <appl_buf.h>

#include <appl_status.h>

#include <appl_buf0.h>

#include <appl_unused.h>

#include <appl_convert.h>

#undef NDEBUG
#include <assert.h>

#include <stdio.h>

//
//
//
void
    appl_debug_impl::s_break(void)
{
    assert(0);
} // s_break()

//
//
//
void
    appl_debug_impl::s_print(
        unsigned char const * const
            p_message_min,
        unsigned char const * const
            p_message_max)
{
    fwrite(
        p_message_min,
        1,
        appl_buf_len(
            p_message_min,
            p_message_max),
        stderr);
} // s_print()

//
//
//
void
    appl_debug_impl::s_print0(
        char const * const
            p_message0)
{
    unsigned char const * const
        pc_uchar =
        appl_convert::to_uchar_ptr(
            p_message0);

    appl_debug_impl::s_print(
        pc_uchar,
        pc_uchar + appl_buf0_len(
            pc_uchar));

} // s_print0()

#else /* #if defined APPL_DEBUG */

typedef void appl_dummy;

#endif /* #if defined APPL_DEBUG */
