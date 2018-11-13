/* See LICENSE for license details */

/*

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
    return
        appl_status_ok;

} // f_init()

//
//
//
enum appl_status
    appl_xlib_std::v_add_ref(void)
{
    return
        appl_status_not_implemented;

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
Screen *
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
