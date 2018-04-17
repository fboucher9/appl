/* See LICENSE for license details */

/*

Module: appl_thread_std_node.h

Description:

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_STD_NODE_H)
#error include appl_thread_std_node.h once
#endif /* #if defined(INC_APPL_THREAD_STD_NODE_H) */

#define INC_APPL_THREAD_STD_NODE_H

struct appl_context;

struct appl_thread_property;

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

/* Header file dependency */
#if !defined(INC_APPL_THREAD_NODE_H)
#error include appl_thread_node.h before
#endif /* #if !defined(INC_APPL_THREAD_NODE_H) */

class appl_thread_std_node;

//
//
//
class appl_thread_std_node : public appl_thread
{
    public:

        static
        enum appl_status
            create_instance(
                struct appl_context * const
                    p_context,
                struct appl_thread_property const * const
                    p_thread_property,
                struct appl_thread * * const
                    r_thread);

    protected:

        appl_thread_std_node();

        virtual
        ~appl_thread_std_node();

        virtual
        enum appl_status
            v_start(void);

        virtual
        enum appl_status
            v_stop(
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count,
                void * * const
                    r_result);

        virtual
        enum appl_status
            v_interrupt(void);

    private:

        struct appl_thread_descriptor
            m_descriptor;

        pthread_mutex_t
            m_lock;

        pthread_cond_t
            m_event;

        pthread_t
            m_thread;

        void *
            m_thread_result;

        bool
            m_running;

        unsigned char
            uc_padding[7u];

        appl_thread_std_node(
            class appl_thread_std_node const & r);

        class appl_thread_std_node &
            operator =(
                class appl_thread_std_node const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        void
            thread_handler(void);

        static
        void *
            thread_entry(
                void *
                    p_thread_context);

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

#if defined APPL_DEBUG
        void
            oops(
                unsigned char const * const
                    p_msg_min,
                unsigned char const * const
                    p_msg_max,
                int const
                    i_status_code);
#endif /* #if defined APPL_DEBUG */

}; // class appl_thread_std_node

/* end-of-file: appl_thread_std_node.h */
