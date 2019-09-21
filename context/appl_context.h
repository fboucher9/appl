/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_context_h
{
    inc_appl_context_h = 1
        /* Header file dependencies */
        + inc_appl_object_h
        + inc_appl_predefines_h
};

#include <appl_assert_cplusplus.h>

struct appl_heap;

#if defined APPL_DEBUG
class appl_debug;
#endif /* #if defined APPL_DEBUG */

class appl_thread_mgr;

class appl_mutex_mgr;

class appl_file_mgr;

class appl_poll_mgr;

class appl_clock;

class appl_event_mgr;

class appl_socket_mgr;

struct appl_env;

class appl_library_mgr;

class appl_random_mgr;

class appl_thread_cache_mgr;

struct appl_log;

class appl_pool_mgr;

class appl_timer_mgr;

#if defined APPL_HAVE_XLIB
struct appl_xlib;
#endif /* #if defined APPL_HAVE_XLIB */

class appl_backtrace;

class appl_download_mgr;

//
//
//
struct appl_context : public appl_object
{
    public:

        appl_context(
            struct appl_context * const
                p_context);

        virtual
        ~appl_context();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        struct appl_allocator *
            v_allocator(void) const;

        virtual
        enum appl_status
            v_backtrace(
                class appl_backtrace * * const
                    r_backtrace) const;

        virtual
        enum appl_status
            v_thread_mgr(
                class appl_thread_mgr * * const
                    r_thread_mgr) const;

        virtual
        enum appl_status
            v_mutex_mgr(
                class appl_mutex_mgr * * const
                    r_mutex_mgr) const;

        virtual
        enum appl_status
            v_file_mgr(
                class appl_file_mgr * * const
                    r_file_mgr) const;

        virtual
        enum appl_status
            v_poll_mgr(
                class appl_poll_mgr * * const
                    r_poll_mgr) const;

        virtual
        enum appl_status
            v_clock(
                class appl_clock * * const
                    r_clock) const;

        virtual
        enum appl_status
            v_env(
                struct appl_env * * const
                    r_env) const;

        virtual
        enum appl_status
            v_library_mgr(
                class appl_library_mgr * * const
                    r_library_mgr);

        virtual
        enum appl_status
            v_random_mgr(
                class appl_random_mgr * * const
                    r_random_mgr) const;

        virtual
        enum appl_status
            v_thread_cache_mgr(
                class appl_thread_cache_mgr * * const
                    r_thread_cache_mgr) const;

        virtual
        enum appl_status
            v_log(
                struct appl_log * * const
                    r_log) const;

        virtual
        enum appl_status
            v_pool_mgr(
                class appl_pool_mgr * * const
                    r_pool_mgr) const;

        virtual
        enum appl_status
            v_timer_mgr(
                class appl_timer_mgr * * const
                    r_timer_mgr) const;

#if defined APPL_HAVE_XLIB
        virtual
        enum appl_status
            v_xlib(
                struct appl_xlib * * const
                    r_xlib) const;
#endif /* #if defined APPL_HAVE_XLIB */

        virtual
        enum appl_status
            v_socket_mgr(
                class appl_socket_mgr * * const
                    r_socket_mgr) const;

        virtual
        enum appl_status
            v_event_mgr(
                class appl_event_mgr * * const
                    r_event_mgr) const;

        virtual
        enum appl_status
            v_netdevice_mgr(
                class appl_netdevice_mgr * * const
                    r_netdevice_mgr) const;

        virtual
        enum appl_status
            v_download_mgr(
                class appl_download_mgr * * const
                    r_download_mgr) const;

#if defined APPL_DEBUG
        virtual
        enum appl_status
            v_debug(
                class appl_debug * * const
                    r_debug) const;
#endif /* #if defined APPL_DEBUG */

    protected:

    private:

        appl_context(
            struct appl_context const & r);

        struct appl_context &
            operator =(
                struct appl_context const & r);

}; // struct appl_context

/* end-of-file: appl_context.h */
