/* See LICENSE for license details */

/*

Module: appl_xlib_std.cpp

Description:

    Standard or POSIX implementation of appl_xlib interface.

*/

#if defined APPL_HAVE_XLIB

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <X11/Xlib.h>

#include <xlib/appl_xlib.h>

#include <xlib/appl_xlib_intf.h>

#include <xlib/appl_xlib_std.h>

#include <appl_allocator_handle.h>

#include <appl_library_handle.h>

#include <appl_mutex_handle.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_xlib_std::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_xlib * * const
            r_instance)
{
    enum appl_status
        e_status;

    class appl_xlib_std *
        p_xlib_std;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_xlib_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_instance) =
            p_xlib_std;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_xlib_std::appl_xlib_std(
    struct appl_context * const
        p_context) :
    appl_xlib(
        p_context),
    m_xlib_handle(),
    m_lock(),
    m_xlib_intf(),
    m_ref_count(1),
    m_xlib_handle_initialized(),
    m_lock_initialized()
{
}

//
//
//
appl_xlib_std::~appl_xlib_std()
{
}

//
//
//
enum appl_status
    appl_xlib_std::f_init_library(void)
{
    enum appl_status
        e_status;

    if (
        !m_xlib_handle_initialized)
    {
        struct appl_library_descriptor
            o_xlib_library_descriptor;

        static unsigned char const g_xlib_name[] =
        {
            'l',
            'i',
            'b',
            'X',
            '1',
            '1',
            '.',
            's',
            'o',
            '.',
            '6'
        };

        o_xlib_library_descriptor.p_name_min =
            g_xlib_name;

        o_xlib_library_descriptor.p_name_max =
            g_xlib_name + sizeof(g_xlib_name);

        struct appl_library *
            p_library;

        e_status =
            appl_library_create(
                m_context,
                &(
                    o_xlib_library_descriptor),
                &(
                    p_library));

        if (
            appl_status_ok
            == e_status)
        {
            m_xlib_handle =
                p_library;

            m_xlib_handle_initialized =
                true;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_init_library()

//
//
//
void
    appl_xlib_std::f_cleanup_library(void)
{
    if (
        m_xlib_handle_initialized)
    {
        appl_library_destroy(
            m_xlib_handle);

        m_xlib_handle =
            0;

        m_xlib_handle_initialized =
            false;
    }
} // f_cleanup_library()

//
//
//
enum appl_status
    appl_xlib_std::f_init_open_display_function(void)
{
    enum appl_status
        e_status;

    /* XOpenDisplay */
    static unsigned char const g_open_display_name[] =
    {
        'X',
        'O',
        'p',
        'e',
        'n',
        'D',
        'i',
        's',
        'p',
        'l',
        'a',
        'y'
    };

    e_status =
        appl_library_query(
            m_xlib_handle,
            g_open_display_name,
            g_open_display_name + sizeof(g_open_display_name),
            &(
                m_xlib_intf.o_open_display.p_symbol));

    if (
        appl_status_ok
        == e_status)
    {
    }
#if defined APPL_DEBUG
    else
    {
        static char const g_msg0[] = "failed dlsym of XOpenDisplay\n";
        appl_debug_print0(m_context, g_msg0);
    }
#endif /* #if defined APPL_DEBUG */

    return
        e_status;

} // f_init_open_display_function()

//
//
//
enum appl_status
    appl_xlib_std::f_init_close_display_function(void)
{
    enum appl_status
        e_status;

    /* XCloseDisplay */
    static unsigned char const g_close_display_name[] =
    {
        'X',
        'C',
        'l',
        'o',
        's',
        'e',
        'D',
        'i',
        's',
        'p',
        'l',
        'a',
        'y'
    };

    e_status =
        appl_library_query(
            m_xlib_handle,
            g_close_display_name,
            g_close_display_name + sizeof(g_close_display_name),
            &(
                m_xlib_intf.o_close_display.p_symbol));

    if (
        appl_status_ok
        == e_status)
    {
    }
#if defined APPL_DEBUG
    else
    {
        static char const g_msg0[] = "failed dlsym of XCloseDisplay\n";
        appl_debug_print0(m_context, g_msg0);
    }
#endif /* #if defined APPL_DEBUG */

    return
        e_status;

} // f_init_close_display_function()

//
//
//
enum appl_status
    appl_xlib_std::f_init_default_screen_function(void)
{
    enum appl_status
        e_status;

    /* XDefaultScreen */
    static unsigned char const g_default_screen_name[] =
    {
        'X',
        'D',
        'e',
        'f',
        'a',
        'u',
        'l',
        't',
        'S',
        'c',
        'r',
        'e',
        'e',
        'n'
    };

    e_status =
        appl_library_query(
            m_xlib_handle,
            g_default_screen_name,
            g_default_screen_name + sizeof(g_default_screen_name),
            &(
                m_xlib_intf.o_default_screen.p_symbol));

    if (
        appl_status_ok
        == e_status)
    {
    }
#if defined APPL_DEBUG
    else
    {
        static char const g_msg0[] = "failed dlsym of XDefaultScreen\n";
        appl_debug_print0(m_context, g_msg0);
    }
#endif /* #if defined APPL_DEBUG */

    return
        e_status;

} // f_init_default_screen_function()

//
//
//
enum appl_status
    appl_xlib_std::f_init_display_width_function(void)
{
    enum appl_status
        e_status;

    /* XDisplayWidth */
    static unsigned char const g_display_width_name[] =
    {
        'X',
        'D',
        'i',
        's',
        'p',
        'l',
        'a',
        'y',
        'W',
        'i',
        'd',
        't',
        'h'
    };

    e_status =
        appl_library_query(
            m_xlib_handle,
            g_display_width_name,
            g_display_width_name + sizeof(g_display_width_name),
            &(
                m_xlib_intf.o_display_width.p_symbol));

    if (
        appl_status_ok
        == e_status)
    {
    }
#if defined APPL_DEBUG
    else
    {
        static char const g_msg0[] = "failed dlsym of XDisplayWidth\n";
        appl_debug_print0(m_context, g_msg0);
    }
#endif /* #if defined APPL_DEBUG */

    return
        e_status;

} // f_init_display_width_function()

//
//
//
enum appl_status
    appl_xlib_std::f_init_display_height_function(void)
{
    enum appl_status
        e_status;

    /* XDisplayHeight */
    static unsigned char const g_display_height_name[] =
    {
        'X',
        'D',
        'i',
        's',
        'p',
        'l',
        'a',
        'y',
        'H',
        'e',
        'i',
        'g',
        'h',
        't'
    };

    e_status =
        appl_library_query(
            m_xlib_handle,
            g_display_height_name,
            g_display_height_name + sizeof(g_display_height_name),
            &(
                m_xlib_intf.o_display_height.p_symbol));

    if (
        appl_status_ok
        == e_status)
    {
    }
#if defined APPL_DEBUG
    else
    {
        static char const g_msg0[] = "failed dlsym of XDisplayHeight\n";
        appl_debug_print0(m_context, g_msg0);
    }
#endif /* #if defined APPL_DEBUG */

    return
        e_status;

} // f_init_display_height_function()

//
//
//
enum appl_status
    appl_xlib_std::f_init_functions(void)
{
    enum appl_status
        e_status;

    e_status =
        f_init_open_display_function();

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            f_init_close_display_function();

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                f_init_default_screen_function();

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    f_init_display_width_function();

                if (
                    appl_status_ok
                    == e_status)
                {
                    e_status =
                        f_init_display_height_function();
                }
            }
        }
    }

    return
        e_status;

} // f_init_functions()

