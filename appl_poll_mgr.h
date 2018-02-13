/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POLL_MGR_H
#error include appl_poll_mgr.h once
#endif /* #if defined INC_APPL_POLL_MGR_H */

#define INC_APPL_POLL_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_LIST_H
#error include appl_list.h before
#endif /* #if ! defined INC_APPL_LIST_H */

struct appl_poll_descriptor;

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_context;

class appl_thread_node;

class appl_mutex_node;

class appl_poll_node;

class appl_poll_mgr;

//
//
//
class appl_poll_mgr : public appl_object
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_context * const
                    p_context,
                class appl_poll_mgr * * const
                    r_poll_mgr);

        virtual
        enum appl_status
            v_create(
                struct appl_poll_descriptor const * const
                    p_poll_descriptor,
                class appl_poll_node * * const
                    r_poll_node);

    protected:

        appl_poll_mgr();

        virtual
        ~appl_poll_mgr();

        class appl_thread_node *
            p_thread_node;

        class appl_mutex_node *
            p_mutex_node;

        struct appl_list
            o_nodes;

    private:

        appl_poll_mgr(
            class appl_poll_mgr const & r);

        class appl_poll_mgr &
            operator =(
                class appl_poll_mgr const & r);

}; // class appl_poll_mgr

/* end-of-file: appl_poll_mgr.h */
