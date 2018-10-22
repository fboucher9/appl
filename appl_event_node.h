/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_NODE_H
#error include appl_event_node.h once
#endif /* #if defined INC_APPL_EVENT_NODE_H */

#define INC_APPL_EVENT_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_POOL_OBJECT_H
#error include appl_pool_object.h before
#endif /* #if ! defined INC_APPL_POOL_OBJECT_H */

struct appl_event;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_event : public appl_pool_object
{
    public:

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

        appl_event();

        virtual
        ~appl_event();

    private:

        appl_event(
            struct appl_event const & r);

        struct appl_event &
            operator =(
                struct appl_event const & r);

}; // struct appl_event

/* end-of-file: appl_event_node.h */
