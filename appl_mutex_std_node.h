/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MUTEX_STD_NODE_H
#error include appl_mutex_std_node.h once
#endif /* #if defined INC_APPL_MUTEX_STD_NODE_H */

#define INC_APPL_MUTEX_STD_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_MUTEX_NODE_H
#error include appl_mutex_node.h before
#endif /* #if ! defined INC_APPL_MUTEX_NODE_H */

struct appl_mutex_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_context;

class appl_mutex_node;

class appl_mutex_std_node;

//
//
//
class appl_mutex_std_node : public appl_mutex_node
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_context * const
                    p_context,
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                class appl_mutex_node * * const
                    r_mutex_node);

    protected:

        appl_mutex_std_node();

        virtual
        ~appl_mutex_std_node();

    private:

        appl_mutex_std_node(
            class appl_mutex_std_node const & r);

        class appl_mutex_std_node &
            operator =(
                class appl_mutex_std_node const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
            v_lock(void);

        virtual
        enum appl_status
            v_unlock(void);

}; // class appl_mutex_std_node

/* end-of-file: appl_mutex_std_node.h */
