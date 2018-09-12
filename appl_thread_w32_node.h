/* See LICENSE for license details */

/*

Module: appl_thread_w32_node.h

Description:

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_W32_NODE_H)
#error include appl_thread_w32_node.h once
#endif /* #if defined(INC_APPL_THREAD_W32_NODE_H) */

#define INC_APPL_THREAD_W32_NODE_H

struct appl_thread_property_handle;

/* Assert compiler */
#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

/* Header file dependency */
#if !defined(INC_APPL_THREAD_NODE_H)
#error include appl_thread_node.h before
#endif /* #if !defined(INC_APPL_THREAD_NODE_H) */

/* Assert OS */
#if ! defined APPL_OS_WINDOWS
#error include from windows build
#endif /* #if ! defined APPL_OS_WINDOWS */

struct appl_context;

class appl_thread_w32_node;

//
//
//
class appl_thread_w32_node : public appl_thread
{
    public:

        static
        enum appl_status
            create_instance(
                struct appl_context * const
                    p_context,
                struct appl_thread_property const * const
                    p_thread_property_handle,
                struct appl_thread * * const
                    r_thread);

    protected:

        appl_thread_w32_node();

        virtual
        ~appl_thread_w32_node();

        virtual
        enum appl_status
            v_start(
                void (* const p_callback)(
                    void * const
                        p_context),
                void * const
                    p_context);

        virtual
        enum appl_status
            v_stop(
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

        virtual
        enum appl_status
            v_interrupt(void);

    private:

        struct appl_thread_descriptor
            m_descriptor;

        // --

        class appl_mutex_impl
            m_lock;

        class appl_event_impl
            m_event;

        // --

        HANDLE
            m_w32_thread_handle;

        void *
            pv_padding[1u];

        // --

        bool
            m_running;

        bool
            m_start;

        bool
            m_kill;

        unsigned char
            uc_padding[5u];

        appl_thread_w32_node(
            class appl_thread_w32_node const & r);

        class appl_thread_w32_node &
            operator =(
                class appl_thread_w32_node const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        enum appl_status
            init(
                struct appl_thread_property const * const
                    p_thread_property);

        virtual
        enum appl_status
            v_cleanup(void);

        static
        DWORD
        CALLBACK
            thread_entry(
                void * const
                    p_thread_ctxt);

        void
            thread_handler(void);

}; // class appl_thread_w32_node

/* end-of-file: appl_thread_w32_node.h */
