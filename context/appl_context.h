/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_context_h
{
    inc_appl_context_h =
        /* Header file dependencies */
        inc_appl_object_h
};

struct appl_object;

struct appl_context;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

struct appl_context;

struct appl_allocator;

struct appl_heap;

#if defined APPL_DEBUG
class appl_debug;
#endif /* #if defined APPL_DEBUG */

struct appl_options;

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

struct appl_xlib;

//
//
//
struct appl_context : public appl_object
{
    public:

        struct appl_allocator *
            m_allocator;

        struct appl_heap *
            m_heap;

        /* -- */

        void *
            z_options[1u];

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

        class appl_event_mgr *
            m_event_mgr;

        class appl_socket_mgr *
            m_socket_mgr;

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

        struct appl_xlib *
            m_xlib;

        /* -- */

#if defined APPL_DEBUG
        class appl_debug *
            m_debug;

        void *
            pv_debug_padding[1u];
#endif /* #if defined APPL_DEBUG */

        static
        struct appl_context *
        from_object_handle(
            struct appl_object const * const
                p_object);

    protected:

        appl_context();

        virtual
        ~appl_context();

    private:

        appl_context(
            struct appl_context const & r);

        struct appl_context &
            operator =(
                struct appl_context const & r);

}; // struct appl_context

/* end-of-file: appl_context.h */
