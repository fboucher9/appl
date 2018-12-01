/* See LICENSE for license details */

/*

*/

#if defined APPL_HAVE_XLIB

#include <stdio.h>

#include <X11/Xlib.h>

#define APPL_CONFIG_WITH_XLIB

#include <appl.h>

#include <xlib/appl_xlib_test.h>

/*

*/
enum appl_status
appl_xlib_test_1(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_xlib *
        p_xlib;

    e_status =
        appl_xlib_create(
            p_context,
            &(
                p_xlib));

    if (
        appl_status_ok
        == e_status)
    {
        Display *
            p_xlib_display;

        p_xlib_display =
            appl_xlib_open_display(
                p_xlib,
                NULL);

        if (
            p_xlib_display)
        {
            int
                i_screen_index;

            int
                i_display_width;

            int
                i_display_height;

            i_screen_index =
                appl_xlib_default_screen(
                    p_xlib,
                    p_xlib_display);

            i_display_width =
                appl_xlib_display_width(
                    p_xlib,
                    p_xlib_display,
                    i_screen_index);

            i_display_height =
                appl_xlib_display_height(
                    p_xlib,
                    p_xlib_display,
                    i_screen_index);

            printf("x11: [%d] %dx%d\n",
                i_screen_index,
                i_display_width,
                i_display_height);

            appl_xlib_close_display(
                p_xlib,
                p_xlib_display);
        }

        appl_xlib_destroy(
            p_xlib);
    }

    return
        e_status;

} /* appl_xlib_test_1() */

#else /* #if defined APPL_HAVE_XLIB */

typedef void appl_dummy;

#endif /* #if defined APPL_HAVE_XLIB */

/* end-of-file: appl_xlib_test.c */
