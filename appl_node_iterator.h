/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_NODE_ITERATOR_H
#error include appl_node_iterator.h once
#endif /* #if defined INC_APPL_NODE_ITERATOR_H */

#define INC_APPL_NODE_ITERATOR_H

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_node_iterator;

//
//
//
class appl_node_iterator
{
    public:

        appl_node_iterator(
            class appl_node * const
                p_node);

        ~appl_node_iterator();

        class appl_node *
            get_node(void);

        bool
            next(void);

        bool
            prev(void);

    private:

        class appl_node *
            p_cur;

        class appl_node *
            p_end;

        appl_node_iterator(
            class appl_node_iterator const & r);

        class appl_node_iterator &
            operator =(
                class appl_node_iterator const & r);

}; // class appl_node_iterator

/* end-of-file: appl_node_iterator.h */
