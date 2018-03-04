/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_STD_NODE_H
#error include appl_event_std_node.h once
#endif /* #if defined INC_APPL_EVENT_STD_NODE_H */

#define INC_APPL_EVENT_STD_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_EVENT_NODE_H
#error include appl_event_node.h before
#endif /* #if ! defined INC_APPL_EVENT_NODE_H */

struct appl_event_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_context;

class appl_event_node;

class appl_event_std_node;

//
//
//
class appl_event_std_node : public appl_event_node
{
    public:

        static
        enum appl_status
            s_create(
                class appl_context * const
                    p_context,
                struct appl_event_descriptor const * const
                    p_event_descriptor,
                class appl_event_node * * const
                    r_event_node);

    protected:

        appl_event_std_node();

        virtual
        ~appl_event_std_node();

    private:

        pthread_cond_t
            m_pthread_event_storage;

        bool
            m_pthread_event_initialized;

        unsigned char
            m_uc_padding[7u];

        appl_event_std_node(
            class appl_event_std_node const & r);

        class appl_event_std_node &
            operator =(
                class appl_event_std_node const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

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
            v_signal(void);

        virtual
        enum appl_status
            v_wait(
                class appl_mutex_node * const
                    p_mutex_nodet);

}; // class appl_event_std_node

/* end-of-file: appl_event_std_node.h */
