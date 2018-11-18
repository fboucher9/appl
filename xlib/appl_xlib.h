/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_xlib_h
{
    inc_appl_xlib_h =
        /* Header file dependency */
        inc_appl_object_h
};

/* Assert configuration */
#if ! defined APPL_HAVE_XLIB
#error must have XLIB
#endif /* #if ! defined APPL_HAVE_XLIB */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_xlib : public appl_object
{
    public:

        virtual
        enum appl_status
            v_add_ref(void);

        virtual
        Display *
        v_open_display(
            char const * const
                p_display_name0);

        virtual
        int
        v_close_display(
            Display * const
                p_display);

        virtual
        int
        v_default_screen(
            Display * const
                p_display);

        virtual
        int
        v_display_width(
            Display * const
                p_display,
            int const
                i_screen_number);

        virtual
        int
        v_display_height(
            Display * const
                p_display,
            int const
                i_screen_number);

    protected:

        appl_xlib();

        virtual
        ~appl_xlib();

    private:

        appl_xlib(
            struct appl_xlib const & r);

        struct appl_xlib &
            operator =(
                struct appl_xlib const & r);

}; // struct appl_xlib

/* end-of-file: appl_xlib.h */
