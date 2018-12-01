/* See LICENSE for license details */

/*

*/

#if defined APPL_HAVE_XLIB

#include <appl_status.h>

#include <appl_types.h>

#include <X11/Xlib.h>

#include <xlib/appl_xlib_service.h>

#include <appl_object.h>

#include <xlib/appl_xlib.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
appl_xlib_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_xlib * * const
        r_instance)
{
    enum appl_status
        e_status;

    struct appl_xlib * const
        p_xlib =
        p_context->m_xlib;

    e_status =
        p_xlib->v_add_ref();

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_instance) =
            p_xlib;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_xlib_service::s_destroy(
    struct appl_xlib * const
        p_xlib)
{
    struct appl_context * const
        p_context =
        p_xlib->get_context();

    return
        p_xlib->v_destroy(
            p_context->m_allocator);

} // s_destroy()

//
//
//
struct appl_object *
appl_xlib_service::s_parent(
    struct appl_xlib * const
        p_xlib)
{
    return
        p_xlib;

} // s_parent()

//
//
//
Display *
appl_xlib_service::s_open_display(
    struct appl_xlib * const
        p_xlib,
    char const * const
        p_display_name0)
{
    return
        p_xlib->v_open_display(
            p_display_name0);

} // s_open_display()

//
//
//
int
appl_xlib_service::s_close_display(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display)
{
    return
        p_xlib->v_close_display(
            p_display);

} // s_close_display()

//
//
//
int
appl_xlib_service::s_default_screen(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display)
{
    return
        p_xlib->v_default_screen(
            p_display);

} // s_default_screen()

//
//
//
int
appl_xlib_service::s_display_width(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display,
    int const
        i_screen_number)
{
    return
        p_xlib->v_display_width(
            p_display,
            i_screen_number);

} // s_display_width()

//
//
//
int
appl_xlib_service::s_display_height(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display,
    int const
        i_screen_number)
{
    return
        p_xlib->v_display_height(
            p_display,
            i_screen_number);

} // s_display_height()

#endif /* #if defined APPL_HAVE_XLIB */

/* end-of-file: appl_xlib_service.cpp */
