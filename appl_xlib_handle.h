/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_XLIB_H
#error include appl_xlib.h once
#endif /* #if defined INC_APPL_XLIB_H */

#define INC_APPL_XLIB_H

/* Assert configuration */
#if ! defined APPL_HAVE_XLIB
#error include only if have XLIB
#endif /* #if ! defined APPL_HAVE_XLIB */

/* Header file dependency */
#if ! defined _X11_XLIB_H_
#error include <X11/Xlib.h> before
#endif /* #if ! defined _X11_XLIB_H_ */

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_xlib;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_xlib_create(
    struct appl_context * const
        p_context,
    struct appl_xlib * * const
        r_instance);

struct appl_object *
appl_xlib_parent(
    struct appl_xlib * const
        p_xlib);

/* Wrapper for XOpenDisplay() */
Display *
appl_xlib_open_display(
    struct appl_xlib * const
        p_xlib,
    char const * const
        p_display_name0);

/* Wrapper for XCloseDisplay() */
int
appl_xlib_close_display(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display);

/* Wrapper for XDefaultScreen */
int
appl_xlib_default_screen(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display);

/* Wrapper for XDisplayWidth */
int
appl_xlib_display_width(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display,
    int const
        i_screen_number);

/* Wrapper for XDisplayHeight */
int
appl_xlib_display_height(
    struct appl_xlib * const
        p_xlib,
    Display * const
        p_display,
    int const
        i_screen_number);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_xlib.h */
