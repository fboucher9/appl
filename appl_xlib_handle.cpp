/* See LICENSE for license details */

/*

*/

#if defined APPL_HAVE_XLIB

#include <appl_status.h>

#include <X11/Xlib.h>

#include <appl_xlib_handle.h>

#include <appl_xlib_service.h>

/*

*/
enum appl_status
appl_xlib_create(
    struct appl_context * const
        p_context,
    struct appl_xlib * * const
        r_instance)
{
    return
        appl_xlib_service::s_create(
            p_context,
            r_instance);

} /* _create() */

/*

*/
struct appl_object *
appl_xlib_parent(
    struct appl_xlib * const
        p_xlib)
{
    return
        appl_xlib_service::s_parent(
            p_xlib);

} /* _parent() */

/*

*/
Display *
appl_xlib_open_display(
    struct appl_xlib * const
        p_xlib,
    char const * const
        p_display_name0)
{
    return
        appl_xlib_service::s_open_display(
            p_xlib,
            p_display_name0);

} /* _open_display() */

/*

*/
int
appl_xlib_close_display(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display)
{
    return
        appl_xlib_service::s_close_display(
            p_xlib,
            p_display);

} /* _close_display() */

/*

*/
int
appl_xlib_default_screen(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display)
{
    return
        appl_xlib_service::s_default_screen(
            p_xlib,
            p_display);

} /* _default_screen() */

/*

*/
int
appl_xlib_display_width(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display,
    int const
        i_screen_number)
{
    return
        appl_xlib_service::s_display_width(
            p_xlib,
            p_display,
            i_screen_number);

} /* _display_width() */

/*

*/
int
appl_xlib_display_height(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display,
    int const
        i_screen_number)
{
    return
        appl_xlib_service::s_display_height(
            p_xlib,
            p_display,
            i_screen_number);

} /* _display_height() */

#endif /* #if defined APPL_HAVE_XLIB */

/* end-of-file: appl_xlib_handle.cpp */
