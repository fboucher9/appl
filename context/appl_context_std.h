/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_context_std_h
{
    inc_appl_context_std_h =
        /* Header file dependencies */
        inc_appl_context_h
};

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

struct appl_context;

struct appl_context_init_descriptor;

class appl_context_std;

//
//
//
class appl_context_std : public appl_context
{
    public:

        static
        enum appl_status
            create_instance(
                struct appl_context * * const
                    r_context);

        static
        enum appl_status
            s_destroy(
                struct appl_context * const
                    p_context);

        appl_context_std();

        virtual
        ~appl_context_std();

        enum appl_status
            f_init(
                struct appl_context_init_descriptor const * const
                    p_context_descriptor);

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

        bool
            b_init_heap;

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

#define PADDING (2)
#include <appl_padding.h>

        /* -- */

        appl_context_std(
            class appl_context_std const & r);

        class appl_context_std &
            operator =(
                class appl_context_std const & r);

        enum appl_status
            init_heap(
                struct appl_heap * const
                    p_heap);

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

        enum appl_status
            init_poll_mgr(void);

        void
            cleanup_poll_mgr(void);

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

        static
        void
            s_bootstrap(void);

}; // class appl_context_std

/* end-of-file: appl_context_std.h */
