/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <debug/appl_debug.h>

#include <appl_debug_handle.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

#include <debug/appl_debug_test.h>

#include <appl_unused.h>

#if defined APPL_OS_LINUX
#include <signal.h>
#endif /* #if defined APPL_OS_LINUX */

//
//
//
void
    appl_debug_test_1(
        struct appl_context * const
            p_context)
{
    appl_debug_print0(
        p_context,
        "debug_print0 number=[");

    appl_debug_print_number(
        p_context,
        666,
        0,
        0);

    appl_debug_print0(
        p_context,
        "]\n");

#if defined APPL_OS_LINUX
    signal(SIGINT, SIG_IGN);
#endif /* #if defined APPL_OS_LINUX */

    appl_debug_break(
        p_context);

#if defined APPL_OS_LINUX
    signal(SIGINT, SIG_DFL);
#endif /* #if defined APPL_OS_LINUX */

} // appl_debug_test_1()

//
//  Function: appl_debug_test_2
//
//  Description:
//      Unit testing for appl_debug base class.
//
//  Comments:
//      The base class is not normally tested unless a derived class has
//      forgotten to override some virtual methods.  Also the deleting
//      destructor of a base class is not normally called.
//
void
    appl_debug_test_2(
        struct appl_context * const
            p_context)
{
    struct appl_allocator *
        p_allocator;

    p_allocator =
        appl_context_get_allocator(
            p_context);

    class appl_debug *
        p_debug_base;

    enum appl_status
        e_status;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_debug_base));

    if (
        appl_status_ok
        == e_status)
    {
        static unsigned char const g_msg[] =
        {
            'y',
            'o',
            '!',
            '\n'
        };

        p_debug_base->v_print(
            g_msg,
            g_msg + sizeof(g_msg));

#if defined APPL_OS_LINUX
        signal(SIGINT, SIG_IGN);
#endif /* #if defined APPL_OS_LINUX */

        p_debug_base->v_break();

#if defined APPL_OS_LINUX
        signal(SIGINT, SIG_DFL);
#endif /* #if defined APPL_OS_LINUX */

        appl_delete(
            p_allocator,
            p_debug_base);
    }

} // appl_debug_test_2()

#else /* #if defined APPL_DEBUG */

typedef void appl_dummy;

#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_debug_test.cpp */