//
//
//
enum appl_status
    appl_xlib_std::f_init(void)
{
    enum appl_status
        e_status;

    e_status =
        f_init_library();

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_mutex_descriptor
            o_mutex_descriptor;

        struct appl_mutex *
            p_mutex;

        e_status =
            appl_mutex_create(
                m_context,
                &(
                    o_mutex_descriptor),
                &(
                    p_mutex));

        if (
            appl_status_ok
            == e_status)
        {
            m_lock =
                p_mutex;

            m_lock_initialized =
                true;

            e_status =
                f_init_functions();

            if (
                appl_status_ok
                != e_status)
            {
                appl_mutex_destroy(
                    m_lock);

                m_lock_initialized =
                    false;
            }
        }
#if defined APPL_DEBUG
        else
        {
            static char const g_msg0[] = "failed to create mutex for xlib\n";
            appl_debug_print0(m_context, g_msg0);
        }
#endif /* #if defined APPL_DEBUG */

        if (
            appl_status_ok
            != e_status)
        {
            f_cleanup_library();
        }
    }
#if defined APPL_DEBUG
    else
    {
        static char const g_msg0[] = "failed dlopen of xlib\n";
        appl_debug_print0(m_context, g_msg0);
    }
#endif /* #if defined APPL_DEBUG */

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_xlib_std::v_add_ref(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_lock(m_lock);

    if (
        appl_status_ok
        == e_status)
    {
        if (1 == m_ref_count)
        {
            // Do init of library...
        }

        m_ref_count ++;

        appl_mutex_unlock(m_lock);
    }

    return
        e_status;

} // v_add_ref()

//
//
//
Display *
appl_xlib_std::v_open_display(
    char const * const
        p_display_name0)
{
    return
        (*(m_xlib_intf.o_open_display.p_function))(
            p_display_name0);

} // v_open_display()

//
//
//
int
appl_xlib_std::v_close_display(
    Display * const
        p_display)
{
    return
        (*(m_xlib_intf.o_close_display.p_function))(
            p_display);

} // v_close_display()

//
//
//
int
appl_xlib_std::v_default_screen(
    Display * const
        p_display)
{
    return
        (*(m_xlib_intf.o_default_screen.p_function))(
            p_display);

} // v_default_screen()

//
//
//
int
appl_xlib_std::v_display_width(
    Display * const
        p_display,
    int const
        i_screen_number)
{
    return
        (*(m_xlib_intf.o_display_width.p_function))(
            p_display,
            i_screen_number);

} // v_display_width()

//
//
//
int
appl_xlib_std::v_display_height(
    Display * const
        p_display,
    int const
        i_screen_number)
{
    return
        (*(m_xlib_intf.o_display_height.p_function))(
            p_display,
            i_screen_number);

} // v_display_height()

//
//
//
appl_size_t
    appl_xlib_std::v_cleanup(void)
{
    appl_size_t
        i_result;

    if (
        m_ref_count)
    {
        m_ref_count --;

        signed long int
            i_ref_count;

        i_ref_count =
            m_ref_count;

        if (
            0 == i_ref_count)
        {
            // Do cleanup
            f_cleanup_library();

            if (m_lock_initialized)
            {
                appl_mutex_destroy(
                    m_lock);

                m_lock =
                    0;

                m_lock_initialized =
                    false;
            }

            i_result =
                sizeof(class appl_xlib_std);
        }
        else
        {
            // Release library
            if (
                1 == i_ref_count)
            {
            }

            // Keep object

            i_result =
                0;
        }
    }
    else
    {
        i_result =
            0;
    }

    return
        i_result;

} // v_cleanup()

#endif /* #if defined APPL_HAVE_XLIB */

/* end-of-file: appl_xlib_std.cpp */
