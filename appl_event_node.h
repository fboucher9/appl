/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_NODE_H
#error include appl_event_node.h once
#endif /* #if defined INC_APPL_EVENT_NODE_H */

#define INC_APPL_EVENT_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_event_handle;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_event_node;

//
//
//
class appl_event_node : public appl_object
{
    public:

        static
        class appl_event_node *
            convert_handle(
                struct appl_event_handle * const
                    p_event_handle);

        virtual
        enum appl_status
            v_signal(void);

        virtual
        enum appl_status
            v_wait(
                class appl_mutex_node * const
                    p_mutex_node,
                unsigned long int const
                    i_time_freq,
                unsigned long int const
                    i_time_count);

    protected:

        appl_event_node();

        virtual
        ~appl_event_node();

    private:

        appl_event_node(
            class appl_event_node const & r);

        class appl_event_node &
            operator =(
                class appl_event_node const & r);

}; // class appl_event_node

/* end-of-file: appl_event_node.h */
