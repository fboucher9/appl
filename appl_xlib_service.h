/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_XLIB_SERVICE_H
#error include appl_xlib_service.h once
#endif /* #if defined INC_APPL_XLIB_SERVICE_H */

#define INC_APPL_XLIB_SERVICE_H

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_xlib_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_xlib * * const
                r_instance);

        static
        struct appl_object *
        s_parent(
            struct appl_xlib * const
                p_xlib);

        static
        Display *
        s_open_display(
            struct appl_xlib * const
                p_xlib,
            char const * const
                p_display_name0);

        static
        int
        s_close_display(
            struct appl_xlib * const
                p_xlib,
            Display * const
                p_display);

        static
        int
        s_default_screen(
            struct appl_xlib * const
                p_xlib,
            Display * const
                p_display);

        static
        int
        s_display_width(
            struct appl_xlib * const
                p_xlib,
            int const
                i_screen_number);

        static
        int
        s_display_height(
            struct appl_xlib * const
                p_xlib,
            int const
                i_screen_number);

}; // class appl_xlib_service

/* end-of-file: appl_xlib_service.h */
