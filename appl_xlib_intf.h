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

        Screen *
            (* p_function)(
                struct appl_xlib * const
                    p_xlib,
                Display * const
                    p_display);

    } o_default_screen;

    union appl_xlib_display_width_ptr
    {
        void *
            p_symbol;

        int
            (* p_function)(
                struct appl_xlib * const
                    p_xlib,
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
                struct appl_xlib * const
                    p_xlib,
                int const
                    i_screen_number);

    } o_display_height;

    void *
        pv_padding[1u];

}; /* struct appl_xlib_intf */

/* end-of-file: appl_xlib_intf.h */
