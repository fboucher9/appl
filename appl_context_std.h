/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_CONTEXT_STD_H)
#error include appl_context_std.h once
#endif /* #if defined(INC_APPL_CONTEXT_STD_H) */

#define INC_APPL_CONTEXT_STD_H

struct appl_context_descriptor;

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
    // friend struct appl_heap;

    public:

        static
        enum appl_status
            create_instance(
                struct appl_context_descriptor const * const
                    p_context_descriptor,
                struct appl_context * * const
                    r_context);

        appl_context_std();

        virtual
        ~appl_context_std();

        enum appl_status
            f_init(
                struct appl_context_init_descriptor const * const
                    p_context_descriptor);

    protected:

        virtual
        enum appl_status
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

        bool
            b_init_debug;

        bool
            b_init_options;

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

        /* -- */

        bool
            b_init_event_mgr;

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

        enum appl_status
            init_debug(void);

        void
            cleanup_debug(void);

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

}; // class appl_context_std

/* end-of-file: appl_context_std.h */
