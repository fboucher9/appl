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

#include <appl_unused.h>

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

#else /* #if defined APPL_DEBUG */

typedef void appl_dummy;

#endif /* #if defined APPL_DEBUG */
