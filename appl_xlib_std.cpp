/* See LICENSE for license details */

/*

Module: appl_xlib_std.cpp

Description:

    Standard or POSIX implementation of appl_xlib interface.

*/

#if defined APPL_HAVE_XLIB

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <X11/Xlib.h>

#include <appl_xlib.h>

#include <appl_xlib_intf.h>

#include <appl_xlib_std.h>

#include <appl_allocator.h>

#include <appl_unused.h>

#include <appl_library_handle.h>

#include <appl_library_node.h>

#include <appl_mutex_handle.h>

#include <appl_mutex_node.h>

//
//
//
enum appl_status
    appl_xlib_std::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_xlib * * const
            r_instance)
{
    enum appl_status
        e_status;

    class appl_xlib_std *
        p_xlib_std;

    e_status =
        p_allocator->alloc_object(
            &(
                p_xlib_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_instance) =
            p_xlib_std;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_xlib_std::appl_xlib_std() :
    appl_xlib(),
    m_xlib_handle(),
    m_lock(),
    m_ref_count(1),
    m_xlib_intf()
{
}

//
//
//
appl_xlib_std::~appl_xlib_std()
{
}

//
//
//
enum appl_status
    appl_xlib_std::f_init(void)
{
    enum appl_status
        e_status;

    struct appl_library_descriptor
        o_xlib_library_descriptor;

    static unsigned char const g_xlib_name[] =
    {
        'X',
        '1',
        '1'
    };

    o_xlib_library_descriptor.p_name_min =
        g_xlib_name;

    o_xlib_library_descriptor.p_name_max =
        g_xlib_name + sizeof(g_xlib_name);

    struct appl_library *
        p_library;

    e_status =
        appl_library_create(
            m_context,
            &(
                o_xlib_library_descriptor),
            &(
                p_library));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_mutex_descriptor
            o_mutex_descriptor;

        struct appl_mutex *
            p_mutex;

        e_status =
            appl_mutex_create(
                m_context,
                &(
                    o_mutex_descriptor),
                &(
                    p_mutex));

        if (
            appl_status_ok
            == e_status)
        {
            m_xlib_handle =
                p_library;

            m_lock =
                p_mutex;

            if (
                appl_status_ok
                != e_status)
            {
                p_mutex->v_destroy();
            }
        }

        if (
            appl_status_ok
            != e_status)
        {
            p_library->v_destroy();
        }
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_xlib_std::v_add_ref(void)
{
    enum appl_status
        e_status;

    e_status =
        m_lock->v_lock();

    if (
        appl_status_ok
        == e_status)
    {
        if (1 == m_ref_count)
        {
            // Do init of library...
        }

        m_ref_count ++;

        m_lock->v_unlock();
    }

    return
        e_status;

} // v_add_ref()

//
//
//
Display *
appl_xlib_std::v_open_display(
    char const * const
        p_display_name0)
{
    appl_unused(
        p_display_name0);

    return
        0;

} // v_open_display()

//
//
//
int
appl_xlib_std::v_close_display(
    Display * const
        p_display)
{
    appl_unused(
        p_display);

    return
        -1;

} // v_close_display()

//
//
//
int
appl_xlib_std::v_default_screen(
    Display * const
        p_display)
{
    appl_unused(
        p_display);

    return
        0;

} // v_default_screen()

//
//
//
int
appl_xlib_std::v_display_width(
    int const
        i_screen_number)
{
    appl_unused(
        i_screen_number);

    return
        -1;

} // v_display_width()

//
//
//
int
appl_xlib_std::v_display_height(
    int const
        i_screen_number)
{
    appl_unused(
        i_screen_number);

    return
        -1;

} // v_display_height()

//
//
//
enum appl_status
    appl_xlib_std::v_cleanup(void)
{
    enum appl_status
        e_status;

    signed long int
        i_ref_count;

    m_ref_count --;

    i_ref_count =
        m_ref_count;

    if (
        0 >= i_ref_count)
    {
        // Do cleanup

        e_status =
            appl_status_ok;
    }
    else
    {
        // Release library
        if (
            1 == i_ref_count)
        {
        }

        // Keep object

        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_cleanup()

#endif /* #if defined APPL_HAVE_XLIB */

/* end-of-file: appl_xlib_std.cpp */
