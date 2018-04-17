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
                struct appl_context_descriptor const * const
                    p_context_descriptor,
                struct appl_context * * const
                    r_context);

    protected:

        appl_context_std();

        virtual
        ~appl_context_std();

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

        virtual
        enum appl_status
            destroy(void);

    private:

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

        unsigned char
            uc_padding[5u];

        appl_context_std(
            class appl_context_std const & r);

        class appl_context_std &
            operator =(
                class appl_context_std const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        enum appl_status
            init_heap(
                class appl_heap * const
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

}; // class appl_context_std

/* end-of-file: appl_context_std.h */
