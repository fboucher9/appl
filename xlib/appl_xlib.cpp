/* See LICENSE for license details */

/*

*/

#if defined APPL_HAVE_XLIB

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <X11/Xlib.h>

#include <xlib/appl_xlib.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
    appl_xlib::v_add_ref(void)
{
    return
        appl_raise_not_implemented();

} // v_add_ref()

//
//
//
Display *
appl_xlib::v_open_display(
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
appl_xlib::v_close_display(
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
appl_xlib::v_default_screen(
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
appl_xlib::v_display_width(
    Display * const
        p_display,
    int const
        i_screen_number)
{
    appl_unused(
        p_display,
        i_screen_number);

    return
        -1;

} // v_display_width()

//
//
//
int
appl_xlib::v_display_height(
    Display * const
        p_display,
    int const
        i_screen_number)
{
    appl_unused(
        p_display,
        i_screen_number);

    return
        -1;

} // v_display_height()

//
//
//
appl_xlib::appl_xlib(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_xlib::~appl_xlib()
{
}

#endif /* #if defined APPL_HAVE_XLIB */

/* end-of-file: appl_xlib.cpp */
