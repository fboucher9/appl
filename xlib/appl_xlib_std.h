/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_xlib_std_h
{
    inc_appl_xlib_std_h =
        /* Header file dependency */
        inc_appl_xlib_h
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
class appl_xlib_std : public appl_xlib
{
    public:

        // Context will create a single instance
        // Automatically destroyed on last release
        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_xlib * * const
                    r_instance);

        appl_xlib_std();

        virtual
        ~appl_xlib_std();

        enum appl_status
            f_init(void);

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

    private:

        // --

        struct appl_library *
            m_xlib_handle;

        struct appl_mutex *
            m_lock;

        // --

        signed long int
            m_ref_count;

        unsigned long int
            ul_padding[1u];

        // --

        struct appl_xlib_intf
            m_xlib_intf;

        // --

        bool
            m_xlib_handle_initialized;

        bool
            m_lock_initialized;

        unsigned char
            uc_padding[6u];

        // --

        appl_xlib_std(
            class appl_xlib_std const & r);

        class appl_xlib_std &
            operator =(
                class appl_xlib_std const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        enum appl_status
            f_init_library(void);

        void
            f_cleanup_library(void);

        enum appl_status
            f_init_open_display_function(void);

        enum appl_status
            f_init_close_display_function(void);

        enum appl_status
            f_init_default_screen_function(void);

        enum appl_status
            f_init_display_width_function(void);

        enum appl_status
            f_init_display_height_function(void);

        enum appl_status
            f_init_functions(void);

}; // class appl_xlib_std

/* end-of-file: appl_xlib_std.h */
