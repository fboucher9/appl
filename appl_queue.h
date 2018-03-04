/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_QUEUE_H
#error include appl_queue.h once
#endif /* #if defined INC_APPL_QUEUE_H */

#define INC_APPL_QUEUE_H

/* Header file dependency */
/* ... */

class appl_queue;

//
//
//
class appl_queue : public appl_object
{
    public:

        static
        enum appl_status
            s_create(
                class appl_context * const
                    p_context,
                class appl_queue * * const
                    r_queue);

        appl_queue();

        virtual
        ~appl_queue();

        virtual
        enum appl_status
            v_push(
                class appl_node * const
                    p_node);

        virtual
        enum appl_status
            v_pop(
                class appl_node * const
                    p_node);

        // unblock a thread that is waiting for a push or pop
        virtual
        enum appl_status
            v_kill(void);

    protected:

        class appl_mutex_node *
            m_lock;

        class appl_event_node *
            m_event;

        class appl_node
            m_list;

        signed long int volatile
            m_kill;

    private:

        appl_queue(
            class appl_queue const & r);

        class appl_queue &
            operator =(
                class appl_queue const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

}; // class appl_queue

/* end-of-file: appl_queue.h */
