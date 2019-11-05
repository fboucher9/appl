/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_CONTEXT_STD_H

/* Reverse include guard */
enum guard_appl_context_std_h
{
    inc_appl_context_std_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_context_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_context_std : public appl_context
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * * const
                    r_context);

        static
        enum appl_status
            s_destroy(
                struct appl_context * const
                    p_context);

        appl_context_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_context_std();

        enum appl_status
            f_init(void);

    protected:

        virtual
        appl_size_t
            v_cleanup(void);

    private:

        static
        struct init_cleanup_item
        {
            enum appl_status
                (appl_context_std::* p_init)(void);

            void
                (appl_context_std::* p_cleanup)(void);

        }
        const
        g_init_cleanup_items[];

        /* -- */

        class appl_heap_std
            m_heap_std;

        /* -- */

        struct appl_allocator *
            m_allocator;

        void *
            z_allocator[1u];

        /* -- */

        class appl_backtrace *
            m_backtrace;

        class appl_thread_mgr *
            m_thread_mgr;

        /* -- */

        class appl_mutex_mgr *
            m_mutex_mgr;

        class appl_file_mgr *
            m_file_mgr;

        /* -- */

        class appl_poll_mgr *
            m_poll_mgr;

        class appl_clock *
            m_clock;

        /* -- */

        struct appl_env *
            m_env;

        class appl_library_mgr *
            m_library_mgr;

        /* -- */

        class appl_random_mgr *
            m_random_mgr;

        class appl_thread_cache_mgr *
            m_thread_cache_mgr;

        /* -- */

        struct appl_log *
            m_log;

        class appl_pool_mgr *
            m_pool_mgr;

        /* -- */

        class appl_timer_mgr *
            m_timer_mgr;

#if defined APPL_HAVE_XLIB
        struct appl_xlib *
            m_xlib;
#else /* #if defined APPL_HAVE_XLIB */
        void *
            z_xlib[1u];
#endif /* #if defined APPL_HAVE_XLIB */

        /* -- */

        class appl_event_mgr *
            m_event_mgr;

        class appl_socket_mgr *
            m_socket_mgr;

        /* -- */

        class appl_netdevice_mgr *
            m_netdevice_mgr;

        class appl_download_mgr *
            m_download_mgr;

        /* -- */

        class appl_dir_mgr *
            m_dir_mgr;

        class appl_unique_mgr *
            m_unique_mgr;

        /* -- */

#if defined APPL_DEBUG
        class appl_heap_dbg *
            m_heap_dbg;

        class appl_debug *
            m_debug;
#endif /* #if defined APPL_DEBUG */

        /* -- */

        bool
            b_init_allocator;

#if defined APPL_DEBUG
        bool
            b_init_debug;
#else /* #if defined APPL_DEBUG */
        bool
            z_init_debug[1u];
#endif /* #if defined APPL_DEBUG */

        bool
            b_init_thread_mgr;

        bool
            b_init_mutex_mgr;

        bool
            b_init_file_mgr;

        bool
            b_init_poll_mgr;

        bool
            b_init_clock;

        bool
            b_init_event_mgr;

        /* -- */

        bool
            b_init_socket_mgr;

        bool
            b_init_env;

        bool
            b_init_library_mgr;

        bool
            b_init_random_mgr;

        bool
            b_init_log;

        bool
            b_init_pool_mgr;

        bool
            b_init_thread_cache_mgr;

        bool
            b_init_timer_mgr;

        /* -- */

#if defined APPL_HAVE_XLIB
        bool
            b_init_xlib;
#else /* #if defined APPL_HAVE_XLIB */
        unsigned char
            z_init_xlib[1u];
#endif /* #if defined APPL_HAVE_XLIB */

        bool
            b_init_backtrace;

        bool
            b_init_netdevice_mgr;

        bool
            b_init_download_mgr;

        bool
            b_init_dir_mgr;

        bool
            b_init_unique_mgr;

#define PADDING (6)
#include <misc/appl_padding.h>

        /* -- */

        appl_context_std(
            class appl_context_std const & r);

        class appl_context_std &
            operator =(
                class appl_context_std const & r);

        enum appl_status
            init_heap(void);

        void
            cleanup_heap(void);

#if defined APPL_DEBUG
        enum appl_status
            init_debug(void);
#endif /* #if defined APPL_DEBUG */

#if defined APPL_DEBUG
        void
            cleanup_debug(void);
#endif /* #if defined APPL_DEBUG */

        enum appl_status
            finalize_heap(void);

        void
            shutdown_heap(void);

        enum appl_status
            init_options(
                struct appl_context_descriptor const * const
                    p_context_descriptor);

        void
            cleanup_options(void);

        enum appl_status
            init_thread_mgr(void);

        void
            cleanup_thread_mgr(void);

        enum appl_status
            init_mutex_mgr(void);

        void
            cleanup_mutex_mgr(void);

        enum appl_status
            init_file_mgr(void);

        void
            cleanup_file_mgr(void);

#if 0
        enum appl_status
            init_poll_mgr(void);

        void
            cleanup_poll_mgr(void);
#endif

        enum appl_status
            init_clock(void);

        void
            cleanup_clock(void);

        enum appl_status
            init_event_mgr(void);

        void
            cleanup_event_mgr(void);

        enum appl_status
            init_socket_mgr(void);

        void
            cleanup_socket_mgr(void);

        enum appl_status
            init_env(void);

        void
            cleanup_env(void);

        enum appl_status
            init_library_mgr(void);

        void
            cleanup_library_mgr(void);

        enum appl_status
            init_random_mgr(void);

        void
            cleanup_random_mgr(void);

        enum appl_status
            init_log(void);

        void
            cleanup_log(void);

        enum appl_status
            init_pool_mgr(void);

        void
            cleanup_pool_mgr(void);

        enum appl_status
            init_thread_cache_mgr(void);

        void
            cleanup_thread_cache_mgr(void);

        enum appl_status
            init_timer_mgr(void);

        void
            cleanup_timer_mgr(void);

#if defined APPL_HAVE_XLIB
        enum appl_status
            init_xlib(void);

        void
            cleanup_xlib(void);
#endif /* #if defined APPL_HAVE_XLIB */

        enum appl_status
            init_backtrace(void);

        void
            cleanup_backtrace(void);

        enum appl_status
            init_netdevice_mgr(void);

        void
            cleanup_netdevice_mgr(void);

        enum appl_status
            init_download_mgr(void);

        void
            cleanup_download_mgr(void);

        enum appl_status
            init_dir_mgr(void);

        void
            cleanup_dir_mgr(void);

        enum appl_status
            init_unique_mgr(void);

        void
            cleanup_unique_mgr(void);

        static
        void
            s_bootstrap(void);

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

#if 0
        virtual
        enum appl_status
            v_poll_mgr(
                class appl_poll_mgr * * const
                    r_poll_mgr) const;
#endif

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

        virtual
        enum appl_status
            v_dir_mgr(
                class appl_dir_mgr * * const
                    r_dir_mgr) const;

        virtual
        enum appl_status
            v_unique_mgr(
                class appl_unique_mgr * * const
                    r_unique_mgr) const;

#if defined APPL_DEBUG
        virtual
        enum appl_status
            v_debug(
                class appl_debug * * const
                    r_debug) const;
#endif /* #if defined APPL_DEBUG */

}; // class appl_context_std

/* end-of-file: appl_context_std.h */
