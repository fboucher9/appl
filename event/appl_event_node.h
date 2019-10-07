/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_EVENT_NODE_H

/* Reverse include guard */
enum guard_appl_event_node_h
{
    inc_appl_event_node_h =
        /* Header file dependencies */
        inc_appl_object_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_event : public appl_object
{
    public:

        appl_event(
            struct appl_context * const
                p_context);

        virtual
        ~appl_event();

        virtual
        enum appl_status
            v_signal(void);

        virtual
        enum appl_status
            v_wait(
                struct appl_mutex * const
                    p_mutex_node,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

    protected:

    private:

        appl_event(
            struct appl_event const & r);

        struct appl_event &
            operator =(
                struct appl_event const & r);

}; // struct appl_event

/* end-of-file: appl_event_node.h */
