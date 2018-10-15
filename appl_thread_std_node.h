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

/* Header file dependency */
#if ! defined INC_APPL_THREAD_IMPL_H
#error include appl_thread_impl.h before
#endif /* #if ! defined INC_APPL_THREAD_IMPL_H */

class appl_thread_std_node;

//
//      How to remove mutex and event from thread impl?
//          Required to delay start a threa
//          Required to wait for stop
//

//
//      Removal of v_start method:
//          To start the thread on v_start, we must
//          push a descriptor onto a queue.
//

//
//      Removal of v_stop method:
//          Thread pushes result onto queue
//          Application pops result from queue
//          Who allocates memory for queue?
//

#if 0
class appl_thread_sync
{
    public:

        enum appl_status
            set_value(
                void * const
                    p_value);

        enum appl_status
            get_value(
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count,
                void * * const
                    r_value);

    private:

        class appl_mutex_impl *
            m_lock;

        class appl_event_impl *
            m_event;

        struct appl_thread *
            m_thread;

        void *
            m_value;

}; // class appl_thread_sync
#endif

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
            v_start(
                struct appl_thread_descriptor const * const
                    p_thread_descriptor);

        virtual
        enum appl_status
            v_interrupt(void);

    private:

        // --

        class appl_thread_impl
            m_thread_impl;

        // --

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

        enum appl_status
            init(
                struct appl_thread_property const * const
                    p_thread_property);

        virtual
        enum appl_status
            v_cleanup(void);

}; // class appl_thread_std_node

/* end-of-file: appl_thread_std_node.h */
