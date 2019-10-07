/* See LICENSE for license details */

/*

*/
struct appl_xlib_intf
{
    union appl_xlib_open_display_ptr
    {
        void *
            p_symbol;

        Display *
            (* p_function)(
                char const *
                    p_display_name0);

    } o_open_display;

    union appl_xlib_close_display_ptr
    {
        void *
            p_symbol;

        int
            (* p_function)(
                Display *
                    p_display);

    } o_close_display;

    // --

    union appl_xlib_default_screen_ptr
    {
        void *
            p_symbol;

        int
            (* p_function)(
                Display * const
                    p_display);

    } o_default_screen;

    union appl_xlib_display_width_ptr
    {
        void *
            p_symbol;

        int
            (* p_function)(
                Display * const
                    p_display,
                int const
                    i_screen_number);

    } o_display_width;

    // --

    union appl_xlib_display_height_ptr
    {
        void *
            p_symbol;

        int
            (* p_function)(
                Display * const
                    p_display,
                int const
                    i_screen_number);

    } o_display_height;

#define PADDING (APPL_SIZEOF_PTR)
#include <misc/appl_padding.h>

}; /* struct appl_xlib_intf */

/* end-of-file: appl_xlib_intf.h */
