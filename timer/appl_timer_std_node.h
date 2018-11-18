/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_TIMER_STD_NODE_H
#error include appl_timer_std_node.h once
#endif /* #if defined INC_APPL_TIMER_STD_NODE_H */

#define INC_APPL_TIMER_STD_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_TIMER_H
#error include appl_timer.h before
#endif /* #if ! defined INC_APPL_TIMER_H */

/* Predefine */
struct appl_timer_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_timer_std_node : public appl_timer
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_timer * * const
                    r_timer);

        appl_timer_std_node();

        virtual
        ~appl_timer_std_node();

        enum appl_status
            f_init(void);

    protected:

    private:

        struct appl_list
            m_used_list;

        struct appl_list
            m_free_list;

        struct appl_thread *
            m_thread;

        struct appl_mutex *
            m_lock;

        struct appl_event *
            m_event;

        signed long int volatile
            m_thread_kill;

        signed long int volatile
            m_thread_killed;

        appl_timer_std_node(
            class appl_timer_std_node const & r);

        class appl_timer_std_node &
            operator =(
                class appl_timer_std_node const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_schedule(
                struct appl_timer_descriptor const * const
                    p_timer_descriptor);

        static
        void
            s_worker(
                void * const
                    p_thread_context);

        void
            f_worker(void);

        appl_ull_t
            f_read_clock(void);

}; // class appl_timer_std_node

/* end-of-file: appl_timer_std_node.h */
