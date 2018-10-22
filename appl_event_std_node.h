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

struct appl_context;

struct appl_event;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_event_std_node;

//
//
//
class appl_event_std_node : public appl_event
{
    friend struct appl_pool;
    public:

        static
        enum appl_status
            s_create(
                struct appl_pool * const
                    p_pool,
                struct appl_event_descriptor const * const
                    p_event_descriptor,
                struct appl_event * * const
                    r_event);

    protected:

        appl_event_std_node();

        virtual
        ~appl_event_std_node();

    private:

        class appl_event_impl
            m_event_impl;

        bool
            m_event_impl_initialized;

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

        enum appl_status
            f_init(
                struct appl_event_descriptor const * const
                    p_event_descriptor);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_signal(void);

        virtual
        enum appl_status
            v_wait(
                struct appl_mutex * const
                    p_mutex,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

}; // class appl_event_std_node

/* end-of-file: appl_event_std_node.h */
