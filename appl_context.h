/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_CONTEXT_H)
#error include appl_context.h once
#endif /* #if defined(INC_APPL_CONTEXT_H) */

#define INC_APPL_CONTEXT_H

/* Header file dependency */
#if !defined(INC_APPL_OBJECT_H)
#error include appl_object.h before
#endif /* #if !defined(INC_APPL_OBJECT_H) */

struct appl_object_handle;

struct appl_context_handle;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

struct appl_context;

class appl_heap;

#if defined APPL_DEBUG
class appl_debug;
#endif /* #if defined APPL_DEBUG */

class appl_options;

class appl_thread_mgr;

class appl_mutex_mgr;

class appl_file_mgr;

class appl_poll_mgr;

class appl_clock;

class appl_event_mgr;

class appl_socket_mgr;

class appl_env;

//
//
//
struct appl_context : public appl_object
{
    public:

        class appl_heap *
            m_heap;

        class appl_options *
            m_options;

        /* -- */

        class appl_thread_mgr *
            m_thread_mgr;

        class appl_mutex_mgr *
            m_mutex_mgr;

        /* -- */

        class appl_file_mgr *
            m_file_mgr;

        class appl_poll_mgr *
            m_poll_mgr;

        /* -- */

        class appl_clock *
            m_clock;

        class appl_event_mgr *
            m_event_mgr;

        /* -- */

        class appl_socket_mgr *
            m_socket_mgr;

        class appl_env *
            m_env;

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

}; // class appl_context

/* end-of-file: appl_context.h */
