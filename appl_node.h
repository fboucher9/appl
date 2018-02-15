/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_NODE_H
#error include appl_node.h
#endif /* #if defined INC_APPL_NODE_H */

#define INC_APPL_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Header file dependency */
#if ! defined INC_APPL_LIST_H
#error include appl_list.h before
#endif /* #if ! defined INC_APPL_LIST_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_node;

//
//
//
class appl_node : public appl_object
{
    public:

        appl_node();

        virtual
        ~appl_node();

        struct appl_list *
            get_list(void);

        static
        class appl_node *
            get_node(
                struct appl_list * const
                    p_list);

        class appl_node *
            get_next(void);

        class appl_node *
            get_prev(void);

        static
        void
            join(
                class appl_node * const
                    p_node_left,
                class appl_node * const
                    p_node_right);

    private:

        struct appl_list
            o_list;

        appl_node(
            class appl_node const & r);

        class appl_node &
            operator =(
                class appl_node const & r);

}; // class appl_node

//
//
//
class appl_node_iterator
{
    public:

    protected:

    private:

}; // class appl_node_iterator

/* end-of-file: appl_node.h */
