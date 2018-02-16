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

    protected:

        class appl_node *
            p_next;

        class appl_node *
            p_prev;

    private:

        appl_node(
            class appl_node const & r);

        class appl_node &
            operator =(
                class appl_node const & r);

}; // class appl_node

/* end-of-file: appl_node.h */
